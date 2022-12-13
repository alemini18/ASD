#include <bits/stdc++.h>
#include "input.hpp"
#include "median.hpp"

using namespace std;

int main1(int argc, char** argv){
  vector<int> v;
  cin>>v;
  int* a=new int[v.size()];
  for(int i=0;i<v.size();i++)a[i]=v[i];
  cout<<median_of_medians(a,v.size(),atoi(argv[1]))<<endl;
  delete [] a;

}

int main(){
  int n=5;
  int a[]={1,2,3,4,5};
  int* b=new int[n];
  do{
    for(int i=0;i<n;i++)b[i]=a[i];
    sort5(b,n);
    for(int i=0;i<n;i++)cout<<b[i]<<" \n"[i==n-1];
    }while(next_permutation(a,a+n));
}
