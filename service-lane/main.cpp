#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int largest_vehicle(int i, int j, int* width)
{
    int min = 3;
    
    for(int k = i; k <= j; k++)
        if(width[k] < min) min = width[k];
    
    return min;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, t;
    cin >> n;
    cin >> t;
    
    int* width = new int[n];
    int w;
    
    for(int i = 0; i < n; i++)
    {
        cin >> w;
        width[i] = w;
    }
    
    int i, j;
    
    for(int k = 0; k < t; k++)
    {
        cin >> i;
        cin >> j;
        cout << largest_vehicle(i, j, width);
    }
    
    free [] width;
    
    return 0;
}
