/****************************************************************************
 File name:  rational.c
 Author:     Computer Science, Pacific University
 Date:
 Class:      CS300
 Assignment: Rational
 Purpose:    This is the implementation file for each of the rational
             functions associated with the rational module. There is no
             error checking.
****************************************************************************/

#include <stdio.h>
#include "../include/rational.h"

/****************************************************************************
 Function:    setRational

 Description: Initializes a fraction to the values of the numerator and
              denominator passed in.

 Parameters:  psRational  - a fraction
              numerator   - numerator initialization value
							denominator - denominator initialization value

 Returned:    None
****************************************************************************/


void setRational (Rational *psRational, int numerator, int denominator)
{
	psRational->numerator = numerator;
	psRational->denominator = denominator;
}

/****************************************************************************
 Function:    getRational

 Description: Reads a Rational number from the keyboard

 Parameters:  psRational  - a fraction

 Returned:    None
****************************************************************************/


void getRational (Rational *psRational)
{
	char slash;

	scanf ("%d %c %d", &(psRational->numerator), &slash,
										 &(psRational->denominator));
}

/****************************************************************************
 Function:    printRational

 Description: Outputs a fraction in the form
              numerator / denominator to the screen

 Parameters:  psRational - a fraction to be printed

 Returned:    None
****************************************************************************/
void printRational (const Rational *psRational)
{

  printf ("%d / %d", psRational->numerator, psRational->denominator);
}

/****************************************************************************
 Function:    isEqualRational

 Description: Compares two fractions returning a value of true if the
              numerators and denominators of both fractions are the same.

 Parameters:  psRational1 - first fraction used in comparison
              psRational2 - second fraction used in comparison

 Returned:    true if objects are equal; else, false
****************************************************************************/


bool isEqualRational (const Rational *psRational1, const Rational *psRational2)
{
  return ((psRational1->numerator == psRational2->numerator) &&
          (psRational1->denominator == psRational2->denominator));
}

/****************************************************************************
 Function:    multiplyRational

 Description: Multiples the numerators and denominators of two fractions.

 Parameters:  psRational1 - first rational number
              psRational2 - second rational number

 Returned:    A fraction that contains the result of the multiplication
							not reduced
****************************************************************************/

Rational multiplyRational (const Rational *psRational1,
													 const Rational *psRational2)
{
  Rational sFraction;

  sFraction.numerator = psRational1->numerator * psRational2->numerator;
  sFraction.denominator = psRational1->denominator * psRational2->denominator;

  return sFraction;
}

/****************************************************************************
 Function:    multiplyRational

 Description: Multiples the numerators and denominators of two fractions.

 Parameters:  psRational1 - first rational number
              psRational2 - second rational number

 Returned:    A fraction that contains the result of the multiplication.
****************************************************************************/

Rational divideRational (const Rational *psRational1,
												 const Rational *psRational2)
{
  Rational sFraction;

  setRational (&sFraction, psRational2->denominator, psRational2->numerator);
  sFraction = multiplyRational (psRational1, &sFraction);

  return sFraction;
}

/***************************************************************************
 Method:	    gcd

 Description: Finds the greatest common divisor of two integers

 Parameters:  num1 - first integer
              num2 - second integer

 Returned:    The greatest common divisor is returned
***************************************************************************/
static int gcd (int num1, int num2)
{
	int lower = num1;
	int gcdVal = 1;
	int i;

	if (num2 < num1)
	{
		lower = num2;
	}

	for (i = lower; i > 1 && gcdVal == 1; --i)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			gcdVal = i;
		}
	}
	return gcdVal;
}
/****************************************************************************
 Function:	  reduceRational

 Description: Divides the numerator and denominator of a Rational number
              by the greatest common divisor

 Parameters:  psRational - a rational number

 Returned:    A reduced rational
****************************************************************************/
Rational reduceRational (const Rational *psRational)
{
	Rational sRational;
	int divisor;

	setRational (&sRational, psRational->numerator, psRational->denominator);

	divisor = gcd (psRational->numerator, psRational->denominator);

	if (1 != divisor)
	{
		sRational.numerator /= divisor;
		sRational.denominator /= divisor;
	}

	return sRational;
}


/****************************************************************************
 Function:    addRational

 Description: Adds two rational numbers a/b + c/d = (ad + bc) / bd

 Parameters:  psRational1 - first rational number
              psRational2 - second rational number

 Returned:    A fraction that contains the result of the addition
****************************************************************************/
Rational addRational (const Rational *psRational1,
											const Rational *psRational2)
{
	Rational sFraction;

  sFraction.numerator = (psRational1->numerator * psRational2->denominator) +
												(psRational2->numerator * psRational1->denominator);
  sFraction.denominator = psRational1->denominator * psRational2->denominator;

  return sFraction;
}


