#include "floatx.h"

#include <limits.h>
#include <math.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static void usage(const char *progName);
static int string_to_int(const char *s);
static int interact(const floatxDef *def, FILE *in, FILE *out);

/* Program be invoked with 2 arguments: tot_bits, exp_bits. */
int main(int argc, const char *argv[]) {
  if (argc != 3) usage(argv[0]);
  int tot_bits = string_to_int(argv[1]);
  int exp_bits = string_to_int(argv[2]);
  if (tot_bits > sizeof(floatx)*CHAR_BIT) {
    fprintf(stderr, "requested total floatx size %d exceed max size %zu\n",
            tot_bits, (size_t)sizeof(floatx)*CHAR_BIT);
    usage(argv[0]);
  }
  if (exp_bits + 1 >= tot_bits) {
    fprintf(stderr, "no space for fraction with %d exponent bits within %d "
            "total bits\n", exp_bits, tot_bits);
    usage(argv[0]);
  }
  const floatxDef floatXParams = { tot_bits, exp_bits };
  return interact(&floatXParams, stdin, stdout);
}

static void usage(const char *progName) {
  fprintf(stderr, "%s N_TOTAL_BITS N_EXP_BITS\n", progName);
  exit(1);
}

/* ----------------------
	Returns integer value corresponding to *s
	s must point to a valid ASCII representation of a decimal int.
 	Exits with error message if s is not valid.
 ----------------------------*/
static int string_to_int(const char *s) {
  char *p;
  errno=0;
  int value = strtol(s, &p, 10);
  if (*p != 0) {
    fprintf(stderr, "%s is not an int\n", s);
    exit(1);
  }
  if (errno != 0) {
	  perror("In string_to_int, got error: ");
	  exit(1);
  }
  return value;
}

/*-----------------------------------------------------------------------------------------------
	While more lines on input stream...
		write prompt to output stream
		read 2 ints at a time: value and exp2.
		convert value * 2**exp2 to a floatx as per def,
		write results to stream out.
		Returns non-zero on I/O error.
 ------------------------------------------------------------------------------------------------*/
static int interact(const floatxDef *def, FILE *in, FILE *out) {
  while (1) { //till EOF or I/O error
    int value, exp2;
    fprintf(stderr,"Enter value exp2: "); // Write prompt
    if (fscanf(in, "%d %d", &value, &exp2) != 2) {
		if (feof(in)) break;
		if (ferror(in)) {
		  fprintf(stderr, "i/o error ... aborting\n");
		  break;
		}
		fprintf(stderr, "bad input ignored ... continuing\n");
		int c;
		while ((c = fgetc(in)) != '\n' && c != EOF) { /* skip line */ }
		continue; // back to top of loop
    }
    fprintf(stderr,"\n");
    floatx fx = number_to_floatx(def, value, exp2);
    double z = floatx_to_double(def, fx);
    double trueValue = 1.0 * value * pow(2, exp2);
    int nHexets = (def->tot_bits + 3)/4;
    fprintf(out, "input: %d * (2**%d) = %g; floatx bits: 0x%0*lx; "
            "floatx value: %g\n", value, exp2, trueValue, nHexets, fx, z);
  } //till EOF or I/O error
  return ferror(in);
}
