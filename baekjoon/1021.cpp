#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t, res = 0;
  deque<int> D;

  cin >> n >> m;

  for (int i = 1; i < n + 1; i++)
  {
    D.push_back(i);
  }

  // 2489

  while (m--)
  {
    cin >> t;

    int idx = find(D.begin(), D.end(), t) - D.begin(); // t의 idx 찾기

    while (D.front() != t)
    {
      // 찾는 원소가 front쪽에 더 가까이 있는 경우
      if ((int)D.size() - idx > idx)
      {
        D.push_back(D.front());
        D.pop_front();
      }
      else
      {
        D.push_front(D.back());
        D.pop_back();
      }
      res++;
    }
    D.pop_front();
  }

  cout << res;
}
