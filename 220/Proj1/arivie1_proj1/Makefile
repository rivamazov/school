SRC_FILES = \
  Makefile \
  README \
  floatx.c \
  floatx.h \
  main.c

floatx:  	main.c floatx.c floatx.h
		gcc -g -Wall -std=c99 -o floatx main.c floatx.c -lm

clean:
		rm -f floatx proj1.tar.gz *.o *~ 
		-rm -r $(USER)_proj1
		-rm $(USER)_proj1.tar.gz

dist:		$(SRC_FILES)
		mkdir $(USER)_proj1
		cp $(SRC_FILES) $(USER)_proj1
		tar -cvzf $(USER)_proj1.tar.gz $(USER)_proj1
		rm -r $(USER)_proj1