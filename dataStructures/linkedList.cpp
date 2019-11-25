

#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n* next;
};

typedef n node;

// print given linked kist
int printLinkedList(node * r){
	while(r != NULL){
		printf(" %d \n",r -> data);
		r = r -> next;
	}
	printf("END of Linked List\n");
	return 0;
}

int addNode(node ** r_ptr, int val){
	
	// add first Node if not exist
	if(*r_ptr==NULL){
		*r_ptr = (node*)malloc(sizeof(node));
		(*r_ptr) -> next = NULL;
		(*r_ptr) -> data = val;
	}
	else{// add node to the end of the list
		// iterate to the end of the list 	
		node * iter = *r_ptr;
		while(iter -> next != NULL)
			iter = iter -> next;
		// create and add node to the end of the list and make sure ended with NULL next ptr of the new node 
		iter -> next = (node*)malloc(sizeof(node));
		iter -> next -> next = NULL;
		iter -> next -> data = val;
	}
	return 0;
}

int main(){
	node* root = NULL;
	
	for(int i=1;i<=10;i++)
		addNode(&root,i*10);

	printLinkedList(root);

	return 0;
}


