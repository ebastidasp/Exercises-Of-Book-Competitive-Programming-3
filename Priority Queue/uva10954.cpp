#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin>>n && n){
    priority_queue<int, vector<int>, greater<int>> nums;
    int orN = n;
    while(n--){
      int input;
      cin >> input;
      nums.push(input);
    }
    int sum = 0;
    while(nums.size()){
      int currSum = 0;
      currSum += nums.top();
      nums.pop();
      currSum += nums.top();
      nums.pop();
      sum += currSum;
      if(nums.size())
        nums.push(currSum);
    }
    cout<<sum<<'\n';
  }
}