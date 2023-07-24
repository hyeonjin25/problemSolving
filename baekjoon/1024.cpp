#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  long n,l;
  long arr[105];
  long sl=105;
  cin >> n >> l;

  for(int i=0; i<n; i++){
    for(int j=l; j<=100; j++){ // 몇번 도는지
      if(j>n) break;

      long sum=0;
      for(int h=i; h<i+j; h++){
        sum+=h;
      }
      if(sum==n){
        if(sl<j) continue;
        int g=0;
        for(int h=i; h<i+j; h++){
          arr[g++]=h;
        }
        sl = j;
      }
    }
  }

  if(sl==105) cout << -1;
  else{
    for(int i=0; i<sl; i++){
      cout << arr[i] << ' ';
    }
  }
}