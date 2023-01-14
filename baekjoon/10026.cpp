#include <bits/stdc++.h>

using namespace std;

int vis1[105][105];
int vis2[105][105];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string paper[n];
  string str;

  queue<pair<int, int>> Q;
  queue<pair<int, int>> Q2;
  for (int i = 0; i < n; i++)
  {
    cin >> paper[i];
  }

  int ans1 = 0;
  int ans2 = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // 정상
      if (vis1[i][j] == 0)
      {
        Q.push({i, j});
        vis1[i][j] = 1;
        char color = paper[i][j]; // 시작 색깔
        ans1++;

        while (Q.size())
        {
          auto cur = Q.front();
          Q.pop();

          for (int k = 0; k < 4; k++)
          {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (vis1[nx][ny] == 1 || paper[nx][ny] != color)
              continue;

            Q.push({nx, ny});
            vis1[nx][ny] = 1;
          }
        }
      }
    }
  }

  // 적록생맹
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (vis2[i][j] == 0)
      {
        Q2.push({i, j});
        vis2[i][j] = 1;

        // 초록 -> 빨강
        if (paper[i][j] == 'G')
          paper[i][j] = 'R';

        char color = paper[i][j]; // 시작 색깔
        ans2++;

        while (Q2.size())
        {
          auto cur = Q2.front();
          Q2.pop();

          for (int k = 0; k < 4; k++)
          {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
              
            // 초록 -> 빨강
            if (paper[nx][ny] == 'G')
              paper[nx][ny] = 'R';
            if (vis2[nx][ny] == 1 || paper[nx][ny] != color)
              continue;

            Q2.push({nx, ny});
            vis2[nx][ny] = 1;
          }
        }
      }
    }
  }

  cout << ans1 << ' ' << ans2;
}