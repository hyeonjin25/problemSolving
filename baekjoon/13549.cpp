#include <bits/stdc++.h>

using namespace std;

int vis[100005];

string paper[1005];

queue<int_fast64_t> Q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  fill(vis, vis + 100005, 1e9);

  Q.push(n);
  vis[n] = 0;

  while (Q.size())
  {
    int cur = Q.front();
    Q.pop();

    for (int nx : {cur + 1, cur - 1, cur * 2})
    {
      int a = vis[cur] + 1;
      if (nx == cur * 2) a--;
      if (nx < 0 || nx > 100000)
        continue;
      if (vis[nx] <= a) // 0초에 지나가면 이미 갔던 경우보다 더 최적의 경우가 될 수 있으므로 지나가게 해줌, 원래의 경우보다 느리거나 같으면 안가도 됨
        continue;

      Q.push(nx);
      vis[nx] = a;
    }
  }
  cout << vis[k] << '\n';
}