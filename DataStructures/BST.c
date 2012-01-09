#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	int data;
} Node;

int insert(Node **head, int data) {
	if (*head) {
		if (data <= (*head)->data)
			return insert(&(*head)->left, data);
		else
			return insert(&(*head)->right, data);
	}
	*head = (Node *) malloc(sizeof(Node));
	if (!*head)
		return -1;

	(*head)->data = data;
	(*head)->left = NULL;
	(*head)->right = NULL;
	return 0;

}

void print(Node *head) {
	if (head) {
		print(head->left);
		printf("%d ", head->data);
		print(head->right);
	}

}

int delete(Node **head, int data) {
	Node *temp;
	if (!(*head))
		return -1;

	if (data < (*head)->data)
		return delete(&(*head)->left, data);
	else if (data > (*head)->data)
		return delete(&(*head)->right, data);

	if (!(*head)->left && !(*head)->right) {
		free(*head);
		*head = NULL;
		return 1;
	}

	if ((*head)->left && (*head)->right) {
		temp = (*head);
		while (temp->left->left)
			temp = temp->left;
		(*head)->data = temp->left->data;
		return delete(&(temp->left), temp->left->data);
	}

	temp = *head;
	if ((*head)->left)
		*head = temp->left;
	else
		*head = temp->right;
	free(temp);
	return 1;
}

void freeNode(Node *head) {
	if (head) {
		freeNode(head->left);
		freeNode(head->right);
		free(head);
	}
}

void trimTree(Node **head, int A, int B) {

	Node *temp;

	if (!(*head))
		return;
	if ((*head)->data < A) {
		temp = *head;
		*head = (*head)->right;
		freeNode(temp->left);
		free(temp);
		trimTree(head, A, B);
	} else if ((*head)->data > B) {
		temp = *head;
		*head = (*head)->left;
		freeNode(temp->right);
		free(temp);
		trimTree(head, A, B);
	} else {
		trimTree(&((*head)->left), A, B);
		trimTree(&((*head)->right), A, B);
	}
}

Node *findSucess(Node *head, int data) {
	Node *temp;
	if (!head)
		return NULL;

	if (head->data == data)
		return head->right;
	if (data < head->data) {
		temp = findSucess(head->left,data);
		return temp ? temp : head;
	} else
		return findSucess(head->right,data);
}

int main() {
	int i = 0;
	unsigned int iseed = (unsigned int) time(NULL);
	srand(iseed);

	Node *head = NULL;
	insert(&head, 5);
	insert(&head, 2);
	insert(&head, 12);

	insert(&head, -4);
	insert(&head, 3);

	insert(&head, 9);
	insert(&head, 21);

	insert(&head, 19);
	insert(&head, 25);

	print(head);
//delete(&head, 9);
//delete(&head, 12);

	//trimTree(&head, 4, 4);
	printf("\n");
	printf("%d",findSucess(head,25)->data);
	return 0;
}