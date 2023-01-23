#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M;
    cin>>M;
    while(M--){
        int N, K;
        cin>>N>>K;
        vector<bool> isFalseCoin (N, true);
        while (K--){
            int P;
            cin>>P;
            vector<int> left, right;
            for(int i = 0; i < P; i++){
                int leftNumber;
                cin>>leftNumber;
                left.push_back(leftNumber);
            }
            
            for(int i = 0; i < P; i++){
                int rightNumber;
                cin>>rightNumber;
                right.push_back(rightNumber);
            }
            char result;
            cin>>result;
            switch (result){
                case '<':
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < P; j++){
                        if(right[j] == i+1){
                            j = P;
                            break;
                        } else if (j == P-1){
                            isFalseCoin[j] = false;
                        }
                    }
                }
                break;
                case '>':
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < P; j++){
                        if(left[j] == i+1){
                            j = P;
                            break;
                        } else if (j == P-1){
                            isFalseCoin[j] = false;
                        }
                    }
                }
                break;
                case '=':
                for(int i = 0; i < P; i++){
                    isFalseCoin[right[i]-1] = false;
                    isFalseCoin[left[i]-1] = false;
                }
                break;
            }
        }
        vector<int> falseCoin;
        for(int i = 0; i < N; i++){
            if(isFalseCoin[i]){
                falseCoin.push_back(i+1);
            }
        }
        if(N < 3) {
            cout<<0<<'\n';
        }
        else if(falseCoin.size() == 1)
            cout<<falseCoin[0]<<'\n';
        else
            cout<<0<<'\n';
        cout<<'\n';
    }

    return 0;
}
