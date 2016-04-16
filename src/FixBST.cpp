/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void findFaultNodes(struct node *root, struct node **node1, struct node **node2, struct node **node3, struct node **before) {
	if (root) {
		findFaultNodes(root->left, node1, node2, node3, before);
		if (*before && root->data < (*before)->data) {
			if (!*node1) {
				*node1 = *before;
				*node3 = root;
			}
			else
				*node2 = root;
		}
		*before = root;
		findFaultNodes(root->right, node1, node2, node3, before);
	}
}

void fix_bst(struct node *root){
	if (!root)
		return;
	struct node *node1 = NULL;
	struct node *node2 = NULL;
	struct node *node3 = NULL;
	struct node *before = NULL;
	findFaultNodes(root, &node1, &node2, &node3, &before);
	if (!node2)
		node2 = node3;
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

