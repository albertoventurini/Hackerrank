#include <iostream>
#include <set>


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
        
        set<unsigned int> duplicates;
        
        for(j = i + 1; j < N; j++)
        {
            if(numbers[j] > numbers[i] && duplicates.find(numbers[j]) == duplicates.end())
            {
                duplicates.insert(numbers[j]);
                duplets_cache[i]++;
            }
        }
        /*
        j = i + 1;
        while(numbers[j] == numbers[i])
            j++;*/
        duplets_cache[i] += duplets(i + 1);
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
        for(j = i + 1; j < N; j++)
            if(numbers[j] > numbers[i]) triplets_cache[i] += duplets(j);
        
        j = i + 1;
        while(numbers[j] == numbers[i])
            j++;
        triplets_cache[i] += triplets(j);
    }
    
    return triplets_cache[i];
}



int main()
{
    cin >> N;
    
    numbers = new unsigned int[N];
    duplets_cache = new int[N];
    triplets_cache = new int[N];
    
    int k;
    for(int i = 0; i < N; i++)
    {
        cin >> k;

        numbers[i] = k;
        duplets_cache[i] = -1;
        triplets_cache[i] = -1;
    }
    
    for(int i = 0; i < N; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    cout << duplets(5) << endl;
    
    return 0;
}
