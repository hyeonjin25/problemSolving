#include <bits/stdc++.h>
using namespace std;

int par[205];
int mat[205][205];

int find(int a){
  if(a==par[a])return a;
  else return par[a]=find(par[a]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a>b) swap(a,b);
  par[b]=a;
}

int main(){
  int n,m; cin >> n>>m;

  for(int i=1; i<=n; i++){
    par[i]=i;
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int a; cin >> a;
      if(a==1) merge(i,j);
    }
  }

  int p; cin >> p;
  p=find(p);
  for(int i=1; i<m; i++){
    int a; cin >> a;
    if(find(a)!=p) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}