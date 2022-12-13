#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int nax=1e5+5;

typedef long long ll;

ll c[nax];
ll cc[nax];
ll dp[nax];
set<int> cg[nax];
vector<int> g[nax];
vector<int> inv[nax];
int id[nax];
int n,m,k;
int s,e;
vector<int> toposort;
bool v[nax];
void dfs1(int x){
  if(v[x])return;
  v[x]=true;
  for(int a:g[x])dfs1(a);
  toposort.push_back(x);
}
void dfs2(int x, int val){
  if(v[x])return;
  v[x]=1;
  id[x]=val;
  for(int a:inv[x])dfs2(a,val);
}
void korasaju(){
  fill(v,v+n,0);
  for(int i=0;i<n;i++)dfs1(i);
  fill(v,v+n,0);
  reverse(all(toposort));
  for(int i:toposort)if(!v[i])dfs2(i,k++);
  for(int i=0;i<n;i++){
    cc[id[i]]+=c[i];
  for(int x:g[i]){
    if(id[i]!=id[x]){
    cg[id[i]].insert(id[x]);
  }
  }
}
s=id[0];
e=id[n-1];
}
ll dfs(int x){
  if(v[x])return dp[x];
  if(x==e)return c[x];
  v[x]=1;
  dp[x]=-1;
  ll ans=-1;
  for(int a:cg[x]){
      ans=max(ans,dfs(a));
  }
  if(ans==0)return dp[x];
  ans+=cc[x];
  return dp[x]=ans;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>c[i];
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    inv[b].push_back(a);
  }
  korasaju();
  fill(v,v+k,0);
  cout<<dfs(s)<<endl;
}
