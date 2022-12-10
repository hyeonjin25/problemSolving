#include <bits/stdc++.h>
using namespace std;

int vis[102][102];
string paper[102];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++)
    cin >> paper[i];

  for (int i = 0; i < n; i++)
    fill(vis[i], vis[i] + m, -1);

  Q.push({0, 0});
  vis[0][0] = 1;

  while (Q.size())
  {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int k = 0; k < 4; k++)
    {
      int nx = cur.first + dx[k];
      int ny = cur.second + dy[k];
      if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)
        continue;
      if (vis[nx][ny] != -1 || paper[nx][ny] == '0')
        continue;
      vis[nx][ny] = vis[cur.first][cur.second] + 1;
      if (nx == n - 1 && ny == m - 1)
      {
        cout << vis[nx][ny];
        return 0;
      }
      Q.push({nx, ny});
    }
  }
}