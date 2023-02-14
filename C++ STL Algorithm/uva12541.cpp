#include <bits/stdc++.h>

using namespace std;

class person {
  public:
    string name;
    int day, month, year;
    person (string _name, int _day, int _month, int _year) {
      name = _name;
      day = _day;
      month = _month;
      year = _year;
    }
};

bool sortPeople (const person &a, const person &b) {
  if (a.year == b.year) {
    if(a.month == b.month) {
      return a.day > b.day;
    }
    return a.month > b.month;
  }
  return a.year > b.year;
}

int main(){
  int numberofpeople;
  cin>>numberofpeople;
  int orNumberOfPeople = numberofpeople;
  vector <person> people;
  while(numberofpeople--) {
    string n;
    int d, m, y;
    cin>>n;
    cin>>d>>m>>y;
    person newPerson (n, d, m, y);
    people.push_back(newPerson);
  }
  sort(people.begin(), people.end(), sortPeople);
  cout<<people[0].name<<'\n';
  cout<<people[orNumberOfPeople-1].name<<'\n';
  return 0;
}