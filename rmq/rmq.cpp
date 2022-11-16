#include<bits/stdc++.h>
#include "rmq.hpp"
#include "../stars/input.hpp"

using namespace std;

int main(){
  vector<int> v,q;
  cin>>v>>q;
  int n=v.size();
  int qq=q.size();
  for(int i=0;i<n;i++)v[i]=-v[i];
  rmq a=rmq(v);
  for(int i=0;i<qq;i+=2){
    cout<<-v[a(q[i],q[i+1])]<<" ";
  }


}
