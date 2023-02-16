#include <bits/stdc++.h>

using namespace std;

int main(){
  int input;
  cin.tie(NULL);
  while(cin>>input) {
    bitset <32> bset(input);
    bitset <32> newSet;
    for(int i = 0; i < 32; i++){
      newSet[8*(3-(i/8))+(i%8)] = bset[i];
    }
    int bitsetint = (int)(newSet.to_ulong());
    cout<<input<<" converts to "<<bitsetint<<'\n';
  }
  return 0;
}