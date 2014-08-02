#include <iostream>
#include <map>
#include <assert.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    
    map<int, int> a;
    
    int j;
    for(int i = 0; i < n; i++)
    {
        cin >> j;
        
        if(a.find(j) == a.end())
            a[j] = 1;
        else
            a[j]++;
    }
    
    cin >> n;
    
    map<int, int> b;
    
    for(int i = 0; i < n; i++)
    {
        cin >> j;
        
        if(b.find(j) == b.end())
            b[j] = 1;
        else
            b[j]++;
    }
    
    
    map<int, int>::iterator a_it = a.begin();
    map<int, int>::iterator b_it = b.begin();
    
    int space = 0;
    
    while( b_it != b.end() )
    {
        while( (*b_it).first < (*a_it).first )
        {
            if(space == 0) space = 1; else cout << " ";
            cout << (*b_it).first;
            
            b_it++;
        }
        
        if( (*b_it).first == (*a_it).first )
        {
            if( (*b_it).second > (*a_it).second )
            {
                if(space == 0) space = 1; else cout << " ";
                cout << (*b_it).first;
            }
            
            a_it++;
            b_it++;
        }
        
        //else if( (*b_it).first >  (*a_it).first )
        //    assert(0);
    }
    
    cout << endl;
    
    return 0;
}
