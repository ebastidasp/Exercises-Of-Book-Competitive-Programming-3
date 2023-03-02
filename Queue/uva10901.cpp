#include <bits/stdc++.h>

using namespace std;

int main(){
  int tests;
  cin>>tests;
  cin.tie(NULL);
  while(tests--){
    int n,t,m;
    cin>>n>>t>>m;
    vector<pair<int, string>> cars;
    vector<bool> hasArrived(m, false);
    vector<int> boat (m);
    int carsInBoat;
    string currBoatPosition = "left";
    while(m--){
      int input;
      string stringInput;
      cin>>input;
      cin>>stringInput;
      pair<int,string> aux;
      aux.first = input;
      aux.second = stringInput;
      cars.push_back(aux);
    }
    int time = 0;
    int carsThatHaveArrived = cars.size();
    while(carsThatHaveArrived){
      carsInBoat = 0;
      for(int i = 0; i < cars.size(); i++){
        if(cars[i].second == currBoatPosition && carsInBoat < n && time >= cars[i].first && !hasArrived[i]){
          boat[i] = time+t;
          hasArrived[i] = true;
          carsThatHaveArrived--;
          carsInBoat++;
        }
        if(carsInBoat == n)
          break;
      }
      bool isThereCarToPickUp = false;
      for(int i = 0; i < cars.size(); i++){
        if(cars[i].first <= time && !hasArrived[i]){
          isThereCarToPickUp = true;
          break;
        }
      }
      if(currBoatPosition == "left" && (carsInBoat || isThereCarToPickUp)){
        currBoatPosition = "right";
        time += t;
      }
      else if(currBoatPosition == "right" && (carsInBoat || isThereCarToPickUp)) {
        currBoatPosition = "left";
        time += t;
      }
      else
        time++;
    }
    for(int i = 0; i < boat.size(); i++){
      cout<<boat[i]<<'\n';
    }
    if(tests)
      cout<<'\n';
  }
  return 0;
}