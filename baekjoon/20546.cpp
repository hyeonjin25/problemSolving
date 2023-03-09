#include <bits/stdc++.h>

using namespace std;

int arr[15];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int jnum = 0,snum = 0; // 주식 개수

  int down = 0, up = 0;
  int jcsh, scsh;
  cin >> jcsh;
  scsh=jcsh; // 현금

  for(int i=0; i<14;i++) cin >> arr[i];

  int price;
  for(int i=0; i<14;i++){
    price = arr[i]; 

    // 준현
    if(jcsh>0){
      jnum += jcsh/price;
      jcsh = jcsh%price;
    }

    // 성욱
    if(up>=2&&snum>0) scsh += snum*price, snum = 0;
    if(down>=2&&scsh>0) snum += scsh/price, scsh = scsh%price;

    if(price!=0 && price > arr[i-1]) up++, down = 0;
    if(price!=0 && price < arr[i-1]) down++, up=0;
  }

  if(jnum>0)jcsh += jnum*price;
  if(snum>0)scsh += snum*price;
  
  if(jcsh>scsh) cout << "BNP";
  else if(jcsh<scsh) cout << "TIMING";
  else cout << "SAMESAME";
}