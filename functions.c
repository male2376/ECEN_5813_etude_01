/*****************************************************************************
 *
*****************************************************************************/
/*------------------------REQUIRED HEADER FILES------------------------*/
#include "main.h"
#include "functions.h"

/*------------------------GLOBAL VARIABLES/POINTERS------------------------*/
/* root of the list */
element *first = NULL;

/***********************************************************
 *  insert_first function
 *
 *  input  : pointer to element
 *  output : none
 *
 *  Function will add the element of the pointer to the 
 *  front of the linked list pointed to by "first"
***********************************************************/
void insert_first( element *item )
{
    if( DEBUG_MODE )
    {
        /* broke out this way to limit width of row */
        printf
        (
            "Adding Element to Front of List:\n"
            "  Element @ %p with data = %4d <0x%04x> @ %p\n"
            "-------------------------------"
            "-------------------------------"
            "-------------------------------\n",
            item,  
            *(data_t*)item->data,  
            *(data_t*)item->data,  
            item->data 
        );
    }
    item->next = first;
    first = item;
}

/***********************************************************
 *  insert_last function
 *
 *  input  : pointer to element
 *  output : none
 *
 *  Function will add the element of the pointer to the end 
 *  of the linked list pointed to by "first"
***********************************************************/
void insert_last( element *item )
{
    element *walker = first;

    if( DEBUG_MODE )
    {
        /* broke out this way to limit width of row */
        printf
        (
            "Adding Element to End of List:\n"
            "  Element @ %p with data = %4d <0x%04x> @ %p\n"
            "-------------------------------"
            "-------------------------------"
            "-------------------------------\n",
            item,  
            *(data_t*)item->data,  
            *(data_t*)item->data,  
            item->data 
        );
    }

    /* case : empty array */
    if( walker == NULL )
    {
        first = item;
    }
    /* case : only 1 element in array */
    else if( walker->next == NULL )
    {
        walker->next = item;
    }
    else
    {
        /* case : step through list until the end */
        /*        then add element to the end     */
        while(TRUE)
        {
            walker = walker->next;
            if( walker->next == NULL )
            {
                walker->next = item;
                break;
            }
        }
    }
}

/***********************************************************
 *  print_list function
 *
 *  input  : pointer to element
 *  output : none
 *  
 *  This function will walk through the link list and print 
 *  the info for each element out based.
***********************************************************/
void print_list( element *item )
{
    element *next   = item;
    data_t  counter = ZERO;

    if( DEBUG_MODE )
    {
        printf( "Complete Link List:\n" );
    }
    else
    {
        printf( "List:\n" );
    }

    while(TRUE)
    {
        if( next != NULL )
        {
            if( DEBUG_MODE )
            {
                /* broke out this way to limit width of row */
                printf
                (
                    "  Element %2d @ %p with data = %4d <0x%04x> @ %p\n",
                    counter, 
                    next,  
                    *(data_t*)next->data,  
                    *(data_t*)next->data,  
                    next->data 
                );
            }
            else
            {
                printf( "  0x%04x\n", *(data_t*)next->data );
            }
            next = next->next;
            counter++;
        }
        else
        {
            /* broke out this way to limit width of row */
            printf
            (
                "-------------------------------"
                "-------------------------------"
                "-------------------------------\n"
            );
            break;
        }
    }
}

/***********************************************************
 *  create_element function
 *
 *  input  : value of type data_t
 *  output : pointer to element
 *
 *  This function will create a new element by allocating
 *  new space.  It will also take the input value and 
 *  allocate space for it, assigning the data pointer to
 *  the allocated data space. The function will then return
 *  the pointer to this element.
***********************************************************/
element * create_element( data_t input_data )
{
    data_t  *val;
    element *next;

    next = malloc(sizeof(element));
    val  = malloc(sizeof(data_t));

    *val = input_data;

    next->data = val;

    if( DEBUG_MODE )
    {
        /* broke out this way to limit width of row */
        printf
        (
            "Creating New Element:\n"
            "  Element @ %p with data = %4d <0x%04x> @ %p\n"
            "-------------------------------"
            "-------------------------------"
            "-------------------------------\n",
            next,  
            *(data_t*)next->data,  
            *(data_t*)next->data,  
            next->data 
        );
    }

    return next;
}

/***********************************************************
 *  remove_first function
 *
 *  input  : none
 *  output : pointer to element
 *
 *  This function will remove and return item from beginning 
 *  of list. returns 0 (NULL pointer) if list is empty.
***********************************************************/
element * remove_first( void )
{
    element *removed = first;
    if( first != NULL )
    {
        first = first->next;

        if( DEBUG_MODE )
        {
            /* broke out this way to limit width of row */
            printf
            (
                "Removing Front Element from List:\n"
                "  Element @ %p with data = %4d <0x%04x> @ %p\n"
                "-------------------------------"
                "-------------------------------"
                "-------------------------------\n",
                removed,  
                *(data_t*)removed->data,  
                *(data_t*)removed->data,  
                removed->data 
            );
        }
    }
    return removed;
}

/***********************************************************
 *  remove_last function
 *
 *  input  : none
 *  output : pointer to element
 *
 *  This function will remove and return item from end of 
 *  list. returns 0 (NULL pointer) if list is empty.
***********************************************************/
element * remove_last( void )
{
    element *walker = first;
    element *shadow = NULL;

    /* case : list is empty */
    if( walker == NULL )
    {
        if( DEBUG_MODE )
        {
            /* broke out this way to limit width of row */
            printf
            (
                "Removing Last Element from List:\n"
                "  Nothing to remove\n"
                "-------------------------------"
                "-------------------------------"
                "-------------------------------\n"
            );
        }
        /* return NULL since no elements in list */
        return NULL;
    }
    /* case : only element in array */
    else if( walker->next == NULL)
    {
        /* set list pointer to NULL since only element removed */
        first = NULL;

        if( DEBUG_MODE )
        {
            /* broke out this way to limit width of row */
            printf
            (
                "Removing Last Element from List:\n"
                "  Element @ %p with data = %4d <0x%04x> @ %p\n"
                "-------------------------------"
                "-------------------------------"
                "-------------------------------\n",
                walker,  
                *(data_t*)walker->data,  
                *(data_t*)walker->data,  
                walker->data 
            );
        }
        
        /* return the only element in list */
        return walker;
    }
    /* case : array with more than 1 element */
    else
    {
        /* walk/loop through the rest of the array */
        while(TRUE)
        {
            /* advance walking pointers */
            shadow = walker;
            walker = walker->next;

            /* case : last element in array */
            if( walker->next == NULL )
            {
                /* set new end of array */
                shadow->next = NULL;

                if( DEBUG_MODE )
                {
                    /* broke out this way to limit width of row */
                    printf
                    (
                        "Removing Last Element from List:\n"
                        "  Element @ %p with data = %4d <0x%04x> @ %p\n"
                        "-------------------------------"
                        "-------------------------------"
                        "-------------------------------\n",
                        walker,  
                        *(data_t*)walker->data,  
                        *(data_t*)walker->data,  
                        walker->data 
                    );
                }

                /* return pointer to disconnected element */
                return walker;   
            }
        }
    }
}

void in_count( void )
{
    static int ii = 0;

    fflush(stdout);
    printf("\rCounting up to %3d\r", ii++ );
    fflush(stdout);
    printf("\rRunning\r");
}