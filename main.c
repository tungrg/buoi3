//
//  main.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright � 2020 macOne. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "array_recursive.h"



int main(int argc, const char * argv[]) {
    printf("1.Cai dat insertion sort voi double linked list\n");
	node* list = NULL;
    push(&list, create_node(2));
    push(&list, create_node(1));
    push(&list, create_node(5));
    push(&list, create_node(25));
    push(&list, create_node(13));
    push(&list, create_node(44));
    push(&list, create_node(53));
    push(&list, create_node(21));
    push(&list, create_node(3));
    print_list(list);
    insertion_sort(&list);
    print_list(list);
    printf("-----------------------------\n");
    printf("2.Tim max va sum trong mang\n");
    int a[] = { 1,3,4,5,6,7 };
    printf("-Max cua mang la: %d\n",find_max_of_array(a,6));
    printf("-Sum cua mang la: %d\n", sum_of_array(a, 5));
    printf("-----------------------------\n");
    printf("3.Tim max va sum trong Linked list\n");
    printf("-Sum cua Linked list la: %d\n", find_sum_of_linked_list(list));
    printf("-Max cua Linked list la: %d\n", find_max_of_linked_list(list));
    return 0;
}
