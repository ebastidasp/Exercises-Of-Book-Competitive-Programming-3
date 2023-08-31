#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    int input;
    cin>>input;
    cout<<(abs((input * 63 + 7492) * 5 - 496) / 10) % 10<<'\n';
  }
}