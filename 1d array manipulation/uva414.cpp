#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    bool cont = true;
    while (cont){
        cin>>N;
        cin.ignore();
        if(N == 0){
            cont = false;
            break;
        }
        vector<string> inputImage;
        vector<int> lengthOfVoid;
        string inputs;
        int originalN = N;
        int minNumber = 25;
        while(N--){
            getline(cin, inputs);
            inputImage.push_back(inputs);
        }
        for(int i = 0; i < originalN; i++){
            for(int j = 0; j < 25; j++){
                if(inputImage[i].at(j) == ' '){
                    for(int k = j+1; k < 25; k++){
                        if(inputImage[i][k] == 'X') {
                            lengthOfVoid.push_back(k-j);
                            minNumber = min(minNumber, k-j);
                            k = 25;
                        }
                    }
                    j = 25;
                } else if(j == 24){
                    lengthOfVoid.push_back(0);
                    minNumber = 0;
                }
            }
        }
        int sizeOfVoid = 0;
        for(int i = 0; i < originalN; i++){
            if( lengthOfVoid[i] > minNumber ){
                sizeOfVoid += lengthOfVoid[i] - minNumber;
            }
        }
        cout<<sizeOfVoid<<'\n';
    }

    return 0;
}