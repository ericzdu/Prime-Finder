/*
	this file contains different methods to filter for prime numbers
*/

#include "filter.h"

//returns prime if is prime, 0 if not
//if input is prime return prime
//check up to the sqrt of the number
int find_prime(int x, int* count) {
	//TODO: find a better way to approximate sqrt 
	if (x == 2 || x % 2 == 1) {
		float threshold = fast_overshoot_sqrt(x); //81199397

		Node* temp = head;
		while (temp && temp->data.number < threshold + 1) {
			if (x % temp->data.number == 0) {
				return 0;
			}
			temp = temp->next;
		}
	}
	else {
		return 0; 
	}
	++(*count);
	return x; 
}

int find_prime_6x(int x, int* count) {
	//deal with 2 and 3 by calling find_prime
	if (x <= 3) {
		return find_prime(x, count); 
	}

	int low = find_prime(6 * x - 1, count);
	int high = find_prime(6 * x + 1, count); 

	//perform these two and then iterate x
	//6 * x + 1; 
	//6 * x - 1;

	return 0; 
}