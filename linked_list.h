//
//  linked_list.h
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright � 2020 macOne. All rights reserved.
//
 
#ifndef linked_list_h
#define linked_list_h
 
typedef struct str_node * link;

typedef struct str_node
{
	int data;
    link next;
    link prev;
} node;
typedef struct list_node {
    node* head;
    node* tail;
} product_list;
 
node* create_node(const int data);
int is_empty(node* const head);
void add(node **head, const int data);
void remove_node (node** head, node* target);
void print_list(node* head);
void clear_list(node **head);
void push(node** head, node* new_node);
void swap(node* p, node* q);
void insertion_sort(node** head);
int find_max_of_linked_list(node* head);
int find_sum_of_linked_list(node* head);
#endif /* linked_list_h */
