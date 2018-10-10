#include "headerlist.h"
#include "sudoku.h"

#define NULL_CHAR (char)0
#define null 0


struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
int tempArr[ARRAY_CATALOG] = {null};
char keyword; // keyword char for finding element
char rplChar; // replacment char
time_t t;
void init(int randNum){
    // ranNum variable ==> random number generated 
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
    /* TODO : Program workflow */
    srand(((unsigned)time(&t)));
    printf("%d", getRand());
	return 0;
}

void menu(){
    // TODO : Create menus
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG
    // TODO : checking if num already used
    
    return num;
    
}




/* Protoype code */

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