#include <bits/stdc++.h>

using namespace std;

pair<int,int> arr[100005];

int main()
{
  int n;
  cin>>n;

  int a,b;
  for(int i=0;i<n;i++) cin >> arr[i].second >> arr[i].first; //{끝,시작}

  sort(arr,arr+n);

  pair<int,int> cur=arr[0];
  int res=1;
  for(int i=1; i<n;i++){
    if(arr[i].second>=cur.first){
      cur=arr[i]; res++;
    }
  }

  cout << res;
}