#include <bits/stdc++.h>

using namespace std;

int mat[2200][2200];

int ans[3]; // 0 => -1, 1 => 0 ,2 => 1

// 전부 같은 숫자인지 체크
bool check(int n, int x, int y)
{
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (mat[x][y] != mat[i][j])
        return false;
  return true;
}

void func(int n, int a, int b)
{
  int first = mat[a][b];

  // 전부 같은 숫자이면 종이 개수 한장 올리고 끝
  if (check(n, a, b))
  {
    ans[first + 1]++;
    return;
  }

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      func(n/3,a+(n/3*i),b+(n/3*j));
    }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];

  func(n,0,0);

  for (int i : ans)
    cout << i << '\n';
}

