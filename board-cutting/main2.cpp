#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


void pick_elem_from_x(list<int>& x, int& cost, int& xm, int& ym)
{
    cost += xm * x.back();
    x.pop_back();
    ym++;
}


void pick_elem_from_y(list<int>& y, int& cost, int& xm, int& ym)
{
    cost += ym * y.back();
    y.pop_back();
    xm++;
}


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
        
        sort(y.begin(), y.end());
        sort(x.begin(), x.end());
        
        int xm = 1; // x multiplication factor
        int ym = 1; // y multiplication factor
        
        int cost = 0;
        
        while(!(x.empty() && y.empty()))
        {           
            if(x.empty())
                pick_elem_from_y(y, cost, xm, ym);
            else if(y.empty())
                pick_elem_from_x(x, cost, xm, ym);
            
            else if(y.back() * ym >= x.back() * (xm + 1))
                pick_elem_from_y(y, cost, xm, ym);
            //else if(x.back() * xm > y.back() * ym)
            else
                pick_elem_from_x(x, cost, xm, ym);

        }
        
        cout << cost << endl;
        
    }
    
    return 0;
}
