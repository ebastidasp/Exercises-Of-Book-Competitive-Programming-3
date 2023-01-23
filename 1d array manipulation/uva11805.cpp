#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin.tie(NULL);
  while(cin>>N){
    if(N == 0) return 0;
    vector<int> chargingStations;
    while(N--){
      int input;
      cin>>input;
      chargingStations.push_back(input);
    }
    sort(chargingStations.begin(), chargingStations.end());
    int pos = true;
    for(int i = 1 ; i < chargingStations.size(); i++){
      if((chargingStations[i] - chargingStations[i-1]) > 200){
        pos = false;
        break;
      }
    }
    if((1522-chargingStations[chargingStations.size()-1]) > 200) pos = false;
    if(pos) cout<<"POSSIBLE"<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
  }
  return 0;
}
