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

bool areAllLettersUppercase(const string &str) {
    for (char c : str) {
        if (c != ' ' && !isupper(c)) {
            return false;
        }
    }
    return true;
}

bool compareProjectNumberOfParticipants(const pair<string, int>& a, const pair<string, int>& b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  return a.second > b.second;
}

int main(){
  string input;
  bool anotherTestCase = true;
  while(anotherTestCase){
    map<string, vector<string>> projectParticipants;
    map<string, int> projectNumberParticipants;
    map<string, bool> isValidParticipant;
    set<string> participants;
    string projectName;
    while(getline(cin, input) && input != "1" && input != "0"){
      if(areAllLettersUppercase(input)){
        projectName =  input;
        projectNumberParticipants[projectName] = 0;
      } else {
        if(participants.find(input) == participants.end()) {
          projectParticipants[projectName].push_back(input);
          isValidParticipant[input] = true;
          participants.insert(input);
        } else if (count(projectParticipants[projectName].begin(), projectParticipants[projectName].end(), input) == 0) {
          isValidParticipant[input] = false;
        }
      }
    }
    for(auto& it : projectParticipants){
      for(auto& itVector : projectParticipants[it.first]){
        if(isValidParticipant[itVector])
          projectNumberParticipants[it.first]++;
      }
    }
    vector<pair<string, int>> vectorProjectNumberOfParticipants(projectNumberParticipants.begin(), projectNumberParticipants.end());
    sort(vectorProjectNumberOfParticipants.begin(), vectorProjectNumberOfParticipants.end(), compareProjectNumberOfParticipants);
    for(auto& it : vectorProjectNumberOfParticipants){
      cout<<it.first<<" "<<it.second<<'\n';
    }
    if (input == "0"){
      anotherTestCase = false;
    }
  }
}