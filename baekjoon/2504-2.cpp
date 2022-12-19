#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;

  int mul = 1; // 곱해야 할 값 (몇개의 괄호 안애 갇혀있는가)
  int ans = 0;
  stack<char> S;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
    {
      S.push(str[i]);
      mul *= 2;
    }
    else if (str[i] == '[')
    {
      S.push(str[i]);
      mul *= 3;
    }
    else if (str[i] == ')')
    {
      if (S.empty() || S.top() != '(')
      {
        cout << 0;
        return 0;
      }
      S.pop();
      if (str[i - 1] == '(')
        ans += mul;
      mul /= 2; // 괄호 하나 닫혔으므로 앞에서 곱해줬던 값 취소
    }
    else if (str[i] == ']')
    {
      if (S.empty() || S.top() != '[')
      {
        cout << 0;
        return 0;
      }
      S.pop();
      if (str[i - 1] == '[')
        ans += mul;
      mul /= 3; // 괄호 하나 닫혔으므로 앞에서 곱해줬던 값 취소
    }
  }
  if (S.empty())
    cout << ans;
  else
    cout << 0;
}