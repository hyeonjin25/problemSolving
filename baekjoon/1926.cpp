#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

queue<pair<int, int>> Q;
bool vis[502][502]; // 방문 체크

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int pnum = 0;
int maxSize = 0;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int paper[502][502];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> paper[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      // 방문하지 않은 그림인 경우
      if (!vis[i][j] && paper[i][j] == 1)
      {
        Q.push({i, j}); // 처음 시작점 추가
        vis[i][j] = 1;
        pnum++;
        int psize = 1;

        // 연결된 그림 학인하기
        while (Q.size())
        {
          pair<int, int> cur = Q.front();
          Q.pop();
          for (int k = 0; k < 4; k++)
          {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx > n-1 || ny < 0 || ny > m-1)
              continue;
            if (vis[nx][ny] || paper[nx][ny] != 1)
              continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
            psize++;
          }
        }
        maxSize = max(maxSize, psize);
      }
    }

  cout << pnum << '\n';
  cout << maxSize;
}