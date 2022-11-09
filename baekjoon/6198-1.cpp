#include <bits/stdc++.h>

using namespace std;

struct building
{
  int index;
  int height;
};

main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,h;
  long long ans = 0;

  stack<building> S;
  cin >> n;

  for (int i = 1; i < n + 1; i++)
  {
    cin >> h;

    // 더 큰 빌딩을 찾기 위해서 스택에 내림차 순으로 넣음
    // 한 빌딩을 만나면 그 빌딩보다 작은 빌딩들은 해당 빌딩보다 작거나 같으므로 pop

    while (!S.empty() && S.top().height <= h)
    {
      ans += i - S.top().index - 1;
      S.pop();
    }
    S.push({i, h});
  }

  while (S.size())
  {
    ans += n - S.top().index;
    S.pop();
  }

  cout << ans;
}