#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <set>

using namespace std;


int main()
{
    int N;
    cin >> N;
    
    vector<int> numbers;
       
    int k;
    for(int i = 0; i < N; i++)
    {
        cin >> k;
        numbers.push_back(k);        
    }
    
    set<tuple<int, int, int>> triplets;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
            for(int k = j; k < N; k++)
            {
                if(numbers[i] < numbers[j] && numbers[j] < numbers[k])
                    triplets.insert(make_tuple(numbers[i], numbers[j], numbers[k]));
            }
        
        //cout << i << endl;
    }

    /*for(auto t : triplets)
    {
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }*/
    cout << triplets.size() << endl;
 
    return 0;
}
