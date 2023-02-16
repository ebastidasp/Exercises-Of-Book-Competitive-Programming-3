#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin>>n, n) {
    bitset <32> set1(n);
    bitset <32> a(0), b(0);
    int countOfOnBits = 0;
    for(int i = 0; i < 32; i++) {
      if(set1[i] == 1) {
        if (countOfOnBits % 2 == 0) {
          a[i] = 1;
        } else {
          b[i] = 1;
        }
        countOfOnBits++;
      }
    }
    cout<<a.to_ulong()<<" "<<b.to_ulong()<<'\n';
  }
  return 0;
}