#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int depth;
    int height;
    Node *left, *right;
};
void preOrder_traversal(Node* root) //O(n)
{
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder_traversal(root->left);
    preOrder_traversal(root->right);
}
void inOrder_traversal(Node* root) //O(n)
{
    if(root == NULL) return;
    inOrder_traversal(root->left);
    cout << root->data << " ";
    inOrder_traversal(root->right);
}
void postOrder_traversal(Node* root) //O(n)
{
    if(root == NULL) return;
    postOrder_traversal(root->left);
    postOrder_traversal(root->right);
    cout << root->data << " ";
}
void levelOrder_traversal(Node* root) //O(n)
{
    queue<Node*> print;
    print.push(root);
    while(!print.empty())
    {
        if(print.front()->left != NULL)
            print.push(print.front()->left);
        if(print.front()->right != NULL)
            print.push(print.front()->right);
        cout << print.front()->data << " ";
        print.pop();
    }
}
Node* searching(Node* root, int data) //O(n)
{
    if(root == NULL)
    {
        cout << "This tree is empty" << endl;
        return NULL;
    }
    queue<Node*> found;
    found.push(root);
    while(!found.empty()) //O(n)
    {
        if(found.front()->data == data)
        {
            cout << "Found!" << endl;
            return found.front();
        }
        if(found.front()->left != NULL)
            found.push(found.front()->left);
        if(found.front()->right != NULL)
            found.push(found.front()->right);
        found.pop();
    }
    cout << "Not found!" << endl;
    return NULL;
}
Node* insertion(Node* root, int data) //O(n)
{
    // insert a node at first vacant child
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if(root == NULL)
    {
        root = node;
        return root;
    }
    queue<Node*> found;
    found.push(root);
    while(!found.empty()) //O(n)
    {
        if(found.front()->left == NULL)
        {
            found.front()->left = node;
            return root;
        }
        else if(found.front()->right == NULL)
        {
            found.front()->right = node;
            return root;
        }
        found.push(found.front()->left);
        found.push(found.front()->right);
        found.pop();
    }
    return root;
}
void find_depth(Node* root, int depth)
{
    if(root == NULL) return;
    root->depth = depth;
    find_depth(root->left, depth + 1);
    find_depth(root->right, depth + 1);
}
Node* find_deepest(Node* root)
{
    if(root == NULL) return NULL;
    find_depth(root, 0);
    queue<Node*> found;
    found.push(root);
    Node* deepest = root;
    while(!found.empty())
    {
        if(found.front()->depth > deepest->depth)
        {
            deepest = found.front();
        }
        if(found.front()->left != NULL)
            found.push(found.front()->left);
        if(found.front()->right != NULL)
            found.push(found.front()->right);
        found.pop();
    }
    return deepest;
}
void deletion(Node* root, int data) //O(n)
{
    // delete a node and replace it with the last node
    Node* del = searching(root, data); //O(n)
    if(del == NULL)
    {
        cout << "This node does not exist" << endl;
        return;
    }
    Node* deepest = find_deepest(root); //O(n)
    del->data = deepest->data;
    queue<Node*> found;
    found.push(root);
    while(!found.empty()) //O(n)
    {
        if(found.front()->left == deepest)
        {
            found.front()->left = NULL;
            return;
        }
        else if(found.front()->right == deepest)
        {
            found.front()->right = NULL;
            return;
        }
        if(found.front()->left != NULL)
            found.push(found.front()->left);
        if(found.front()->right != NULL)
            found.push(found.front()->right);
        found.pop();
    }
    delete deepest;   
}
int main()
{
    int num_nodes;
    cin >> num_nodes;
    Node* root = NULL;
    for(int i = 0; i < num_nodes; i++)
    {
        int data;
        cin >> data;
        root = insertion(root, data);
    }
    cout << "Traversals" << endl;
    preOrder_traversal(root);
    cout << endl;
    inOrder_traversal(root);
    cout << endl;
    postOrder_traversal(root);
    cout << endl;
    levelOrder_traversal(root);
    cout << endl;
    // searching
    int data;
    cout << "Searching" << endl;
    cin >> data;
    Node* found = searching(root, data);
    // insertion
    cout << "Inserting" << endl;
    cin >> data;
    insertion(root, data);
    preOrder_traversal(root);
    cout << endl;
    // deletion
    cout << "Deleting " << endl;
    cin >> data;
    deletion(root, data);
    preOrder_traversal(root);
    cout << endl;
    return 0;
}