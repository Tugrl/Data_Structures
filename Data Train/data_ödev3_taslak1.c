//C program to print binary tree reverse level order traversal
#include <stdio.h>
#include <stdlib.h>
//A binary tree node has data, pointer to left and right child
struct treeNode
{
int data;
struct treeNode* leftptr;
struct treeNode* rightptr;
};
//Function prototypes
void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);
int depth(struct treeNode * root);
//Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode* root)
{
    int h = depth(root);
    for (int i=h; i>=1; i--) 
        printLevel(root, i);

}
void printLevel(struct treeNode* root, int level) //prints the data of the nodes at the sent level 
// reference taken from https://www.geeksforgeeks.org/reverse-level-order-traversal/
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->leftptr, level-1);
        printLevel(root->rightptr, level-1);
    }
}
int depth(struct treeNode* root) // function that calculates the height of the tree
// referenced by https://www.geeksforgeeks.org/reverse-level-order-traversal/
{
    if (root==NULL)
        return 0;
    else
    {
        // compute the height of each subtree 
        int leftdepth = depth(root->leftptr);
        int rightdepth = depth(root->rightptr);
 
        // use the larger 
        if (leftdepth > rightdepth)
            return(leftdepth+1);
        else return(rightdepth+1);
    }
}
//Insert new node to the binary tree
struct treeNode* newNode(int data)
{
struct treeNode* treeNode = (struct treeNode*) malloc(sizeof(struct
treeNode));
treeNode->data = data;
treeNode->leftptr = NULL;
treeNode->rightptr = NULL;
return(treeNode);
}
int main()
{
struct treeNode *root = newNode(9);
root->leftptr = newNode(12);
root->rightptr = newNode(21);
root->leftptr->leftptr = newNode(15);
root->leftptr->rightptr = newNode(8);
root->rightptr->leftptr = newNode(7);
root->rightptr->rightptr = newNode(11);
printf("Level Order traversal of binary tree is \n");
reverseLevelOrder(root);
return 0;
}