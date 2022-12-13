#include <algorithm>
#include <iostream>


int median_of_medians(int* a, int n, int k){
  int pivot;
  if(n<=5){
    std::sort(a,a+n);
    pivot=a[k];
  }else{
  for(int i=0;i<n;i+=5){
    std::sort(a+i,a+i+std::min(n-i,5));
  }
  for(int i=0;i<n;i+=5)std::swap(a[i/5],a[std::min((i+n)/2,i+2)]);
  pivot=median_of_medians(a,(n+4)/5,(n+4)/10);

int j=-1;
for(int i=0;i<n;i++){
  if(a[i]==pivot){
    std::swap(a[i],a[n-1]);
  }
  if(a[i]<pivot){
    j++;
    std::swap(a[i],a[j]);
  }

}
j++;
std::swap(a[j],a[n-1]);
  if(j==k)pivot=a[j];
  else if(k<j)return median_of_medians(a,j,k);
  else return median_of_medians(a+j,n-j,k-j);
}
return pivot;

}
