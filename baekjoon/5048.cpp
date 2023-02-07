#include<bits/stdc++.h>

using namespace std;

long long arr[1000005];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  string temp;
  int c; 
  for(int i=0;i<n;i++){
    cin >> temp;

    reverse(temp.begin(), temp.end());

    arr[i]=stoll(temp);
  }

  sort(arr,arr+n);

  for(int i=0; i<n;i++){
    cout << arr[i] << '\n';
  }
}