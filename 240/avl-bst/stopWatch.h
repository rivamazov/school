#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <iostream>
#include <chrono>

class stopWatch
{
 public:
  stopWatch(){};
  void start();
  void stop();
  friend std::ostream& operator<<(std::ostream &out,stopWatch &st);
 private:
  std::chrono::time_point<std::chrono::system_clock> begin, end;


};

#endif
