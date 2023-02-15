#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  double big=0;
  int bigi=0;
  for(int i=0; i<n;i++) {
    cin >> arr[i];
    if(arr[i]>big){
      big=arr[i];
      bigi=i;
    }
  }

  double res=0;
  for(int i=0; i<n;i++) {
    if(i==bigi) res+=arr[i];
    else res+=(double)arr[i]/2;
  }

  cout << fixed << setprecision(5) << res;
}