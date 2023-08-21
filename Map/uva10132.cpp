#include <bits/stdc++.h>

using namespace std;

// Custom comparator function to compare strings by length
bool compareByLength(const string& str1, const string& str2) {
  return str1.length() < str2.length();
}


int main(){
  string s;
  getline(cin, s);
  size_t T;
  istringstream ss(s);
  ss >> T;
  getline(cin, s);
  while(T--){
    string input;
    map<string, vector<string>> fileFragmentPossibleFileFragments;
    vector<string> fileFragments;
    int totalBits = 0;
    while(getline(cin, input) && !input.empty()){
      totalBits += input.length();
      fileFragments.push_back(input);
    }
    map<string, int> frequencyOfBitset;
    // Sorting the vector using the custom comparator
    sort(fileFragments.begin(), fileFragments.end(), compareByLength);
    int bitsPerFile = totalBits / (fileFragments.size() / 2);
    int lastIndexNotReviewed = fileFragments.size()-1;
    int i = 0;
    while(i < lastIndexNotReviewed){
      int lengthOfStringOfLastIndexNotReviewed = fileFragments[lastIndexNotReviewed].length();
      for(int j = lastIndexNotReviewed; fileFragments[j].length() == lengthOfStringOfLastIndexNotReviewed; j--){
        fileFragmentPossibleFileFragments[fileFragments[i]].push_back(fileFragments[j]);
        lastIndexNotReviewed--;
      }
      int aux = i;
      while(fileFragments[aux].length() == fileFragments[aux+1].length()){
        fileFragmentPossibleFileFragments[fileFragments[aux+1]] = fileFragmentPossibleFileFragments[fileFragments[aux]];
        aux++;
      }
      if(aux > i){
        i = aux + 1;
      } else {
        i++;
      }
    }
    vector<pair<string, vector<string>>> sortedMap(fileFragmentPossibleFileFragments.begin(), fileFragmentPossibleFileFragments.end());
    sort(sortedMap.begin(), sortedMap.end(), [](const pair<string, vector<string>>& a, const pair<string, vector<string>>& b) {
        return a.second.size() < b.second.size();
    });
    for(auto& it : sortedMap){
      for(int i = 0; i < it.second.size(); i++){
        string result;
        result = it.first+it.second[i];
        frequencyOfBitset[result]++;
        result = it.second[i]+it.first;
        frequencyOfBitset[result]++;
      }
    }
    // Convert the map to a vector of pairs
    vector<pair<string, int>> vecFrequency(frequencyOfBitset.begin(), frequencyOfBitset.end());

    // Define a custom comparator to sort by values (the second element of the pair)
    auto customComparator = [](const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second;
    };

    // Sort the vector using the custom comparator
    sort(vecFrequency.begin(), vecFrequency.end(), customComparator);
    cout<<vecFrequency[vecFrequency.size()-1].first<<'\n';
    if(T > 0)
      cout<<'\n';
  }
  return 0;
}