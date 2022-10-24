#include <bits/stdc++.h>

using namespace std;

// o(lgN) ? 19:00
int func4(int n)
{
  int val = 1;
  while (val * 2 <= n)
    val *= 2;
  return val;
}

int main()
{
}