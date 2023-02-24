#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> waysToFactorizeNumber;

void split(const string &s, char delim, vector<int> &elems) {
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    elems.push_back(stoi(item));
  }
}


vector<int> split(const string &s, char delim) {
  vector<int> elems;
  split(s, delim, elems);
  return elems;
}

bool isPrime(int num){
  bool flag=true;
  for(int i = 2; i <= num / 2; i++) {
    if(num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}

void solve(int n, string currVector, int originalNumber, int start){
  string actualCurrentVector = currVector;
  if(isPrime(n) && n != 1) {
    if(actualCurrentVector.length() > 0)
      actualCurrentVector += " ";
    actualCurrentVector += to_string(n);
  }
  else
    for(int i = start; i <= n; i++){
      if(n % i == 0) {   
        if(actualCurrentVector.length() > 0){
          solve(n/i, actualCurrentVector+" "+to_string(i), originalNumber, i);
        }
        else{
          solve(n/i, actualCurrentVector+to_string(i), originalNumber, i);
        }    
      }
    }
  vector<int> numbers = split(actualCurrentVector, ' ');
  sort(numbers.begin(), numbers.end());
  int productOfNumbers = 1;
  for(int i = 0; i < numbers.size(); i++){
    productOfNumbers *= numbers[i];
  }
  if(productOfNumbers == originalNumber && numbers.size() > 1) {
    string factorization = to_string(numbers[0]);
    for(int i = 1; i < numbers.size(); i++){
      factorization += " "+to_string(numbers[i]);
    }
    vector<int> individualNumbers = split(factorization, ' ');
    if(count(waysToFactorizeNumber.begin(), waysToFactorizeNumber.end(), individualNumbers) == 0) {
      waysToFactorizeNumber.push_back(individualNumbers);
    }
  }
}

bool cmp(vector<int>& a,
  vector<int>& b)
{
  int minSize = min(a.size(), b.size());
  for(int i = 0; i < minSize; i++){
    if(a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return true;
}

int main() {
  int input;
  cin.tie(NULL);
  while(cin>>input && input != 0) {
    if(isPrime(input))
      cout<<"0\n";
    else{
      waysToFactorizeNumber.clear();
      string aux ="";
      solve(input, aux, input, 2);
      sort(waysToFactorizeNumber.begin(), waysToFactorizeNumber.end(), cmp);
      cout<<waysToFactorizeNumber.size()<<'\n';
      for(int i = 0; i < waysToFactorizeNumber.size(); i++){
        cout<<waysToFactorizeNumber[i][0];
        for(int j = 1; j < waysToFactorizeNumber[i].size(); j++)
          cout<<" "<<waysToFactorizeNumber[i][j];
        cout<<'\n';
      }
    }
  }
  return 0;
}