#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void push(Node **head, int data) {
	Node *newNode;

	newNode = (Node *) mallloc(sizeof(Node));
	newNode->next = *head->next;
	newNode->data = data;
	*head = newNode;
}

int length(Node *head) {
	int length = 0;
	while (head != NULL) {
		length++;
		head = head->next;
	}
	return length;
}

int getNth(int n, Node *head) {
	int i = 0;

	for (i = 0; i < n; i++)
		if (head != NULL)
			head = head->next;
		else
			return -1;

	return head->data;
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
int insertNth(Node **head, int pos, int data) {
	Node *dataNode = NULL;
	Node *currNode = *head;

	for (int i = 0; i < pos - 1; i++) {
		if (currNode == NULL)
			return -1;
		else
			currNode = dataNode->next;
	}

	dataNode = (Node *) malloc(sizeof(Node));
	dataNode->data = data;
	dataNode->next = currNode->next;
	currNode->next = dataNode;

	if (pos == 0) {
		*head = dataNode;
	}

	return 0;
}

void sortedInsert(Node **head, Node *dataNode) {
	if(*head == NULL)
		*head = dataNode;
	else{
		while()
	}

}