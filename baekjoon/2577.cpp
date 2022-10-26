#include <bits/stdc++.h>

using namespace std;

int res, a, b, c;
int arr[11];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;
  res = a * b * c;

  while (res)
  {
    int c = res % 10;
    res /= 10;
    arr[c]++;
  }

  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << "\n";
  }
}