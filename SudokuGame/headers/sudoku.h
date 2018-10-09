//  sudoku.h, defines application core function
//

#include "headerlist.h"
#include "TableList.h"
#define MAX 2



typedef char arrayPointer[SIZE];
arrayPointer *arrayList[SIZE]; // array of pointer

/* Pointer to array */
arrayPointer *arrayPtr;
arrayPointer *arrayPtr2;

/* initializing sudoku structure */
struct sudokuTable{
	arrayPointer *arrPtr;
	char keyList[MAX];
	int keyPos[MAX][2];
	int keyX;
	int keyY;
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

bool addTable(char array[][SIZE], int size) {
	int row;
	int col;
	for (row = 0; row < size; ++row) {
		
		/* DO SOMETHING */

	}
	/* if (array == NULL) {
		return false;
	} */
	return true;
}

void loadTable(char array[][SIZE], int size){
    int i, j, k;
    for (i = 0; i < size; ++i){
        if (i == 0){
            for (j = 0; j< 73; ++j){
                if (j == (73 - 1)){
                    printf("=\n");
                } else {
                    printf("=");
                }
            }
        }
        for (j = 0; j < size; ++j){
            if (j == (size - 1)){
                printf("%4c   |\n", array[i][j]);
            } else if (j == 0){
				printf("|%4c   |", array[i][j]);
			}else {
                printf("%4c   |", array[i][j]);
            }
        }
        for (j = 0; j < 73; ++j){
            if (j == (73 - 1)){
                printf("=\n");
            } else {
                printf("=");
            }
        }
    }
}

static bool checkArray(char array[][SIZE]){
	if (array == NULL){ // checking if array == NULL
        printf("Error !! failed initilizing table");
		return false;
	}
	return true;
}

bool findElement(char key){
	int i, j;
    for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			/* Action */
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

bool replaceElement(int keyX, int keyY, char replaceChar){
	char temp = sudoTbl.arrPtr[keyX][keyY];
	sudoTbl.arrPtr[keyX][keyY] = replaceChar;
	if (sudoTbl.arrPtr[keyX][keyY] != temp){
		return true;
	}
	return false;
}






