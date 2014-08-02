#include <iostream>
#include <set>

using namespace std;

unsigned int *numbers;
int N;

int triplets()
{
    int count = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            for(int k = j + 1; k < N; k++)
            {
                if(numbers[i] < numbers[j] && numbers[j] < numbers[k])
                    count ++;
            }
        }
        
    }
    
    return count;
}


int main()
{
    int n;
    cin >> n;
    
    numbers = new unsigned int[n];
    
    set<unsigned int> unique_numbers;
    
    int k;
    N = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        
        if(unique_numbers.find(k) == unique_numbers.end())
        {
            unique_numbers.insert(k);
            numbers[N] = k;
            N++;
        }
    }
    
    cout << triplets() << endl;
    
    return 0;
}
