#include <bits/stdc++.h>
#include <fstream>

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
  int T;
  cin>>T;
  int caseId = 1;
  while(T--){
    int subjects;
    cin>>subjects;
    cin.get();
    map<string, int> homeworkDuration;
    while(subjects--){
      string input;
      getline(cin, input);
      vector<string> homeD = split(input, ' ');
      homeworkDuration[homeD[0]] = stoi(homeD[1]);
    }
    int daysToGiveTheAssignment;
    cin>>daysToGiveTheAssignment;
    cin.get();
    string subjectDue;
    getline(cin, subjectDue);
    cout<<"Case "<<caseId++<<": ";
    if(homeworkDuration.find(subjectDue) == homeworkDuration.end()){
      cout<<"Do your own homework!\n";
      continue;
    }
    if(homeworkDuration[subjectDue] <= daysToGiveTheAssignment){
      cout<<"Yesss\n";
    } else if(homeworkDuration[subjectDue] <= daysToGiveTheAssignment + 5){
      cout<<"Late\n";
    } else {
      cout<<"Do your own homework!\n";
    }
  }
}