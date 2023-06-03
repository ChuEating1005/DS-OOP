#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// TODO: (There are no restrictions on the methods you may use.)
struct Node
{
    int key;
    Node* left;
    Node* right;
};
Node* insert(Node* root, int key)
{
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(key < root->key) root->left = insert(root->left , key);
    else if(key > root->key) root->right = insert(root->right , key);
    return root;
}

void InOrder(Node* root)
{
    if (root != NULL) 
    {
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
    }
}
void PreOrder(Node* root)
{
    if (root != NULL) 
    {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(Node* root)
{
    if (root != NULL) 
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
    }
}

int main() {
    //TODO: (There are no restrictions on the methods you may use.)
  
  	int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node* root = NULL;
    root = insert(root,arr[0]);
    for(int i = 1; i < n; i++)
    {
        insert(root, arr[i]);
    }
  	cout << "InOrder traversal: ";
    InOrder(root);
    
    cout << "\nPreOrder traversal: ";
    PreOrder(root);

    cout << "\nPostOrder traversal: ";
    PostOrder(root);
  
  
    return 0;
}