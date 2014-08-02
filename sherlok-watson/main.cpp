#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, K, Q;
    cin >> N >> K >> Q;
    
    vector<int> A;
    
    int k;
    for(int i = 0; i < N; i++)
    {
        cin >> k;
        A.push_back(k);
    }
    
    for(int i = 0; i < N; i++)
        A.push_back(A[i]);

    int x;
    for(int i = 0; i < Q; i++)
    {
        cin >> x;
        
        /*if(x < K)
            cout << A[x + N - K];
        else
            cout << A[x - K];*/
        
        cout << A[x + N - K];
        
        cout << endl;
    }
    
    return 0;
}
