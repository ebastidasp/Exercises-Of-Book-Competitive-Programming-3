#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCases;
  cin>>testCases;
  while(testCases--) {
    int N, M;
    cin>>N>>M;
    vector <int> playersRetired;
    while(M--) {
      int input;
      cin>>input;
      playersRetired.push_back(input);
    }
    int numberOfPlayers = pow(2, N);
    bitset <1024> players;
    int numberOfWoMatches = 0;
    for(int i = 0; i < numberOfPlayers; i++) {
      if(count(playersRetired.begin(), playersRetired.end(), i+1) == 0)
        players[i] = 1;
    }
    while (numberOfPlayers > 1) {
      for(int i = 0; i < numberOfPlayers/2; i++) {
        if(players[2*i] != players[2*i+1]) numberOfWoMatches++;
        players[i] = players[2*i] | players[2*i+1];
      }
      numberOfPlayers /= 2;
    }
    cout<<numberOfWoMatches<<'\n';
  }
  return 0;
}