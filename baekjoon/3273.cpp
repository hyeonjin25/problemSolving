#include <bits/stdc++.h>

using namespace std;

int check[1000001];
int arr[100001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x, t;
  int res = 0;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    arr[i] = t;
    check[t]++;
  }

  cin >> x;
  for (int i = 0; i < n; i++)
  {
    if (check[x - arr[i]])
    {
      cout << arr[i] << ' ';
      res++;
    }
  }

  cout << res / 2;
}