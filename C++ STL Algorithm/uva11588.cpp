#include <bits/stdc++.h>

using namespace std;

bool sortPair (const pair<char, int> &a, const pair<char, int> &b) {
  return a.second > b.second;
}

int main(){
  int n;
  cin>>n;
  int testId = 1;
  while(n--) {
    int R, C, B, b; //Rows, Cols, Bytes of important pixel and bytes of not important pixel
    cin>>R>>C>>B>>b;
    vector <vector<char>> Image (R, vector<char>(C, ' '));
    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        cin>>Image[i][j];
      }
    }
    map <char, int> frequency;
    for (int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
        frequency[Image[i][j]]++;
      }
    }
    vector <pair<char,int>> frequencyVector (frequency.begin(), frequency.end());
    sort(frequencyVector.begin(), frequencyVector.end(), sortPair);
    int maxFrequency = frequencyVector[0].second;
    int answer = 0;
    for(int i = 0; i < frequencyVector.size(); i++) {
      if(frequencyVector[i].second == maxFrequency)
        answer += frequencyVector[i].second*B;
      else
        answer += frequencyVector[i].second*b;
    }
    cout<<"Case "<<testId<<": "<<answer<<'\n';
    testId++;
  }

  return 0;
}