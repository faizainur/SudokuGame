#include "headerlist.h"
#include "sudoku.h"

struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
size_t keyword; // keyword char for finding element
size_t rplChar; // replacment char
size_t temp;
time_t t;
int row, col;

void init(int randNum){
    // ranNum variable ==> random number generated 
    // after player choose 'New Game' menu
    int i, j;
    initTables();
    sudoTbl.arrPtr = arrayList[randNum]; // choosing tables based on random number (ranOp)
    sudoTbl.blankCounter = 0;
    loadTable(sudoTbl.arrPtr, SIZE);
    // Count blank spot in the table
    for (i = 0; i < SIZE; ++i){
        for (j = 0; j < SIZE; ++j){
            /* Do Somthing */
            if (sudoTbl.arrPtr[i][j] == ' '){
                sudoTbl.blankCounter += 1;
            }
        }
    }
    printf("%d", sudoTbl.blankCounter);
}

int getRand();
void showMenu();

int main(int argc, char const *argv[])
{    
    /* TODO : Program workflow */
    // How to FIX IT : add space( ) before %c in scanf function
    srand(((unsigned)time(&t))); // ONLY RUN ONCE
    init(0);
	return 0;
}

void showMenu(){
    // TODO : Create menussystem("pause");
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG
    // TODO : checking if num already used
    
    return num; 
}
