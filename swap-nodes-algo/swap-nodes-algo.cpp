#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Tree
{
public:    
    int key;
    Tree* left;
    Tree* right;
};

Tree* build_tree(vector<pair<int, int>*> nodes)
{
    Tree* root = new Tree();
    root->key = 1;

    list<Tree*> queue;
    queue.push_back(root);

    for(pair<int, int>* node: nodes)
    {
        Tree* tree = queue.front();
        queue.pop_front();

        if(node->first != -1)
        {
            tree->left = new Tree();
            tree->left->key = node->first;
            queue.push_back(tree->left);
        }

        if(node->second != -1)
        {
            tree->right = new Tree();
            tree->right->key = node->second;
            queue.push_back(tree->right);
        }
    }

    return root;
}

void inorder_traversal_rec(Tree *tree)
{
    if(tree != NULL)
    {
        inorder_traversal_rec(tree->left);
        cout << tree->key << " ";
        inorder_traversal_rec(tree->right);
    }
}

void inorder_traversal(Tree *tree)
{
    inorder_traversal_rec(tree);
    cout << endl;
}

void swap_rec(Tree* tree, int K, int level)
{
    if(tree != NULL)
    {
        if(((level + 1) % K) == 0)
        {
            Tree* tmp = tree->left;
            tree->left = tree->right;
            tree->right = tmp;
        }

        swap_rec(tree->left, K, level+1);
        swap_rec(tree->right, K, level+1);

    }
}

void swap(Tree* tree, int K)
{
    swap_rec(tree, K, 0);
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>*> nodes;

    int l, r;

    for(int i = 0; i < N; i++)
    {
        cin >> l >> r;
        nodes.push_back(new pair<int, int>(l, r));
    }

    Tree *tree = build_tree(nodes);
    
    int T, K;
    cin >> T;    
    for(int i = 0; i < T; i++)
    {
        cin >> K;
        swap(tree, K);
        inorder_traversal(tree);
    }
}
