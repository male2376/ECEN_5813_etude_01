
#ifndef MAIN_H
#define MAIN_H

/*------------------------LIBRARY FILES------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*------------------------DEFINED VALUES------------------------*/
#define ZERO  (0)
#define ONE   (0xFACF ^ 0xFACE)
#define TEN   (0x8 | 0x2)

#define D0014 (0xE)
#define D0056 (57 & 0xFFFE)
#define D1024 (1<<10)
#define D0250 (501>>1)

#define TRUE (1)

#define DEBUG_MODE (1)
/* NULL already defined in multiple header files */
/* #define NULL (0) */

/*------------------------TYPEDEFS------------------------*/
/* data configuration type for whole program */
typedef uint16_t data_t;
//typedef int data_t;

/***********************************************************
 *  struct : element_s
 *
 *  The struct is used as the Nodes for each of the Links 
 *  in the Link List. The struct has a pointer to a data 
 *  space and one to what would be the next element in a 
 *  list or NULL;
***********************************************************/
typedef struct element_s
{
  /* user data associated with item */
  void *data; 
  /* points to next item or 0 (NULL pointer) if this is the last item */
  struct element_s *next; 
} element;

/*------------------------FUCNTION DEFINITIONS------------------------*/
/* PROVIDED FUNCTIONS */
void      insert_first    ( element *item );
element * remove_first    ( void );
element * remove_last     ( void );
/* CREATED FUNCTIONS */
element * create_element  ( data_t input_data );
void      insert_last     ( element *item );
void      print_list      ( element *item );

#endif