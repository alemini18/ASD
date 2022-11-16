#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "input.hpp"

using namespace std;

int main(){
  int n,x;
  vector<int> v;
  cin>>v>>x;
  n=v.size();
  vector<pair<int,int> > a(n);
  for(int i=0;i<n;i++){
    a[i].first=v[i];
    a[i].second=i;
  }
  sort(a.begin(),a.end());
  int l=0,r=n-1;
  while(l<r){
    int s=a[l].first+a[r].first;
    if(s==x){
      cout<<a[l].second<<" "<<a[r].second<<endl;
      l=n;
  }
  else if(s>x)r--;
  else l++;
  }
  cout<<"-1 -1"<<endl;
}
