/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * deQ(struct node **Q, int *front) {
	struct node *temp = Q[*front];
	*front = (*front % 50) + 1;
	return temp;
}

void enQ(struct node **Q, int *end, struct node *temp) {
	Q[*end] = temp;
	*end = *end % 50 + 1;
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (!root)
		return NULL;
	int *arr = (int *)malloc(sizeof(int) * 50);
	struct node **Q = (struct node **) malloc(sizeof(struct node *) * 50);
	int index = 0;
	int front = 0;
	int end = 0;
	while (front <= end) {
		arr[index++] = root->data;
		if (root->right)
			enQ(Q, &end, root->right);
		if (root -> left)
			enQ(Q, &end, root->left);
		root = deQ(Q, &front);
	} 
	return arr;
}
