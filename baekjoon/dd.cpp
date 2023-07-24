#include <bits/stdc++.h>
using namespace std;

set<int> xarr[200005]; // 각 행의 곰팡이 개체 배열
set<int> yarr[200005]; // 각 열의 곰팡이 개체 배열
int x[200005];         // 곰팡이 개체 수의 x좌표
int y[200005];         // 곰팡이 개체 수의 y좌표

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  int n, m, q;
  long long ans = 0;
  int count = 0;

  for (int t = 0; t < T; t++)
  {
    cin >> n >> m >> q;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i=0; i<n; i++) xarr[i].clear();
    for (int i=0; i<m; i++) yarr[i].clear();
    int big = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> arr[i][j];
        xarr[i].insert(arr[i][j]);
        yarr[j].insert(arr[i][j]);
        x[arr[i][j]] = i;
        y[arr[i][j]] = j;
      }
    }

    int r, c, b;
    int old;
    int safe = 1;
    for (int i = 0; i < q; i++)
    {
      cin >> r >> c >> b;
      r--, c--;
      old = arr[r][c];

      int mx = *(--xarr[r].end());
      int oy = y[mx];
      bool o1 = false;
      if (*(--yarr[oy].end()) == mx)
        count--, o1 = true;

      int mx2 = *(--yarr[c].end());
      int ox = x[mx2];
      bool o2 = false;
      if (*(--xarr[ox].end()) == mx2)
        count--, o2 = true;

      if (o1 && o2 && mx == mx2)
        count++;

      arr[r][c] = b;
      xarr[r].erase(old);
      xarr[c].erase(old);
      xarr[r].insert(b);
      yarr[c].insert(b);
      x[b] = r;
      y[b] = c;

      mx = *(--xarr[r].end());
      oy = y[mx];
      o1 = false;
      if (*(--yarr[oy].end()) == mx)
        count++, o1 = true;

      mx2 = *(--yarr[c].end());
      ox = x[mx2];
      o2 = false;
      if (*(--xarr[ox].end()) == mx2)
        count++, o2 = true;

      if (o1 && o2 && mx == mx2)
        count--;

      ans += count;
    }

    cout << '#' << t + 1<< ' ' << ans;
  }
}