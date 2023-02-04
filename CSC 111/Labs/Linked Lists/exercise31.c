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

/* list_size( list_ptr ) 
   Return the size (number of nodes) of the provided list.
*/
int list_size( LinkedList* list_ptr ){
    int values;
    ListNode* current_node = list_ptr->head;
    while(current_node != NULL){
        values += 1;
        current_node = current_node->next;
    }
    return values;
}

/* add_front( list_ptr, new_element ) 
   Given a pointer to a LinkedList object and an integer element,
   add a new node containing the provided element at the beginning of the list.
*/
void add_front( LinkedList* list_ptr, int new_element ){
    /* Your code here:
	- Create a new node using malloc()
	- Set the element in the new node to be the provided value
	- Set the next pointer in the new node as needed
	- Set the head pointer of the LinkedList object as needed.
    */
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
    /* Your code here */
    if (list_ptr->head == NULL) {
        printf("No node to delete.\n");
    }
    else {
        ListNode* deleteNode = list_ptr->head;
        list_ptr->head = deleteNode->next;
        free(deleteNode);
    }
}

int main(){

    LinkedList L;
    L.head = NULL; //Set the head of the list to be NULL to indicate that the list is empty.
    printf("Part A\n");
    printf("Contents of L: ");
    print_list(&L); //Should print nothing (since the list is empty)
    printf("Size of L: %d\n", list_size(&L) );

    add_front(&L, 10);

    printf("Part B\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Size of L: %d\n", list_size(&L) );

    add_front(&L, 6);
    add_front(&L, 17);
    add_front(&L, 187);

    printf("Part C\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Size of L: %d\n", list_size(&L) );

    printf("Done testing add_front\n");

    remove_front(&L);

    printf("Part D\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Size of L: %d\n", list_size(&L) );

    remove_front(&L);
    remove_front(&L);
    remove_front(&L);

    printf("Part E\n");
    printf("Contents of L: ");
    print_list(&L);
    printf("Size of L: %d\n", list_size(&L) );

    return 0;
}