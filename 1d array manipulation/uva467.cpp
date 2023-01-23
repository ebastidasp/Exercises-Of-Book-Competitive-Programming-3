#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int idSet = 1;
    while(getline(cin, line)){
        int minCycle = 90;
        vector<int> timings;
        stringstream ss(line);
        int individualTime;
        while(ss >> individualTime){
            timings.push_back(individualTime);
            minCycle = min(minCycle, individualTime);
        }
        bool allCantBeGreenAgain = true;
        for(int i = 2*minCycle; i <= 3600; i++){
            bool allGreen = true;
            for(int j = 0; j < timings.size(); j++){
                if(i/timings[j] % 2 != 0 || (i % timings[j]) >= (timings[j] - 5)){
                    allGreen = false;
                    break;
                }
            }
            if(allGreen){
                cout<<"Set "<<idSet<<" synchs again at "<<i/60<<" minute(s) and "<<i%60<<" second(s) after all turning green."<<'\n';
                allCantBeGreenAgain = false;
                break;
            }
        }
        if(allCantBeGreenAgain){
            cout<<"Set "<<idSet<<" is unable to synch after one hour."<<'\n';
        }
        idSet++;
    }

    return 0;
}
