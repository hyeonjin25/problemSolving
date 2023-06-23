#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, a;
  cin >> t;

  while(t--){
    cin >> a;
    if (1 < a&&a < 5)
      cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
  }
}