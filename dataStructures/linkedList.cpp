#include <stdio.h>
#include <stdlib.h>

struct n{
	int data;
	n* next;
};

typedef n node;

// print given linked list 
void printLinkedList(node * r){
	while(r != NULL){
		printf(" %d \n",r -> data);
		r = r -> next;
	}
	printf("END of Linked List\n");
}

int addNodeToBegining(node ** r_ptr, int val){	
	// add first Node if not exist
	if(*r_ptr==NULL){
		*r_ptr = (node*)malloc(sizeof(node));
		(*r_ptr) -> next = NULL;
		(*r_ptr) -> data = val;
	}
	else{
		node * temp = (node*)malloc(sizeof(node));
		temp -> next = *r_ptr;
		temp -> data = val;
		*r_ptr = temp;
	}
	return 0;
}

int addNodeToEnd(node * iter, int val){
	if(iter == NULL)
		return 1;
	while(iter -> next != NULL)
		iter = iter -> next;

	iter -> next = (node *)malloc(sizeof(node));
	iter -> next -> data = val;
	iter -> next -> next = NULL;

	return 0;
}

int main(){
	node* root = NULL;

	for(int i=1;i<=10;i++)
		addNodeToBegining(&root,i*100);

	for(int i=1;i<=10;i++)
		addNodeToEnd(root,i*10);

	printLinkedList(root);

	return 0;
}

