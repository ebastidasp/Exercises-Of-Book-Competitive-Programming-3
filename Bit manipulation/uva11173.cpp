#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCases;
  cin>>testCases;
  while(testCases--) {
    int n, k;
    cin>>n>>k;
    cout<< (k^(k>>1)) <<'\n';    
  }
  return 0;
}