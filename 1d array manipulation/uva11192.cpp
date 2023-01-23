#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while(cin>>n){
    if(n == 0) return 0;
    string line;
    cin>>line;
    int lengthOfString = line.length() / n;
    vector<string> output;
    int start = 0;
    while(n--){
      output.push_back(line.substr(start, lengthOfString));
      for(int i = 0; i < output[output.size()-1].length() / 2; i++){
        swap(output[output.size()-1][i], output[output.size()-1][output[output.size()-1].length() - i -1]);
      }
      start += lengthOfString;
    }
    for(int i = 0; i < output.size(); i++){
      cout<<output[i];
    }
    cout<<'\n';
  }
  return 0;
}
