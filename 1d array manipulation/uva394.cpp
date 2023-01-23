#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r;
    cin>>n>>r;
    vector <string> names;
    vector <int> bases;
    vector <int> sizeBitsV;
    vector <int> Dimensions;
    vector <vector<pair<int, int>>> lowerUpperBoundOfDimensions;
    
    while(n--){
        string name;
        int base, sizeBits, D;
        cin>>name;
        cin>>base>>sizeBits>>D;
        vector<pair<int, int>> lowerUpperBoundOfDimension;
        Dimensions.push_back(D);
        while(D--){
            int l, u;
            cin>>l>>u;
            pair <int, int> lowerUpper;
            lowerUpper.first = l;
            lowerUpper.second = u;
            lowerUpperBoundOfDimension.push_back(lowerUpper);
        }
        names.push_back(name);
        bases.push_back(base);
        sizeBitsV.push_back(sizeBits);
        lowerUpperBoundOfDimensions.push_back(lowerUpperBoundOfDimension);
    }
    
    while(r--){
        string nameOfArray;
        cin>>nameOfArray;
        for(int i = 0; i < names.size(); i++){
            if(names[i] == nameOfArray){
                vector < int > indexes;
                int index;
                for(int j = 0; j < Dimensions[i]; j++){
                    cin>>index;
                    indexes.push_back(index);
                }
                vector<int> c(Dimensions[i] + 1);
                c[Dimensions[i]] = sizeBitsV[i];
                int substractionC0 = -1*c[Dimensions[i]]*lowerUpperBoundOfDimensions[i][Dimensions[i]-1].first;
                for(int k = Dimensions[i] - 1; k > 0; k--){
                    c[k] = c[k+1]*(lowerUpperBoundOfDimensions[i][k].second - lowerUpperBoundOfDimensions[i][k].first + 1);
                    substractionC0 -= c[k]*lowerUpperBoundOfDimensions[i][k-1].first;
                }
                c[0] = bases[i] + substractionC0;
                int answer = c[0];
                for(int k = 1; k < c.size(); k++) {
                    answer += c[k]*indexes[k-1];
                }
                string stringAnswer = names[i]+"[";
                for(int k = 0; k < Dimensions[i] - 1; k++){
                    stringAnswer = stringAnswer + to_string(indexes[k]) + ", ";
                }
                stringAnswer = stringAnswer + to_string(indexes[Dimensions[i] - 1]) + "] = " + to_string(answer);
                cout<<stringAnswer<<'\n';
            }
        }
    }

    return 0;
}
