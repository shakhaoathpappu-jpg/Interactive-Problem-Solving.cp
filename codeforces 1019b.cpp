#include<bits/stdc++.h>
using namespace std;

int ask(int x){
  cout << "? " << x+1 << "\n";
  fflush(stdout);
  int res; cin >> res;
  return res;
}

void ans(int x){
  if(x==-1){
    cout << "! -1";
  }
  else{
    cout << "! " << x+1 << "\n";
  }
  fflush(stdout);
}

int half;

int f(int x){
  int p=ask(x);
  int q=ask(half+x);
  return p-q;
}

int main(){
  int n; cin >> n;
  if((n/2)%2){ans(-1);return 0;}
  half=(n/2);

  int f0=f(0);
  if(f0==0){ans(0);return 0;}
  int l=1,r=half-1;
  while(l<=r){
    int te=(l+r)/2;
    int fv=f(te);
    if(fv==0){ans(te);return 0;}
    if((f0<0 && fv<0) || (f0>0 && fv>0)){
      l=te+1;
    }
    else{
      r=te-1;
    }
  }
  ans(-1);
  return 0;
  return 0;
}
