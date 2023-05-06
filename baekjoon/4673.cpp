#include<bits/stdc++.h>
using namespace std;

int arr[20000];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n;
  for(int i=1; i<10000; i++){
    int t=i;
    n=t;
    while(t>=1){
      n+=t%10;
      t/=10;
    }
    arr[n]=1;
  }

  for(int i=1; i<=10000; i++){
    if(arr[i]==0) cout << i <<'\n';
  }
}