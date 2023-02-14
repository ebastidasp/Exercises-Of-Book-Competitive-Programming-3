#include <bits/stdc++.h>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(item);
  }
}


vector<string> split(const string &s, char delim) {
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

bool sortStrings (const string & a, const string & b) {
  return (a+b) > (b+a);
}

int main(){
  int n;
  while(cin>>n, n){
    vector<string> inputStrings;
    string input, sol;
    cin.ignore();
    getline(cin, input);
    inputStrings = split(input, ' ');
    sort(inputStrings.begin(), inputStrings.end(), sortStrings);
    for(int i = 0; i < inputStrings.size(); i++)
      cout<<inputStrings[i];
    cout<<'\n';
  }

  return 0;
}