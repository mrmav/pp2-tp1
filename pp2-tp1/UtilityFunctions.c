/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include "Types.h"
#include "UtilityFunctions.h"

void printLine(int size) {

	for (int i = 0; i < size; i++) {
		printf("-");
	}

}

void printNode(Node* n) {

	for (int i = 0; i < SEQUENCE_SIZE; i++) {

		printf("%i", n->sequence[i]);

	}

};

void printRow(Row* r) {
	
	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		printf(" ");
		printNode(r->nodes[i]);
		printf(" |");
	}
};

void printMatrix(Matrix* m) {

	//print a line
	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	printf("\n");

	//print column labels
	printf("| \\ |");
	for (int i = 1; i < COLUMNS_NUMBER * (SEQUENCE_SIZE + 3); i++) {
		
		if((i) % (SEQUENCE_SIZE + 3) == 0) {
		
			printf("|");
		
		}
		else if((i + SEQUENCE_SIZE) % (SEQUENCE_SIZE + 3) == 0 ) {

			printf("%i", (i + SEQUENCE_SIZE) / (SEQUENCE_SIZE + 3));

		}
		else {

			printf(" ");
		}

	}
	printf("|\n");

	//print a line
	//printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	//printf("\n");

	for (int i = 0; i < ROWS_NUMBER; i++) {

		printf("| %c |", 65 + i);
		printRow(m->rows[i]);
		printf("\n");
	}
	
	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	
	printf("\n");
	
};

int randomInt(int min, int max) {

	return rand() % (max - min) + min;

}

int validateOperation(Matrix* matrix) {

	int isValid = 0;

	printf("Please validate the operation using your Matrix Card.\n");

	for (int i = 0; i < SECURITY_LEVEL; i++) {

		int row, col, digit, ans;
		char rowChar;

		row   = randomInt(0, ROWS_NUMBER - 1);
		col   = randomInt(0, COLUMNS_NUMBER - 1);
		digit = randomInt(0, SEQUENCE_SIZE - 1);
		
		rowChar = 65 + row;

		printf("Check %i out of %i.\n", i + 1, SECURITY_LEVEL);
		printf("Please input the corresponding digit in the cell %c%i, position %i:\n", rowChar, col + 1, digit + 1);
		printf("> ");

		scanf("%i", &ans);
		getchar();

		isValid = validatePosition(ans, row, col, digit, matrix);
		
	}

	return isValid;

}

int validatePosition(int ans, int row, int col, int digit, Matrix* matrix) {

	// digits should be only between 0-9 inclusive
	if (ans > 9 || ans < 0) {

		return 0;

	}

	// get the matrix digit in the given position
	int matrixDigit = matrix->rows[row]->nodes[col]->sequence[digit];
	
	if (matrixDigit == ans) {

		return 1;

	}
	else {

		return 0;

	}

}
