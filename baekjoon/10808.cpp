#include <bits/stdc++.h>

using namespace std;

int arr[105];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string word;
  cin >> word;

  for (char c : word)
    arr[c - 'a']++;

  for (int i = 0; i < 26; i++)
    cout << arr[i] << ' ';
}