#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node* BST_search(Node* root, int value) // O(logn)
{
    if(root == NULL)
        return NULL;
    else if(root->key == value)
        return root;
    else if(root->key < value)
        return BST_search(root->right, value); // T(n/2)
    else
        return BST_search(root->left, value); // T(n/2)
}   
int BST_max(Node* root)
{
    Node* max = root;
    if(root == NULL)
        return 0;
    else while(max->right != NULL)
    {
        max = max->right;
    }
    return max->key;
}
int BST_min(Node* root)
{
    Node* min = root;
    if(root == NULL)
        return 0;
    else while(min->left != NULL)
    {
        min = min->left;
    }
    return min->key;
}
Node* BST_insert(Node* cur, int value) //O(logn)
{
    if(cur == NULL)
    {
        cur = new Node;
        cur->key = value;
        cur->left = NULL;
        cur->right = NULL;
    }
    else if(value <= cur->key)
        cur->left = BST_insert(cur->left, value); // T(n/2)
    else if(value >= cur->key)
        cur->right = BST_insert(cur->right, value); // T(n/2)
    return cur;
}