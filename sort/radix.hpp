#include <algorithm>
#include <vector>
#include <utility>


void counting_sort(std::pair<int,int>* a, int n, int base){
  int k=a[0].first%base;
  for(int i=0;i<n;i++)k=std::max(k,a[i].first%base);

  std::vector<std::pair<int,int>> c[k+1];
  for(int i=0;i<n;i++)c[a[i].first%base].push_back(a[i]);
  int id=0;
  for(int i=0;i<=k;i++)
  for(int j=0;j<c[i].size();j++)a[id++]=c[i][j];
}
void radix_sort(int* a, int n, int base){

  int k=a[0];
  for(int i=0;i<n;i++)k=std::max(k,a[i]);
  std::pair<int,int>* arr=new std::pair<int,int>[n];
  for(int i=0;i<n;i++)arr[i]=std::make_pair(a[i],a[i]);
  while(k>0){
    counting_sort(arr,n,base);
    for(int i=0;i<n;i++)arr[i].first/=base;
    k/=base;
  }
  for(int i=0;i<n;i++)a[i]=arr[i].second;
  delete [] arr;

}
void radix_sort(std::vector<int>& a, int base){
  int n=a.size();
  int k=a[0];
  for(int i=0;i<n;i++)k=std::max(k,a[i]);
  std::pair<int,int>* arr=new std::pair<int,int>[n];
  for(int i=0;i<n;i++)arr[i]=std::make_pair(a[i],a[i]);
  while(k>0){
    counting_sort(arr,n,base);
    for(int i=0;i<n;i++)arr[i].first/=base;
    k/=base;
  }
  for(int i=0;i<n;i++)a[i]=arr[i].second;
  delete [] arr;

}
