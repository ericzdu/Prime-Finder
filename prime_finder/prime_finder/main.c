#include "filter.h"

//divide by all prime numbers before
//store linked list of all previous primes
//linked list is best because we can just divide in order and add to the end. 
//fundamental theorem of arithmetic

Node* head = NULL; 
Node* curr = NULL;

int main(int argc, char* argv[]) {

	time_t start_time = time(NULL);
	time_t current_time;
	int i = 0;
	int j = 1;
	int prime = 1;
	int count = 0, found = 0, result = 0;

	do {
		//15 second timer
		current_time = time(NULL);

		//initial filtering method, filter odd numbers > 1
		found = find_prime(++prime, &count);
		if (found) {
			result = found; 
			push_to_linked_list(found, count); 
		}

		//second filtering method, filter numbers 6n+1 and 6n-1, where n is positive

		if ((int)(current_time - start_time) > i) {
			i = (int)(current_time - start_time);
			printf("%d seconds elapsed!\n", i);
		}

		if (curr && curr->data.count % j == 0) {
			printf("%dth prime number: %d\n", j, curr->data.number);
			j *= 2;
		}

	} while (difftime(current_time, start_time) < 1);

	printf("highest prime found: %d\n", result);
	printf("number of primes found: %d\n", count);

	//print and free all primes: 
	curr = head;
	while (curr != NULL) {
		/*if (curr->data.count % i == 0) {
			printf("%dth prime number: %d", i, curr->data.number);
		}*/
		//printf("num:%d count:%d, ", curr->data.number, curr->data.count);
		Node* temp = curr;
		curr = curr->next;

		free(temp);
	}

	return 0;
}