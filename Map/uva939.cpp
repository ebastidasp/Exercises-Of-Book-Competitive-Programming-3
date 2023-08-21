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
  int n;
  cin>>n;
  cin.get();
  map<string, string> nameGene;
  map<string, pair<string, string>> parents;
  while(n--){
    string input;
    getline(cin, input);
    vector<string> nameAndGeneOrSon = split(input, ' ');
    if(nameAndGeneOrSon[1] != "non-existent" && nameAndGeneOrSon[1] != "dominant" && nameAndGeneOrSon[1] != "recessive"){
      if(parents.find(nameAndGeneOrSon[1]) != parents.end()){
        parents[nameAndGeneOrSon[1]].second = nameAndGeneOrSon[0];
      } else {
        parents[nameAndGeneOrSon[1]].first = nameAndGeneOrSon[0];
      }
    } else {
      nameGene[nameAndGeneOrSon[0]] = nameAndGeneOrSon[1];
    }
  }
  while(parents.size() > 0){
    for(map<string, pair<string, string>>::iterator it = parents.begin(); it != parents.end(); ++it){
      pair<string, string> genesOfParents;
      if(nameGene.find(it->second.first) != nameGene.end()){
        genesOfParents.first = nameGene[it->second.first];
        if(nameGene.find(it->second.second) != nameGene.end()){
          genesOfParents.second = nameGene[it->second.second];
          if (genesOfParents.first > genesOfParents.second) {
            swap(genesOfParents.first, genesOfParents.second);
          }
          if((genesOfParents.first == "recessive" && genesOfParents.second == "recessive") || (genesOfParents.first == "dominant" && genesOfParents.second == "non-existent")) {
            nameGene[it->first] = "recessive";
          } else if((genesOfParents.first == "dominant" && genesOfParents.second == "recessive") || (genesOfParents.first == "dominant" && genesOfParents.second == "dominant")){
            nameGene[it->first] = "dominant";
          } else {
            nameGene[it->first] = "non-existent";
          }
          parents.erase(it->first);
          break;
        } else {
          continue;
        }
      } else {
        continue;
      }
    }
  }
  vector<pair<string, string>> sortedNameGeneVec(nameGene.begin(), nameGene.end());
  // Sort the vector based on the keys (first element of the pair)
  sort(sortedNameGeneVec.begin(), sortedNameGeneVec.end());

  // Print the sorted vector
  for (const auto& entry : sortedNameGeneVec) {
      cout << entry.first << " " << entry.second << endl;
  }

  return 0;
}