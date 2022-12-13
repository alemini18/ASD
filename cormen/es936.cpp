#include <bits/stdc++.h>
#include "../kth_element/quickselect.hpp"

using namespace std;

void quantiles(int* arr, int n, int k){
  //cout<<n<<" "<<k<<endl;
  if(k<=1||n<=1)return;
    int sz_block=n/k;
    int median_block=n/2-(n/2)%sz_block;
    quickselect(arr,n,median_block);
    quantiles(arr,median_block,median_block/sz_block);
    quantiles(arr+median_block,n-median_block,(n-median_block+sz_block-1)/sz_block);
  }

int main(){
  int n,k;
  cin>>n>>k;
  int* a=new int[n];
  for(int i=0;i<n;i++)cin>>a[i];
  quantiles(a,n,k);
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  delete [] a;
}
