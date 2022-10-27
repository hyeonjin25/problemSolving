#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string str1, str2;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int check[30]{};

    cin >> str1 >> str2;

    for (auto s : str1)
    {
      check[s - 'a']++;
    }

    for (auto s : str2)
    {
      check[s - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
      if (check[i] != 0)
      {
        cout << "Impossible" << '\n';
        goto g;
      }
    }
    cout << "Possible" << '\n';
  g:
    continue;
  }
}