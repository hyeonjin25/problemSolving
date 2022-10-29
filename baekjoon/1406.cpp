#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  char c, p;
  string s;
  int m;

  cin >> s;
  // for (auto c : s)
  // {
  //   L.push_back(s[i]);
  // }

  list<char> L(s.begin(), s.end());
  auto it = L.end();

  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> c;

    if (c == 'L')
    {
      if (it != L.begin())
        it--;
    }
    else if (c == 'D')
    {
      if (it != L.end())
        it++;
    }
    else if (c == 'B')
    {
      if (it != L.begin())
        it = L.erase(--it);
    }
    else if (c == 'P')
    {
      cin >> p;
      L.insert(it, p);
    }
  }

  for (auto i : L)
  {
    cout << i;
  }
}