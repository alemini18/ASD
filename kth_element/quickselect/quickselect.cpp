#include "quickselect.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std::chrono;
using namespace std;
typedef duration<double, seconds::period> secs;
const double E = 0.0001;
double getResolution() {
    steady_clock::time_point start = steady_clock::now();
    steady_clock::time_point end;
    do {
        end = steady_clock::now();
    } while (start == end);
    return duration_cast<secs>(end - start).count();
}


int main(){

  int n,k;
  std::cin>>n>>k;
  int* a=new int[n];
  for(int i=0;i<n;i++)std::cin>>a[i];
  steady_clock::time_point start = steady_clock::now();
  std::cout<<kth_element(a,n,k)<<std::endl;
  steady_clock::time_point end= steady_clock::now();
  std::cout<<duration_cast<secs>(end - start).count()<<std::endl;
  delete [] a;
  return 0;
}
