#include <iostream>
#include <set>
#include <climits>


int *duplets_cache;
int *triplets_cache;
unsigned int *numbers;
int N;


using namespace std;

int duplets(int i)
{
    if(i >= N - 1)
        return 0;
    
    if(duplets_cache[i] == -1)
    {
        duplets_cache[i] = 0;
        
        int j;
        for(j = i + 1; j < N; j++)
            if(numbers[j] > numbers[i]) duplets_cache[i]++;
        
        //duplets_cache[i] += duplets(i + 1);
    }
    
    return duplets_cache[i];
}


int triplets(int i)
{
    if(i >= N - 2)
        return 0;
    
    if(triplets_cache[i] == -1)
    {
        triplets_cache[i] = 0;
        
        int j;
        int min = INT_MAX;
        int min_j = N;
        
        for(j = i + 1; j < N; j++)
            if(numbers[j] > numbers[i]) triplets_cache[i] += duplets(j);
        
        triplets_cache[i] += triplets(i + 1);
    }
    
    return triplets_cache[i];
}



int main()
{
    int n;
    cin >> n;
    
    numbers = new unsigned int[n];
    duplets_cache = new int[n];
    triplets_cache = new int[n];
    
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
            duplets_cache[N] = -1;
            triplets_cache[N] = -1;
            N++;
        }
    }
    
    cout << triplets(0) << endl;
    
    return 0;
}
