#include <bits/stdc++.h>

using namespace std;

int main(){
  string input;
  int caseId = 1;
  while(cin >> input && input != "*"){
    cout << "Case " << caseId++ <<": ";
    if(input == "Hajj")
      cout << "Hajj-e-Akbar\n";
    else
      cout << "Hajj-e-Asghar\n";
  }
}