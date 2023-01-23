#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> rotate (vector<vector<char>> parameter, int angle) {
  vector<vector<char>> returnVector (parameter.size(), vector<char>(parameter.size(), ' '));
  int n = parameter.size();
  switch (angle) {
    case 90:
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          returnVector[i][n-1-j] = parameter[j][i];
        }
      }
      break;
    case 180:
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          returnVector[n-1-j][n-1-i] = parameter[j][i];
        }
      }
      break;
    case 270:
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          returnVector[n-1-i][j] = parameter[j][i];
        }
      }
      break;
    default:
      break;
  }
  return returnVector;
}

vector<vector<char>> reflect (vector<vector<char>> parameter) {
  vector<vector<char>> returnVector (parameter.size(), vector<char>(parameter.size(), ' '));
  int n = parameter.size();
  for(int i = 0; i < n; i++) {
    returnVector[i] = parameter[n-1-i];
  }
  return returnVector;
}

int main()
{
  int n;
  cin.tie(NULL);
  int patternId = 1;
  while(cin>>n){
    vector<vector<char> > pattern(n, vector<char>(n)),
      newPattern(n, vector<char>(n));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c)
        cin >> pattern[r][c];
      for (int c = 0; c < n; ++c)
        cin >> newPattern[r][c];
    }
    if (newPattern == pattern) {
      cout<<"Pattern "<<patternId<<" was preserved."<<'\n';
    } else {
      if (rotate(pattern, 90) == newPattern) {
        cout<<"Pattern "<<patternId<<" was rotated 90 degrees."<<'\n';
      } else if (rotate(pattern, 180) == newPattern) {
        cout<<"Pattern "<<patternId<<" was rotated 180 degrees."<<'\n';
      } else if (rotate(pattern, 270) == newPattern) {
        cout<<"Pattern "<<patternId<<" was rotated 270 degrees."<<'\n';
      } else if (reflect(pattern) == newPattern) {
        cout<<"Pattern "<<patternId<<" was reflected vertically."<<'\n';
      } else if (rotate(reflect(pattern), 90) == newPattern) {
        cout<<"Pattern "<<patternId<<" was reflected vertically and rotated 90 degrees."<<'\n';
      } else if (rotate(reflect(pattern), 180) == newPattern) {
        cout<<"Pattern "<<patternId<<" was reflected vertically and rotated 180 degrees."<<'\n';
      } else if (rotate(reflect(pattern), 270) == newPattern) {
        cout<<"Pattern "<<patternId<<" was reflected vertically and rotated 270 degrees."<<'\n';
      } else {
        cout<<"Pattern "<<patternId<<" was improperly transformed."<<'\n';
      }
    }
    patternId++;
  }
  return 0;
}
