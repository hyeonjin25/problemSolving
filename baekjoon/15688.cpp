#include <bits/stdc++.h>

using namespace std;

int arr[2000010];


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >>n;

  int temp;
  while(n--){
    cin >> temp;
    arr[temp+1000000]++;
  }

  for(int i=0; i<=2000000; i++)
    for(int j=0; j<arr[i]; j++)
      cout << i-1000000  << '\n';
  
}