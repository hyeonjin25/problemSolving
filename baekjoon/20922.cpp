#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int chk[100005];

int main()
{
  int n,k;
  cin>>n>>k;

  for(int i=0; i<n;i++) cin >> arr[i];

  int st=0;
  int big=0;
  for(int i=0; i<n;i++){
    if(++chk[arr[i]]>k){
      while(chk[arr[i]]>k) chk[arr[st++]]--;
    } 
    big=max(big,i-st+1);
  }
  cout << big;
}