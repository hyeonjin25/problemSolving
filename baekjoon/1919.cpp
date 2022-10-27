#include <bits/stdc++.h>

using namespace std;

int check1[30];
int check2[30];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string str1, str2;

  cin >> str1 >> str2;
  for (auto s : str1)
  {
    check1[s - 'a']++;
  }
  for (auto s : str2)
  {
    check2[s - 'a']++;
  }

  int sum = 0;
  for (int i = 0; i < 26; i++)
  {
    sum += abs(check1[i] - check2[i]);
  }
  cout << sum;
}