#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int main()
{
  int n; cin >> n;
  for(int i=0; i<n;i++) cin >> arr[i];

  sort(arr,arr+n);

  int big=0;
  for(int i=0; i<n;i++){
    int w = (n-i) * arr[i];
    big = max(big,w);
  }

  cout << big;
}