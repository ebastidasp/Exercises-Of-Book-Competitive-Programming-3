#include <bits/stdc++.h>

using namespace std;

class Team {
  public:
    string name;
    int pointsEarned;
    int goalScored;
    int goalAgainst;
    int gamesWon;
    int gamesTied;
    int gamesLost;
    Team (string _name) {
      name = _name;
      pointsEarned = goalAgainst = goalScored = gamesWon = gamesTied = gamesLost = 0;
    }
};

string to_lower(string s) {
	for (int i = 0; i < s.length(); i++)
    if (s[i] >= 'A'&&s[i] <= 'Z')
      s[i] += 'a' - 'A';
	return s;
}

bool sortTeam (const Team &a, const Team &b){
  if(a.pointsEarned != b.pointsEarned) 
    return a.pointsEarned > b.pointsEarned;
  if((a.goalScored-a.goalAgainst) != (b.goalScored-b.goalAgainst))
    return (a.goalScored-a.goalAgainst) > (b.goalScored-b.goalAgainst);
  if(a.goalScored != b.goalScored)
    return a.goalScored > b.goalScored;
  return to_lower(a.name) < to_lower(b.name);
}

int main()
{
  int teams, games;
  int times = 0;
  while(cin>>teams>>games) {
    if(teams == 0 && games == 0) return 0;
    if (times > 0) cout<<'\n';
    vector <Team> Teams;
    cin.ignore();
    string input;
    for(int i = 0; i < teams; i++) {
      getline(cin, input);
      Team newTeam(input);
      Teams.push_back(newTeam);
    }
    for(int i = 0; i < games; i++){
      getline(cin, input);
      bool foundJ = false;
      for(int j = 0; j < Teams.size(); j++){
        if(input.find(Teams[j].name) == 0){
          foundJ = true;
          int scoreOfHomeTeam, scoreOfAwayTeam;
          scoreOfHomeTeam = stoi(input.substr(Teams[j].name.length()+1, input.find('-')-1-(Teams[j].name.length()+1)));
          bool foundK = false;
          for (int k = 0; k < Teams.size(); k++){
            if(input.find(Teams[k].name) > 0 && input.find(Teams[k].name) != string::npos) {
              foundK = true;
              scoreOfAwayTeam = stoi(input.substr(input.find('-')+2, input.find(Teams[k].name)-(input.find('-')+2)));
              Teams[j].goalScored += scoreOfHomeTeam;
              Teams[j].goalAgainst += scoreOfAwayTeam;
              Teams[k].goalScored += scoreOfAwayTeam;
              Teams[k].goalAgainst += scoreOfHomeTeam;
              if (scoreOfHomeTeam > scoreOfAwayTeam){
                Teams[j].pointsEarned += 3;
                Teams[j].gamesWon++;
                Teams[k].gamesLost++;
              }
              else if (scoreOfHomeTeam == scoreOfAwayTeam){
                Teams[j].pointsEarned++;
                Teams[k].pointsEarned++;
                Teams[j].gamesTied++;
                Teams[k].gamesTied++;
              }
              else{
                Teams[k].pointsEarned += 3;
                Teams[k].gamesWon++;
                Teams[j].gamesLost++;
              }
              break;
            }
          }
          if (!foundK) {
            int lastIndexOfNumber;
            for(int l = input.find('-')+2; l < input.length(); l++) {
              if(input.at(l) < '0' || input.at(l) > '9') {
                lastIndexOfNumber = l-1;
                break;
              }
            }
            scoreOfAwayTeam = stoi(input.substr(input.find('-')+2, lastIndexOfNumber+1-(input.find('-')+2)));
            Teams[j].goalScored += scoreOfHomeTeam;
            Teams[j].goalAgainst += scoreOfAwayTeam;
            if (scoreOfHomeTeam > scoreOfAwayTeam){
              Teams[j].pointsEarned += 3;
              Teams[j].gamesWon++;
            }
            else if (scoreOfHomeTeam == scoreOfAwayTeam){
              Teams[j].pointsEarned++;
              Teams[j].gamesTied++;
            }
            else{
              Teams[j].gamesLost++;
            }
          }
          break;
        }
      }
      if(!foundJ) {
        for (int k = 0; k < Teams.size(); k++){
          if(input.find(Teams[k].name) > 0 && input.find(Teams[k].name) != string::npos) {
            int firstIndexOfNumber;
            for(int l = input.find('-')-2; l >= 0; l--) {
              if(input.at(l) < '0' || input.at(l) > '9') {
                firstIndexOfNumber = l+1;
                break;
              }
            }
            int scoreOfHomeTeam = stoi(input.substr(firstIndexOfNumber, input.find('-')-1-firstIndexOfNumber));
            int scoreOfAwayTeam = stoi(input.substr(input.find('-')+2, input.find(Teams[k].name)-(input.find('-')+2)));
            Teams[k].goalScored += scoreOfAwayTeam;
            Teams[k].goalAgainst += scoreOfHomeTeam;
            if (scoreOfHomeTeam > scoreOfAwayTeam){
              Teams[k].gamesLost++;
            }
            else if (scoreOfHomeTeam == scoreOfAwayTeam){
              Teams[k].pointsEarned++;
              Teams[k].gamesTied++;
            }
            else{
              Teams[k].pointsEarned += 3;
              Teams[k].gamesWon++;
            }
            break;
          }
        }
      }
    }
    sort(Teams.begin(), Teams.end(), sortTeam);
    int currTeam = 0;
    for(int i = 0; i < Teams.size(); i++) {
      if (i > 0){
        if(Teams[i].pointsEarned < Teams[i-1].pointsEarned || (Teams[i].goalScored-Teams[i].goalAgainst) < (Teams[i-1].goalScored-Teams[i-1].goalAgainst) || Teams[i].goalScored < Teams[i-1].goalScored){
          currTeam = i;
          for(int j = 0; j < 2 - to_string(currTeam+1).length(); j++)
            cout<<" ";
          cout<<currTeam+1<<".";
        } else {
          cout<<"   ";
        }
      } else if (i == 0) {
        cout<<" "<<1<<".";
      }
      for(int j = 0; j < 16 - Teams[i].name.length(); j++){
        cout<<" ";
      }
      cout<<Teams[i].name;
      for(int j = 0; j < 4 - to_string(Teams[i].pointsEarned).length(); j++){
        cout<<" ";
      }
      cout<<Teams[i].pointsEarned;
      for(int j = 0; j < 4 - to_string(Teams[i].gamesWon+Teams[i].gamesTied+Teams[i].gamesLost).length(); j++) {
        cout<<" ";
      }
      cout<<Teams[i].gamesWon+Teams[i].gamesTied+Teams[i].gamesLost;
      for(int j = 0; j < 4 - to_string(Teams[i].goalScored).length(); j++){
        cout<<" ";
      }
      cout<<Teams[i].goalScored;
      for(int j = 0; j < 4 - to_string(Teams[i].goalAgainst).length(); j++){
        cout<<" ";
      }
      cout<<Teams[i].goalAgainst;
      for(int j = 0; j < 4 - to_string(Teams[i].goalScored-Teams[i].goalAgainst).length(); j++){
        cout<<" ";
      }
      cout<<Teams[i].goalScored-Teams[i].goalAgainst;
      if((Teams[i].gamesWon+Teams[i].gamesTied+Teams[i].gamesLost) == 0) {
        string performance = "N/A";
        for(int j = 0; j < 7 - performance.length(); j++){
          cout<<" ";
        }
        cout<<performance<<'\n';
      }
      else {
        cout<< fixed << setprecision(2) << setw(7) << (Teams[i].pointsEarned * 100.0 / (3.0*(Teams[i].gamesWon + Teams[i].gamesTied + Teams[i].gamesLost))) << '\n';
      }
    }
    times++;
  }
  return 0;
}
