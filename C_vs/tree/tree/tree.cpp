#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int val;
	struct tree* left;
	struct tree* right;
}tree;

void display(tree* t) {
	if (t) 
	{
		printf("%d ", t->val);
		display(t->left);		
		display(t->right);
	}	
}

tree* addNode(tree* t, int data)
{
	if (!t)
	{
		t = (tree*)malloc(sizeof(tree));
		t->val = data;
		t->right = NULL;
		t->left = NULL;
	}
	else if (data < t->val)
		t->left = addNode(t->left, data);
	else if (data > t->val)
		t->right = addNode(t->right, data);

	return t;
}

tree* addNode(tree* t, int data) {
	if (!t) {
		t = (tree*)malloc(sizeof(tree));
		t->val = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (data < t->val)
		t->left = addNode(t->left, data);
	else if (data > t->val)
		t->right = addNode(t->right, data);

	return t;
}

tree* findMax(tree* t) {
	if (t)
	{
		while (t->right) {
			t = t->right;
		}
	}
	return t;
}

tree* findMin(tree* t) {
	if (t)
	{
		while (t->left) {
			t = t->left;
		}
	}
	return t;
}

tree* remove(tree* t, int data) 
{
	tree* temp = nullptr;
	
	if (t)
	{
		if (data == t->val)
		{
			if (t->left == NULL && t->right == NULL)
			{
				free(t);
				return NULL;
			}
			else
			{
				if (t->left == NULL) {
					temp = t->right;
					free(t);
					return temp;
				}
				if (t->right == NULL) {
					temp = t->left;
					free(t);
					return temp;
				}
				temp = findMax(t->left);
				t->val = temp->val;
				t->left = remove(t->left, temp->val);
			}
		}
		else
		{
			if (data < t->val)
				t->left = remove(t->left, data);
			else
				t->right = remove(t->right, data);
		}
		return t;
	}
}

int get_inorder_index(int* inorder, int begin, int end, int target) {
	for (int i = begin; i <= end; i++) {
		if (inorder[i] == target)
			return i;
	}
	return -1;
}

tree* tree_restore(int* preorder, int* inorder, int begin, int end) {
	static int preIdx = 0;
	tree* newNode = NULL;

	if (begin <= end)
	{
		newNode = (tree*)malloc(sizeof(tree));
		newNode->val = preorder[preIdx++];
		newNode->left = newNode->right = NULL;
		int inIdx = get_inorder_index(inorder, begin, end, newNode->val);
		newNode->left = tree_restore(preorder, inorder, begin, inIdx - 1);
		newNode->right = tree_restore(preorder, inorder, inIdx + 1, end);
	}

	return newNode;
}

int main() {
	/*tree* test = (tree*)malloc(sizeof(tree));
	test->val = 6;
	test->left = NULL;
	test->right = NULL;

	addNode(test, 4);
	addNode(test, 8);
	addNode(test, 2);
	addNode(test, 5);
	addNode(test, 7);
	addNode(test, 9);
	addNode(test, 1);
	addNode(test, 3);

	display(test);*/

	tree* root = NULL;
	int preorder[6] = { 1,2,4,5,3,6 };
	int inorfer[6] = { 4,2,5,1,6,3 };



	return 0;
}
