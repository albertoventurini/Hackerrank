#include <iostream>
#include <assert.h>

using namespace std;

struct Node
{
    Node *left, *right;
    int n_nodes;
    int value;
    int height;
    int balance;
    
    Node(int v) :
        left(0),
        right(0),
        n_nodes(1),
        value(v),
        height(1),
        balance(0)
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
    
    void insert(Node *n);

//private:
    Node *root;
    
    void dtor_helper(Node *n);
    void insert_recursive(Node *n, Node *p);
    
    Node* right_rotate(Node *q);
    Node* left_rotate(Node *p);
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




Node* Tree::right_rotate(Node *q)
{
    assert(q);
    assert(q->left);
    
    Node *p = q->left;
    Node *b = p->left;
    
    p->right = q;
    q->left = b;
    
    return p;
}



Node* Tree::left_rotate(Node *p)
{
    assert(p);
    assert(p->right);
    
    Node *q = p->right;
    Node *b = q->left;
    
    p->right = b;
    q->left = p;
    
    return q;
}



void Tree::insert_recursive(Node *n, Node *p)
{
    assert(n);
    assert(p);
    
    // Insert node 'n' as normal BST
    if(n->value > p->value)
    {
        if(p->right == NULL)
            p->right = n;
        else
            insert_recursive(n, p->right);
    }
    
    else if(n->value < p->value)
    {
        if(p->left == NULL)
            p->left = n;
        else
            insert_recursive(n, p->left);
    }
    
    // Calculates height of node 'p'
    int hl = 0;
    if(p->left) hl = p->left->height;
    
    int hr = 0;
    if(p->right) hr = p->right->height;
    
    p->height = 1;
    p->height += hl > hr ? hl : hr;
    
    p->balance = hl - hr;
    
    Node *new_root;
    
    if(p->balance > 1 && p->left->balance >= 0)
    {
        new_root = right_rotate(p);
    }
    
    if(p->balance > 1 && p->left->balance < 0)
    {
        p->left = left_rotate(p->left);
        new_root = right_rotate(p);
    }
    
    if(p->balance < -1 && p->right->balance > 0)
    {
        p->right = right_rotate(p->right);
        new_root = left_rotate(p);
    }
    
    if(p->balance < -1 && p->right->balance <= 0)
    {
        new_root = left_rotate(p);
    }
    
    if(p == root) root = new_root;
    
    
}


void Tree::insert(Node *n)
{
    if(root == NULL)
        root = n;
    else
        insert_recursive(n, root);
}



int main()
{
    Tree t;
    t.insert(new Node(1));
    t.insert(new Node(2));
    t.insert(new Node(3));
    
    cout << t.root->value;
    return 0;
    
    
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
            
            tree.insert(new Node(j));
            
            //shifts += tree.insert(new Node(j));
            //cout << "  " << j << "  " << shifts << endl;
        }
        
        cout << shifts << endl;
        
    }
    
    return 0;
}
