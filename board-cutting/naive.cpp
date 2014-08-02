#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int M, N;
        cin >> M >> N;
        
        vector<int> y;
        vector<int> x;
        
        int k;
        
        for(int i = 0; i < M - 1; i++)
        {
            cin >> k;
            y.push_back(k);
        }
        
        for(int i = 0; i < N - 1; i++)
        {
            cin >> k;
            x.push_back(k);
        }
        
        int xm = 1; // x multiplication factor
        int ym = 1; // y multiplication factor
        
        int min = INT_MAX;
        
        
        
    }
    
    
    return 0;
}
