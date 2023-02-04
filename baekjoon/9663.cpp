#include <bits/stdc++.h>

using namespace std;

int n;
int mat[16][16];
int isused1[16]; // y
int isused2[35]; // x + y
int isused3[35]; // x - y + n-1

int res;

void func(int k){
  if(k>=n) res++;

  for(int i=0;i<n;i++){
    if(!isused1[i]&&!isused2[k+i]&&!isused3[k-i+n-1])
    {
      isused1[i]=1;
      isused2[k+i]=1;
      isused3[k-i+n-1]=1;
      func(k+1);
      isused1[i]=0;
      isused2[k+i]=0;
      isused3[k-i+n-1]=0;
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  func(0);

  cout << res;
}