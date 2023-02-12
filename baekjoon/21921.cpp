#include <bits/stdc++.h>

using namespace std;

int arr[250005];

int main()
{
  int n,m,sum=0;
  int res=0; 
  int count=0;
  cin >> n >> m;

  for(int i=0; i<n;i++) cin>>arr[i];
  
  int st=0; 
  for(int i=0; i<n;i++){
    sum+=arr[i];
    if(i-st>=m) {
      sum-=arr[st];
      st++;
    }
    if(res==sum) count++;
    else if(sum>res){
      res=sum;
      count=1;
    }
  }

  if(res==0) cout <<"SAD";
  else cout << res << '\n' << count;
}