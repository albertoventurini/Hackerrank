#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;


void write_test_case(int n, ofstream& out)
{
    vector<unsigned long> vec;
    set<unsigned long> used_nums;
    
    unsigned long k;
    
    for(int i = 0; i < n; i++)
    {
        k = rand();
        if(used_nums.find(k) == used_nums.end())
        {
            used_nums.insert(k);
            vec.push_back(k);
            vec.push_back(k);
        }
    }
    
    random_shuffle(vec.begin(), vec.end());
    
    out << vec.size() << endl;
    
    for(int i = 0; i < vec.size(); i++)
    {
        if(i != 0)
            out << " ";
        
        out << vec[i];
    }
    
    out << endl;
    
}




int main()
{
    srand(time(NULL));

    int answer_naive, answer_main5;
    answer_naive = answer_main5 = 0;
    
    while(answer_naive == answer_main5)
    {
    
        ofstream out("input_gen.txt");
        
        write_test_case(100, out);

        system("./naive < input_gen.txt > output_gen_naive.txt");
        system("./main5 < input_gen.txt > output_gen_main5.txt");
        
        ifstream in_naive("output_gen_naive.txt");
        ifstream in_main5("output_gen_main5.txt");
        

        in_naive >> answer_naive;
        in_main5 >> answer_main5;
    }
    
    return 0;
}
