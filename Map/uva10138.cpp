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
    vector<int> ratesByTimeOfTheDay;
    getline(cin, input);
    vector<string> ratesByTimeOfTheDayString = split(input, ' ');
    for (const string &str : ratesByTimeOfTheDayString) {
      stringstream ss(str);
      int rate;
      ss>>rate;
      ratesByTimeOfTheDay.push_back(rate);
    }
    map<string, double> carBill;
    map<string, vector<string>> carTimeAndType;
    map<string, vector<Record>> carRecords;
    while(getline(cin, input) && !input.empty()){
      vector<string> carTimeAndType = split(input, ' ');
      Record newRecord (stoi(carTimeAndType[1].substr(3,2)), stoi(carTimeAndType[1].substr(6,2)), stoi(carTimeAndType[1].substr(9,2)), carTimeAndType[2], stoi(carTimeAndType[3]));
      carRecords[carTimeAndType[0]].push_back(newRecord);
    }
    for(auto& it: carRecords){
      sort(carRecords[it.first].begin(), carRecords[it.first].end(), compareRecords);
      Record beforeRecord(0,0,0,"",0);
      for(auto& it2: carRecords[it.first]){
        if(it2.type == "exit" && beforeRecord.type == "enter"){
          int distance = abs(it2.startingPointKm-beforeRecord.startingPointKm);
          double rate = distance * ratesByTimeOfTheDay[beforeRecord.h] / 100.0;
          carBill[it.first] += rate + 1;
        }
        beforeRecord = it2;
      }
    }
    for(auto& it : carBill){
      it.second += 2;
      cout<<it.first<<" $"<< fixed << setprecision(2) <<it.second<<'\n';
    }
    if(T) cout<<'\n';
  }
  return 0;
}