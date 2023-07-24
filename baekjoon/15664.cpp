#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int isused[10];
int paper[10];

void func(int k,int index)
{
  if (k == m)
  {
    for (int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for (int i = index; i < n; i++)
  {
    if (!isused[i-1] && i > 0 && paper[i-1] == paper[i]) continue;
    if (!isused[i])
    {
      arr[k] = paper[i];
      isused[i] = 1;
      func(k + 1,i);
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

  func(0,0);
}