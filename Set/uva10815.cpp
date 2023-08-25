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
  string fullBook = "";
  while(getline(cin, input)){
    transform(input.begin(), input.end(), input.begin(), [](char c) {
      if (!isalpha(c)) {
        return ' '; // Replace non-letter characters with a space
      } else {
        return c;   // Keep alphabetic characters as-is
      }
    });
    fullBook += input + " ";
  }
  vector<string> wordsBook = split(fullBook, ' ');
  set<string> wordsBookSet;
  for(auto it : wordsBook){
    if(it.length() > 0 && it != "\n"){
      string aux = it;
      for(int i = 0; i < aux.length(); i++){
        if(aux.at(i) >= 'A' && aux.at(i) <= 'Z'){
          aux.at(i) = tolower(aux.at(i)); 
        }
      }
      wordsBookSet.insert(aux);
    }
  }
  for(set<string>::iterator it = wordsBookSet.begin(); it != wordsBookSet.end(); it++){
    cout<<*it<<'\n';
  }
}