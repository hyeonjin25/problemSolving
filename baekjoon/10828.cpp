#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  string str;
  stack<int> S;

  cin >> n;

  while (n--)
  {
    cin >> str;
    if (str == "push")
    {
      cin >> x;
      S.push(x);
    }
    else if (str == "pop")
    {
      if (S.empty())
        cout << -1 << '\n';
      else
      {
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if (str == "top")
    {
      if (S.empty())
        cout << -1 << '\n';
      else
        cout << S.top() << '\n';
    }
    else if (str == "size")
      cout << S.size() << '\n';
    else if (str == "empty")
    {
      if (S.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
  }
}