/****************************************************************************
 File name:  main.c
 Author:     Computer Science, Pacific University
 Date:
 Class:      CS300
 Assignment: Rational
 Purpose:    This program is the driver to test each function of the
						 rational module. There is no error checking.
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../include/rational.h"

/****************************************************************************
 Function:    main

 Description: Driver for the reduced fraction

 Parameters:  argc - number of input arguments
							argv - each argument string

 Returned:    EXIT Status
****************************************************************************/
int main (int argc, char *argv[])
{
  Rational sRational1, sRational2, sRational3;

  setRational (&sRational1, 1, 2);
  setRational (&sRational2, 2, 4);

  printRational (&sRational1);
  printf ("\n");
  printRational (&sRational2);
  printf ("\n");

  printf ("Is Equal: %i\n", isEqualRational ( &sRational1,  &sRational2));

  sRational3 = multiplyRational (&sRational1, &sRational2);
  printRational (&sRational3);
  printf ("\n");

  sRational3 = divideRational (&sRational3, &sRational1);
  printRational (&sRational3);
  printf ("\n");

  sRational3 = reduceRational (&sRational3);
  printRational (&sRational3);
  printf ("\n");

  sRational3 = addRational (&sRational3, &sRational3);
  printRational (&sRational3);
  printf ("\n");

  return EXIT_SUCCESS;
}



