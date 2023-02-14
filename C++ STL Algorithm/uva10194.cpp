#include <bits/stdc++.h>

using namespace std;

class Team {
  public:
    string name;
    int pointsEarned;
    int goalDifference;
    int goalScored;
    int gamesPlayed;
    int gamesWon;
    int gamesDrawn;
    Team (string _name) {
      name = _name;
      gamesDrawn = gamesWon = pointsEarned = goalDifference = goalScored = gamesPlayed = 0;
    }
};

string to_lower(string s) {
	for (int i = 0; i < s.length(); i++)
    if (s[i] >= 'A'&&s[i] <= 'Z')
      s[i] += 'a' - 'A';
	return s;
}

bool sortTeams(const Team &a,
  const Team &b)
{
  if (a.pointsEarned != b.pointsEarned)
    return a.pointsEarned > b.pointsEarned;
  if (a.gamesWon != b.gamesWon)
    return a.gamesWon > b.gamesWon;
  if (a.goalDifference != b.goalDifference) 
    return a.goalDifference > b.goalDifference;
  if (a.goalScored != b.goalScored) 
    return a.goalScored > b.goalScored;
  if (a.gamesPlayed != b.gamesPlayed)
    return a.gamesPlayed < b.gamesPlayed;
  return strcasecmp(a.name.c_str(), b.name.c_str()) < 0;
}

int main()
{
  int n;
  cin>>n;
  cin.tie(NULL);
  int times = 0;
  while(n--){
    string tournamentName;
    if(times == 0) {
      cin.ignore();
      times = 1;
    }
    getline(cin, tournamentName);
    int numberOfTeams;
    cin>>numberOfTeams;
    cin.ignore();
    vector <Team> teams;
    while(numberOfTeams--) {
      string name;
      getline(cin,name);
      Team newTeam(name);
      teams.push_back(newTeam);
    }
    int numberOfMatches;
    cin>>numberOfMatches;
    cin.ignore();
    while(numberOfMatches--){
      string match;
      getline(cin,match);
      int scoreOfFirstTeam = stoi( match.substr( match.find('#')+1, match.find('@')-match.find('#') ) );
      int scoreOfSecondTeam = stoi( match.substr( match.find('@') + 1, match.find('#', match.find('#')+1)-match.find('@') ) );
      for(int i = 0; i < teams.size(); i++) {
        if (match.find(teams[i].name) == 0) {
          if(scoreOfFirstTeam > scoreOfSecondTeam) {
            teams[i].pointsEarned += 3;
            teams[i].gamesWon++;
          }
          else if(scoreOfFirstTeam == scoreOfSecondTeam) {
            teams[i].pointsEarned++;
            teams[i].gamesDrawn++;
          }
          teams[i].goalScored += scoreOfFirstTeam;
          teams[i].goalDifference += scoreOfFirstTeam - scoreOfSecondTeam;
          teams[i].gamesPlayed++;
        } else if (match.find(teams[i].name) > 0 && match.find(teams[i].name) != string::npos) {
          if(scoreOfSecondTeam > scoreOfFirstTeam){
            teams[i].pointsEarned += 3;
            teams[i].gamesWon++;
          }
          
          else if(scoreOfFirstTeam == scoreOfSecondTeam) {
            teams[i].pointsEarned++;
            teams[i].gamesDrawn++;
          }
          teams[i].goalScored += scoreOfSecondTeam;
          teams[i].goalDifference += scoreOfSecondTeam - scoreOfFirstTeam;
          teams[i].gamesPlayed++;
        }
      }
    }
    sort(teams.begin(), teams.end(), sortTeams);
    cout<<tournamentName<<'\n';
    for(int i = 0; i < teams.size(); i++) {
      cout<<i+1<<") "<<teams[i].name<<" "<<teams[i].pointsEarned<<"p, "<<teams[i].gamesPlayed<<"g ("<<teams[i].gamesWon<<"-"<<teams[i].gamesDrawn<<"-"<<teams[i].gamesPlayed-teams[i].gamesWon-teams[i].gamesDrawn<<"), "<<teams[i].goalDifference<<"gd ("<<teams[i].goalScored<<"-"<<teams[i].goalScored-teams[i].goalDifference<<")\n";
    }
    if(n) cout<<'\n';
  }
  return 0;
}
