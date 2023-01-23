#include <bits/stdc++.h>

using namespace std;

int paper[130][130];
int res[2]; // 0 : 하얀, 1: 파란

bool check(int n, int x, int y)
{
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (paper[x][y] != paper[i][j])
        return false;

  return true;
}

void func(int n, int x, int y)
{
  int first = paper[x][y];
  if (check(n, x, y))
  {
    res[first]++;
    return;
  }

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      func(n / 2, x + n / 2 * i, y + n / 2 * j);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> paper[i][j];

  func(n, 0, 0);

  for (int i : res)
    cout << i << '\n';
}