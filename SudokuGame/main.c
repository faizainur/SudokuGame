#include "headerlist.h"
#include "sudoku.h"





struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
char keyword; // keyword char for finding element
char rplChar; // replacment char
time_t t;
        int row, col;


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

int getRand();
void showMenu();

int main(int argc, char const *argv[])
{    
    /* TODO : Program workflow */
    srand(((unsigned)time(&t))); // ONLY RUN ONCE
    BEGIN : init(0);
    showMenu();
    
    if (replaceElement(row, col, rplChar)){
        printf("\nSuccesful");
        system("pause");
        system("cls");
        goto BEGIN;
    } else {
        printf("Error !!");
    }
	return 0;
}

void showMenu(){
    // TODO : Create menussystem("pause");

   
    printf("\nBaris : ");
    scanf("%d", &row);
    printf("\nKolom : ");
    scanf("%d", &col);
     printf("\nChar pengganti : ");
    scanf("%c", &rplChar);
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG
    // TODO : checking if num already used
    
    return num;
    
}