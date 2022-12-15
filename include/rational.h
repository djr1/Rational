/****************************************************************************
 File name:  rational.h
 Author:     Computer Science, Pacific University
 Date:
 Class:      CS300
 Assignment: Rational
 Purpose:    To define the header file for the rational module
****************************************************************************/

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <stdbool.h>

typedef struct Rational
{
  int numerator;
  int denominator;
} Rational;

extern void 			setRational (Rational *psRational,
															 int numerator, int denominator);
extern void				getRational (Rational *psRational);
extern void 			printRational (const Rational *psRational);
extern bool 			isEqualRational (const Rational *psRational1,
																	 const Rational *psRational2);
extern Rational 	multiplyRational (const Rational *psRational1,
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  const Rational *psRational2);
extern Rational 	divideRational (const Rational *psRational1,
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	  const Rational *psRational2);
extern Rational		addRational (const Rational *psRational1,
															 const Rational *psRational2);
extern Rational		reduceRational (const Rational *psRational);


#endif

