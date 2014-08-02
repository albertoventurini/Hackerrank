#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

/*
list<int> find_pairs(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    
    int min_distance = INT_MAX;
    int distance;
    
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        distance = abs(numbers[i] - numbers[i+1]);
        if(distance < min_distance)
            min_distance = distance;
    }

    list<int> result;
    
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        distance = abs(numbers[i] - numbers[i+1]);
        if(distance == min_distance)
        {
            result.push_back(numbers[i]);
            result.push_back(numbers[i+1]);
        }           
    }
    
    return result;    
}
*/




list<int> find_pairs(vector<int> numbers)
{
    list<int> result;
    
    sort(numbers.begin(), numbers.end());
    
    int min_distance = INT_MAX;
    int distance;
    
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        distance = abs(numbers[i] - numbers[i+1]);
        
        if(distance < min_distance)
        {
            min_distance = distance;
            
            result.clear();
        }
        
        if(distance == min_distance)
        {
            result.push_back(numbers[i]);
            result.push_back(numbers[i+1]);
        }
        
    }

    return result;    
}




int main()
{
    int N;
    cin >> N;
    
    vector<int> numbers;
    
    int a;
    
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }
    
    list<int> pairs = find_pairs(numbers);
    
    for(list<int>::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if(it != pairs.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
    
    return 0;
}
