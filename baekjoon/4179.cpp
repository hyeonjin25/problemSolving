#include <bits/stdc++.h>
using namespace std;

int vis[1002][1002];
int vis2[1002][1002];
char paper[1002][1002];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> Q;
  queue<pair<int, int>> Q2;

  fill(&vis[0][0], &vis[1001][1002], 10000);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cin >> paper[i][j];
      if (paper[i][j] == 'F'){
        Q.push({i, j});
        vis[i][j]=0; // 불 있는 곳 => 0
      }
      if (paper[i][j] == 'J')
        Q2.push({i, j});
        vis2[i][j]=0; // 지훈이 0부터 시작
    }

  // 불의 모든 곳의 이동시간 기록
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
      if (vis[nx][ny] != 10000 || paper[nx][ny] != '.')
        continue;
      vis[nx][ny] = vis[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  // 탈출 여부
  while (Q2.size())
  {
    auto cur = Q2.front();
    Q2.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      {
        // 탈출한 경우
        cout << vis2[cur.first][cur.second] + 1;
        return 0;
      }
      if (vis2[nx][ny] > 0 || paper[nx][ny] != '.')
        continue;
      if (vis2[cur.first][cur.second] + 1 >= vis[nx][ny])
        continue;
      vis2[nx][ny] = vis2[cur.first][cur.second] + 1;
      Q2.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";
}
