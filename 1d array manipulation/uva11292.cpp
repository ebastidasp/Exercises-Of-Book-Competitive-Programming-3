#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin.tie(NULL);
  while(cin>>n){
    cin>>m;
    if(m == n && n == 0) {
      return 0;
    }
    vector<int> dragonHeads;
    vector<int> knights;
    for(int i = 0; i < n; i++){
      int input;
      cin>>input;
      dragonHeads.push_back(input);
    }
    for(int i = 0; i < m; i++){
      int input;
      cin>>input;
      knights.push_back(input);
    }
    if(n > m)
      cout<<"Loowater is doomed!"<<'\n';
    else {
      sort(dragonHeads.begin(), dragonHeads.end());
      sort(knights.begin(), knights.end());
      int sum = 0;
      int numberOfKnightsUsed = 0;
      int pK = 0;
      for(int i = 0; i < n; i++){
        for(int j = pK; j < m; j++){
          if(dragonHeads[i] <= knights[j]) {
            numberOfKnightsUsed++;
            sum += knights[j];
            pK = j+1;
            break;
          }
        }
      }
      if(numberOfKnightsUsed == n) {
        cout<<sum<<'\n';
      } else {
        cout<<"Loowater is doomed!"<<'\n';
      }
    }
  }
  return 0;
}
