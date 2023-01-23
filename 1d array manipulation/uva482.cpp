#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string line;
    scanf("%d", &t);
    getchar();
    while(t--){
        getchar();
        getline(cin,line);
        stringstream ss(line);
        map<int,string> array;
        int individualNumber;
        vector<int> indexes;
        while(ss>>individualNumber){
            indexes.push_back(individualNumber);
        }
        getline(cin, line);
        stringstream ss2(line);
        string individualFloat;
        int i = 1;
        while(ss2>>individualFloat){
            array[indexes[i-1]] = individualFloat;
            i++;
        }
        for(int j = 1; j < i; j++){
            cout<<array[j]<<'\n';
        }
        if(t) cout<<'\n';
    }

    return 0;
}
