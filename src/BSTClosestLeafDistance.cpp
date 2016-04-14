/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int get_nearest_leaf_of_a_node(struct node *root){
	int leftTreeHeight;
	int rightTreeHeight;
	if (root == NULL)
		return -1;
	leftTreeHeight = get_nearest_leaf_of_a_node(root->left);
	rightTreeHeight = get_nearest_leaf_of_a_node(root->right);
	if (leftTreeHeight == -1 && rightTreeHeight != -1) 
		return rightTreeHeight + 1;
	else if (leftTreeHeight != -1 && rightTreeHeight == -1)
		return leftTreeHeight + 1;
	else if (leftTreeHeight > rightTreeHeight) 
		return rightTreeHeight + 1;
	else
		return leftTreeHeight + 1;
}

void get_near_leaf_of_given_node(struct node *root, struct node *temp, int *near_leaf, int *noOfEdges) {
	int current_near_leaf;
	if (!root)
		return;
	if (root == temp) {
		*noOfEdges = 1;
		*near_leaf = get_nearest_leaf_of_a_node(root);
	} else {
		get_near_leaf_of_given_node(root->left, temp, near_leaf, noOfEdges);
		if (*noOfEdges != 0) {
			current_near_leaf = get_nearest_leaf_of_a_node(root);
			if (*near_leaf > *noOfEdges + current_near_leaf) {
				*near_leaf = *noOfEdges + current_near_leaf;
			}
		} else {
			get_near_leaf_of_given_node(root->right, temp, near_leaf, noOfEdges);
			if (*noOfEdges != 0) {
				current_near_leaf = get_nearest_leaf_of_a_node(root);
				if (*near_leaf > *noOfEdges + current_near_leaf) {
					*near_leaf = *noOfEdges + current_near_leaf;
				}
			}
		}
	}
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (!root || !temp)
		return -1;
	int near_leaf = -1;
	int noOfEdges = 0;
	get_near_leaf_of_given_node(root, temp, &near_leaf, &noOfEdges);
	return near_leaf;
}