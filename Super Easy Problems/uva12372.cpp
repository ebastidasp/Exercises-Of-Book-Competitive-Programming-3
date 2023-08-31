#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  int caseId = 1;
  while(T--){
    cout<<"Case "<<caseId++<<": ";
    int l, w, h;
    cin >> l >> w >> h;
    if(l > 20 || w > 20 || h > 20){
      cout<<"bad\n";
    } else {
      cout<<"good\n";
    }
  }
  return 0;
}