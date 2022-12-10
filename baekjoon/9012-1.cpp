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
      if (c == '(')
        S.push(c);
      else if (S.size() && S.top() == '(')
        S.pop();
      else
        goto g;
    }
    if (S.empty())
    {
      cout << "YES\n";
      continue;
    }
  g:
    cout << "NO\n";
  }
}