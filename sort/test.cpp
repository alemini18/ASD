#include <iostream>
#include "input.hpp"
#include "radix.hpp"

using namespace std;

int main(){
  vector<int> v;
  cin>>v;
  radix_sort(v,2);
  cout<<v<<endl;


}
