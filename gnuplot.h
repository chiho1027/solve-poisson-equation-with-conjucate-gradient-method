#ifndef GNUPLOT_H
#define GNUPLOT_H
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class gnuplot{
public:
  gnuplot();
  ~gnuplot();
  void operator() (const string & command);
protected:
  FILE *gnuplotpipe;
};


gnuplot::gnuplot(){
  gnuplotpipe = popen("gnuplot -persist","w");
  if(!gnuplotpipe)
    cerr<<("Gnuplot not found !");
}

gnuplot::~gnuplot(){
  fprintf(gnuplotpipe,"exit\n");
  pclose(gnuplotpipe);
}

void gnuplot::operator() (const string & command){
  
  fprintf(gnuplotpipe,"%s\n", command.c_str());
  fflush(gnuplotpipe);
}

struct timespec diff(struct timespec start, struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}




#endif
