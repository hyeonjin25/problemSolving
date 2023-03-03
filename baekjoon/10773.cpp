#include <bits/stdc++.h>

using namespace std;

int main()
{
  stack<int> S;
  int k, t;

  cin >> k;

  while (k--)
  {
    cin >> t;

    if (t == 0)
      S.pop();
    else
      S.push(t);
  }

  int sum = 0;
  while (S.size())
  {
    sum += S.top();
    S.pop();
  }

  cout << sum;
}