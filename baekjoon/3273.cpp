#include <bits/stdc++.h>

using namespace std;

int check[2000001];
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
    check[t] = 1;
  }

  cin >> x;
  for (int i = 0; i < n; i++)
  {
    if (x - arr[i] >= 0 && check[x - arr[i]])
    {
      res++;
    }
  }

  cout << res / 2;
}