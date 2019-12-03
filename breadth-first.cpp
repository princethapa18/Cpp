/* 15 august 2018
    breadth-first traversal
    traversing level by level
               F           level 0
             /   \
            D     J        level 1
           / \   /  \
          B   E  G   K     level 2

    level 0 --> level 1 ----> level 2
    F ----> | D ----> J---> | B --> E --> G --> K |

    depth-first [preorder, postorder and inorder] (covers the depth first )

    breadth-first ex: tree of officers . Getting the chain of command

    helper data structure : queue

    //creating a new node containing some data
    tree * newNode(int data)
    {
        tree * ret = NULL;
        ret = (tree*)malloc(sizeof(tree));
        ret->left = ret->right = NULL;
        return ret;
    }

    // inserting a data in to the binary search tree
    tree * insertTree(tree *root , int data)
    {
        if(root == NULL) return newNode(data);
        if(data < root->data) root->left  = insertTree(root->left,  data);
        if(data > root->data) root->right = insertTree(root->right, data);
        return root;
    }
*/

#include <iostream>
// for malloc , calloc etc in C use #include "stdlib.h"
#include <cstdlib>
#include <queue>
using namespace std;

// define tree data structure
// this is a binary search tree not binary tree
// we need to compare
typedef struct tree{
    char c;
    tree *left;
    tree *right;
} tree;

tree * newnode(char c)
{
    tree * temp = (tree*) malloc(sizeof(tree));
    temp->c = c;
    temp->left = temp->right = NULL;
    return temp;
}

tree * insertTree(tree *root, char c)
{
    if(root == NULL) return newnode(c);

    //cout << root->c << " vs " << c << endl;
    if(c < root->c )
    {
        //cout << "inserting at the left : " << c << endl;
        root->left = insertTree(root->left,  c);
    }
    if(c > root->c )
    {
        //cout << "inserting at the right : " << c << endl;
        root->right = insertTree(root->right, c);
    }
    return root;
}

void breadthFirst(tree *root)
{
    if(root == NULL) return;

    queue<tree*> que;
    que.push(root);

    while (!que.empty())
    {
        tree * temp = que.front();
        cout << temp->c << " --> ";
        if(temp->left)  que.push(temp->left);
        if(temp->right) que.push(temp->right);
        que.pop();
    }
}

//void freeTree(tree * root)
//{
//    if(root == NULL) return;

//    if(root->left)
//}

int main()
{
    tree * root = NULL;
    root = insertTree(root, 'f');
    insertTree(root, 'd');
    insertTree(root, 'j');
    insertTree(root, 'b');
    insertTree(root, 'e');
    insertTree(root, 'g');
    insertTree(root, 'k');

    cout << "breadth-first or level order traversal." << endl << "output should be: f -> d -> j -> b -> e -> g -> k" << endl;
    breadthFirst(root);
    return 0;
}

