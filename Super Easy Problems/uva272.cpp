#include <bits/stdc++.h>

using namespace std;

int main(){
  string input;
  string output = "";
  bool begins = true;
  while(getline(cin, input)){
    for(int i = 0; i < input.length(); i++){
      if(input.at(i) == '"' && begins){
        begins = false;
        input.at(i) = '`';
        input.insert(i, "`");
      } else if(input.at(i) == '"' && !begins){
        begins = true;
        input.at(i) = char(39);
        string str = "";
        str += char(39);
        input.insert(i, str);
      }
    }
    output += input + '\n';
  }
  cout<<output;
}