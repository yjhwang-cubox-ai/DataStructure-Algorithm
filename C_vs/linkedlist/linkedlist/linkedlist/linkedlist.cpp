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

void insert_node_rear(node** head, int val)
{
	node* newnode = (node*)malloc(sizeof(node));
	//scanf_s("%d", &newnode->value);
	newnode->value = val;
	newnode->next = nullptr;

	node* currentnode = *head;

	if (*head == NULL) {
		*head = newnode;
		return;
	}
		
	while (currentnode->next != nullptr) {
		currentnode = currentnode->next;
	}
		
	currentnode->next = newnode;
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
	node* List = NULL;

	insert_node_rear(&List, 1);
	insert_node_rear(&List, 3);
	insert_node_rear(&List, 2);
	insert_node_rear(&List, 7);
	insert_node_rear(&List, 5);
	display(List);

	return 0;

}