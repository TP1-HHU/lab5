#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
//------------------------------------------------------------------------------
// Make sure M_PI is defined irrespective of compiler
#ifndef M_PI
const double M_PI = 3.1415926536;
#endif
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
struct particle{
    double x,y;
};
//------------------------------------------------------------------------------
struct statistics{
    double msd,sx,sy;
};
//------------------------------------------------------------------------------
void init(particle* const p, const int N);
void push(particle* const p, const int N);
statistics stat(const particle* const p, const int N);
void write_to_file(const particle* const p, const int N, const string fname);
string create_filename(const string basename, const int N);
//------------------------------------------------------------------------------
int main(void){
    srand(time(NULL));
    const int Npart  = 500;
    particle*  p  = new particle[Npart];
    const double step = 0.1;
    statistics s;

    ofstream ofstat("statistics");
    const string basename = "rwalk";

    const int Nsteps = 100;		// total # of steps
    const int Nfiles = 20;		// total # of output files (excl. initial file)
    int Nsubsteps    = Nsteps / Nfiles; // # steps between outputs

    init(p, Npart);

    for(int i = 0; i <= Nfiles; i++){
      s = stat(p,Npart);
      ofstat << i << "\t" << s.msd << "\t" << s.sx << "\t" << s.sy << endl;
      write_to_file(p, Npart, create_filename(basename,i));
	    for(int j = 0; j < Nsubsteps; j++)
	         push(p, Npart);

    }

    ofstat.close();

    delete[] p;
    return 0;
}
//------------------------------------------------------------------------------
statistics stat(const particle* const p, const int N){
  // your code goes here
}
//------------------------------------------------------------------------------
void push(particle* const p, const int N){
    // your code goes here
}
//------------------------------------------------------------------------------
void init(particle* const p, const int N){
    for(int i = 0; i < N; i++){
	      p[i].x = 0;
	      p[i].y = 0;
    }
}
//------------------------------------------------------------------------------
string create_filename(const string basename, const int N){
    stringstream s;
    s.str("");
    s << basename << "_"  << N;
    return s.str();
}
//------------------------------------------------------------------------------
void write_to_file(const particle* const p, const int N, const string fname){
    ofstream out(fname.c_str());
    for(int i = 0; i < N; i++)
	     out << p[i].x << "\t" << p[i].y << endl;
    out.close();
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
