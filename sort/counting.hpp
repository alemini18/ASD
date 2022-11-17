#include <algorithm>
#include <vector>


void counting_sort(int* a, int n){
  int k=a[0];
  for(int i=0;i<n;i++)k=std::max(k,a[i]);

  int* c=new int[k+1];
  for(int i=0;i<=k;i++)c[i]=0;
  for(int i=0;i<n;i++)c[a[i]]++;
  for(int i=1;i<=k;i++)c[i]+=c[i-1];
  int* b=new int[n];
  for(int i=n-1;i>=0;i--){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  for(int i=0;i<n;i++)a[i]=b[i];
  delete [] c;
  delete [] b;
}
void counting_sort(std::vector<int> &a){
  int n=a.size();
  int k=a[0];
  for(int i=0;i<n;i++)k=std::max(k,a[i]);

  int* c=new int[k+1];
  for(int i=0;i<=k;i++)c[i]=0;
  for(int i=0;i<n;i++)c[a[i]]++;
  for(int i=1;i<=k;i++)c[i]+=c[i-1];
  int* b=new int[n];
  for(int i=n-1;i>=0;i--){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  for(int i=0;i<n;i++)a[i]=b[i];
  delete [] b;
  delete [] c;
}
