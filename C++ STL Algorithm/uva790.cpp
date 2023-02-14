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

class Problem {
  public:
    string problem;
    string time;
    bool solved;
    Problem (string problemInput, string timeInput, bool isSolved) {
      problem = problemInput;
      time = timeInput;
      solved = isSolved;
    }
};

class Team {
  public:
    string name;
    vector <Problem> problemsTried;
    int problemsSolved, timeConsumed;
    Team (string nameInput) {
      name = nameInput;
      problemsSolved = 0;
      timeConsumed = 0;
    }
};

bool sortTeams(const Team &a,
  const Team &b)
{
  if (a.problemsSolved != b.problemsSolved) {
    return a.problemsSolved > b.problemsSolved;
  } else if (a.timeConsumed != b.timeConsumed) {
    return a.timeConsumed < b.timeConsumed;
  } else {
    return stoi(a.name) < stoi(b.name);
  }
}

int main()
{
  int numTestCases;
  cin>>numTestCases;
  cin.ignore();
  cin.ignore();
  while (numTestCases--) {
    int minTeam = 1, maxTeam = 1;
    string line;
    vector <Team> Teams;
    vector <string> problemNames;
    while (getline(cin, line) && line.length() > 0) {
      vector <string> data = split(line, ' ');
      maxTeam = max (maxTeam, stoi(data[0]));
      problemNames.push_back(data[0]);
      bool exists = false;
      int index = -1;
      for (int i = 0; i < Teams.size(); i++) {
        if(Teams[i].name == data[0]) {
          exists = true;
          index = i;
          break;
        }
      }
      bool isSolved = data[3] == "Y";
      Problem newProblem (data[1], data[2], isSolved);
      if (!exists) {
        Team newTeam(data[0]);
        newTeam.problemsTried.push_back(newProblem);
        Teams.push_back(newTeam);
      } else {
        bool shouldAddAsNewProblem = true;
        for(int i = 0; i < Teams[index].problemsTried.size(); i++){
          if(Teams[index].problemsTried[i].problem == newProblem.problem && Teams[index].problemsTried[i].solved && newProblem.solved) {
            int timeConsumedI, timeConsumedNP;
            timeConsumedI = 60*stoi(Teams[index].problemsTried[i].time.substr(0,Teams[index].problemsTried[i].time.length()-3)) + stoi(Teams[index].problemsTried[i].time.substr(Teams[index].problemsTried[i].time.length()-2,2));
            timeConsumedNP = 60*stoi(newProblem.time.substr(0,newProblem.time.length()-3)) + stoi(newProblem.time.substr(newProblem.time.length()-2,2));
            string hours = to_string(min(timeConsumedI, timeConsumedNP)/60);
            string mins = "";
            if (min(timeConsumedI, timeConsumedNP)%60 < 10) {
              mins += "0";
            }
            mins += to_string(min(timeConsumedI, timeConsumedNP)%60);
            Teams[index].problemsTried[i].time = hours+":"+mins;
            shouldAddAsNewProblem = false;
            break;
          }
        }
        if (shouldAddAsNewProblem)
          Teams[index].problemsTried.push_back(newProblem);
      }
    }
    for (int i = minTeam; i <= maxTeam; i++) {
      bool teamExists = false;
      for(int j = 0; j < Teams.size(); j++) {
        if (stoi(Teams[j].name) == i) {
          teamExists = true;
          break;
        }
      }
      if (!teamExists) {
        Team newTeam(to_string(i));
        Teams.push_back(newTeam);
      }
    }
    for(int i = 0; i < Teams.size(); i++){
      int problemsSolved = 0, timeConsumed = 0;
      for(int j = 0; j < Teams[i].problemsTried.size(); j++) {
        if (Teams[i].problemsTried[j].solved){
          problemsSolved++;
          timeConsumed += 60*stoi(Teams[i].problemsTried[j].time.substr(0,Teams[i].problemsTried[j].time.length()-3)) + stoi(Teams[i].problemsTried[j].time.substr(Teams[i].problemsTried[j].time.length()-2,2));
        } else {
          for(int k = 0; k < Teams[i].problemsTried.size(); k++) {
            if(k != j && Teams[i].problemsTried[k].solved && Teams[i].problemsTried[k].problem == Teams[i].problemsTried[j].problem) {
              int timeConsumedJ, timeConsumedK;
              timeConsumedJ = 60*stoi(Teams[i].problemsTried[j].time.substr(0,Teams[i].problemsTried[j].time.length()-3)) + stoi(Teams[i].problemsTried[j].time.substr(Teams[i].problemsTried[j].time.length()-2,2)); 
              timeConsumedK = 60*stoi(Teams[i].problemsTried[k].time.substr(0,Teams[i].problemsTried[k].time.length()-3)) + stoi(Teams[i].problemsTried[k].time.substr(Teams[i].problemsTried[k].time.length()-2,2));
              if (timeConsumedK >= timeConsumedJ) {
                timeConsumed += 20;
              }
            }
          }
        }
      }
      Teams[i].problemsSolved = problemsSolved;
      Teams[i].timeConsumed = timeConsumed;
    }
    sort(Teams.begin(), Teams.end(), sortTeams);
    cout<<"RANK TEAM PRO/SOLVED TIME\n";
    int rank = 1;
    for (int i = 0; i < Teams.size(); i++) {
      if (i > 0){
        if (Teams[i].problemsSolved < Teams[i-1].problemsSolved || Teams[i].timeConsumed > Teams[i-1].timeConsumed) {
          rank = i+1;
        }
      }
      int numberOfDigits = 1;
      int aux = rank;
      while (aux/10 > 0) {
        numberOfDigits++;
        aux = aux/10;
      }
      for(int j = 0; j < 4-numberOfDigits; j++) {
        cout<<" ";
      }
      cout<<rank;
      for(int j = 0; j < 5 - Teams[i].name.length(); j++) {
        cout<<" ";
      }
      cout<<Teams[i].name;
      if (Teams[i].problemsSolved > 0) {
        int numberOfDigitsPSolved = 1;
        aux = Teams[i].problemsSolved;
        while (aux/10 > 0) {
          numberOfDigitsPSolved++;
          aux = aux/10;
        }
        for(int j = 0; j < 5 - numberOfDigitsPSolved; j++) {
          cout<<" ";
        }
        cout<<Teams[i].problemsSolved;
        int numberOfDigitsTConsumed = 1;
        aux = Teams[i].timeConsumed;
        while (aux/10 > 0) {
          numberOfDigitsTConsumed++;
          aux = aux/10;
        }
        for(int j = 0; j < 11 - numberOfDigitsTConsumed; j++) {
          cout<<" ";
        }
        cout<<Teams[i].timeConsumed<<'\n';
      } else {
        cout<< '\n';
      }
    }
    if(numTestCases)
      cout<<'\n';
  }
  return 0;
}
