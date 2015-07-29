#include "node.h"
#include<stdio.h>
#include<stdlib.h>

/**
Defects of variable array
1. Copy takes time, the original array is too large, resulting in efficiency slows
2. The need to apply for a new array of more space, until there is no free, lead to insufficient memory
*/

int main(int argc,const char* argv[])
{
	Node *head = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){			//add to linked list
			Node *p = (Node*)malloc(sizeof(Node));
			p->value = number;
			p->next = NULL;
			//find the last
			Node *last = head;
			if( last ){
				while( last->next){
					last = last->next;
				}
				// attach
				last->next = p;
			}else{
				head = p;
		    }
		}
	} while( number != -1);
	

	return 0;
}