#include <bits/stdc++.h>

using namespace std;

int check[13];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, s, y, t;

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> y;
    t = s == 0 ? 0 : 6;
    check[y + t]++;
  }
  int sum = 0;
  for (int i = 1; i < 13; i++)
  {
    sum += (check[i] + (k - 1)) / k;
  }
  cout << sum;
}