#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"

int main(){
	node_t* stack=NULL;
	node_t* stack2=NULL;
	
	for(int i=0;i<10;i++){
		printf("BeforePush: %lX -> %lX\n",(long int)stack, stack==NULL ? NULL : (long int)stack->next );
		push(&stack,10*i);
		printf("AfterPush: %lX -> %lX\n\n",(long int)stack, stack==NULL ? NULL : (long int)stack->next );
	}
	printStackReverse(stack);

	for(int i=0;i<10;i++){
		printf("BeforePop: %lX -> %lX\n",(long int)stack, stack==NULL ? NULL : (long int)stack->next );
		push(&stack2,pop(&stack));
		printf("AfterPop: %lX -> %lX\n\n",(long int)stack, stack==NULL ? NULL : (long int)stack->next );
	}
	pop(&stack);
	printStackReverse(stack);
	printStackReverse(stack2);

	return 0;
}
