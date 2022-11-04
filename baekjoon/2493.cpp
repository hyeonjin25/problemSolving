#include <bits/stdc++.h>

using namespace std;

struct Tower
{
  int index;
  int val;
};

stack<Tower> S;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  cin >> n;

  // 왼쪽에 자신보다 큰 탑이 존재하지 않는 경우 무조거 0이 출력되도록 하기 위함
  S.push({0, 100000001});

  for (int i = 1; i < n + 1; i++)
  {
    cin >> t;

    // top이 오른 쪽 보다 작으면 계속 pop (어차피 더 오른 쪽의 수는 지금 오른 쪽이 막으므로 필요x)
    while (S.top().val < t)
      S.pop();

    cout << S.top().index << ' ';

    S.push({i, t});
  }
}