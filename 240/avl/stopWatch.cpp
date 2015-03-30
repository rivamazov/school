#include "stopWatch.h"

void stopWatch::start()
{
  begin = std::chrono::system_clock::now();
}

void stopWatch::stop()
{
  end = std::chrono::system_clock::now();
}

std::ostream& operator<<(std::ostream &out,stopWatch &st)
{
  std::chrono::duration<double> elapsed_seconds = st.end - st.begin;
  out << "elapsed time: " << elapsed_seconds.count() << "s\n";
  return out;
}
