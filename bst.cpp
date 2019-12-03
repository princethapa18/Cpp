// 24 July 2018 Tuesday
// a simple Binary Search Tree implementation for integers
// binary tree --> in which a parent can have 2 child at most [ there is no restriction on how data is stored)
// binary search tree  --> there is restriction [ all the key < root is placed at left and all the key > root is placed at right]
/*
                 50              h = 0
               /    \
              30     70          h = 1
             /  \   /  \
            20  40 60  80        h = 2   [ 50 is root. 20, 40, 60 and 80 are leaf nodes(which have no child). 30 and 40 are siblings ]

            Max no. of elements = 2^(h+1) - 1   [ h is the height of the tree ]
*/

// a bst takes O(logn) time for insertion , deletion and search

/*
    insertion ---> compare the keys
    if(key < root->key) insertAtLeft
    if(key > root->key) insertAtRight

    traversing a bst
    preorder ---> root --> left  --> right
    postorder --> left --> right --> root
    inorder   --> left --> root  --> right

    by recursion (done)
    by iteration (TBD)

    breadth first traversal ( level order traversal) TBD
    50 --> 30 --> 70 --> 20 --> 40 --> 60 --> 70

    Finding a key
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node
{
    int key;
    node *right;
    node *left;
} node;

/* new node creation */
node * newNode(int key)
{
    node * temp = (node *)malloc(sizeof(node));
    temp->key  = key;
    temp->left = temp->right = NULL;
    return temp;
}

node * insert(node * node, int key)
{
    if(node == NULL) return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);
    if(key > node->key)
        node->right = insert(node->right, key);

    return node;
}
/* left --> root --> right */
void inorder(node * root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << " " << root->key << "  --->";
        inorder(root->right);
    }
}
/* left --> right --> root */
void postorder(node * root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->key << "  --->";
    }
}

int main()
{
    node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);

    cout << "\n postorder traversal\n";
    postorder(root);

    return 0;
}

