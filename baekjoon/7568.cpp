#include <bits/stdc++.h>
using namespace std;

struct person
{
  int idx;
  int h;
  int w;
};

int cmp(person a, person b)
{
  if (a.w != b.w)
    return a.w > b.w;
  if (a.h != b.h)
    return a.h > b.h;
  else
    return a.idx > b.idx;
}

int arr[55];

int main()
{
  int n;
  cin >> n;
  person p[55];
  for (int i = 0; i < n; i++)
  {
    cin >> p[i].w >> p[i].h;
    p[i].idx = i;
  }

  int rate;
  for (int i = 0; i < n; i++)
  {
    rate = 1;
    for (int j = 0; j < n; j++)
    {
      if (p[i].h < p[j].h && p[i].w < p[j].w)
        rate++;
    }
    arr[p[i].idx] = rate;
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << ' ';
  }
}