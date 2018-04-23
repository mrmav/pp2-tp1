/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: prototypes for utility functions
*/

#ifndef UTILITYFUNCTIONS
#define UTILITYFUNCTIONS

#include "Types.h"

/*
Prints a line
*/
void printLine(int size);

/*
Prints information about the given node
*/
void printNode(Node* n);

/*
Resets a Node by populating it with a new sequence
*/
void resetNode(Node* n);

/*
Allows to perform a function in each node.
It works by cycling through the linked list
and calling the function given as a parameter.
*/
void forEachNode(Node* head, void(*f)(Node* n));


/*
Prints information about the given row
*/
//void printRow(Row* r);

/*
Prints information about the given matrix
*/
//void printMatrix(Matrix* m);

/*
Returns number between min and max-1
*/
int randomInt(int min, int max);

/*
Asks user to input matrix card data and validates operation.
Returns 1 if sucessfull, 0 otherwise.
*/
//int validateOperation(Matrix* matrix);

/*
Checks if given digit is correct
*/
//int validatePosition(int ans, int row, int col, int digit, Matrix* matrix);

#endif // !UTILITYFUNCTIONS
