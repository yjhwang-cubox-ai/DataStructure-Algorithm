#include <stdio.h>
#include <memory>

typedef struct node {
	int value;
	struct node* next;
} node;

node* head = NULL;

void insert_node_front(node** head)
{
	node* newnode = (node*)malloc(sizeof(node));
	scanf_s("%d", &newnode->value);
	newnode->next = NULL;

	if (head == NULL) {
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
 }

void display(node* head)
{
	node* currentnode = NULL;
	currentnode = head;

	while (currentnode != NULL) {
		printf("%d  ", currentnode->value);
		currentnode = currentnode->next;
	}
}

int main() {
	node* head = NULL;

	insert_node_front(&head);
	insert_node_front(&head);
	insert_node_front(&head);
	insert_node_front(&head);
	insert_node_front(&head);
	display(head);

	return 0;

}