#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[105]; // 무게 / 가치
int d[105][100005];
int n;
const int inf = 1e9;
int func(int i, int j){
  if (j == 0) return 0;
  if (i == 0) return -inf;

  if (d[i][j] != -inf) return d[i][j];
  if(j-arr[i].first>=0)
    d[i][j] = max(func(i-1, j), func(i-1, j-arr[i].first) + arr[i].second);
  else
    d[i][j] = func(i-1, j);
  return d[i][j];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i=0; i<105; i++) {
    for (int j=0; j<100005; j++) {
      d[i][j] = -inf;
    }
  }
  int w; cin >> n>>w;

  for(int i=1; i<=n; i++){
    int a, b;
    cin >> a>>b;
    arr[i]={a,b};
  }

  int m=0;
  for(int i=0; i<=w; i++){
    m = max(m, func(n, i));
  }
  cout << m;
}

