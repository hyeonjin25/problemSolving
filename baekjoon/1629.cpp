#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// b가 계속 절반으로 깎이므로 시간복잡도 O(logb)

ll func(ll a, ll b, ll c)
{
  if (b == 1)
    return a % c;

  ll val = func(a, b / 2, c);
  val = val * val % c;

  if (b % 2 == 1)
    return val * a % c;
  else
    return val % c;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;
  cout << func(a, b, c);
}
