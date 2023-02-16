#include <bits/stdc++.h>

using namespace std;

int main(){
  string input;
  while(getline(cin, input)) {
    list <char> beijuText;
    list <char> :: iterator it = beijuText.begin(); 
    for(int i = 0; i < input.length(); i++) {
      if(input.at(i) == '[') {
        it = beijuText.begin();
      } else if (input.at(i) == ']') {
        it = beijuText.end();
      } else {
        beijuText.insert(it, input.at(i));
      }
    }
    for (list<char>::iterator itfor = beijuText.begin(); itfor != beijuText.end(); itfor++) {
      cout<<*itfor;
    }
    cout<<'\n';
  }
  return 0;
}