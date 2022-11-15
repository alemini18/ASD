#include<bits/stdc++.h>
#include "rmq.hpp"

int main(){
  int n,q;
  std::cin>>n>>q;
  int* arr=new int[n];
  for(int i=0;i<n;i++)std::cin>>arr[i];
  rmq a(arr,n);
  for(int i=0;i<q;i++){
    int l,r;
    std::cin>>l>>r;
    std::cout<<arr[a(l,r)]<<" ";
  }
  delete [] arr;
  return 0;
}
