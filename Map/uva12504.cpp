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

bool comparePairs(const pair<string, string>& a, const pair<string, string>& b){
  return a.first < b.first;
}

int main(){
  int T;
  cin>>T;
  cin.get();
  while(T--){
    map<string, string>  d1, d2;
    string input;
    getline(cin, input);
    bool wordOrValue = false;
    string word = "", value = ""; 
    for(int i = 1; i < input.length(); i++){
      if(input.at(i) == ':'){
        wordOrValue = true;
      } else if((input.at(i) == ',' || input.at(i) == '}') && word != ""){
        wordOrValue = false;
        d1[word] = value;
        word = value = "";
      } else {      
        if(!wordOrValue && input.at(i) != '}'){
          word += input.at(i);
        } else {
          value += input.at(i);
        }
      }
    }
    getline(cin, input);
    for(int i = 1; i < input.length(); i++){
      if(input.at(i) == ':'){
        wordOrValue = true;
      } else if((input.at(i) == ',' || input.at(i) == '}') && word != ""){
        wordOrValue = false;
        d2[word] = value;
        word = value = "";
      } else {      
        if(!wordOrValue && input.at(i) != '}'){
          word += input.at(i);
        } else {
          value += input.at(i);
        }
      }
    }
    vector<pair<string, string>> d1Vector(d1.begin(), d1.end()), d2Vector(d2.begin(), d2.end());
    sort(d1Vector.begin(), d1Vector.end(), comparePairs);
    sort(d2Vector.begin(), d2Vector.end(), comparePairs);
    vector<string> added, removed, changed;
    for(auto& it : d1Vector){
      if(d2.find(it.first) != d2.end()){
        if(d2[it.first] != it.second){
          changed.push_back(it.first);
        }
      } else {
        removed.push_back(it.first);
      }
    }
    for(auto& it : d2Vector){
      if(d1.find(it.first) == d1.end()){
        added.push_back(it.first);
      }
    }
    if(!added.size() && !removed.size() && !changed.size()){
      cout<<"No changes\n";
    } else{
      if(added.size()){
        cout<<"+";
        int count = 0;
        for(auto& word : added){
          cout<<word;
          if(count < added.size() - 1){
            cout<<",";
          }
          count++;
        }
        cout<<'\n';
      }
      if(removed.size()){
        cout<<"-";
        int count = 0;
        for(auto& word : removed){
          cout<<word;
          if(count < removed.size() - 1){
            cout<<",";
          }
          count++;
        }
        cout<<'\n';
      }
      if(changed.size()){
        cout<<"*";
        int count = 0;
        for(auto& word : changed){
          cout<<word;
          if(count < changed.size() - 1){
            cout<<",";
          }
          count++;
        }
        cout<<'\n';
      }
    }
    added.clear();
    removed.clear();
    changed.clear();
    cout<<'\n';
  }
}