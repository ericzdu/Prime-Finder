#ifndef HEADER_H
#define HEADER_H
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

float fast_overshoot_sqrt(int x); 

void push_to_linked_list(int number, int count);

extern Node* head;
extern Node* curr;

#endif