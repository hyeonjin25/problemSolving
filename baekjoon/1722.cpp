#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int arr[25];
  int save[25][500];
  cin >> n;

  for(int i=0; i<n; i++) arr[i] = i+1;

  int q,a; 
  int qa[25];
  cin >> q;
  if(q==1) cin >> a;
  else{
    for(int i=0; i<n; i++){
      cin >> qa[i];
    }
  }

  int j=1;
  do{
    if(q==1&&j==a){
      for(int i=0; i<n; i++){
        cout << arr[i] <<' ';
      }
    }
    if(q==2){
      int flag = 1;
      for(int i=0; i<n; i++){
        if(qa[i]!=arr[i]) flag=0;
      }
      if(flag){
        cout << j;
      }
    }
    j++;
  }
  while(next_permutation(arr,arr+n));

}