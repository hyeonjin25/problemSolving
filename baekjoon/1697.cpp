#include <bits/stdc++.h>
using namespace std;

int vis[1000000];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,k;
  queue<int> Q;
  
  cin >>n>>k;
  
  if(n==k) {
      cout << 0;
      return 0;
  }
  
  fill(vis,vis+1000000,-1);
  
  Q.push(n);
  vis[n]=0;
  
  while(Q.size()){
    int cur = Q.front(); Q.pop();
    for(auto nx : {cur-1, cur+1, cur*2}){
        if(nx<0||nx>100000) continue;
        if(vis[nx]>0) continue;
        if(nx==k){
            cout << vis[cur]+1;
            return 0;
        }
        Q.push(nx);
        vis[nx]=vis[cur]+1;
    }   
  }
  
}
