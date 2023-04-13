#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l, t;
  deque<int> D;

  cin >> n;
  int mi = 1000000001;
  for (int i = 1; i < n + 1; i++)
  {
    cin >> t;

    while (i - l + 1 <= 0)


    D.push_back(t);
    mi = min(t, mi);

    // D의 사이즈는 l보다 커질 수 없음 -> 앞을 뺴면서 오른쪽으로 이동
    if (D.size() > l)
      D.pop_front();
  }
}
