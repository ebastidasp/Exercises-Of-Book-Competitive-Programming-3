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
  string allWords = "";
  while(getline(cin, input)){
    transform(input.begin(), input.end(), input.begin(), [](char c) -> char {
      if (!isalpha(c) && c != '-') {
        return ' '; // Replace non-letter characters with a space
      } else {
        return c;   // Keep alphabetic characters as-is
      }
    });
    if(input.length() > 0 && input.at(input.length() - 1) == '-'){
      input.erase(input.length() - 1);
      allWords += input;
    } else {
      allWords += input + " ";
    }
  }
  vector<string> wordsBook = split(allWords, ' ');
  set<string> wordsBookSet;
  for(auto it : wordsBook){
    if(it.length() > 0){
      string aux = it;
      transform(aux.begin(), aux.end(), aux.begin(), [](char c) -> char {
        if (isupper(c)) {
          return tolower(c);
        } else {
          return c;   // Keep alphabetic characters as-is
        }
      });
      wordsBookSet.insert(aux);
    }
  }
  for(set<string>::iterator it = wordsBookSet.begin(); it != wordsBookSet.end(); it++){
    cout<<*it<<'\n';
  }
}