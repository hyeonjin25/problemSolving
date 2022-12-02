#include <bits/stdc++.h>

using namespace std;

// 왼쪽, 오른쪽 모두 시도해 보고 더 적은 연산이 필요한 쪽 선택

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t, left = 0, right = 0, res = 0;
  deque<int> D;

  cin >> n >> m;

  for (int i = 1; i < n + 1; i++)
  {
    D.push_back(i);
  }

  while (m--)
  {
    cin >> t;
    deque<int> D2 = D; // 복사

    // 오른쪽으로 이동
    while (D.front() != t)
    {
      D.push_back(D.front());
      D.pop_front();
      right++;
    }

    // 왼쪽으로 이동
    while (D2.front() != t)
    {
      D2.push_front(D2.back());
      D2.pop_back();
      left++;
    }

    D.pop_front();

    res += min(left, right);
    left = 0;
    right = 0;
  }

  cout << res;
}
