#include <bits/stdc++.h>

using namespace std;

string arr[55];

int cmp(const string& a, const string& b){
  if(a.length()!=b.length()) return a.length()<b.length();
  int sum_a=0; int sum_b=0;
  for(int i=0;i<a.length();i++){
    if(a[i]-'0'<=9) sum_a+=a[i]-'0';
    if(b[i]-'0'<=9) sum_b+=b[i]-'0';
  }
  if(sum_a!=sum_b) return sum_a<sum_b;
  return a<b; // 사전 순
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n;i++){
    cin >> arr[i];
  }

  sort(arr,arr+n,cmp);

  for(int i=0; i<n;i++){
    cout << arr[i] << '\n';
  }
}