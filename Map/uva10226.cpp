#include <bits/stdc++.h>

using namespace std;

// Custom comparator function to compare strings by length
bool compareByLength(const string& str1, const string& str2) {
  return str1.length() < str2.length();
}

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

class Record {
  public:
    int d, h, m, min, startingPointKm;
    string type;

    Record(int _d, int _h, int _m, string _type, int _startingPointKm){
      d = _d, h = _h, m = _m, startingPointKm = _startingPointKm;
      type = _type;
    }
};

bool compareRecords (const Record& A, const Record& B){
  return A.m+A.h*60+A.d*60*24 < B.m+B.h*60+B.d*60*24; 
}

int main(){
  string s;
  getline(cin, s);
  size_t T;
  istringstream ss(s);
  ss >> T;
  getline(cin, s);
  map<int, int> minutesTillMonth;
  while(T--){
    string input;
    int count = 0;
    map<string, int> numberOfTreesPerSpecies;
    while(getline(cin, input) && !input.empty()){
      numberOfTreesPerSpecies[input]++;
      count++;
    }
    for(auto& it : numberOfTreesPerSpecies){
      cout<<it.first<<" "<< fixed << setprecision(4)<<it.second/(count*1.0)*100.0<<'\n';
    }
    if(T)
      cout<<'\n';
  }
  return 0;
}