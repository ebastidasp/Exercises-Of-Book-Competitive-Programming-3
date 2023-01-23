#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &a,
  const pair<int,int> &b) {
  return (a.second > b.second);
}

int main()
{
  int G, P;
  while(cin>>G){
    cin>>P;
    if (!G && !P) return 0;
    vector <vector<int>> positions (G, vector<int>(P, 0));
    for(int i = 0; i < G; i++){
      for(int j = 0; j < P; j++) {
        cin>>positions[i][j];
      }
    }
    int scoreSystems;
    cin>>scoreSystems;
    vector<vector<int>> pointsGivenDependingOnScoreSystemAndPosition;
    while(scoreSystems--) {
      int numberOfCarsThatGetPoints;
      cin>>numberOfCarsThatGetPoints;
      vector<int> pointsGiven;
      for(int i = 0; i < numberOfCarsThatGetPoints; i++) {
        int input;
        cin>>input;
        pointsGiven.push_back(input);
      }
      pointsGivenDependingOnScoreSystemAndPosition.push_back(pointsGiven);
    }
    for(int i = 0; i < pointsGivenDependingOnScoreSystemAndPosition.size(); i++) {
      vector<pair <int, int>> pointsGivenToPlayer;
      for(int i = 0; i < P; i++) {
        pair<int, int> player;
        player.first = i;
        player.second = 0;
        pointsGivenToPlayer.push_back(player);
      }
      for(int j = 0; j < positions.size(); j++) {
        for(int k = 0; k < positions[j].size(); k++) {
          if (positions[j][k] <= pointsGivenDependingOnScoreSystemAndPosition[i].size()) {
            pointsGivenToPlayer[k].second += pointsGivenDependingOnScoreSystemAndPosition[i][positions[j][k]-1];
          }
        }
      }
      sort(pointsGivenToPlayer.begin(), pointsGivenToPlayer.end(), sortbysec);
      int max = pointsGivenToPlayer[0].second;
      int index = 0;
      vector<int> outputPlayers;
      while (pointsGivenToPlayer[index].second == max) {
        outputPlayers.push_back(pointsGivenToPlayer[index].first+1);
        index++;
      }
      sort(outputPlayers.begin(), outputPlayers.end());
      for(int i = 0; i < outputPlayers.size(); i++) {
        if (i == outputPlayers.size() -1) {
          cout<<outputPlayers[i];
        } else {
          cout<<outputPlayers[i]<<" ";
        }
      }
      cout<<'\n';
    }
  }
  return 0;
}