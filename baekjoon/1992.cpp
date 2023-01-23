#include <bits/stdc++.h>

using namespace std;

string paper[70];
int res[2];

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

  char first = paper[x][y];
  if (check(n, x, y))
  {
    cout << first;
    return;
  }

  cout << '(';

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      func(n / 2, x + n / 2 * i, y + n / 2 * j);

  cout << ')';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
      cin >> paper[i];

  func(n, 0, 0);
}