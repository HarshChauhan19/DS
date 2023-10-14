#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

int main()

{

struct Term {
    int coefficient;
    int x_exponent;
    int y_exponent;
};

struct Term polynomial[3]; // Assuming there are three terms in the polynomial

// Term 1: 2x^2
polynomial[0].coefficient = 2;
polynomial[0].x_exponent = 2;
polynomial[0].y_exponent = 0;

// Term 2: 5xy
polynomial[1].coefficient = 5;
polynomial[1].x_exponent = 1;
polynomial[1].y_exponent = 1;

// Term 3: y^2
polynomial[2].coefficient = 1; // Assuming the coefficient for y^2 is 1
polynomial[2].x_exponent = 0;
polynomial[2].y_exponent = 2;

}