#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// typedef union leaf
// {
//     int val;
//     int operation;
// } leaf;

typedef struct node_i
{
    int opcode;
    struct node_i *next;
} node_i;

// typedef struct ast
// {
//     node_i *left;
//     node_i *right;

// } ast;

void push(node_i **head, int *element) {}
int *pop() { return 0; }
