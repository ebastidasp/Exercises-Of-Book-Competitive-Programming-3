#include <bits/stdc++.h>

using namespace std;

bool sortbyLastName(const pair<string, vector<string>> &a,
  const pair<string, vector<string>> &b)
{
  return (a.first < b.first);
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

int main()
{
  int numDepartments;
  cin>>numDepartments;
  cin.ignore();
  vector<pair<string, vector<string>>> people;
  while(numDepartments--){
    string nameOfDepartment;
    getline(cin, nameOfDepartment);
    string input;
    while (getline(cin, input) && input.size() > 0) {
      vector<string> data = split(input, ',');
      string lastname = data[2];
      data.erase(data.begin()+2);
      data.push_back(nameOfDepartment);
      pair<string, vector<string>> ps;
      ps.first = lastname;
      ps.second = data;
      people.push_back(ps);
    }
  }
  sort(people.begin(), people.end(), sortbyLastName);
  for(int i = 0; i < people.size(); i++) {
    cout<<"----------------------------------------\n";
    cout<<people[i].second[0]<<" "<<people[i].second[1]<<" "<<people[i].first<<'\n';
    cout<<people[i].second[2]<<'\n';
    cout<<"Department: "<<people[i].second[6]<<'\n';
    cout<<"Home Phone: "<<people[i].second[3]<<'\n';
    cout<<"Work Phone: "<<people[i].second[4]<<'\n';
    cout<<"Campus Box: "<<people[i].second[5]<<'\n';
  }
  return 0;
}
