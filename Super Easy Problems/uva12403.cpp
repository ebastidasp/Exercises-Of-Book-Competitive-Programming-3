#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  int sum = 0;
  while(T--){
    string input;
    cin >> input;
    if(input == "donate"){
      int number;
      cin >> number;
      sum += number;
    } else if(input == "report"){
      cout << sum << '\n';
    }
  }
}