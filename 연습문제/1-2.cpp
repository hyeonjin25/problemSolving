#include <bits/stdc++.h>

using namespace std;

// o(n^2)
func2(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
      if (arr[i] + arr[j] == 100)
        return 1
  }
  return 0;
}

int main()
{
}