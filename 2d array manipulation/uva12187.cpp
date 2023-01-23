#include <bits/stdc++.h>

using namespace std;

int main()
{
  int numberOfHeirs, rows, cols, numberOfBattles;
  while (cin >> numberOfHeirs >> rows >> cols >> numberOfBattles, numberOfHeirs) {
    vector<vector<int>> counties (rows+1, vector<int>(cols+1, -1));
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        cin>>counties[i][j];
      }
    }
    vector<vector<int>> auxMatrix (rows+1, vector<int>(cols+1, -1));
    auxMatrix = counties;
    while (numberOfBattles--) {
      for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
          if (i == 0 && j == 0) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
          } else if (i > 0 && i < rows-1 && j == 0) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
          } else if (i == rows-1 && j == 0) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
          } else if (i == 0 && j > 0 && j < cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          } else if (i > 0 && i < rows-1 && j > 0 && j < cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          } else if (i == rows-1 && j > 0 && j < cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j+1]) {
              auxMatrix[i][j+1] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          } else if (i == 0 && j == cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          }  else if (i > 0 && i < rows-1 && j == cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i+1][j]) {
              auxMatrix[i+1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          } else if (i == rows-1 && j == cols-1) {
            if ((counties[i][j]+1)%numberOfHeirs == counties[i-1][j]) {
              auxMatrix[i-1][j] = counties[i][j];
            }
            if ((counties[i][j]+1)%numberOfHeirs == counties[i][j-1]) {
              auxMatrix[i][j-1] = counties[i][j];
            }
          }        
        }
      }
      counties = auxMatrix;
    }
    for (int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        cout<<counties[i][j];
        if(j < cols-1) {
          cout<<" ";
        }
      }
      cout<<'\n';
    }
  }
  return 0;
}