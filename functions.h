#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*------------------------LIBRARY FILES------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*------------------------FUCNTION DEFINITIONS------------------------*/
/* PROVIDED FUNCTIONS */
void      insert_first    ( element *item );
element * remove_first    ( void );
element * remove_last     ( void );
/* CREATED FUNCTIONS */
element * create_element  ( data_t input_data );
void      insert_last     ( element *item );
void      print_list      ( element *item );

void      in_count        ( void );
#endif