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
  int m, n;
  cin>>m>>n;
  cin.get();
  map<string, int> dictionaryValue;
  string input;
  while(m--){
    getline(cin, input);
    vector<string> wordValue = split(input, ' ');
    dictionaryValue[wordValue[0]] = stoi(wordValue[1]);
  }
  while(n > 0){
    n--;
    string jobDescription = "";
    while(getline(cin, input) && input != "."){
      jobDescription += input;
      jobDescription += " ";
    }
    vector<string> wordsInJobDescription = split(jobDescription, ' ');
    long long salary = 0;
    for(auto& it : wordsInJobDescription){
      salary += dictionaryValue[it];
    }
    cout<<salary<<'\n';
  }
  return 0;
}