#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  cin.get();
  map<string, string> slogans;
  while(T--){
    string firstLine, secondLine;
    getline(cin, firstLine);
    getline(cin, secondLine);
    slogans[firstLine] = secondLine;
  }
  int D;
  cin>>D;
  cin.get();
  while(D--){
    string input;
    getline(cin, input);
    cout<<slogans[input]<<'\n';
  }
}