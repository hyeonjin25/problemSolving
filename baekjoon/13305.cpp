#include<iostream>
using namespace std;

long long line[101010];
long long price[101010];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  
  for(int i=0; i<n-1; i++){
    cin >> line[i];
  }
  for(int i=0; i<n; i++){
    cin >> price[i];
  }

  long long res = 0;
  long long pr_min = price[0];

  for(int i=0; i<n; i++){
    pr_min = min(pr_min,price[i]);
    res += pr_min*line[i];
  }

  cout << res;
}