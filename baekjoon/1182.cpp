#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[22];
int res;

void func(int k, int sum){
  if(k==n){
    if(sum==s) res++;
    return;
  }

  func(k + 1, sum);
  func(k + 1, sum+arr[k]);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n>> s;
  for(int i=0; i<n;i++){
    cin >> arr[i];
  }

  func(0,0);

  if(s==0)res--;
  cout << res;
}