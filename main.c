#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//struct for linked list nodes
typedef struct Node {
	int number;
	struct Node* next;
}Node;


//divide by all prime numbers before
//store linked list of all previous primes
//linked list is best because we can just divide in order and add to the end. 
//fundamental theorem of arithmetic

int main(int argc, char* argv[]) {
	time_t start_time = time(NULL);
	time_t current_time;
	Node* head = malloc(sizeof(Node));
	Node* curr = head;
	int i = 0;
	int prime = 2;
	int found;
	int count = 0;

	do {
		//15 second timer
		current_time = time(NULL);
		if (prime == 2 || prime % 2 == 1) {
			found = find_prime(prime, &count);
			curr->number = found;
			//allocate space for next node and store it in current
		}

		++prime;

		if ((int)(current_time - start_time) > i) {
			i = (int)(current_time - start_time);
			printf("%d seconds elapsed!\n", i);
		}
	} while (difftime(current_time, start_time) < 1);


	printf("highest prime found: %d\n", found);
	printf("number of primes found: %d\n", count);
	return 0;
}

//if input is prime return prime
int find_prime(int prime, int* count) {
	for (int i = 2; i < prime / 2; ++i) {
		if (prime % i == 0) {
			return 0;
		}
	}

	++ * count;
	return prime;
}

