#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}


vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

int main(){
  int SET;
  cin>>SET;
  while(SET--){
    int stations, cargoLimit, limitOfQueue;
    cin>>stations>>cargoLimit>>limitOfQueue;
    int time = 0;
    stack<int> cargo;
    cargo.push(0);
    vector<queue<int>> boxInStations (stations);
    cin.get();
    int totalCargos = 0;
    for(int i = 0; i < stations; i++){
      string inputString;
      getline(cin, inputString);
      vector<string> numbers = split(inputString, ' ');
      for(int j = 1; j < numbers.size(); j++){
        boxInStations[i].push(stoi(numbers[j]));
        totalCargos++;
      }
    }
    int currentStation = 0;
    while(totalCargos){
      while(cargo.size() > 1 && (cargo.top() == (currentStation+1) || boxInStations[currentStation].size() < limitOfQueue)){
        if(cargo.top() == currentStation+1){
          cargo.pop();
          time++;
          totalCargos--;
        } else if (boxInStations[currentStation].size() < limitOfQueue) {
          boxInStations[currentStation].push(cargo.top());
          cargo.pop();
          time++;
        }
      }
      while(cargo.size()-1 < cargoLimit && boxInStations[currentStation].size() > 0){
        cargo.push(boxInStations[currentStation].front());
        boxInStations[currentStation].pop();
        time++;
      }
      if(totalCargos)
        time += 2;
      currentStation++;
      currentStation%=stations;
    }
    cout<<time<<'\n';
  }
  return 0;
}