#include <bits/stdc++.h>

using namespace std;

int main(){
  double arr[4];
  while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3] && (arr[0] || arr[1] || arr[2] || arr[3])){
    double sum = 0;
    if(arr[1] > arr[0])
      sum += 720 + (40 - arr[1] + arr[0])/40*360;
    else
      sum += 720 + (arr[0] - arr[1])/40*360;
    if(arr[2] > arr[1])
      sum += 360 + (arr[2] - arr[1])/40*360;
    else
      sum += 360 + (40 - arr[1] + arr[2])/40*360;
    if(arr[3] > arr[2])
      sum += (40 - arr[3] + arr[2])/40*360;
    else
      sum += (arr[2] - arr[3])/40*360;
    cout<<sum<<'\n';
  }
}