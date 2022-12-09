#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;

  stack<pair<char, int>> S; // 괄호, 잘린 횟수
  string str;
  cin >> str;
  for (char c : str)
  {
    if (c == '(')
      S.push({c, 0});
    else
    {
      pair<char, int> prev = S.top();
      S.pop();
      if (prev.second == 0)
      {
        // 레이저인 경우
        if (S.size())
          S.top().second++; // 잘린 횟수 증가
      }
      else
      {
        // 막대의 끝인 경우
        ans += prev.second + 1; // 잘린 조각 세기
        // 해당 막대보다 긴 막대는 무조건 해당 막대가 잘릴 때 같이 잘렸으므로 잘린 횟수 더하기
        if (S.size())
          S.top().second += prev.second;
      }
    }
  }

  cout << ans;
}