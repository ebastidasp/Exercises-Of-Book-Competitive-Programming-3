#include <bits/stdc++.h>

using namespace std;

void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}

int main()
{
  int tests;
  cin.tie(NULL);
  cin>>tests;
  int testId = 1;
  while(tests--){
    int arr[3];
    vector<vector<int>> solvedByEach;
    for(int i = 0; i < 3; i++){
      cin>>arr[i];
      vector<int> problemsSolved;
      for(int j = 0; j < arr[i]; j++){
        int input;
        cin>>input;
        problemsSolved.push_back(input);
      }
      remove(problemsSolved);
      sort(problemsSolved.begin(), problemsSolved.end());
      solvedByEach.push_back(problemsSolved);
    }
    vector<vector<int>> uniqueProblemsSolvedByEach;
    for(int i = 0; i < solvedByEach.size(); i++){
      vector<int> uniqueProblemsSolved;
      uniqueProblemsSolved.push_back(i+1);
      for(int j = 0; j < solvedByEach[i].size(); j++) {
        bool wasSolvedByAnyOther = false;
        for(int k = 0; k < solvedByEach.size(); k++) {
          if(k != i) {
            bool same = false;
            for(int l = 0; l < solvedByEach[k].size(); l++) {
              if(solvedByEach[k][l] == solvedByEach[i][j]){
                same = true;
                break;
              }
            }
            wasSolvedByAnyOther = wasSolvedByAnyOther | same;
          }
        }
        if(!wasSolvedByAnyOther) {
          uniqueProblemsSolved.push_back(solvedByEach[i][j]);
        }
      }
      uniqueProblemsSolvedByEach.push_back(uniqueProblemsSolved);
    }
    sort(uniqueProblemsSolvedByEach.begin(), uniqueProblemsSolvedByEach.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() > b.size(); });
    cout<<"Case #"<<testId<<":"<<'\n';
    for(int i = 0; i < uniqueProblemsSolvedByEach.size(); i++) {
      if(i == 0) {
        if (uniqueProblemsSolvedByEach[i].size() > 1)
          cout<<uniqueProblemsSolvedByEach[i][0]<<" "<<uniqueProblemsSolvedByEach[i].size() - 1<<" ";
        else
          cout<<uniqueProblemsSolvedByEach[i][0]<<" "<<uniqueProblemsSolvedByEach[i].size() - 1;
        for(int j = 1; j < uniqueProblemsSolvedByEach[i].size(); j++) {
          if (j < uniqueProblemsSolvedByEach[i].size() - 1) { cout<<uniqueProblemsSolvedByEach[i][j]<<" "; }
            else { cout<<uniqueProblemsSolvedByEach[i][j]; }
        }
        cout<<'\n';
      } else if(uniqueProblemsSolvedByEach[i].size() == uniqueProblemsSolvedByEach[i-1].size()){
        if (uniqueProblemsSolvedByEach[i].size() > 1)
          cout<<uniqueProblemsSolvedByEach[i][0]<<" "<<uniqueProblemsSolvedByEach[i].size() - 1<<" ";
        else
          cout<<uniqueProblemsSolvedByEach[i][0]<<" "<<uniqueProblemsSolvedByEach[i].size() - 1;
        for(int j = 1; j < uniqueProblemsSolvedByEach[i].size(); j++) {
          if (j < uniqueProblemsSolvedByEach[i].size() - 1) { cout<<uniqueProblemsSolvedByEach[i][j]<<" "; }
            else { cout<<uniqueProblemsSolvedByEach[i][j]; }
        }
        cout<<'\n';
      } else break;
    }
    testId++;
  }
  return 0;
}
