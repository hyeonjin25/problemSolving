#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int isused[10];
int paper[10];

void func(int k)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (!isused[i])
    {
      arr[k] = paper[i];
      isused[i] = 1;
      func(k + 1);
      isused[i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio();
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> paper[i];

  sort(paper,paper+n);

  func(0);
}