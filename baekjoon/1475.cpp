#include <bits/stdc++.h>

using namespace std;

int arr[11];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n)
  {
    int c = n % 10;
    if (c == 9)
      c = 6;
    arr[c]++;
    n /= 10;
  }

  int max = 0;
  for (int i = 0; i < 10; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
      if (i == 6)
        max = (max + 1) / 2;
    }
  }

  cout << max;
}