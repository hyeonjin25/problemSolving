#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c)
{
  int half = 1 << (n - 1);

  if (n == 0)
    return 0;

  // 첫번쨰 사각형
  if (half > r && half > c)
    return func(n - 1, r, c);

  // 두번쨰 사각형
  if (half > r && half <= c)
    return half * half + func(n - 1, r, c - half);

  // 세번쨰 사각형
  if (half <= r && half > c)
    return 2 * half * half + func(n - 1, r - half, c);

  // 네번쨰 사각형
  if (half <= r && half <= c)
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, c;
  cin >> n >> r >> c;

  cout << func(n, r, c);
}