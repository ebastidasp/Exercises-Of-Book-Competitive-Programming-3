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

bool comparePairStringInt(const pair<string, int>& a, const pair<string, int>& b){
  return a.second > b.second;
}

int main(){
  string input;
  while(getline(cin, input) && input != "0"){
    istringstream ss (input);
    int numberOfCourseCombinations;
    ss>>numberOfCourseCombinations;
    map<string, int> frequencyOfCourseCombinations;
    while(numberOfCourseCombinations--){
      getline(cin, input);
      vector<string> coursesInCombination = split(input, ' ');
      sort(coursesInCombination.begin(), coursesInCombination.end());
      string combination = "";
      for(auto& it: coursesInCombination){
        combination += it;
      }
      frequencyOfCourseCombinations[combination]++;
    }
    vector<pair<string, int>> frequencyOfCourseCombinationsVector (frequencyOfCourseCombinations.begin(), frequencyOfCourseCombinations.end());
    sort(frequencyOfCourseCombinationsVector.begin(), frequencyOfCourseCombinationsVector.end(), comparePairStringInt);
    int targetValue = frequencyOfCourseCombinationsVector[0].second;
    int numberOfStudentsTakingSomeCourseCombinationMostPopular = count_if(frequencyOfCourseCombinationsVector.begin(), frequencyOfCourseCombinationsVector.end(),
      [targetValue](const std::pair<std::string, int>& element) {
          return element.second == targetValue;
      });
    cout<<numberOfStudentsTakingSomeCourseCombinationMostPopular * targetValue<<'\n';
  }
}