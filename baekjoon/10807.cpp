#include <bits/stdc++.h>

using namespace std;

int check[205];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, v, t;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    check[t + 100]++;
  }
  cin >> v;
  cout << check[v + 100];
}