#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a < x)
      cout << a << ' ';
  }
}