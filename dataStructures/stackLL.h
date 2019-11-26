#ifndef stackll
#define stackll
struct node_s{ 
        int data;
        node_s * next;
};
typedef node_s node_t;

int push(node_t**,int);
int pop(node_t**);
void printStackReverse(node_t*);

#endif
