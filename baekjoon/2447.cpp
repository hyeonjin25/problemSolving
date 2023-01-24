#include <bits/stdc++.h>

using namespace std;

char paper[6600][6600];

void func(int n, int x, int y)
{
  if (n == 1)
  {
    paper[x][y] = '*';
    return;
  }

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      if (i == 1 && j == 1)
        continue;
      func(n / 3, x + n / 3 * i, y + n / 3 * j);
    }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    fill(paper[i], paper[i] + n, ' ');

  func(n, 0, 0);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << paper[i][j];
    cout << '\n';
  }
}