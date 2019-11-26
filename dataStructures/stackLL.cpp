#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"


int push(node_t** head_ptr, int val){
	if(*head_ptr == NULL){
		*head_ptr = (node_t*)malloc(sizeof(node_t));
		(*head_ptr)->next = NULL;
		(*head_ptr)->data = val;
		return 0;
	}
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->next = *head_ptr;
	temp->data = val;
	*head_ptr = temp;
	return 0;
}

int pop(node_t** head_ptr){
	if(*head_ptr == NULL){
		printf("Stack Empty(Pop)\n");
		return -1; // Stack empty
	}
	int rvalue = (*head_ptr)->data;
	node_t* temp = *head_ptr;
	*head_ptr = (*head_ptr)->next;
	free(temp);
	return rvalue;
}

void printStackReverse(node_t* head){
	if(head == NULL){
		printf("Stack Empty(Print)\n");
		return;
	}
	while(head != NULL){
		printf(" %d ",head->data);
		head = head->next;
	}
	printf("\n");
}
