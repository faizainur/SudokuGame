#include "headerlist.h"
#include "sudoku.h"





struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
size_t keyword; // keyword char for finding element
size_t rplChar; // replacment char
size_t temp;time_t t;
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
void fetchTable(char[][SIZE], char[][SIZE]);

int main(int argc, char const *argv[])
{    
    /* TODO : Program workflow */
    // How to FIX IT : add space( ) before %c in scanf function
    srand(((unsigned)time(&t))); // ONLY RUN ONCE
    BEGIN : init(0);
    if (replaceElement(row, col, rplChar)){
        goto BEGIN;
    } else {
        printf("Error replacing element !!!");
    }
	return 0;
}

void showMenu(){
    // TODO : Create menussystem("pause");

    printf("\nChar pengganti, baris, dan kolom : ");
    scanf(" %c %d %d", &rplChar, &row, &col);
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG
    // TODO : checking if num already used
    
    return num; 
}

void fetchTable(char origin[][SIZE], char des[][SIZE]){
    int i, j;
    for (i = 0; i < SIZE; ++i){
        for (j = 0; j < SIZE; ++j){
            des[i][j] = origin[i][j];
        }
    }
}

/* init(0);
    showMenu();
    
    if (replaceElement(row, col, rplChar)){
        printf("\nSuccesful");
        system("pause");
        system("cls");
        loadTable(sudoTbl.arrPtr, SIZE);
        showMenu();
        if (replaceElement(row, col, rplChar)){
            printf("\nSuccesful");
            system("pause");
            system("cls");
            loadTable(sudoTbl.arrPtr, SIZE);
            showMenu();
        } else {
            printf("Error !!");
        }
    } else {
        printf("Error !!");
    } */