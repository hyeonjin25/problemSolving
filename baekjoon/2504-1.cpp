#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;

  stack<pair<char, int>> S; // 괄호, 점수
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(' || str[i] == '[')
      S.push({str[i], 0});
    else if (str[i - 1] == '(' && str[i] == ')')
    {
      S.pop();
      if (S.size())
      {
        if (S.top().first == '(')
          S.top().second += 2 * 2;
        else if (S.top().first == '[')
          S.top().second += 3 * 2;
        else
          ans += 2;
      }else ans+=2;
    }
    else if (str[i - 1] == '[' && str[i] == ']')
    {
      S.pop();
      if (S.size())
      {
        if (S.top().first == '(')
          S.top().second += 2 * 3;
        else if (S.top().first == '[')
          S.top().second += 3 * 3;
        else
          ans += 3;
      }else ans+=3;
    }
    else if ((str[i] == ')' && S.size() && S.top().first == '(') || (str[i] == ']' && S.size() && S.top().first == '['))
    {
      pair<char, int> prev = S.top();
      S.pop();
      if (S.size())
      {
        if (S.top().first == '(')
          S.top().second += 2 * prev.second;
        else
          S.top().second += 3 * prev.second;
      }
      else
        ans += prev.second;
    }
    else
    {
      cout << 0;
      goto g;
    }
  }
  cout << ans;
g:
  return 0;
}
