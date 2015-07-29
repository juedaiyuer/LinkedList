#include "node.h"
#include<stdio.h>
#include<stdlib.h>

//only finish input operate,ouput operate have problem by my way

Node* add(Node *head,int number);

int main(int argc,const char* argv[])
{
	Node *head = NULL;
	int number;
	int cnt=0;
	do{
		scanf("%d",&number);
		head = add(head,number);
		cnt++;
	} while( number != -1);

	for(int i=0;i<cnt;i++){
		printf("%d",*(head+i));
	}
	return 0;
}

Node* add(Node *head,int number){
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
	return head;
}