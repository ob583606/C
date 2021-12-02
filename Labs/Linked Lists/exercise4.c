#include <stdio.h>
#include <stdlib.h>

// The ListNode type is used to represent individual nodes of the list
typedef struct ListNode{
    int element;
    struct ListNode* next; //Pointer to the next node in the list, or NULL if no further nodes exist.
} ListNode;

// The LinkedList type is used to represent the entire list (although
// it is actually superfluous since it only contains one thing, it is useful
// to model it this way to improve organization)
typedef struct {
    ListNode* head; //Pointer to the first (head) node in the list, or NULL if the list is empty.
} LinkedList;

/* print_list( list_ptr ) 
   Print the elements of the provided linked list in forwards order.
*/
void print_list( LinkedList* list_ptr ){
    ListNode* current_node = list_ptr->head;
    while(current_node != NULL){
	printf("%d ", current_node->element);
	current_node = current_node->next;
    }
    printf("\n");
}


/* add_front( list_ptr, new_element ) 
   Given a pointer to a LinkedList object and an integer element,
   add a new node containing the provided element at the beginning of the list.
*/
void add_front( LinkedList* list_ptr, int new_element ){
    ListNode* NewNode = malloc( sizeof(ListNode) );
    NewNode->element = new_element;
    NewNode->next = list_ptr->head;
    list_ptr->head = NewNode;
}

/* remove_front( list_ptr ) 
   Delete the first node of the provided list. Remember to use free()
   to deallocate the memory.
*/
void remove_front( LinkedList* list_ptr ){
    if (list_ptr->head == NULL) {
        printf("No node to delete.\n");
    }
    else {
        ListNode* deleteNode = list_ptr->head;
        list_ptr->head = deleteNode->next;
        free(deleteNode);
    }
}

/* count_positive( list_ptr )
   Given a pointer to a LinkedList object, count and return
   the number of elements of the list that are greater than 
   zero. Note that if the list is empty, the return value 
   should be zero.
*/
int count_positive( LinkedList* list_ptr ){
    int total = 0;
    ListNode* current = list_ptr->head;
    if (current == NULL) {
        return 0;
    }

    while (current != NULL) {
        if (current->element > 0) {
            total += 1;
        }
        current = current->next;
    }
    return total;
}


/* compute_average( list_ptr )
   Given a pointer to a LinkedList object, compute the 
   average of the elements in the list. If the list is
   empty, return zero.

   Note that the average must be computed as a 
   floating-point value (even though list elements are 
   integers).
*/
double compute_average( LinkedList* list_ptr ){
    double total = 0;
    float quan = 0;
    ListNode* current = list_ptr->head;
    if (current == NULL) {
        return 0;
    }

    while (current != NULL) {
        quan += 1;
        total += current->element;
        current = current->next;
    }

    return (total/quan);
}

int main(){

    LinkedList L;
    L.head = NULL; //Set the head of the list to be NULL to indicate that the list is empty.
    printf("Part A\n");
    printf("Contents of L: ");
    print_list(&L); //Should print nothing (since the list is empty)
    printf("Positive elements in L: %d\n", count_positive(&L));
    printf("Average of elements in L: %.2f\n", compute_average(&L));

    add_front(&L, 10);

    printf("Part B\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Positive elements in L: %d\n", count_positive(&L));
    printf("Average of elements in L: %.2f\n", compute_average(&L));

    add_front(&L, -6);
    add_front(&L, 0);
    add_front(&L, -17);
    add_front(&L, 187);

    printf("Part C\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Positive elements in L: %d\n", count_positive(&L));
    printf("Average of elements in L: %.2f\n", compute_average(&L));

    remove_front(&L);
    remove_front(&L);
    remove_front(&L);
    remove_front(&L);
    remove_front(&L);

    return 0;
}