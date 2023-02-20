//
//  linked_list.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright � 2020 macOne. All rights reserved.
//
 
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
 
node* create_node(const int data)
{
	node *n = (node*) malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}
int is_empty(node* const head)
{
	return head == NULL;
}
 
void add(node **head, const int data)
{	
	node *n = create_node(data);
	if (is_empty(*head)) {
		*head = n;
	} else {
		push(head, n);
	}
}

void push(node** head, node* new_node) {
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL) {
		(*head)->prev = new_node;
	}
	*head = new_node;
}

void swap(node* a, node* b)
{
	 

	if (a->next == b) { // right next to each other
		a->next = b->next;
		b->prev = a->prev;

		if (a->next != NULL)
			a->next->prev = a;

		if (b->prev != NULL)
			b->prev->next = b;


		b->next = a;
		a->prev = b;
	}
	else {
		node* p = b->prev;
		node* n = b->next;

		b->prev = a->prev;
		b->next = a->next;

		a->prev = p;
		a->next = n;

		if (b->next != NULL)
			b->next->prev = b;
		if (b->prev != NULL)
			b->prev->next = b;

		if (a->next != NULL)
			a->next->prev = a;
		if (a->prev != NULL)
			a->prev->next = a;

	}
}


void insertion_sort(node** head) {
	add(head, (*head)->data);
	for (node* i = (*head)->next; !is_empty(i); i = i->next) {
		
		node* j = i->prev;
		for (j; j != *head && j->data > i->data; j = j->prev) {
			//swap(j->next, j);
		}
		//j = j->prev;
		swap(j->next, i);
	}
	remove_node(head, *head);
}

int find_max_of_linked_list(node* head)
{
	int x = 0;
	if (head == NULL)
		return INT_MIN;
	x = find_max_of_linked_list(head->next);
	if (x > head->data)
		return x;
	else
		return head->data;
}

int find_sum_of_linked_list(node* head)
{
	if (is_empty(head)) {
		return 0;
	}
	return find_sum_of_linked_list(head->next) + head->data;
}


void remove_node (node** head, node* target) {
	if(*head == NULL || target == NULL) {	
		return;
	}
	if(*head == target) {
		*head = target->next;
	}
	if (target->next != NULL) {
		target->next->prev = target->prev;
	}
	if(target->prev != NULL) {
		target->prev->next = target->next;
	}
	free(target);
}


void print_list(node* head) {
	/*if (is_empty(head)) {
		return;
	}
		printf("[%d]->",head->data);
	print_list_recursive(head->next);*/
	if (is_empty(head)) printf("Empty list!\n");
	else
	{
		node* p = head;
		while (p != NULL)
		{
			printf("[%d]->", p->data);
			p = p->next;
		}
		printf("[]\n");
	}
}



 
void clear_list(node **head)
{
	if (is_empty(*head)) return;
	while (*head != NULL)
	{
		node *p = *head;
		*head = p->next;
		free(p);
	}
}
