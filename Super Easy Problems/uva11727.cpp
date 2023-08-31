#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  cin>>T;
  int caseId = 1;
  while(T--){
    vector<int> arr;
    for(int i = 0; i < 3; i++){
      int input;
      cin>>input;
      arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    cout<<"Case "<<caseId++<<": "<<arr[1]<<'\n';
  }
}