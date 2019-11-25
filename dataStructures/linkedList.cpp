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

int addNodeToInterval(node ** r_ptr, int val){
	if(*r_ptr==NULL){
		*r_ptr = (node*)malloc(sizeof(node));
		(*r_ptr) -> next = NULL;
		(*r_ptr) -> data = val;
		return 0;
	}

	node * iter = (*r_ptr);
	while(iter -> next != NULL && iter -> next -> data < val)
		iter = iter -> next;	
		
	node * temp = (node*)malloc(sizeof(node));
	temp -> next = iter -> next;
	temp -> data = val;
	iter -> next = temp;	

	return 0;
}

int addNodeSequentialy(node **root_ptr, int val){
	if(*root_ptr==NULL)
		return addNodeToBegining(root_ptr,val); // or addNodeToInterval(root_ptr,val);
	else if((*root_ptr) -> data > val)
		return addNodeToBegining(root_ptr,val);
	else
		return addNodeToInterval(root_ptr,val);

}

int deleteNode(node **root_ptr,int val){
	if(*root_ptr == NULL) // Empty linked list
		return 0;

	if((*root_ptr)->data == val){ // Delete first node
		node * temp = *root_ptr;
		*root_ptr = (*root_ptr)->next;
		free(temp);
		return 0;
	}

	node * iter = *root_ptr;
	while(iter->next != NULL && iter -> next -> data != val)
		iter = iter -> next;

	if(iter -> next == NULL){ // Couldn't find val that will be deleted in the list
		printf("Couldn't find val in list");
		return 1;
	}
	// Delete node at middle or the end
	node * temp = iter -> next;
	iter -> next = temp -> next;
	free(temp);	
	return 0;
}

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
	deleteNode(&root,4);
	printLinkedList(root);
	deleteNode(&root,40);
	printLinkedList(root);
	deleteNode(&root,450);
	printLinkedList(root);
	deleteNode(&root,400);
	printLinkedList(root);
	deleteNode(&root,50);
	printLinkedList(root);
	

	return 0;
}

