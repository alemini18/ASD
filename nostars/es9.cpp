#include <iostream>
#include <vector>
#include "input.hpp"

using namespace std;

int main(){
  vector<int> v;
  int x;
  cin>>v>>x;
  int n=v.size();
  if(n!=0){
    int j=0;
    int s=v[0];
    for(int i=1;i<n;i++){
      s+=v[i];
      while(j<=min(i,n-1)&&(s>x||v[j]==0))s-=v[j++];
      if(j==n)break;
      if(s==x){
        cout<<j<<" "<<i<<endl;
        return 0;
      }
    }
  }
  cout<<"-1 -1"<<endl;
}
