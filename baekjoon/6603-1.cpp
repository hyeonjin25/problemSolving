#include <bits/stdc++.h>
using namespace std;

int arr[10];
int per[50];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    int k;
    cin >> k;

    if (k == 0)
      return 0;

    for (int i = 0; i < k; i++)
      cin >> arr[i];

    for (int i = 0; i < k; i++)
    {
      if (i < 6)
        per[i] = 0;
      else
        per[i] = 1;
    }

    do
    {
      for (int i = 0; i < k; i++)
      {
        if (per[i] == 0)
          cout << arr[i] << ' ';
      }
      cout << '\n';
    } while (next_permutation(per, per + k));
        cout << '\n';
  }
}