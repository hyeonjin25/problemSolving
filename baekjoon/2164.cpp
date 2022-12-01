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
    Q.push(i);

  while (Q.size() != 1)
  {

    Q.pop();

    Q.push(Q.front());
    Q.pop();
  }

  cout << Q.front();
}