#include <bits/stdc++.h>
#include "input.hpp"

using namespace std;

int main(){
  vector<int> v;
  cin>>v;
  int n=v.size();
  int a=v[0];
  int dif=1;
  for(int i=1;i<n;i++){
    if(v[i]==a)dif++;
    else dif--;
    if(dif==0){
      dif=1;
      a=v[i];
    }
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    if(v[i]==a)cnt++;
  }
  if(cnt>n/2)cout<<a<<endl;
  else cout<<"No majority"<<endl;

}
