#include <stdio.h>
#include "ll.h"

// Singly Linked List
// Insert a node at:
// beginning
// end
// given position
// Delete a node by:
// value
// position
// Traverse a linked list
// Find the length of a linked list
// Search an element in a linked list
// Reverse a linked list (iterative & recursive)
// Find the middle of a linked list
// Detect a loop (cycle detection)
// Find the nth node from the end
//
// Doubly Linked List
// Insert and delete nodes
// Reverse a doubly linked list
// Advantages over singly linked list
// Applications of doubly linked list
// ..Circular Linked List
// Difference between circular and singly linked list
// Detect loop in a circular linked list
// Split a circular linked list into two halves
//
// ..Intermediate / Interview-Focused
// Remove duplicates from a sorted linked list
// Remove duplicates from an unsorted linked list
// Check if a linked list is a palindrome
// Merge two sorted linked lists
// Intersection point of two linked lists
// Add two numbers represented by linked lists
// Swap nodes without swapping data
// Pairwise swap nodes
//
// ..Advanced / Tricky
// Clone a linked list with random pointer
// Flatten a multilevel linked list
// Reverse nodes in k-groups
// Segregate even and odd nodes
// Rotate a linked list
// Reorder list (L0 → Ln → L1 → Ln-1)
// Delete nodes having greater value on right
// Sort a linked list (Merge Sort)
// Convert linked list to BST
// LRU Cache using linked list + hashmap

int feat_implemented = 0;
int feat_total = 36;

void print_app_info(char *test)
{
	printf("linked list manipulation\n");
	printf("%s: command option value\n", test);
	printf("%s: insert head value\n", test);
	printf("%s: features completion [%d/%d], %d%\n", test, feat_implemented, feat_total, (feat_implemented*100)/feat_total);
	printf("sample:\n");
	printf("%s insert head 44\n", test);
}

int parse_args(int argc, void *argv[])
{
	print_app_info(argv[0]);	
	return 0;
}

int main(int argc, void *argv[])
{
	if (parse_args(argc, argv))
		return 1;

	return 0;
}
