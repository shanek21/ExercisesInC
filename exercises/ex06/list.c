/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 * 
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 * 
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 * 
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    int val;
    Node *next_node;

    // Return -1 if the list is empty
    if (*list == NULL) {
        return -1;
    }
    
    val = (*list)->val; // store the value of the head node
    next_node = (*list)->next; // store the new head
    free(*list); // free the old head
    *list = next_node; // assign the new head

    return val;
}


/* Adds a new element to the beginning of the list.
 * 
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    *list = make_node(val, *list);
}


/* Removes the first element with the given value
 * 
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    Node *prev_node = NULL;
    Node *curr_node = *list;

    // Find first node with specified value and the node before it
    while (curr_node != NULL && curr_node->val != val) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    // If the end of LL was reached before value was found
    if (curr_node == NULL) {
        return 0; // no node removed
    }

    prev_node->next = curr_node->next; // remove curr_node from LL
    free(curr_node); // free curr_node

    return 1;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 * 
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    Node *prev_node = NULL;
    Node *curr_node = *list;
    Node *next_node;

    while (curr_node != NULL) {
        next_node = curr_node->next; // move next_node forward in LL

        curr_node->next = prev_node; // reverse the current node

        prev_node = curr_node; // move prev_node forward in LL
        curr_node = next_node; // move curr_node forward in LL
    }

    *list = prev_node; // assign the head
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
