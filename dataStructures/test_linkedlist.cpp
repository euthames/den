#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
        node* root = NULL;

        addNodeSequentialy(&root,400);
        addNodeSequentialy(&root,40);
        addNodeSequentialy(&root,4);
        addNodeSequentialy(&root,450);
        addNodeSequentialy(&root,50);
        addNodeSequentialy(&root,50);
        printLinkedList(root);

        deleteNode(&root,50);
        printLinkedList(root);
        deleteNode(&root,999);
        printLinkedList(root);
        deleteNode(&root,4);
        printLinkedList(root);
        deleteNode(&root,450);
        printLinkedList(root);
        deleteNode(&root,400);
        printLinkedList(root);
        deleteNode(&root,50);
        printLinkedList(root);
        deleteNode(&root,40);
        printLinkedList(root);
        deleteNode(&root,40);
        printLinkedList(root);
        deleteNode(&root,40);
        printLinkedList(root);


        return 0;

}

