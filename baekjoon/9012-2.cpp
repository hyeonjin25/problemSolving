#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ans = 0;

  stack<char> S;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
      S.push(str[i]);           // 막대 저장
    else if (str[i - 1] == '(') // 레이저인 경우
    {
      // 레이저이므로 막대에서 제거
      S.pop();
      ans += S.size(); // 막대 개수만큼 잘린 조각 나옴
    }
    else // 막대의 끝
    {
      S.pop();
      ans++;
    }
  }
  cout << ans;
}