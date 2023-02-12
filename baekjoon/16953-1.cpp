#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long a,b; cin >> a>> b;

  queue<pair<long long,int>>Q;

  Q.push({a,0});

  while(Q.size()){
    auto cur=Q.front(); Q.pop();

    for(long long c:{cur.first*2, cur.first*10+1})
    if(c==b) {
      cout << cur.second+2;
      return 0;
    }
    else if(c<b){
      Q.push({c,cur.second+1});
    } 
  }

  cout << -1;
}