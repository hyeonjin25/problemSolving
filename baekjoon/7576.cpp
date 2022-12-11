#include <bits/stdc++.h>
using namespace std;

int vis[1002][1002];
int paper[1002][1002];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> m >> n;

  queue<pair<int, int>> Q;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cin >> paper[i][j];

      if (paper[i][j] == 1)
      {
        Q.push({i, j});
        vis[i][j] = 1;
      }
    }

  while (Q.size())
  {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (vis[nx][ny] || paper[nx][ny] != 0)
        continue;
      vis[nx][ny] = vis[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] == 0 && paper[i][j] == 0)
      {
        cout << -1;
        return 0;
      }
      ans = max(ans, vis[i][j]);
    }

  cout << --ans;
}