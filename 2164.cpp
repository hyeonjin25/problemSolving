#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  queue<int> Q;

  cin >> n;

  for (int i = 1; i < n + 1; i++)
  {
    Q.push(i);
  }

  bool b = 1;
  while (Q.size() != 1)
  {
    if (b)
      Q.pop();
    else
    {
      Q.push(Q.front());
      Q.pop();
    }

    b = !b;
  }

  cout << Q.front();
}