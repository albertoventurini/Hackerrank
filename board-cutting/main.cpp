#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>


using namespace std;



struct Node
{
    list<int> x, y;
    
    int cost_so_far;
    int cost_remaining_y, cost_remaining_x;
    int xm, ym;
    
    Node(const list<int>& x, const list<int>& y);
    
    int cost() const
    {
        return cost_so_far + cost_remaining_y + cost_remaining_x;
    }
    
    bool leaf() const
    {
        return x.empty() && y.empty();
    }
    
    void pick_next_elem();
    void pick_elem_from_x();
    void pick_elem_from_y();
};


Node::Node(const list<int>& x, const list<int>& y)
{
    this->x = x;
    this->y = y;
    
    xm = ym = 1;
    
    cost_so_far = 0;
    
    for(auto i : y)
        cost_remaining_y += i;
        
    for(auto i : x)
        cost_remaining_x += i;
}



void Node::pick_elem_from_x()
{
    cost_remaining_x -= xm * x.back();
    cost_so_far += xm * x.back();
    x.pop_back();
    ym++;
}


void Node::pick_elem_from_y()
{
    cost_remaining_y -= ym * y.back();
    cost_so_far += ym * y.back();
    y.pop_back();
    xm++;
}




struct NodeCompare
{
    bool operator()(Node *n1, Node *n2)
    {
        return n1->cost() < n2->cost();
    }
};






int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int M, N;
        cin >> M >> N;
        
        list<int> y;
        list<int> x;
        
        int k;
        
        for(int i = 0; i < M - 1; i++)
        {
            cin >> k;
            y.push_back(k);
        }
        
        for(int i = 0; i < N - 1; i++)
        {
            cin >> k;
            x.push_back(k);
        }
        
        priority_queue<Node*, vector<Node*>, NodeCompare> openset;
        openset.push(new Node(x, y));
        
        while(!openset.empty())
        {
            Node *n = openset.top();
            openset.pop();
            
            if(n->leaf())
                break;
            
            Node *nx = new Node(n->x, n->y);

        }
        

        
    }
    
    return 0;
}
