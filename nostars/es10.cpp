#include <iostream>
#include <vector>
#include "input.hpp"

using namespace std;

int main(){
  vector<int> v;
  cin>>v;
  int n=v.size();
  int mini=0;
  int ans1=0,ans2=0;
  for(int i=1;i<n;i++){
    mini=(min(v[mini],v[i])==v[i]?i:mini);
    if(v[i]-v[mini]>v[ans2]-v[ans1]){
      ans2=i;
      ans1=mini;
    }
  }
  cout<<ans1<<" "<<ans2<<endl;

}
