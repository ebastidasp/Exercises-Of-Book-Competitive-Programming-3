#include <bits/stdc++.h>

using namespace std;

class Computer {
  public:
    int y, a, b;
    Computer (int _y, int _a, int _b) {
      y = _y;
      a = _a;
      b = _b;
    }
};

int main(){
  int computers;
  int testId = 1;
  while(cin>>computers, computers) {
    vector <Computer> Computers;
    while (computers--) {
      int y, a, b;
      cin>>y>>a>>b;
      Computer newComputer(y, a, b);
      Computers.push_back(newComputer);
    }
    cout<<"Case #"<<testId<<":\n";
    if (Computers.size() == 1) {
      cout<<"The actual year is "<<Computers[0].y<<".\n";
    }
    else {
      vector <int> possibleYears;
      for(int i = Computers[0].a + 1; i < 10000; i++) {
        if (i%(Computers[0].b-Computers[0].a)-Computers[0].y%(Computers[0].b-Computers[0].a) == 0)
          possibleYears.push_back(i);
      }
      bool foundYear = false;
      for(int i = 0; i < possibleYears.size(); i++) {
        bool isPossibleYear = true;
        for (int j = 1; j < Computers.size(); j++){
          if (!(possibleYears[i]%(Computers[j].b-Computers[j].a)-Computers[j].y%(Computers[j].b-Computers[j].a) == 0) || !(possibleYears[i] >= Computers[j].a)) {
            isPossibleYear = false;
            break;
          }
        }
        if (isPossibleYear) {
          foundYear = true;
          cout<<"The actual year is "<<possibleYears[i]<<".\n";
          break;
        }
      }
      if (!foundYear) {
        cout<<"Unknown bugs detected."<<'\n';
      }
    }
    cout<<'\n';
    testId++;
  }
  return 0;
}