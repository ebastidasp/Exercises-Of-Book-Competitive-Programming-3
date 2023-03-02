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
  int numberOfTeams;
  int testId = 1;
  while(cin>>numberOfTeams && numberOfTeams){
    vector<vector<int>> teams;
    vector<int> aux;
    map <int,int> lastIndexOfTeamInQueue;
    map <int, int> teamOfNumber;
    map <int, int> indexInTeamOfNumber;
    cin.get();
    while(numberOfTeams--) {
      string inputString;
      getline(cin, inputString);
      vector<string> numbers = split(inputString, ' ');
      int size = stoi(numbers[0]);
      aux.clear();
      for(int i = 1; i < numbers.size(); i++){
        teamOfNumber[stoi(numbers[i])] = teams.size();
        indexInTeamOfNumber[stoi(numbers[i])] = i-1;
        aux.push_back(stoi(numbers[i]));
      }
      teams.push_back(aux);
      lastIndexOfTeamInQueue[teams.size()-1] = -1;
    }
    string instruction;
    vector<queue<int>> teamQueue;
    cout<<"Scenario #"<<testId++<<'\n';
    while(getline(cin, instruction) && instruction != "STOP") {
      if(instruction == "DEQUEUE"){
        if(!teamQueue.empty() && !teamQueue[0].empty()){
          int out = teamQueue[0].front();
          cout<<out<<'\n';
          teamQueue[0].pop();
          if(teamQueue[0].empty()){
            teamQueue.erase(teamQueue.begin());
            map<int, int>::iterator it;
            for(it = lastIndexOfTeamInQueue.begin(); it != lastIndexOfTeamInQueue.end(); it++){
              if(it->second != -1)
                it->second--;
            }
          }
        }
      } else {
          int itemToPush = stoi(instruction.substr(8, instruction.length()-8));
          if(lastIndexOfTeamInQueue[teamOfNumber[itemToPush]] == -1) {
            queue<int> auxQueue;
            auxQueue.push(itemToPush);
            teamQueue.push_back(auxQueue);
            lastIndexOfTeamInQueue[teamOfNumber[itemToPush]] = teamQueue.size()-1;
          } else {
            teamQueue[lastIndexOfTeamInQueue[teamOfNumber[itemToPush]]].push(itemToPush);
          }
        }
    }
    cout<<'\n';
  }
  return 0;
}