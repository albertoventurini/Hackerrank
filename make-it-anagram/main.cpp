#include <iostream>
#include <map>

using namespace std;


int main()
{
    string str1, str2;
    
    cin >> str1;
    cin >> str2;
    
    map<char, int> map1, map2;
    
    for(int i = 0; i < str1.length(); i++)
        map1[str1[i]]++;
    
    for(int i = 0; i < str2.length(); i++)
        map2[str2[i]]++;
    
    int count = 0;
    
    for(auto it1 : map1)
    {
        //cout << it.first << endl;
        
        auto it2 = map2.find(it1.first);
        
        if(it2 == map2.end())
            count += it1.second;
        else if(it1.second > it2->second)
            count += it1.second - it2->second;
    }

    for(auto it2 : map2)
    {
        //cout << it.first << endl;
        
        auto it1 = map1.find(it2.first);
        
        if(it1 == map1.end())
            count += it2.second;
        else if(it2.second > it1->second)
            count += it2.second - it1->second;
    }
    
    cout << count << endl;
    
    //cout << str1 << endl;
    //cout << str2 << endl;
    
    return 0;
}
