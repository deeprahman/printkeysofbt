#include <stdio.h>
#include <stdlib.h>

// tree item structure
typedef struct node
{
    struct node *left;  // link to left node
    struct node *right; // link to the right node
    int key;            // node key
} NODE;

// Queue item structure
typedef struct qe
{                      // queue element structure
    struct qe *next;   // queue pointer
    struct node *node; // queue contents
} QE;

/**
 * Create a new node
 */
NODE *newNode(int key)
{
    NODE *t = (NODE *)malloc(sizeof(NODE));
    t->key = key;
    t->left = t->right = NULL;
    return t;
}

/*
* Put a node in the queue
*/
int enqueue(QE **queue, NODE *node)
{
    QE *q = *queue;
    QE *r = (QE *)malloc(sizeof(QE));
    r->node = node;
    if (q == 0)
    {
        *queue = r;
    }
    else
    {
        while (q->next)
        {
            q = q->next;
        }
        q->next = r;
    }
    r->next = 0;
}

/**
 * Remove the first item from a given queue
 * @param QE queue a pointer to a pointer to the queue   
 */
NODE *dequeue(QE **queue)
{
    QE *q = *queue; // the pointer variable '*q' holds the memory address of the first element of the queue
    if (q)
    {                     // when the queue element
        *queue = q->next; // Makes the second item of the queue the first item
    }
    return q->node; // return the first item of the queue
}

/**
 * get the number of elements in the given queue
 */
int qlength(QE *queue)
{
    int n = 0;
    while (queue)
    { // run as long as queue point to the valid memory address
        n++;
        queue = queue->next;
    }
    return n;
}

/*
* Print a binary tree by levels
* each level on a line
*/

void printLevel(NODE *root)
{
    int nodeCount; // Tracks the nodes on a level
    if (root == NULL)
        return;
    QE *queue = 0;          // create a FIFO queue
    enqueue(&queue, root); // start with root
    while (1)
    {
        nodeCount = qlength(queue);
        if (nodeCount == 0)
            break;
        // dequeue nodes of current level, enqueue nodes of next level
        while (nodeCount > 0)
        {
            NODE *node = dequeue(&queue);
            printf("%d ", node->key);
            if (node->left != NULL)
                enqueue(&queue, node->left);
            if (node->right != NULL)
                enqueue(&queue, node->right);
            nodeCount--;
        }
        printf("\n");
    }
}

/*
Our b-tree

                   1
                /     \
            2            3
         /    \        /    \
       4        5     6       0
*/

int main()
{
    // Create a simple b-tree
    NODE *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(0);
    printLevel(root);
    return 0;
}