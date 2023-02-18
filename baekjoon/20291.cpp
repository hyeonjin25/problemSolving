#include <bits/stdc++.h>

using namespace std;

string arr[50005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i=0; i<n;i++) cin >>arr[i];

  for(int i=0; i<n;i++){
    int idx = arr[i].find('.');
    arr[i]=arr[i].substr(idx+1);
  }

  sort(arr,arr+n);

  string cur=arr[0];
  int count=0;
  for(int i=0; i<n+1;i++){
    if(cur!=arr[i]) {
      cout << cur << ' ' << count << '\n';
      cur=arr[i];
      count = 1;
    }
    else count++;
  }
}