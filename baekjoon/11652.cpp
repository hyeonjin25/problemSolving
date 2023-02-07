#include <bits/stdc++.h>

using namespace std;

long long arr[100005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n;i++){
    cin >> arr[i];
  }

  sort(arr,arr+n); // 정렬을 함으로써 똑같은 수들이 붙어있게 됨

  int cur_num = 0; // 현재 수의 횟수
  int max_num = 0; // 가장 여러번 나온 횟수
  long long max_value = arr[0]; // 가장 여러번 나온 숫자
  
  for(int i=0; i<n;i++){
    if(i!=0 && arr[i-1]!=arr[i]) cur_num=0; // 새로운 수 인 경우 횟수 초기화
    cur_num++;
    if(cur_num>max_num){
      max_num = cur_num;
      max_value = arr[i];
    }
  } 

  cout << max_value;
}