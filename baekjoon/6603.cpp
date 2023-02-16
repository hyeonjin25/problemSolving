#include <bits/stdc++.h>
using namespace std;

int k;
int arr[15];
int per[15];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    cin >> k;

    if (k == 0)
      return 0;

    for (int i = 0; i < k; i++)
      cin >> arr[i];

    // 앞자리 6개만 0으로 채우기
    for (int i = 0; i < k; i++)
    {
      if (i >= 6)
        per[i] = 1;
      else
        per[i] = 0;
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