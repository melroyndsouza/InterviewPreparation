#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

//done
void push(Node **head, int data) {
	Node *newNode;

	newNode = (Node *) malloc(sizeof(Node));
	newNode->next = *head;
	newNode->data = data;
	*head = newNode;
}

//done
int length(Node *head) {
	int length = 0;
	while (head != NULL) {
		length++;
		head = head->next;
	}
	return length;
}

//done
void print(Node *head, char *name){
	printf("\nName [%s] \nLength [%d] \nValues : ",name,length(head));

	while (head != NULL){
		printf("%d \t",head->data);
		head = head->next;
	}
}

//done
int getNth(int n, Node *head) {
	int i = 0;

	for (i = 0; i < n; i++)
		if (head != NULL)
			head = head->next;
		else
			return -1;

	if(head!=NULL)								//didnt check this 1st time
		return head->data;
	else
		return -1;
}


void delList(Node **head) {
	Node *current = *head;
	Node *toDel = NULL;

	while (current != NULL) {
		toDel = current;
		current = current->next;
		free(toDel);
	}

	*head = NULL;

}

//done
int pop(Node **head) {
	Node *dataNode;
	int data;

	if (head == NULL || *head == NULL)
		return -1;

	dataNode = *head;
	data = dataNode->data;
	*head = dataNode->next;
	free(dataNode);

	return data;

}

//difficult
//done
int insertNth(Node **head, int pos, int data) {
	Node *dataNode,*prevNode = NULL;
	Node *currNode = *head;

	int i;

	for (i = 0; i < pos; i++) {
		if (currNode == NULL)
			return -1;
		else{
			prevNode=currNode;
			currNode = currNode->next;

		}
	}


	dataNode = (Node *) malloc(sizeof(Node));
	dataNode->data = data;
	dataNode->next = currNode;

	if (prevNode == NULL)
		*head = dataNode;
	else
		prevNode->next = dataNode;

	return 0;
}



void sortedInsert(Node **head, Node *dataNode) {
	Node *prevNode, *currNode;
	if (*head == NULL)
		*head = dataNode;
	else {
		currNode = *head;
		prevNode = NULL;
		while (currNode != NULL && currNode->data <= dataNode->data) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		if (prevNode != NULL)
			prevNode->next = dataNode;
		else
			*head = dataNode;
		dataNode->next = currNode;
	}
}

/*
void insertSort() {

}
*/


//done
void append(Node **a, Node **b) {
	Node *lastNode;
	if (*a == NULL) {
		*a = *b;

	} else {
		lastNode = *a;
		while (lastNode->next != NULL)
			lastNode = lastNode->next;
		lastNode->next = *b;
	}
	*b = NULL;
}

//done
void frontBackSplit(Node *head, Node **front, Node **back) {
	Node *slowPtr, *fastPtr,*slowPtrPrev;
	slowPtrPrev =NULL;
	slowPtr = head;
	fastPtr = head;
	while (fastPtr != NULL) {
		slowPtrPrev = slowPtr;
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
		if (fastPtr != NULL)
			fastPtr = fastPtr->next;
	}

	*front = head;
	*back = slowPtr;
	if(slowPtrPrev!=NULL)
		slowPtrPrev->next = NULL;
}

//done
void removeDuplicates(Node *head) {
	Node *currPtr = head;
	Node *nxtPtr = head->next;
	Node* temp;
	while (nxtPtr != NULL) {
		while (nxtPtr != NULL && nxtPtr->data == currPtr->data) {
			temp = nxtPtr;
			nxtPtr = nxtPtr->next;
			free(temp);
		}
		currPtr->next = nxtPtr;
		currPtr = currPtr->next;
		nxtPtr = nxtPtr->next;
	}
}

//difficult
//done
void alternatingSplit(Node *head, Node **a, Node **b) {
	Node *currNode, *nxtNode;
	*a = head;
	*b = head->next;
	currNode = head;
	while (currNode->next != NULL) {
		nxtNode = currNode->next;
		currNode->next = nxtNode->next;
		currNode = nxtNode;
	}

}
/*

Node* shuffleMerge(Node *a, Node *b) {

}
*/


//done
Node* sortedMerge(Node *a, Node *b) {
	Node *prevNode, *currNode, *head;

	prevNode = NULL;
	while (a != NULL || b != NULL) {
		if (a == NULL) {
			currNode = b;
			b = b->next;
		} else if (b == NULL) {
			currNode = a;
			a = a->next;
		} else if (a->data < b->data) {
			currNode = a;
			a = a->next;
		} else {
			currNode = b;
			b = b->next;
		}
		if (prevNode != NULL)
			prevNode->next = currNode;
		else
			head = currNode;
		prevNode = currNode;
		currNode->next =NULL;
	}
	return head;
}

Node *sortedIntersect(Node *a, Node *b) {
	Node *head = NULL;
	Node *currNode, *prevNode = NULL;
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			currNode = (Node *) malloc(sizeof(Node));
			currNode->data = a->data;

			if (prevNode == NULL)
				head = currNode;
			else
				prevNode->next = currNode;

			prevNode = currNode;
		} else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;

	}
	return head;
}

//done
Node* reverse(Node *prevNode, Node *currNode) {
	Node *head;
	if (currNode->next == NULL)
		head = currNode;
	else
		head = reverse(currNode, currNode->next);
	currNode->next = prevNode;
	return head;
}


int main(){
	Node* head = NULL;
	Node *a,*b;
	a=NULL;
	b=NULL;
	push(&b,6);
	push(&b,5);
	push(&a,4);
	push(&b,3);
	//push(&head,4);
	push(&b,2);
	push(&a,1);
	//push(&head,6);
	head = sortedMerge(a,b);
	//append(&a,&b);
	print(head,"head");

	return 0;
}
