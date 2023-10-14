#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<pair<ll,ll>>mat[880];
ll d[880];
ll n;


// d-> 200000000
ll func(ll st, ll ed){
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
  fill(d,d+n+1,1e9);
  q.push({0,st});
  d[st]=0;

  while(q.size()){
    auto [nd,n] = q.top(); q.pop();
    if(nd!=d[n])continue;
    for(auto nxt:mat[n]){
      auto[nxd,nx] = nxt;
      if(d[nx]<=d[n]+nxd) continue;
      d[nx] = d[n]+nxd;
      q.push({d[nx],nx});
    }
  }

  return d[ed];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ll e; cin >> n>>e;
  ll a,b,c;
  for(ll i=0; i<e; i++){
    cin >>a>>b>>c;
    mat[a].push_back({c,b});
    mat[b].push_back({c,a});
  }

  ll v1,v2; cin >>v1>>v2;

  ll res1 = func(1,v1)+func(v1,v2)+func(v2,n);
  ll res2 = func(1,v2)+func(v2,v1)+func(v1,n);

  ll mn = min(res1,res2);
  if(mn >= 1e9) cout << -1;
  else cout << mn;
}