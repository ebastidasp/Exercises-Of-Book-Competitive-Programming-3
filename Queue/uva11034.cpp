#include <bits/stdc++.h>

using namespace std;

int main(){
  int tests;
  cin>>tests;
  cin.tie(NULL);
  while(tests--){
    int l, m;
    cin>>l>>m;
    queue<pair<int, string>> carsInLeftBank;
    queue<pair<int, string>> carsInRightBank;
    string currBoatPosition = "left";
    while(m--){
      int input;
      string stringInput;
      cin>>input;
      cin>>stringInput;
      pair<int,string> aux;
      aux.first = input;
      aux.second = stringInput;
      if(stringInput == "left")
        carsInLeftBank.push(aux);
      else
        carsInRightBank.push(aux);
    }
    int numberOfTimesFerryHasCrossed = 0;
    int carsThatHaveArrived = carsInLeftBank.size()+carsInRightBank.size();
    int carsInBoat = 0;
    int capacityOfFerry;
    while(carsThatHaveArrived){
      capacityOfFerry = l*100;
      carsInBoat = 0;
      if(currBoatPosition == "left"){
        if(carsInLeftBank.size()){
          while((capacityOfFerry-carsInLeftBank.front().first) >= 0){
            carsThatHaveArrived--;
            capacityOfFerry -= carsInLeftBank.front().first;
            carsInLeftBank.pop();
            carsInBoat++;
            if(carsInLeftBank.empty())
              break;
          }
        }
      } else {
        if(carsInRightBank.size()){
          while((capacityOfFerry-carsInRightBank.front().first) >= 0){
            carsThatHaveArrived--;
            capacityOfFerry -= carsInRightBank.front().first;
            carsInRightBank.pop();
            carsInBoat++;
            if(carsInRightBank.empty())
              break;
          }
        }
      }
      if(currBoatPosition == "left" && (carsThatHaveArrived || carsInBoat)){
        currBoatPosition = "right";
        numberOfTimesFerryHasCrossed++;
      }
      else if(currBoatPosition == "right" && (carsThatHaveArrived || carsInBoat)) {
        currBoatPosition = "left";
        numberOfTimesFerryHasCrossed++;
      }
    }
    cout<<numberOfTimesFerryHasCrossed<<'\n';
  }
  return 0;
}