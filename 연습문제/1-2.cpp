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

// o(n)
func3(int arr[], int n)
{
  int arr1[101] = {};
  for (auto i : arr)
  {
    if (arr1[100 - arr[i]])
      return 1;
    arr1[arr[i]] = 1;
  }
  return 0;
}

int main()
{
}