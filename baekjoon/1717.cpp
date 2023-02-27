#include <bits/stdc++.h>

using namespace std;

int par[1000005];

int find(int a){
  if(par[a]==a) return a;
  else return par[a]=find(par[a]);
}

void merge(int a,int b){
  a = find(a);
  b = find(b);
  if(a>b) swap(a,b);
  par[b]=a;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin >>n >>m;

  for(int i=0; i<=n; i++){
    par[i]=i;
  }

  for(int i=0; i<m;i++){
    int a,b,c; cin >> a>>b>>c;

    if(a==0) merge(b,c);
    else {
      if(find(b)==find(c)) cout << "yes"<<'\n';
      else cout << "no"<<'\n';
    }
  }
}