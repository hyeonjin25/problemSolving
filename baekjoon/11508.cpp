#include <bits/stdc++.h>

using namespace std;

int arr[100005];

bool cmp(int a, int b){
  return a>b;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  for(int i=1; i<=n; i++) cin >> arr[i];

  sort(arr+1, arr+n+1, cmp);

  long long sum=0;
  for(int i=1; i<=n; i++){
    if(i%3!=0) sum+= arr[i];
  }

  cout << sum;
}