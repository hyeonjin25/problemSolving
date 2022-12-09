#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, ans = 0;
  cin >> n;

  while (n--)
  {
    stack<char> S;
    string str;
    cin >> str;
    for (char c : str)
    {
      if (S.size() && S.top() == c)
        S.pop();
      else
        S.push(c);
    }
    if (S.empty())
      ans++;
  g:
    continue;
  }

  cout << ans;
}