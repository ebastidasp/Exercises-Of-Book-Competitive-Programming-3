#include <bits/stdc++.h>

using namespace std;

bool sortFloors (const int & a, const int & b) {
  return abs(a) > abs(b);
}

int main(){
  int n;
  cin>>n;
  while(n--){
    int numberOfFloors;
    cin>>numberOfFloors;
    vector <int> floors;
    while(numberOfFloors--){
      int input;
      cin>>input;
      floors.push_back(input);
    }
    sort(floors.begin(), floors.end(), sortFloors);
    int answer = 1;
    int currFloor = floors[0];
    for(int i = 1; i < floors.size(); i++){
      if(((floors[i] > 0 && currFloor < 0) || (floors[i] < 0 && currFloor > 0)) && abs(currFloor) > abs(floors[i])) {
        answer++;
        currFloor = floors[i];
      }
    }
    cout<<answer<<'\n';
  }

  return 0;
}