#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

int main(){
  string input;
  map<string, string> dictionary;
  while(getline(cin, input) && !input.empty()){
    vector<string> inputSplit = split(input, ' ');
    dictionary[inputSplit[1]] = inputSplit[0];
  }
  while(getline(cin, input) && !input.empty()){
    if(dictionary.find(input) != dictionary.end()){
      cout<<dictionary[input]<<'\n';
    } else {
      cout<<"eh\n";
    }
  }
}