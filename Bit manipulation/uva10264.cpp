#include <bits/stdc++.h>

using namespace std;

int main(){
  int dimension;
  while(cin>>dimension) {
    map<int, int> cornerWeights;
    int numberOfCorners = pow(2, dimension);
    for (int i = 0; i < numberOfCorners; i++) {
      int input;
      cin>>input;
      cornerWeights[i] = input;
    }
    vector <int> potencyOfCorners (numberOfCorners, 0);
    for (int i = 0; i < numberOfCorners; i++) {
      for (int j = 0; j < dimension; j++) {
        bitset <15> set1 (i);
        set1[j] = !set1[j];
        potencyOfCorners[i] += cornerWeights[set1.to_ulong()];
      }
    }
    vector <int> sumOfPotencyOfNeighboringCorners;
    for(int i = 0; i < potencyOfCorners.size(); i++){
      for(int j = 0; j < dimension; j++) {
        bitset <15> set1 (i);
        set1[j] = !set1[j];
        if(set1.to_ullong() > i){
          int sum = potencyOfCorners[i]+potencyOfCorners[set1.to_ulong()];
          sumOfPotencyOfNeighboringCorners.push_back(sum);
        }
      }
    }
    sort(sumOfPotencyOfNeighboringCorners.begin(), sumOfPotencyOfNeighboringCorners.end(), greater<int>());
    cout<<sumOfPotencyOfNeighboringCorners[0]<<'\n';
  }
  return 0;
}