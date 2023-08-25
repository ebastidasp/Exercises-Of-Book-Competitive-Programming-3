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
  long long T;
  cin>>T;
  while(T--){
    int A, U;
    cin>>A>>U;
    vector<long long> elements;
    for(int i = 0; i < A; i++){
      long long numberInput;
      cin>>numberInput;
      elements.push_back(numberInput);
    }
    multiset<long long> elementsMset;
    multiset<long long>::iterator it;
    elementsMset.insert(elements[0]);
    it = elementsMset.begin();
    int eIndex = 1;
    int uIndex;
    bool first = true;
    for(int i = 0; i < U; i++){
      cin >> uIndex;
      while(uIndex > eIndex){
        elementsMset.insert(elements[eIndex]);
        if(elements[eIndex] < *it){
          it--;
        }
        eIndex++;
      }
      if(first){
        it = elementsMset.begin();
        first = false;
      } else {
        it++;
      }

      cout << *it << '\n';
    }
    if(T) cout<<'\n';
  }
  return 0;
}