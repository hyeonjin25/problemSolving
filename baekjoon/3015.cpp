#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long t, res = 0;
  stack<pair<int, int>> S; // 키, 같은키의 수

  cin >> n;

  // 543321 3

  while (n--)
  {
    cin >> t;

    int num = 1;
    while (S.size() && S.top().first <= t)
    {
      res += S.top().second;
      if (S.size() && S.top().first == t)
        num += S.top().second;
      S.pop();
    }

    if (S.size())
      res++;
    S.push({t, num});
  }

  cout << res;
}