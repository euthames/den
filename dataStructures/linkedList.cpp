

#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n* next;
};

typedef n node;

int printLinkedList(node * r){
	while(r != NULL){
		printf(" %d \n",r -> data);
		r = r -> next;
	}
	printf("END of Linked List\n");
	return 0;
}

int addNode(node ** r_ptr, int val){

	if(*r_ptr==NULL){
		*r_ptr = (node*)malloc(sizeof(node));
		(*r_ptr) -> next = NULL;
		(*r_ptr) -> data = val;
	}
	else{
		node * iter = *r_ptr;
		while(iter -> next != NULL)
			iter = iter -> next;

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

	// print ll
	printLinkedList(root);

	return 0;
}

