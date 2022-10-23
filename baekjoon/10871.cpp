#include <bits/stdc++.h>

using namespace std;

int main()
{
  
  set<int> st;
  for (int i=0; i<100000; i++) {
    st.insert(i);
  }
  for (int i=0; i<100000; i++) {
    st.erase(i);
  }
}