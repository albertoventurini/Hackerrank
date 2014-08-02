#include <iostream>

using namespace std;

struct Node
{
    Node *left, *right;
    int n_nodes;
    int value;
    
    Node(int v) : left(0), right(0), n_nodes(1), value(v)
    {
    }
};



class Tree
{
public:
    Tree() : root(0)
    {
    }
    
    ~Tree();
    
    int insert(Node *n);

private:
    Node *root;
    
    void dtor_helper(Node *n);
    int insert_recursive(Node *n, Node *p);
};



void Tree::dtor_helper(Node *n)
{
    if(n)
    {
        dtor_helper(n->left);
        dtor_helper(n->right);
        delete n;
    }
}


Tree::~Tree()
{
    dtor_helper(root);
}


int Tree::insert_recursive(Node *n, Node *p)
{
    int res = 0;
    
    if(n->value == p->value)
    {
        p->n_nodes++;
        
        if(p->right)
            res = p->right->n_nodes;
    }
    
    //if(n->value >= p->value)
    //    p->n_nodes++;
    
    else if(n->value > p->value)
    {
        p->n_nodes++;
        
        if(p->right == NULL)
            p->right = n;
        else
            res = insert_recursive(n, p->right);
    }
    
    else //if(n->value < p->value)
    {
        res = p->n_nodes;
        
        if(p->left == NULL)
            p->left = n;
        else
            res += insert_recursive(n, p->left);
    }
    
    return res;
}


int Tree::insert(Node *n)
{
    if(root == NULL)
    {
        root = n;
        return 0;
    }
    else
        return insert_recursive(n, root);
}



int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        
        Tree tree;
        int shifts = 0;
        
        for(int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            
            shifts += tree.insert(new Node(j));
            //cout << "  " << j << "  " << shifts << endl;
        }
        
        cout << shifts << endl;
        
    }
    
    return 0;
}
