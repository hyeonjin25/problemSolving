#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  list<int> L;

  cin >> n >> k;

  for (int i = 1; i < n + 1; i++)
    L.push_back(i);

  auto it = L.begin();
  cout << '<';

  while (L.size())
  {
    for (int i = 0; i < k - 1; i++)
    {
      it++;
      if (it == L.end())
        it = L.begin();
    }
    cout << *it;
    if (L.size() != 1)
      cout << ", ";
    it = L.erase(it);
    if (it == L.end())
      it = L.begin();
  }
  cout << '>';
}