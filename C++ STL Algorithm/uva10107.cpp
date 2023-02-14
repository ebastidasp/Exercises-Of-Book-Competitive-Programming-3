#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector <int> values;
  int input;
  cin.tie(NULL);
  while(cin>>input){
    values.push_back(input);
    sort(values.begin(), values.end());
    if(values.size() % 2 == 1) {
      cout<<values[values.size()/2]<<'\n';
    } else {
      int val = (values[values.size()/2] + values[values.size()/2-1])/2;
      cout<<val<<'\n';
    }
  }
  return 0;
}