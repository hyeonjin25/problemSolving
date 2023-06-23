#include <bits/stdc++.h>
using namespace std;

int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  int t, n;
  cin >> t;

  while(t--){
    cin >> n;
    int f, b, a;
    int flag=0;
    cin >> b;
    f=b;
    cout << 1;
    for(int i=1; i<n; i++){
      cin >> a;
      if(!flag) {
        if(b<=a)
          cout << 1;
        else {
          if(f>=a)
            cout << 1;
          else {
            cout << 0;
            continue;
          }
          flag=1;
        }
      }
      else{
        if(b<=a&&a<=f){
          cout << 1;
        }
        else{
          cout << 0;
          continue;
        }
      }
      b=a;
    }
    cout << '\n';
  }
}