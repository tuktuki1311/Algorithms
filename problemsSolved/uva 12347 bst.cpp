#include<bits/stdc++.h>

using namespace std;

struct node
{

    int data;
    node *left, *right;

};
node* CreateNode(int data)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;

}
node* InsertNode(node *root, int data)
{
    if(root==NULL)
        root=CreateNode(data);

    else if(data<=root->data)
        root->left=InsertNode(root->left,data);

    else if(data>root->data)
        root->right=InsertNode(root->right,data);

    return root;
}

void printPostorder(node* root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d\n", root->data);
}

int main()
{
    node *root,*head;
    root=NULL;
    int item;
    scanf("%d",&item);
    root=InsertNode(root,item);

    while(scanf("%d",&item)!=EOF)
        head=InsertNode(root,item);

    printPostorder(root);

    return 0;
}
