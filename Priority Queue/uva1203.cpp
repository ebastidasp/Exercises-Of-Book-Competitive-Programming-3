#include <bits/stdc++.h>

using namespace std;

int main(){
  string input;
  vector<pair<int, int>> registerFrequency;
  priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> gq;
  while(cin>>input && input != "#"){
    int registernumber, frequency;
    cin>>registernumber>>frequency;
    registerFrequency.push_back(make_pair(frequency, registernumber));
  }
  sort(registerFrequency.begin(), registerFrequency.end());
  int numberOfRegistersToShow;
  cin>>numberOfRegistersToShow;
  for(auto it : registerFrequency){
    for(int i = 1; i <= numberOfRegistersToShow; i++){
      gq.push(make_pair(it.first*i, it.second));
    }
  }
  for(int i = 0; i < numberOfRegistersToShow; i++){
    cout<<gq.top().second<<'\n';
    gq.pop();
  }
}