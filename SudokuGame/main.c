#include "headerlist.h"
#include "sudoku.h"

struct sudokuTable sudoTbl; // Intializing sudokuTable structure object
size_t keyword; // keyword char for finding element
size_t rplChar; // replacment char
size_t temp;
time_t t;
int row, col;
int wrongIndex[9];
int last;
int getRand();
void helpMenu();
int mainMenu();
int opsi();



void init(int randNum){
    // ranNum variable ==> random number generated 
    // after player choose 'New Game' menu
    int i, j;
    initTables();
    sudoTbl.arrPtr = arrayQList[randNum]; // choosing tables based on random number (ranOp)
    sudoTbl.ansArr = arrayAList[randNum];
    sudoTbl.blankCounter = 0;
    loadTable(sudoTbl.arrPtr, SIZE);
    // Count blank spot in the table
    for (i = 0; i < SIZE; ++i){
        for (j = 0; j < SIZE; ++j)
        {
            /* Do Something */
            if (sudoTbl.arrPtr[i][j] == ' ')
            {
                sudoTbl.blankCounter += 1;
            }
        }
    }
    // printf("%d", sudoTbl.blankCounter);
}

int main(int argc, char const *argv[])
{    
    /* TODO : Program workflow */
    // How to FIX IT : add space( ) before %c in scanf function
    srand(((unsigned)time(&t)));
    int random, i;
    
    int ops = mainMenu();
    switch(ops){
        case 1 :
            goto NEWGAME;
            break;
        case 2 :
            goto EXIT;
    }
    NEWGAME : random = getRand();
    BACKTOGAME : 
	init(random);
    // Input
    printf("Masukkan baris : ");
    scanf("%d", &row);
    printf("Maukkan kolom : ");
    scanf("%d", &col);
    printf("Masukkan char : ");
    scanf(" %c", &rplChar);
    if (replaceElement(row, col, rplChar)){
        sudoTbl.blankCounter -= 1;
        if (sudoTbl.blankCounter == 0){
            bool status = eval(sudoTbl.arrPtr, sudoTbl.ansArr, wrongIndex);
            if (!status){
                system("cls");
                for (i = 0; i < 9; i++){
                    if (wrongIndex[i] != 0) {
                        printf("ada yang salah pada jawaban anda! periksa baris %d\n", i+1);
                    }
                }
                goto BACKTOGAME;
            } else {
                last = random;
                system("cls");
                init(last);
                int stat = opsi();
                if (stat == 1){
                   RAND : random = getRand();
                   if (random != last){
                       goto BACKTOGAME;
                   } else {
                       goto RAND;
                   }
                }
            }
        } else {
            system("cls");
            goto BACKTOGAME;
        }
    }
    
	
	
    EXIT :
    system("pause");
	return 0;
}

int getRand(){
    int i, num;
    bool status;
    num = rand() % ARRAY_CATALOG; // generate number between 0 and ARRAY_CATALOG    
    return num; 
}

void helpMenu(){
	printf("Sudoku Game :\n");
	printf("HOW TO PLAY : Anda harus memasukkan angka pada bagian tabel yang kosong\n");
	printf("hingga untuk setiap baris, kolom, dan setiap 3x3 box tabel, tidak terdapat angka yang sama.\n");
	printf("Bilangan input adalah digit 1 sampai 9\n\n");
	
	printf("HOW TO INPUT : untuk memasukkan input pada tabel, anda dapat memasukkan 3 angka yang dipisahkan\n");
	printf("dengan spasi, angka tersebut akan dibaca sebagai baris_kolom_input.\n\n");
	printf("contoh : \nmasukkan baris 4\nmasukkan kolom : 3\nmasukkan nilai : 9\n");
	printf("yang berarti memasukkan nilai 9 pada tabel baris ke 4 dan kolom ke 3\n\n");
	printf("IMPORTANT : Pastikan anda menginputkan angka antara 1 hingga 9 kesalahan input akan menghasilkan \nkejadian yg kurang menyenangkan :v\n\n");
}
int mainMenu(){
	int CHOICE1;
	printf("\n-------------------------------------------------------------\n\n");
	printf("                  SUDOKU CHRONICLES SAGA                     \n");
	printf("                play until your brain burst                  \n");
	printf("-------------------------------------------------------------\n\n");
	CHS :
	printf("What would you like to do?\n1.Play!\n2.Don't play, just checking\n3.HELP\n");
	scanf("%d", &CHOICE1);
	switch(CHOICE1){
		case (1) :
            system("cls");
			return 1;
			break;
		
		case (2) :
			return 2;
			break;
			
		case (3) :
            system("cls");
			helpMenu();
            goto CHS;
			break;
		
		default :
			system("cls");
			printf("Pilihan anda tidak terdapat dalam menu, silahkan pillih dengan mengetikan 1 atau 2 lalu tekan enter");
			goto CHS;
			break;
	}
    return 0;
}

int opsi(){
	int CHOICE;
	printf("\n\nSELAMAT! JAWABAN ANDA SUDAH BENAR!");
		printf("\nApa anda ingin lanjutkan bermain?\n1.YA\n2.TIDAK\nJawaban anda : ");
		scanf("%d", &CHOICE);
		switch (CHOICE){
			case (1) :
				system("cls");
				return 1;
				break;
				
			case (2) :
				printf("\nTerimakasih sudah bermain!\n");
				break;
			
			default :
				system("cls");
				printf("Pilihan anda tidak terdapat dalam menu, silahkan pillih dengan mengetikan 1 atau 2 lalu tekan enter");
				opsi();
				break;
		}
    return 0;
}