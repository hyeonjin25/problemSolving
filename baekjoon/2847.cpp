#include<bits/stdc++.h>
using namespace std;

int arr[105];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int ans = 0;
  for(int i=n-1; i>0; i--){
    if(arr[i-1]>=arr[i]){
      ans+=arr[i-1]-(arr[i]-1);
      arr[i-1] = arr[i] - 1;
    }
  }

  cout << ans;
}