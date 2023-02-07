#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

int cmp(const string &a, const string &b)
{
  if (a.length() != b.length())
    return a.length() < b.length();
  return a < b;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  string temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end(), cmp);
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  for (auto i : arr) cout << i << '\n';
}