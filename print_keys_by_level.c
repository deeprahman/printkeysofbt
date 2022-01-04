#include <stdio.h>
#include <stdlib.h>

// tree item structure
typedef struct node{
    struct node *left;  // link to left node
    struct node * right;    // link to the right node
    int key;    // node key
}NODE;

// Queue item structure
typedef struct qe{
    struct qe *next;    // link to next queue item
    NODE *node;     // link to the this item value
}QE;

/*
* Put a node in the queue
*/
int enqueue(QE **queue, NODE *node){
    QE *q = *queue;
    QE *r = (QE *) malloc(sizeof(QE));
    r->node = node;
    if(q == 0){
        *queue = node;
    }else{
        while(q->next){
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
NODE dequeue(QE **queue){
    QE *q = *queue; // the pointer variable '*q' holds the memory address of the first element of the queue
    if(q){ // when the queue element
        *queue = q->next; // Makes the second item of the queue the first item
    }
    return q->node; // return the first item of the queue
} 

/**
 * get the number of elements in the given queue
 */
int qlength(QE *queue){
    int n = 0;
    while(queue){ // run as long as queue point to the valid memory address
        n++;
        queue = queue->next;
    }
    return n;
}