#ifndef linkedlist
#define linkedlist

struct n{
        int data;
        n* next;
};

typedef n node;

void printLinkedList(node * r);
int addNodeToBegining(node ** r_ptr, int val);
int addNodeToInterval(node ** r_ptr, int val);
int addNodeSequentialy(node **root_ptr, int val);
int deleteNode(node **root_ptr,int val);

#endif

