#include "headerlist.h"
#include "sudoku.h"


struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
char keyword; // keyword char for finding element
char rplChar; // replacment char

void init(int randNum){
    // ranOp variable ==> random number generated 
    // after player choose 'New Game' menu
    int i, j;
    initTables();
    sudoTbl.arrPtr = arrayList[randNum]; // choosing tables based on random number (ranOp)
    if(checkArray(sudoTbl.arrPtr)){ // check array
        loadTable(sudoTbl.arrPtr, SIZE);
    }
}

int static getRand();

int main(int argc, char const *argv[])
{
    init(getRand());
    // printf("\ninput keyword and replacement char : ");
    // scanf("%c %c", &keyword, &rplChar);
    // bool status = findElement(sudoTbl.arrPtr, keyword);
    // if (status){
    //     if (replaceElement(sudoTbl.arrPtr, sudoTbl.keyX, sudoTbl.keyY, rplChar)){
    //         printf("Replacing char success\n");
    //         system("pause");
    //         system("cls");
    //         loadTable(sudoTbl.arrPtr, SIZE);

    //     } else {
    //         printf("Unsuccessful");
    //     }
    // } else {
    //     printf("Not found !!");
    // }
    system("pause");
	return 0;
}

void menu(){
    // Create menu option here
}

int static getRand(){
    time_t t;
    srand((unsigned)time(&t));
    return rand() % ARRAY_CATALOG;
}

