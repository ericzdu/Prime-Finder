#include "header.h"

//TODO: return 0 if failed
void push_to_linked_list(int x, int count) {
	Node* next = malloc(sizeof(Node));
	if (next == NULL) {
		//free all previously allocated nodes
		curr = head;
		while (curr != NULL) {
			Node* temp = curr;
			curr = curr->next;
			free(temp);
		}
		exit(1);
	}

	next->data.number = x;
	next->data.count = count;
	next->next = NULL;

	if (head == NULL) {
		head = next;
		curr = next;
	}
	else {
		curr->next = next;
		curr = next;
	}
}

