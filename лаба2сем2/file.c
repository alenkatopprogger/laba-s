#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t; 

struct node {
    int data;
    struct node* next; 
};

node_t *newNode(int data) { 

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

node_t* appendBack(node_t* head, int data)
{
    node_t* new_node = newNode(data);

    if (head == NULL) {
        return new_node;
    }

    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = new_node;

    return head;
}

void printList(node_t *head) {

    node_t* cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void main(){

    int count;

    scanf("%d", &count);
    node_t *node1 = newNode(count);
    node_t* head = node1;

    

     while(count != 0){
        
        scanf("%d", &count);

        if (count != 0){
            head = appendBack(head, count);
        }

     }

     printList(head);

}