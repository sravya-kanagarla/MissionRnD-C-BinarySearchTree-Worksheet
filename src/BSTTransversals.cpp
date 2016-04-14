/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void push(struct node **stack, int *top, struct node *temp) {
	stack[++(*top)] = temp;
}

struct node * pop(struct node ** stack, int *top) {
	return stack[(*top)--];
}

void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	struct node **stack = (struct node **)malloc(sizeof(struct node *) * 50);
	int top = -1;
	int index = 0;
	struct node *temp = root;
	while (1) {
		while (temp) {
			push(stack, &top, temp);
			temp = temp->left;
		}
		temp = pop(stack, &top);
		arr[index++] = temp->data;
		if (top < 0 && !(temp -> right))
			break;
		temp = temp->right;
	}
}

void preorder(struct node *root, int *arr) {
	if (root == NULL || arr == NULL)
		return;
	struct node **stack = (struct node **)malloc(sizeof(struct node *) * 50);
	int top = -1;
	int index = 0;
	struct node *temp = root;
	while (1) {
		while (temp) {
			push(stack, &top, temp);
			arr[index++] = temp->data;
			temp = temp->left;
		}
		temp = pop(stack, &top);
		if (top < 0 && !(temp->right))
			break;
		temp = temp->right;
	}
}

void postorder(struct node *root, int *arr) {
	if (root == NULL || arr == NULL)
		return;
	struct node **stack = (struct node **)malloc(sizeof(struct node *) * 50);
	int top = -1;
	int index = 0;
	struct node *temp;
	while (1) {
		while (root) {
			if (root->right)
				push(stack, &top, root->right);
			push(stack, &top, root);
			root = root->left;
		}
		root = pop(stack, &top);
		if (root->right && stack[top] == root -> right) {
			temp = pop(stack, &top);
			push(stack, &top, root);
			root = temp;
		}
		else {
			arr[index++] = root->data;
			root = NULL;
		}
		if (top < 0 && root == NULL) {
			break;
		}
	}
}