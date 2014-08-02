#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int M, N;
        cin >> M >> N;
        
        list<unsigned long long> y;
        list<unsigned long long> x;
        
        unsigned long long k;
        
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
        
        y.sort();
        x.sort();
        
        unsigned long long xm = 1; // x multiplication factor
        unsigned long long ym = 1; // y multiplication factor
        
        unsigned long long cost = 0;
        
        while(!(x.empty() && y.empty()))
        {           
            if(x.empty())
            {
                cost += ym * y.back();
                y.pop_back();
                xm++;
            }
            else if(y.empty())
            {
                cost += xm * x.back();
                x.pop_back();
                ym++;
            }
            
            else if(y.back() >= x.back())
            {
                cost += ym * y.back();
                y.pop_back();
                xm++;
            }
            else
            {
                cost += xm * x.back();
                x.pop_back();
                ym++;
            }
        }
        
        cost %= 1000000007;
        
        cout << cost << endl;
        
    }
    
    return 0;
}
