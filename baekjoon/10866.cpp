#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

    int n, t;
  deque<int> D;
  string str;
  cin >> n;

  while (n--)
  {
    cin >> str;
    if (str == "push_front")
    {
      cin >> t;
      D.push_front(t);
    }
    else if (str == "push_back")
    {
      cin >> t;
      D.push_back(t);
    }
    else if (str == "pop_front")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
      {
        cout << D.front() << "\n";
        D.pop_front();
      }
    }
    else if (str == "pop_back")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
      {
        cout << D.back() << "\n";
        D.pop_back();
      }
    }
    else if (str == "size")
      cout << D.size() << "\n";
    else if (str == "empty")
      cout << D.empty() << "\n";
    else if (str == "front")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
        cout << D.front() << '\n';
    }
    else if (str == "back")
    {
      if (D.empty())
        cout << -1 << '\n';
      else
        cout << D.back() << '\n';
    }
  }
}
