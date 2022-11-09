#include <bits/stdc++.h>

using namespace std;

main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, h;
  long long ans = 0;

  stack<int> S;
  cin >> n;

  while (n--)
  {
    cin >> h;

    // 한 빌딩의 입장에서 몇개의 빌딩으로 부터 보여질 수 있는지의 수를 합하기
    // 추후에 나오는 다른 빌딩을 볼 수 있는 빌딩들을 스택에 내림차 순으로 넣음
    // 한 빌딩을 만나면 그 빌딩보다 작은 빌딩들은 해당 빌딩을 볼 수 없고,
    // 그 이후에 나오는 빌딩들도 볼 수 없으므로 pop
    // 스택에 남은 빌딩들은 전부 해당 빌딩을 볼 수 있으므로 stack에 남은 빌딩 수만큼 더하기

    while (!S.empty() && S.top() <= h)
    {
      S.pop();
    }
    ans += S.size();
    S.push(h);
  }

  cout << ans;
}