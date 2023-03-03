#include <bits/stdc++.h>

using namespace std;

int vis[105][105][105];

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Point
{
  int z, x, y;
};

int paper[105][105][105];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, h;

  cin >> m >> n >> h;

  int temp;
  queue<Point> Q;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++)
      {
        cin >> temp;
        if (temp == 1)
          Q.push({i, j, k});
        if (temp == 0)
          vis[i][j][k] = -1;
      }

  while (Q.size())
  {
    auto cur = Q.front();
    Q.pop();
    for (int a = 0; a < 6; a++)
    {
      int nx = cur.x + dx[a];
      int ny = cur.y + dy[a];
      int nz = cur.z + dz[a];

      if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
        continue;
      if (vis[nz][nx][ny] >= 0)
        continue;

      Q.push({nz, nx, ny});
      vis[nz][nx][ny] = vis[cur.z][cur.x][cur.y] + 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++)
      {
        if (vis[i][j][k] == -1)
        {
          cout << -1;
          return 0;
        }
        ans = max(ans, vis[i][j][k]);
      }

  cout << ans;
}