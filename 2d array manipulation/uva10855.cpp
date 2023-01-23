#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> rotate90(vector<vector<char>> parameter) {
  vector<vector<char>> returnVector (parameter.size(), vector<char>(parameter.size(), ' '));
  for(int i = 0; i < parameter.size(); i++) {
    for(int j = 0; j < parameter.size(); j++) {
      returnVector[j][parameter.size()-1-i] = parameter[i][j];
    }
  }
  return returnVector;
}

int main()
{
  int N, n;
  while(cin>>N) {
    cin>>n;
    if(!N && !n) return 0;
    vector <vector<char>> bigSquare (N, vector<char>(N, ' ')),
      smallSquare (n, vector<char>(n, ' '));
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++)
        cin>>bigSquare[i][j];
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        cin>>smallSquare[i][j];
    }
    int numberOfOcurrences = 0;
    int numberOfOcurrences90 = 0;
    int numberOfOcurrences180 = 0;
    int numberOfOcurrences270 = 0;
    for(int i = 0; i < N - n + 1; i++) {
      for(int j = 0; j < N - n + 1; j++) {
        vector <vector<char>> currSubSquare (n, vector<char>(n, ' '));
        for(int k = 0; k < n; k++) {
          for(int l = 0; l < n; l++) {
            currSubSquare[k][l] = bigSquare[i+k][j+l];
          }
        }
        if (currSubSquare == smallSquare) numberOfOcurrences++;
        if (currSubSquare == rotate90(smallSquare)) numberOfOcurrences90++;
        if (currSubSquare == rotate90(rotate90(smallSquare))) numberOfOcurrences180++;
        if (currSubSquare == rotate90(rotate90(rotate90(smallSquare))) ) numberOfOcurrences270++;
      }
    }
    cout<<numberOfOcurrences<<" "<<numberOfOcurrences90<<" "<<numberOfOcurrences180<<" "<<numberOfOcurrences270<<'\n';
  }
  return 0;
}