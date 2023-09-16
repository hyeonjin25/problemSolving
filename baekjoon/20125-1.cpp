#include <bits/stdc++.h>

using namespace std;

char v[1010][1010];
int dx[] {-1, 0, 0, 1};
int dy[] {0, -1, 1, 0};
// 0, 1, 2, 3 : 위, 왼, 오, 아

struct S {
  int x, y, cnt;
};
// v[x][y] 는 무조건 *
S go(int x, int y, int d) {
  assert(v[x][y] == '*');
  int cnt = 1;
  while (v[x+dx[d]][y+dy[d]] == '*') {
    x += dx[d];
    y += dy[d];
    cnt++;
  }
  return {x, y, cnt};
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> v[i][j];
    }
  }
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (v[i][j] == '*') {
        int x = i + 1;
        int y = j;

        cout << x << ' ' << y << '\n';
        S a = go(x, y - 1, 1);
        cout << a.cnt << ' ';
        S b = go(x, y + 1, 2);
        cout << b.cnt << ' ';
        S c = go(x + 1, y, 3);
        cout << c.cnt << ' ';
        S d = go(c.x + 1, c.y - 1, 3);
        cout << d.cnt << ' ';
        S e = go(c.x + 1, c.y + 1, 3);
        cout << e.cnt << ' ';
        cout << '\n';

        return 0;
      }
    }
  }
}