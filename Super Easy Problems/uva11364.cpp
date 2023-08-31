#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    int N;
    cin>>N;
    int max = 0, min = 99;
    int input;
    vector<int> arr;
    while(N--){
      cin>>input;
      if(input > max)
        max = input;
      if(input < min)
        min = input;
      arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 1; i < arr.size(); i++){
      sum += arr[i] - arr[i - 1];
    }
    sum += ((max - min)/2 - arr[0]) + (arr[arr.size() - 1] - (max - min)/2);
    cout<<sum<<'\n';
  }
}