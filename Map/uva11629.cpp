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
  int p, g;
  cin>>p>>g;
  cin.get();
  map<string, int> percentageParty;
  while(p--){
    string input;
    getline(cin, input);
    vector<string> inputVector = split(input, ' ');
    vector<string> inputNumber = split(inputVector[inputVector.size()-1], '.');
    percentageParty[inputVector[0]] = stoi(inputNumber[0])*10+stoi(inputNumber[1]);
  }
  int guessId = 1;
  while(g--){
    string input;
    getline(cin, input);
    vector<string> inputVector = split(input, ' ');
    int index = 0;
    string comparison;
    int sum = 0; 
    for(auto & it : inputVector){
      index++;
      if(percentageParty.find(it) != percentageParty.end()){
        sum += percentageParty[it];
      }
      if(it == "<" || it == ">" || it == ">=" || it == "<=" || it == "="){
        comparison = it;
        break;
      }
    }
    string lastString= inputVector[inputVector.size()-1];
    int lastNumber = stoi(lastString)*10;
    cout<<"Guess #"<<guessId++<<" was ";
    if(comparison == "<"){
      if(sum < lastNumber){
        cout<<"correct.\n";
      } else {
        cout<<"incorrect.\n";
      }
    } else if(comparison == ">"){
      if(sum > lastNumber){
        cout<<"correct.\n";
      } else {
        cout<<"incorrect.\n";
      }
    } else if(comparison == "<="){
      if(sum <= lastNumber){
        cout<<"correct.\n";
      } else {
        cout<<"incorrect.\n";
      }
    } else if(comparison == ">="){
      if(sum >= lastNumber){
        cout<<"correct.\n";
      } else {
        cout<<"incorrect.\n";
      }
    } else if(comparison == "="){
      if(sum == lastNumber){
        cout<<"correct.\n";
      } else {
        cout<<"incorrect.\n";
      }
    }
  }
}