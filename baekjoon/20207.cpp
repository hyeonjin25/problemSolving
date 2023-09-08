#include<iostream>
using namespace std;

int arr[400];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n, s,e;
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> s >> e;
    for(int j=s; j<=e; j++){
      arr[j]++;
    }
  }

  int r=0, c=0, ans=0;
  for(int i=1; i<=365; i++){
    if(arr[i]==0){
      ans+=r*c;
      r=0; c=0;
      continue;
    }
    r = max(r,arr[i]);
    c++;
  }

  ans+=r*c;

  cout << ans;
}