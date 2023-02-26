#include<bits/stdc++.h>
using namespace std;

int parent[303030];

int find(int a){
  if (parent[a]==a) return a;
  else return parent[a] = find(parent[a]);
}

void merge(int a, int b){
  a = find(a); 
  b = find(b);
  if(a>b) swap(a,b);
  parent[b]=a;
}

int same(int a, int b){
  if(find(a)==find(b)) return 1;
  else return 0;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=1; i<=n; i++){
    parent[i]=i;
  }

  for(int i=0; i<n-2; i++){
    int a,b;
    cin >> a>>b;
    merge(a,b);
  }

  for (int i=1; i<=n; i++) {
    if (find(i) != 1) {
      cout << 1 << ' ' << i;
      return 0;
    }
  }
}