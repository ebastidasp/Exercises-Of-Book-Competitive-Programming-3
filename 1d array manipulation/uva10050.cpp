#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin.tie(NULL);
  cin>>N;
  while(N--){
    int Days;
    cin>>Days;
    int P;
    cin>>P;
    vector<int> Hartals;
    for(int i = 0; i < P; i++){
      int input;
      cin>>input;
      Hartals.push_back(input);
    }
    int DaysLost = 0;
    for(int i = 1; i <= Days; i++){
      for(int j = 0; j < Hartals.size(); j++){
        if(i % Hartals[j] == 0 && i % 7 != 6 && i % 7 != 0){
          DaysLost++;
          j = Hartals.size();
        }
      }
    }
    cout<<DaysLost<<'\n';
  }
  return 0;
}
