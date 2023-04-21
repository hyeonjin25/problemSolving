#include<bits/stdc++.h>

using namespace std;

int par[100005];
vector<int> v[100005];

int recur(int cur, int p){
  for(auto a:v[cur]){
    if(p==a)continue;
    par[a]=cur;
    recur(a,cur);
  }
  return 0;
}

int main(){
  int n; cin >>n;
  queue<int> q;

  int a,b;
  for(int i=0; i<n-1; i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  recur(1,0);

  for(int i=2; i<=n; i++){
    cout << par[i] << '\n';
  }
}