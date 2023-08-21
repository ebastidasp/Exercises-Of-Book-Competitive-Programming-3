#include <bits/stdc++.h>

using namespace std;

int main(){
  int T;
  int caseId = 1;
  cin>>T;
  while(T--){
    int friends;
    cin>>friends;
    int totalFriends = friends;
    int totalNumberOfUniqueStamps = 0;
    map<string, int> numberOfDifferentPeopleThisStampIsOwnedBy;
    map<string, vector<int>> stampsPerPerson;
    map<string, int> numberOfUniqueStampsPerPerson;
    int personId = 1;
    while(friends--){
      int numberOfStamps;
      cin>>numberOfStamps;
      vector<int> stampsThisPersonHas;
      map<string, bool> stampAlreadyCheckedForThisPerson;
      while(numberOfStamps--){
        int stamp;
        cin>>stamp;
        stampsThisPersonHas.push_back(stamp);
        if(!stampAlreadyCheckedForThisPerson[to_string(stamp)]){
          numberOfDifferentPeopleThisStampIsOwnedBy[to_string(stamp)]++;
          stampAlreadyCheckedForThisPerson[to_string(stamp)] = true;
        }
      }
      stampsPerPerson[to_string(personId++)] = stampsThisPersonHas;
    }
    for(auto& it: numberOfDifferentPeopleThisStampIsOwnedBy){
      if(it.second == 1){
        for(auto& it2 : stampsPerPerson){
          if(count(it2.second.begin(), it2.second.end(), stoi(it.first)) > 0){
            numberOfUniqueStampsPerPerson[it2.first]++;
            totalNumberOfUniqueStamps++;
            break;
          }
        }
      }
    }
    cout<<"Case "<<caseId++<<": ";
    cout<<fixed<<setprecision(6)<<numberOfUniqueStampsPerPerson["1"]/(totalNumberOfUniqueStamps*1.0)*100<<"%";
    for(int i = 2; i <= totalFriends; i++){
      cout<<" "<<fixed<<setprecision(6)<<numberOfUniqueStampsPerPerson[to_string(i)]/(totalNumberOfUniqueStamps*1.0)*100<<"%";
    }
    cout<<'\n';
  }
}