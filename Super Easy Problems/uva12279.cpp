#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int caseId = 1;
  while(cin>>n && n != 0){
    vector<int> arr;
    while(n--){
      int input;
      cin>>input;
      arr.push_back(input);
    }
    int output = arr.size() - 2 * count(arr.begin(), arr.end(), 0);
    cout<<"Case "<<caseId++<<": "<<output<<'\n';
  }
}