#include <bits/stdc++.h>

using namespace std;

int main(){
  string input;
  int caseId = 1;
  while(getline(cin, input) && input != "#"){
    cout<<"Case "<<caseId++<<": ";
    if(input == "HELLO")
      cout<<"ENGLISH\n";
    else if(input == "HOLA")
      cout<<"SPANISH\n";
    else if(input == "CIAO")
      cout<<"ITALIAN\n";
    else if(input == "HALLO")
      cout<<"GERMAN\n";
    else if(input == "BONJOUR")
      cout<<"FRENCH\n";
    else if(input == "ZDRAVSTVUJTE")
      cout<<"RUSSIAN\n";
    else
      cout<<"UNKNOWN\n";
  }
  return 0;
}