#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    stack<char> S;
    string str;
    getline(cin, str);

    if (str == ".")
      break;

    for (auto c : str)
    {
      if (c == '(' || c == '[')
        S.push(c);
      else if (c == ')' || c == ']')
      {
        if (S.size())
        {
          if (c == ')' && S.top() == '(')
          {
            S.pop();
            continue;
          }
          else if (c == ']' && S.top() == '[')
          {
            S.pop();
            continue;
          }
        }

        cout << "no" << '\n';
        goto g;
      }
    }
    if (S.size())
      cout << "no" << '\n';
    else
      cout << "yes" << '\n';

  g:
    continue;
  }
}
