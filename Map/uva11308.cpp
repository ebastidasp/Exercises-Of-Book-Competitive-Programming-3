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
  getline(cin, input);
  istringstream ss(input);
  int numberOfBinders;
  ss >> numberOfBinders;
  while(numberOfBinders--){
    getline(cin, input);
    string nameOfBinder = input;
    transform(nameOfBinder.begin(), nameOfBinder.end(), nameOfBinder.begin(), [](char c) {
      if (!isupper(c)) {
          return static_cast<char>(toupper(c)); // Convert to uppercase
      } else {
          return c;
      }
    });
    getline(cin, input);
    istringstream ss2(input);
    int numberOfIngredients, numberOfRecipes, budget;
    ss2 >> numberOfIngredients;
    ss2 >> numberOfRecipes;
    ss2 >> budget;
    map<string, int> ingredientPrice;
    map<string, int> recipePrice;
    while(numberOfIngredients--){
      getline(cin, input);
      vector<string> ingredientPriceVector = split(input, ' ');
      ingredientPrice[ingredientPriceVector[0]] = stoi(ingredientPriceVector[1]);
    }
    while(numberOfRecipes--){
      getline(cin, input);
      string recipeName = input;
      getline(cin, input);
      int numberOfIngredientsForRecipe = stoi(input);
      while(numberOfIngredientsForRecipe--){
        getline(cin, input);
        vector<string> ingredientForRecipeUnitsNeeded = split(input, ' ');
        recipePrice[recipeName] += ingredientPrice[ingredientForRecipeUnitsNeeded[0]] * stoi(ingredientForRecipeUnitsNeeded[1]);
      }
    }
    vector<pair<string, int>> recipePriceVector (recipePrice.begin(), recipePrice.end());
    sort(recipePriceVector.begin(), recipePriceVector.end(), [](const pair<string, int>& a, const pair<string, int>& b){
      if(a.second == b.second)
        return a.first < b.first;
      return a.second < b.second;
    });
    cout<<nameOfBinder<<'\n';
    int numberOfPossibleRecipes = 0;
    for(auto& it: recipePriceVector){
      if(it.second <= budget){
        cout<<it.first<<'\n';
        numberOfPossibleRecipes++;
      } else {
        break;
      }
    }
    if(!numberOfPossibleRecipes){
      cout<<"Too expensive!\n";
    }
    cout<<'\n';
  }
}