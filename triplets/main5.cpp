#include <iostream>
#include <vector>
#include <algorithm>

// This code uses two BSTs to keep track of the number of elements > and < of k
//
// I.e., given an element k in the input array, the BSTs keep track of
//   * the number of elements < k on the left of k
//   * the number of elements > k on the right of k
//
// We do that using a technique similar to:
// http://stackoverflow.com/questions/9495843/given-an-array-for-each-element-find-out-the-total-number-of-elements-lesser-t
//
// The fact that we can have duplicates is a small nuisance, because
// we need to adjust the counts a little.


using namespace std;


template <typename T>
class Tree
{
    struct Node
    {
        T key;
        Node *left, *right, *center, *parent;
        int n_children;
        
        int less, greater;
        
        Node(T k) : key(k), left(0), right(0), center(0), parent(0), n_children(0), less(0), greater(0) { }
    };
    
public:

    Tree() : root(0) {}
    ~Tree() {}
    
    void insert(T k, int& less, int& greater);
    

private:

    Node *root;
    void insert_recursive(T k, int& less, int& greater, Node *node);
    void adjust_ancestors(Node *n);

};


template <typename T>
void Tree<T>::insert(T k, int& less, int& greater)
{
    less = greater = 0;
    
    if(root == 0)
        root = new Node(k);
    else
        insert_recursive(k, less, greater, root);
}


template <typename T>
void Tree<T>::insert_recursive(T k, int& less, int& greater, Node *node)
{   
    if(k > node->key)
    {
        less++;
        if(node->left) less += node->left->n_children + 1;
        node->n_children++;
        
        
        if(node->right == 0)
        {
            node->right = new Node(k);
            node->right->parent = node;
            
            node->right->less = less;
            node->right->greater = greater;
        }
        else
            insert_recursive(k, less, greater, node->right);
    }
    
    else if(k < node->key)
    {
        greater++;
        if(node->right) greater += node->right->n_children + 1;
        
        node->n_children++;
        
        if(node->left == 0)
        {
            node->left = new Node(k);
            node->left->parent = node;

            node->left->less = less;
            node->left->greater = greater;
        }
        else
            insert_recursive(k, less, greater, node->left);
    }
    
    else
    {
        if(node->left) less += node->left->n_children + 1;
        if(node->right) greater += node->right->n_children + 1;
        
        node->center = new Node(k);
        node->center->parent = node;
        
        node->center->less = less - node->less; // this eliminates the duplicate cases
        node->center->greater = greater;
        
        less -= node->less;
        
        // Subtracts 1 to the number of children in all ancestors,
        // because this node should not be counted as child,
        // because it's a duplicate
        adjust_ancestors(node->parent);
        
    }
}


template <typename T>
void Tree<T>::adjust_ancestors(Node *n)
{
    if(n != 0)
    {
        n->n_children--;
        adjust_ancestors(n->parent);
    }
}



int main()
{
    int N;
    cin >> N;
    
    vector<unsigned long> numbers;
       
    int k;
    for(int i = 0; i < N; i++)
    {
        cin >> k;
        numbers.push_back(k);        
    }
    
    Tree<unsigned long> tree_left, tree_right;
    int less, greater, dummy;
    
    vector<int> less_numbers, greater_numbers;
    for(int i = 0; i < N; i++)
    {
        tree_left.insert(numbers[i], less, dummy);
        less_numbers.push_back(less);
        
        tree_right.insert(numbers[N - i - 1], dummy, greater);
        greater_numbers.push_back(greater);
    }
    
    reverse(greater_numbers.begin(), greater_numbers.end());
    
    unsigned long n_triplets = 0;
    
    for(int i = 0; i < N; i++)
    {
        n_triplets += less_numbers[i] * greater_numbers[i];
    }
    
    cout << n_triplets << endl;

    
    /*
    for(int i = 0; i < less_numbers.size(); i++)
        cout << less_numbers[i] << " ";
    
    cout << endl;
    
    for(int i = 0; i < greater_numbers.size(); i++)
        cout << greater_numbers[i] << " ";
    
    
    
    
    
    cout << endl;*/
    
    
    return 0;
}
