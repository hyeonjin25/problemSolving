#include <bits/stdc++.h>

using namespace std;

vector<int> v[10005];
int vis[10005];
int cnt[10005];
vector<int> b;

void dfs(int cur, int st){
  vis[cur]=1;
  cnt[st]++;
  for(auto e:v[cur]){
    if(!vis[e]) dfs(e,st);
  }
}

int main()
{
  int n,m; cin >> n >> m;

  for(int i=0; i<m;i++) {
    int a,b;
    cin >> a >> b;
    v[b].push_back(a);
  }

  for(int i=1; i<=n; i++) {
    dfs(i,i);
    fill(vis,vis+n+1,0);
  }

  int big=0;
  for(int i=1; i<=n; i++) {
    if(cnt[i]>big) {big=cnt[i]; b.clear(); b.push_back(i);}
    else if(cnt[i]==big) b.push_back(i);
  }

  sort(b.begin(),b.end());
  for(auto i:b) cout << i << ' ';
}