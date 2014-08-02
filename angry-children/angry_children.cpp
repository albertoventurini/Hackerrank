#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int>::iterator Iter;



int min_unfairness(vector<int>& packets, int k)
{  
    sort(packets.begin(), packets.end());

    if(k > packets.size())
        return *packets.end() - *packets.begin();
    
    int current_min = INT_MAX;
    
    Iter a = packets.begin();
    Iter b = packets.begin() + k - 1;
    
    while(b != packets.end())
    {
        int unfairness = *b - *a;
        
        if(unfairness < current_min) current_min = unfairness;
        a++;
        b++;
    }
    
    return current_min;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<int> packets;
    
    for(int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        
        packets.push_back(j);
    }
    
    int u = min_unfairness(packets, k);
    
    cout << u;    
    
    return 0;
}
