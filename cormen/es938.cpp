#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int* x=new int[n+2];
  int* y=new int[n+2];
  for(int i=1;i<=n;i++)cin>>x[i];
  for(int i=1;i<=n;i++)cin>>y[i];
  
  int l=-1,r=n;
  while(r-l>1){
    int m=l+(r-l)/2;
    if(m>=0&&x[m]>y[n-m-1])r=m;
    else if(m<n-1&&y[n-m-2]>=x[m+1])l=m;
  }
  cout<<max(x[l],y[n-l-2])<<endl;
  delete [] x;
  delete [] y;
}
