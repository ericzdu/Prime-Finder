#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct Data {
	int number;
	int count;
}Data;

//struct for linked list nodes
typedef struct Node {
	Data data;
	struct Node* next;
}Node;

int fast_overshoot_sqrt(float x) {
	union {
		float f;
		uint32_t i;
	} conv;

	conv.f = x;
	conv.i = (conv.i >> 1) + 0x1FE6A09E;  // Biased to overshoot, goal is to overshoot as little as possible while still being efficient
	return conv.f;
}

//if input is prime return prime
//check up to the sqrt of the number
int find_prime(int prime, int* count, Node* head) {
	//TODO: find a better way to approximate sqrt 
	int threshold = fast_overshoot_sqrt(prime); //81199397
	//int threshold = sqrt(prime); //8499599

	Node* curr = head; 
	while (curr->data.number < threshold) {
		if (prime % curr->data.number == 0) {
			return 0; 
		}
		curr = curr->next; 
	}

	//for (int i = 3; i < threshold; ++i) {
	//	if (prime % i == 0) {
	//		return 0;
	//	}
	//}

	++(*count);
	return prime;
}

//divide by all prime numbers before
//store linked list of all previous primes
//linked list is best because we can just divide in order and add to the end. 
//fundamental theorem of arithmetic

int main(int argc, char* argv[]) {
	time_t start_time = time(NULL);
	time_t current_time;
	Node* head = malloc(sizeof(Node)); //bad practice but oh well
	if (head == NULL) {
		exit(1); 
	}
	head->data.number = 2; 
	head->next = NULL; 
	Node* curr = head; 
	int i = 0;
	int j = 1; 
	int prime = 2;
	int count = -1; //idk why -1 works but it does
	int found = 0;
	int result = 0; 


	do {
		//15 second timer
		current_time = time(NULL);
		if (prime == 2 || prime % 2 == 1) {
			found = find_prime(prime, &count, head);
			if (found) {
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

				next->data.number = found;
				next->data.count = count; 
				next->next = NULL;
				curr->next = next;
				curr = next;
				result = found; 
			}
			//allocate space for next node and store it in current
		}

		++prime;

		if ((int)(current_time - start_time) > i) {
			i = (int)(current_time - start_time);
			printf("%d seconds elapsed!\n", i);
		}

		if (curr->data.count % j == 0) {
			printf("%dth prime number: %d\n", j, curr->data.number);
			j *= 2; 
		}

	} while (difftime(current_time, start_time) < 60);


	printf("highest prime found: %d\n", result);
	printf("number of primes found: %d\n", count);

	//print and free all primes: 
	curr = head; 
	while (curr != NULL) {
		/*if (curr->data.count % i == 0) {
			printf("%dth prime number: %d", i, curr->data.number); 
		}*/
		//printf("%d, ", curr->number);
		Node* temp = curr; 
		curr = curr->next;

		free(temp); 
	}

	return 0;
}
