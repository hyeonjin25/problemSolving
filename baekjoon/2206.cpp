#include <bits/stdc++.h>

using namespace std;

int vis[1005][1005][2]; // 0층은 벽 뿌술 수 있음, 1층은 벽 뿌술 수 없음

string paper[1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<tuple<int, int, int>> Q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> paper[i];

  Q.push({0, 0, 0});
  vis[0][0][0] = 1;

  while (Q.size())
  {
    int a, b, c;
    tie(a, b, c) = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = a + dx[i];
      int ny = b + dy[i];
      int nc = c;

      if (nx < 0 || ny < 0 || nx > n - 1 || ny > m - 1)
        continue;

      if (paper[nx][ny] == '1') // 벽
      {
        if (nc == 1)
          continue;
        else
          nc = 1; // 벽 만났는데 0층이면 1층으로
      }
      if (vis[nx][ny][nc] > 0)
        continue;

      Q.push({nx, ny, nc});
      vis[nx][ny][nc] = vis[a][b][c] + 1;
    }
  }

  if (vis[n - 1][m - 1][0] == 0 && vis[n - 1][m - 1][1] == 0)
    cout << -1;
  else
  {
    if (vis[n - 1][m - 1][0] == 0)
      cout << vis[n - 1][m - 1][1];
    else if (vis[n - 1][m - 1][1] == 0)
      cout << vis[n - 1][m - 1][0];
    else
      cout << min(vis[n - 1][m - 1][0], vis[n - 1][m - 1][1]);
  }
}