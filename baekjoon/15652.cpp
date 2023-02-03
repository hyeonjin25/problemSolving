#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

void func(int k)
{
  if (k == m + 1)
  {
    for (int i = 1; i < m + 1; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = arr[k - 1]; i <= n; i++)
  {
    arr[k] = i;
    func(k + 1);
  }
}

int main()
{
  ios::sync_with_stdio();
  cin.tie(0);

  cin >> n >> m;
  arr[0] = 1;
  func(1);
}