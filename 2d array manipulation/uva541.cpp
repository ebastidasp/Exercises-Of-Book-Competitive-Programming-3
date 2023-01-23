#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin.tie(NULL);
  while(cin>>n){
    if(n == 0) return 0;
    vector<vector<int> > bitMap(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin>>bitMap[i][j];
      }
    } 
    vector<int> oddRows, oddCols;
    for(int i = 0; i < n; i++) {
      int sumRow = 0, sumCol = 0;
      for(int j = 0; j < n; j++) {
        sumRow += bitMap[i][j];
        sumCol += bitMap[j][i];  
      }
      if(sumRow % 2 != 0) oddRows.push_back(i);
      if(sumCol % 2 != 0) oddCols.push_back(i);
    }
    if(oddRows.size() == 0 && oddCols.size() == 0) cout<<"OK"<<'\n';
    else if (oddRows.size() == 1 && oddCols.size() == 1) cout<<"Change bit ("<<oddRows[0]+1<<","<<oddCols[0]+1<<")"<<'\n';
    else cout<<"Corrupt"<<'\n';
  }
  return 0;
}
