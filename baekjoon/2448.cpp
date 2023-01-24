#include <bits/stdc++.h>

using namespace std;

char paper[6600][6600];

void func(int n, int x, int y)
{
  if (n == 3)
  {
    paper[x][y + 2] = '*';
    paper[x + 1][y + 1] = '*';
    paper[x + 1][y + 3] = '*';
    for (int i = 0; i < 5; i++)
      paper[x + 2][y + i] = '*';

    return;
  }

  int bottom = n * 2;

  func(n / 2, x, y + bottom / 4);
  func(n / 2, x + n / 2, y);
  func(n / 2, x + n / 2, y + bottom / 2);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int bottom = n * 2 - 1;

  for (int i = 0; i < n; i++)
    fill(paper[i], paper[i] + bottom, ' ');

  func(n, 0, 0);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < bottom; j++)
      cout << paper[i][j];
    cout << '\n';
  }
}