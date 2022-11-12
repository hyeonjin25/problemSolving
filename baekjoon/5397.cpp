#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  string s;

  cin >> T;

  while (T--)
  {
    cin >> s;
    list<char> L;
    auto it = L.begin();

    for (auto i : s)
    {
      if (i == '<')
      {
        if (it != L.begin())
          it--;
      }
      else if (i == '>')
      {
        if (it != L.end())
          it++;
      }
      else if (i == '-')
      {
        if (it != L.begin())
          it = L.erase(--it);
      }
      else
      {
        L.insert(it, i);
      }
    }

    for (auto i : L)
      cout << i;
    cout << '\n';
  }
}