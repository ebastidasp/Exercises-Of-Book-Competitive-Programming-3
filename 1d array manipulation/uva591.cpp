#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int setId = 1;
    while (cin>>n){
        if(n == 0) break;
        vector <int> heights;
        int sumOfHeights = 0;
        for(int i = 0; i < n; i++){
            int input;
            cin>>input;
            sumOfHeights += input;
            heights.push_back(input);
        }
        int avg = sumOfHeights/n;
        int sumOfDiffs = 0;
        for(int i = 0; i < n; i++){
            sumOfDiffs += abs(avg - heights[i]);
        }
        cout<<"Set #"<<setId<<'\n';
        cout<<"The minimum number of moves is "<<sumOfDiffs/2<<"."<<'\n';
        setId++;
        cout<<'\n';
    }

    return 0;
}
