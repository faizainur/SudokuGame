//  sudoku.h, defines application core function
//

#include "headerlist.h"
#include "TableList.h"

#define MAX 100


typedef char arrayPointer[SIZE];
arrayPointer *arrayList[SIZE]; // array of pointer

/* Pointer to array */
arrayPointer *arrayPtr;
arrayPointer *arrayPtr2;

/* initializing sudoku structure */
struct sudokuTable{
	arrayPointer *arrPtr;
	unsigned int blankCounter;
	size_t keyX;
	size_t keyY;
};

struct sudokuTable sudoTbl;


void initTables(){

	/* Assign pointer to arrays */
    arrayPtr = tblElements2;
	arrayPtr2 = tblElements3;

	/* Put pointer to array of pointer */
	arrayList[0] = arrayPtr;
	arrayList[1] = arrayPtr2;
	
} 

bool addTable(char array[][SIZE], size_t size) {
	int row;
	int col;
	for (row = 0; row < size; ++row) {
		
		/* DO SOMETHING */
		

	}
	return true;
}

void loadTable(char array[][SIZE], size_t size){
    int i, j, k;
	printf("\n");
    for (i = 0; i < size; ++i){
        for (j = 0; j < size; ++j){
			if (j == 2 || j == 5){
				printf("%4c   ||", array[i][j]);
			} else if (j == size -1){
				printf("%4c   \n", array[i][j]);
			} else {
				printf("%4c   |", array[i][j]);
			}
        }
        if ( i == 2 || i == 5){
			for (j = 0; j < 73; ++j){
				if (j == (73 - 1)){
					printf("=\n");
				} else if (j == 23 || j == 24 || j == 48 || j == 49) {
					printf("|");
				} else {
					printf("=");
				}
        	}
		} else if (i != size -1) {
			for (j = 0; j < 73; ++j){
				if (j == (73 - 1)){
					printf("-\n");
				} else if (j == 23 || j == 24 || j == 48 || j == 49) {
					printf("|");
				} else {
					printf("-");
				}
        	}
		}
    }
}


bool findElement(char key){
	int i, j;
	// TODO
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			if (sudoTbl.arrPtr[i][j] == key){
				sudoTbl.keyX = i;
				sudoTbl.keyY = j;
				return true;
				break;
			}
		}
	}
	return false;
}

bool replaceElement(size_t keyX, size_t keyY, size_t replaceChar){
	char temp = sudoTbl.arrPtr[keyX - 1][keyY - 1];
	sudoTbl.arrPtr[keyX - 1][keyY - 1] = replaceChar;
	if (sudoTbl.arrPtr[keyX - 1][keyY - 1] != temp){
		return true;
	}
	return false;
}







