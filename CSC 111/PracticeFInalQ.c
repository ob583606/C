#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int element;
    struct ListNode* next;
} ListNode;
typedef struct{
    ListNode* head;
} LinkedList;

/* get_last(L)
   Given a pointer to a LinkedList structure, return the value
   of the last node in the list.

   If the list is empty, return 0.

   Parameters: L (pointer to LinkedList)
   Return value (integer):
      - If the list is empty, return 0
      - Otherwise, return the value stored in the last node in the list
*/
int get_last(LinkedList* list_ptr) {
    ListNode* last = NULL;

    if (list_ptr->head == NULL) {
        return 0;
    }
    
    for(ListNode* node = list_ptr->head; node != NULL; node = node->next){
        last = node;
    }
    
    return last->element;
}


void print_list(LinkedList* L){
    for(ListNode* node = L->head; node != NULL; node = node->next){
        printf("%d ", node->element);
    }
    printf("\n");
}
void add_front(LinkedList* L, int new_element){
    ListNode* new_node = malloc( sizeof(ListNode) );
    new_node->element = new_element;
    new_node->next = L->head;
    L->head = new_node;
}
int main(){
    LinkedList L1, L2;
    L1.head = NULL; L2.head = NULL;
    add_front(&L1, 187); add_front(&L1, 17); add_front(&L1, 10); add_front(&L1, 6);
    add_front(&L2, 225); add_front(&L2, 116); add_front(&L2, 111);
    print_list(&L1);
    printf("Last element: %d\n", get_last(&L1) );
    print_list(&L2);
    printf("Last element: %d\n", get_last(&L2) );

    /* The code to delete each node has been omitted for brevity. */
    return 0;
}