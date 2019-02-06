/*****************************************************************************
 *  Author  : Martin Lennartz
 *  Project : ECEN 5813 (Spring '19) Etude #1
 *
 *  Description: 
 *    The following program is a simple link-list program for testing out my
 *  remove_last function. This function will use the "first" pointer to
 *  the list and walk through it until it comes to the last element
 *  (assuming there is any elements) and disconnect it form the list
 *  and return the pointer to the element being removed. 
 *
 *    I added several functions/code to brush up on my C.  I have used C for
 *  over a decade but it has been a couple since I last used it, usually
 *  using C++ instead. I added a DEBUG_MODE switch in the defines to basically
 *  change the verbosity to print a lot more detail if it enabled.
 *  Addtionally, I tried to conform to the style guide, including limiting
 *  my rows to less than 80 characters.
 *  
 *  Some of the code below was provided as a basis to get started. The 
 *  following code was provided in CU BOULDER ECEN 5813:
 *      Sturcture:
 *          element_s
 *      Pointer:
 *          element *first pointer
 *      Functions:
 *          insert_first
 *          remove_first
 *          remove_last  - Definition was provided
*****************************************************************************/

/*------------------------REQUIRED HEADER FILES------------------------*/
#include "main.h"
#include "functions.h"

/*------------------------GLOBAL VARIABLES/POINTERS------------------------*/
/* root of the list - defined in functions.c */
extern element *first;

/***********************************************************
 *  main function
 *
 *  Body of the program to call the create, add, and remove 
 *  functions.
***********************************************************/
int main( void )
{
    /*  Pointer used to create new elements and add to    */
    /*    list pointer will also be used for returns of   */ 
    /*    elements removed from the list                  */
    element *element_ptr = NULL;

    /* allocate space for new element and data_t */
    element_ptr = create_element(D0014);
    insert_first(element_ptr);
    print_list(first);

    element_ptr = create_element(TEN);
    insert_last(element_ptr);
    print_list(first);

    element_ptr = create_element(ZERO);
    insert_first(element_ptr);
    print_list(first);

    element_ptr = create_element(D1024);
    insert_first(element_ptr);
    print_list(first);

    element_ptr = create_element(D0056);
    insert_last(element_ptr);
    print_list(first);

    element_ptr = remove_first();
    print_list(first);

    element_ptr = remove_first();
    print_list(first);

    element_ptr = remove_last();
    print_list(first);

    element_ptr = remove_last();
    print_list(first);

    element_ptr = remove_last();
    print_list(first);

    element_ptr = remove_last();
    print_list(first);

    element_ptr = create_element(ONE);
    insert_last(element_ptr);
    print_list(first);

    element_ptr = create_element(D0250);
    insert_last(element_ptr);
    print_list(first);

    printf("Moving to new section \n");

    for( int ii = 0; ii<4; ii++ )
    {
        in_count();   
    }

    printf("\nEnding new section \n");

    return 0;
}