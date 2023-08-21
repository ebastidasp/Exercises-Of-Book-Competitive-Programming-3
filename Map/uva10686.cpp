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

int main(){
  string s;
  getline(cin, s);
  size_t T;
  istringstream ss(s);
  ss >> T;
  while(T--){
    map<string, vector<string>> wordsCategory;
    map<string, int> minNumberOfWordsCategory;
    vector<string> categories;
    getline(cin, s);
    size_t numberOfCategories;
    istringstream ss(s);
    ss >> numberOfCategories;
    while(numberOfCategories--){
      getline(cin, s);
      istringstream ss(s);
      string word;
      vector<string> categoryWords;
      while(ss>>word){
        categoryWords.push_back(word);
      }
      categories.push_back(categoryWords[0]);
      minNumberOfWordsCategory[categoryWords[0]] = stoi(categoryWords[2]);
      int numberOfWordsCategory = stoi(categoryWords[1]);
      while(numberOfWordsCategory--){
        getline(cin, s);
        istringstream ss(s);
        string anotherWord;
        ss>>anotherWord;
        if(count(wordsCategory[categoryWords[0]].begin(), wordsCategory[categoryWords[0]].end(), anotherWord) == 0)
          wordsCategory[categoryWords[0]].push_back(anotherWord);
      }
    }
    string problemDescription = "";
    while(getline(cin, s) && !s.empty()){
      transform(s.begin(), s.end(), s.begin(), [](char c) {
        if (!isalpha(c)) {
            return ' '; // Replace non-letter characters with a space
        } else {
            return c;   // Keep alphabetic characters as-is
        }
      });
      problemDescription += s + " ";
    }
    vector<string> wordsInProblemDescription;
    istringstream ss2(problemDescription);
    string wordProblemDescription;
    while(ss2>>wordProblemDescription){
      wordsInProblemDescription.push_back(wordProblemDescription);
    }
    map<string, int> numberOfDifferentWordsOfEachCategoryInProblemDescription;
    for(auto& itMap : wordsCategory){
      for(auto& itVector : wordsCategory[itMap.first]){
        if(count(wordsInProblemDescription.begin(), wordsInProblemDescription.end(), itVector) > 0){
          numberOfDifferentWordsOfEachCategoryInProblemDescription[itMap.first]++;
        }
      }
    }
    int difNumberOfCategories = 0;
    for(auto& itCategories : categories){
      if(numberOfDifferentWordsOfEachCategoryInProblemDescription[itCategories] >= minNumberOfWordsCategory[itCategories] || minNumberOfWordsCategory[itCategories] == 0){
        if(difNumberOfCategories > 0){
          cout<<","<<itCategories;
        } else {
          cout<<itCategories;
        }
        difNumberOfCategories++;
      }
    }
    if(difNumberOfCategories == 0)
      cout<<"SQF Problem.";
    cout<<'\n';
  }
}