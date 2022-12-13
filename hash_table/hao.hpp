#include <bits/stdc++.h>

class HAO{
private:
  int* t;
  int* v;
  int sz;
  int tr_sz;
  int MOD=1e9+7;
  int A;
  int B;
  int perm(int a, int i){
    if(i==0)return 1;
    int h=perm(a,i/2);
    h=((long long)h*h)%MOD;
    if(i%2)h=((long long)h*a)%MOD;
    return h;
  }
  int h(int x, int i){
    int x1=((long long)A*x+B)%MOD;
    return perm(x1,i)%MOD;
  }
public:
  HAO(){
    sz=0;
    tr_sz=1;
    t=(int*)malloc(sizeof(int));
    v=(int*)malloc(sizeof(int));
    v[0]=1;

  }
  int* find(int x){
    int i=1;
    int p=h(x,i);
    while(v[p]==0&&t[p]!=x){
      i++;
      p=h(x,i);
    }
    return (t[p]==x?(t+p):NULL);


  }
}
