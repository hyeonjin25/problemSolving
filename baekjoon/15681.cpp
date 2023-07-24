#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int num[100005];

void tree(int node, int par){
  for(auto n:graph[node]){
    if (n == par) continue;
    tree(n, node);
    num[node] += num[n];
  }
  num[node]++;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,r,q;
  cin >> n >> r >> q;
  int u,v;
  for(int i=0; i<n-1; i++){
    cin >> u >> v;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  tree(r, 0);

  int a;
  while(q--){
    cin >>a;
    cout << num[a] << '\n';
  }
}