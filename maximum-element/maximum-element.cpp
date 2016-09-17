#include <iostream>

using namespace std;


class StackWithMax
{
private:
    vector<int> items;

public:    
    void push(int i)
    {
        items.push_back(i);
    }

    int pop()
    {
        int i = items.back();
        items.pop_back();
    }

    int max()
    {

    }

};

int main()
{

}