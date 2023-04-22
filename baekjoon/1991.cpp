#include <bits/stdc++.h>
using namespace std;

char p[30];
char l[100];
char r[100];

void front(int n){
  cout << char(n);
  if(l[n]!='.') front(l[n]);
  if(r[n]!='.') front(r[n]);
}

void mid(int n){
  if(l[n]!='.') mid(l[n]);
  cout << char(n);
  if(r[n]!='.') mid(r[n]);
}

void back(int n){
  if(l[n]!='.') back(l[n]);
  if(r[n]!='.') back(r[n]);
  cout << char(n);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n; 
  cin >> n;

  fill(p,p+30,'.');
  fill(l,l+100,'.');
  fill(r,r+100,'.');

  for(int i=0; i<n; i++){
    cin>>p[i];
    cin>>l[p[i]]>>r[p[i]];
  }

  front('A');
  cout << '\n';
  mid('A');
  cout << '\n';
  back('A');
}