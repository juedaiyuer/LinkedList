#include"node.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct _list{
	Node* head;
} List;

void add( Node* head, int number);

int main(int argc, const char* argv[]){
	List list;
	int number;
	list.head = NULL;
	do{
		scanf("%d",&number);
		if(number != -1){ 
		add(&list, number);
		}
	}while(number != -1);

	return 0;
}

void add(List* pList,int number)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node *last = pList->head;
	if(last){
		while(last->next){
			last = last->next;
		}
		last->next = p;
	}else{
		pList ->head = p;
	}
	
}