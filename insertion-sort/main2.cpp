#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        
        int *numbers = new int[n];
        
        int shifts = 0;
        
        for(int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            numbers[i] = j;
            
            for(int k = 0; k < i; k++)
                if(numbers[k] > numbers[i]) shifts++;
        }
        
        delete [] numbers;
        
        cout << shifts << endl;
        
    }
    
    return 0;
}
