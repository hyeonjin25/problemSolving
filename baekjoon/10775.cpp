#include <bits/stdc++.h>
using namespace std;

int par[100005];

int find(int a){
  if(par[a]==a) return a;
  else return par[a]=find(par[a]);
}

void merge(int a, int b){
  a = find(a); b = find(b);
  if(a>b) swap(a,b);
  par[b]=a;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin >> n>>m;

  for(int i=1; i<=n; i++){
    par[i]=i;
  }

  int cnt=0;
  for(int i=0; i<m; i++){
    int a; cin >> a;
    
    if(find(a)==0) {
      cout << cnt;
      return 0;
    }
    merge(find(a),find(a)-1);
    cnt++;
  }


  cout << cnt;
}