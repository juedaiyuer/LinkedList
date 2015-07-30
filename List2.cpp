#include"node.h"
#include<stdio.h>
#include<stdlib.h>

/**typedef struct _node{
	int value;
	struct _node *next; 
} Node;
*/

// only delete operate not work...

Node* add(Node*head,int number);
void print(Node *head);
Node* delete_number(Node *head,int number);  //delete node of linkedList is number 

int main(int argc, const char* argv[]){
	Node *head;
	int number;
	head=NULL;
	do{
		scanf("%d",&number);
		if(number != -1){ 
		head = add(head, number);			
		}
       // print(head);       //intersting test and go it
	}while(number != -1);
	
	print(head);    // test output

    int num;
	scanf("%d",&num);   //test delete operate 
    head = delete_number(head,num);
	print(head);

	return 0;
}

Node* add(Node*head,int number)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node *last = head;
	if(last){
		while(last->next){
			last = last->next;
		}
		last->next = p;
	}else{
		head = p;
	}
	
	return head;
}

void print(Node *head){
	Node *p;
	for(p=head;p;p=p->next){
		printf("%d\t",p->value);
	}
	printf("\n");
}
Node* delete_number(Node *head,int number){
	Node *q;
	Node *p;
	for(q=NULL,p=head;p;q=p,p->next){
		if(p->value == number){
			if(q){
				q->next = p->next;
			}else{
				head = p->next;
			}
			free(p);

			break;
		}
	}
	return head;
}