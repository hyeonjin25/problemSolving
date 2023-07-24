#include <bits/stdc++.h>

using namespace std;

struct Num
{
  int index;
  int num;
};

int arr[1000001]; // 답을 저장
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  stack<Num> S;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> t;
    while (!S.empty() && S.top().num < t)
    {
      arr[S.top().index] = t;
      S.pop();
    }
    S.push({i, t});
  }

  while (S.size())
  {
    arr[S.top().index] = -1;
    S.pop();
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << ' ';
  }
}