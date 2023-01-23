#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int>& a,
  pair<string, int>& b)
{
    return a.second < b.second;
}
void sort(map<string, int>& M)
{
  
    vector<pair<string, int> > A;
  
    for (auto& it : M) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);
}

int iscapital(char x)
{
    if (x >='A' && x <= 'Z')    return 1;
    else  return 0;
}


int main()
{
    map<char, char> codes = {
      {'A', '2'},
      {'B', '2'},
      {'C', '2'},
      {'D', '3'},
      {'E', '3'},
      {'F', '3'},
      {'G', '4'},
      {'H', '4'},
      {'I', '4'},
      {'J', '5'},
      {'K', '5'},
      {'L', '5'},
      {'M', '6'},
      {'N', '6'},
      {'O', '6'},
      {'P', '7'},
      {'R', '7'},
      {'S', '7'},
      {'T', '8'},
      {'U', '8'},
      {'V', '8'},
      {'W', '9'},
      {'X', '9'},
      {'Y', '9'}
    };
    int M;
    cin>>M;
    int orM = M;
    cin.tie(NULL);
    while(M--){
      int N;
      cin>>N;
      map<string, int> phoneNumbers;
      while (N--)
      {
        string line;
        cin>>line;
        line.erase(remove(line.begin(), line.end(), '-'), line.end());
        string phoneNumber = "";
        for(int i = 0; i < line.length(); i++){
            if(i == 3) {
              phoneNumber += '-';
            }
            if(iscapital(line[i]) && line[i] != 'Q' && line[i] != 'Z'){
              phoneNumber += codes[line[i]];
            } else {
              phoneNumber += line[i];
            }
        }
        phoneNumbers[phoneNumber]++;
      }
      sort(phoneNumbers);
      int numberofphonesthatappearmorethanonce = 0;
      for(auto it : phoneNumbers){
        if(it.second > 1) {
          cout<<it.first<<" "<<it.second<<'\n';
          numberofphonesthatappearmorethanonce++;
        }
      }
      if(numberofphonesthatappearmorethanonce == 0){
        cout<<"No duplicates."<<'\n';
      }
      if(M) {
        cout<<'\n';
      }
    }
    return 0;
}
