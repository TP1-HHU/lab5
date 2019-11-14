#include <iostream>
#include <cstdlib>
//-----------------------------------------------------
using namespace std;
//-----------------------------------------------------
//-----------------------------------------------------

class Vec{
public:
  Vec(const int N, const string s="default"):N(N),name(s){p = new double[N];};
  ~Vec(){delete[] p;};

  void set(const int i, const double c);
  double get(const int i) const;
  void print() const;
private:
  bool validIdx(const int i) const;
  int N;
  double *p;
  const string name;
};
//-----------------------------------------------------
bool Vec::validIdx(const int i) const {
  if ((i=>0) && (i<N))
     return true;
  else{
    cout << "Index error. i = " <<i << ", N = " << N << endl;
    exit(1);
  }
}
//-----------------------------------------------------
void Vec::set(const int i, const double c){
  if (validIdx(i)) p[i] = c;
}
//-----------------------------------------------------
double Vec::get(const int i) const{
  if (validIdx(i)) return p[i];
  else return 0;
}
//-----------------------------------------------------
void Vec::print() const {
  cout << "# " << name << endl;
  for(int i=0; i<N; i++)
    cout << p[i] << endl;
}

//-----------------------------------------------------

int main(){
  int N = 10;
  Vec v(N,"TinGonic");

  for(int i=1; i<=N; i++)
    v.set(i, i*1.1);

  v.print();
  cout << "----" << endl;

  for(int i=1; i<=N+1; i++)
      cout << v.get(i) << endl;

  return 0;
}
