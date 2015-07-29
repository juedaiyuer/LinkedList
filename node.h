#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node{
	int value;
	struct _node *next; 
	//Point to struct _node type, another reason not to write Node, structure type name has not been defined¡£
} Node;

#endif