#include<iostream>
using namespace std;
struct TreeNode{
    int value,height;
    TreeNode *lchild,*rchild;
    TreeNode(int v):value(v),height(1),lchild(NULL),rchild(NULL){}
};

int getHeight(TreeNode* root){
    if(root == NULL) return 0;
    return root->height;
}

int getbalanceFactor(TreeNode* root){
    if(root == NULL) return 0;
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(TreeNode* root){
    root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
}

void L(TreeNode* &root){
    TreeNode* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(TreeNode* &root){
    TreeNode* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(TreeNode* &root,int v){
    if(root == NULL){
        root = new TreeNode(v);
        return;
    }
    if(v < root->value){
        insert(root->lchild,v);
        updateHeight(root);
        if(getbalanceFactor(root) == 2){
            if(getbalanceFactor(root->lchild) == 1){
                R(root);
            }else if(getbalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,v);
        updateHeight(root);
        if(getbalanceFactor(root) == -2){
            if(getbalanceFactor(root->rchild) == -1){
                L(root);
            }else if(getbalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

int main(){
    int n,tmp;
    TreeNode* root = NULL;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&tmp);
        insert(root,tmp);
    }
    printf("%d\n",root->value);
    return 0;
}
