#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    
    cin >> N;
    cin >> K;
    
    vector<int> numbers;
    
    int j;
    for(int i = 0; i < N; i++)
    {
        cin >> j;
        numbers.push_back(j);
    }
    
    sort(numbers.begin(), numbers.end());
    
    vector<int>::iterator it_a = numbers.begin();
    vector<int>::iterator it_b = numbers.begin();
    
    int n_pairs = 0;
    
    while(it_b != numbers.end())
    {
        if(*it_b - *it_a < K)
            it_b++;
        
        if(*it_b - *it_a == K)
            n_pairs++;
        
        if(*it_b - *it_a >= K)
            it_a++;
    }
    
    cout << n_pairs << endl;
    
    return 0;
}
