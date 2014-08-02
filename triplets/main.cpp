#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int n_numbers;
unsigned int *numbers;
unsigned int *triplets_cache;
unsigned int *duplets_cache;


int monoplets(int i)
{
    if(i >= n_numbers)
        return 0;
    else
        return n_numbers - i;
}


int duplets(int i)
{
    if(i >= n_numbers - 1)
        return 0;

    if(duplets_cache[i] == -1)
        duplets_cache[i] = monoplets(i+1) + duplets(i+1);
    
    return duplets_cache[i];
}


int triplets(int i)
{
    if(i >= n_numbers - 2)
        return 0;
    
    if(triplets_cache[i] == -1)
        triplets_cache[i] = duplets(i+1) + triplets(i+1);
    
    return triplets_cache[i];
}



int main()
{
    int N;
    cin >> N;
    
    set<unsigned int> number_set;
    
    int k;    
    for(int i = 0; i < N; i++)
    {
        cin >> k;
        number_set.insert(k);
    }
    
    vector<unsigned int> number_vector;
    
    number_vector.assign(number_set.begin(), number_set.end());
    n_numbers = number_vector.size();
    
    numbers = &number_vector[0];
    
    duplets_cache = new unsigned int[n_numbers];
    triplets_cache = new unsigned int[n_numbers];
    
    for(int i = 0; i < n_numbers; i++)
    {
        duplets_cache[i] = -1;
        triplets_cache[i] = -1;
    }
    
    for(int i = 0; i < n_numbers; i++)
        cout << numbers[i] << " ";
    
    cout << endl;

    
    cout << triplets(2) << endl;
    
    return 0;
}
