#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  stack<int> S;
  string ans; // 정답

  cin >> n;

  int now = 1; // 1~n
  while (n--)
  {
    cin >> t;
    while (t >= now)
    {
      S.push(now++);
      ans += "+\n";
    }
    if (t != S.top())
    {
      cout << "NO";
      return 0;
    }

    S.pop();
    ans += "-\n";
  }

  cout << ans;
}