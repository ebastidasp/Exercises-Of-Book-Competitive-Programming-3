#include <bits/stdc++.h>

using namespace std;

int main(){
  int testCases;
  cin>>testCases;
  while(testCases--) {
    vector <int> landPrices;
    int input;
    while(cin>>input, input) {
      landPrices.push_back(input);
    }
    sort(landPrices.begin(), landPrices.end(), greater<int>());
    long long totalPrice = 0;
    bool isTooExpensive = false;
    for(int i = 0; i < landPrices.size(); i++) {
      totalPrice += 2*pow(landPrices[i],i+1);
      if (totalPrice > 5000000) {
        cout<<"Too expensive\n";
        isTooExpensive = true;
        break;
      }
    }
    if (!isTooExpensive)
      cout<<totalPrice<<'\n';
  }
  return 0;
}