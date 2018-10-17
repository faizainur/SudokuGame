#include "headerlist.h"
#define SIZE 9
#define ARRAY_CATALOG 3

/* TODO: Add Sudoku Table Elements Here */
    
/*char tblElements1[SIZE][SIZE] = {
	{'9', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3'},
    {'1', ' ', '5', ' ', '9', '3', '2', ' ', '6'},
    {' ', '4', ' ', ' ', '5', ' ', ' ', ' ', '9'},
    {'8', ' ', ' ', ' ', ' ', ' ', '4', '7', '1'},
    {' ', ' ', '4', '8', '7', ' ', ' ', ' ', ' '},
    {'7', ' ', '2', '6', ' ', '1', ' ', ' ', '8'},
    {'2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'5', ' ', ' ', ' ', '3', '2', ' ', '9', '4'},
    {' ', '8', '7', ' ', '1', '6', '3', '5', ' '}
};*/
char tblElements1[SIZE][SIZE] = {
	{' ', ' ', '8', '1', '6', '7', '5', '4', '3'},
    {'1', '7', '5', '4', '9', '3', '2', '8', '6'},
    {'6', '4', '3', '2', '5', '8', '7', '1', '9'},
    {'8', '9', '6', '3', '2', '5', '4', '7', '1'},
    {'3', '1', '4', '8', '7', '9', '6', '2', '5'},
    {'7', '5', '2', '6', '4', '1', '9', '3', '8'},
    {'2', '3', '9', '5', '8', '4', '1', '6', '7'},
    {'5', '6', '1', '7', '3', '2', '8', '9', '4'},
    {'4', '8', '7', '9', '1', '6', '3', '5', '2'}
};

// char tblElements2[SIZE][SIZE] = {
// 	{'5', '3', ' ', ' ', '7', ' ', ' ', ' ', ' '},
//     {'6', ' ', ' ', '1', '9', '5', ' ', ' ', ' '},
//     {' ', '9', '8', ' ', ' ', ' ', ' ', '6', ' '},
//     {'8', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3'},
//     {'4', ' ', ' ', '8', ' ', '3', ' ', ' ', '1'},
//     {'7', ' ', ' ', ' ', '2', ' ', ' ', ' ', '6'},
//     {' ', '6', ' ', ' ', ' ', ' ', '2', '8', ' '},
//     {' ', ' ', ' ', '4', '1', '9', ' ', ' ', '5'},
//     {' ', ' ', ' ', ' ', '8', ' ', ' ', '7', '9'}
// };

char tblElements2[SIZE][SIZE] = {
	{'5', ' ', ' ', '6', '7', '8', '9', '1', '2'},
    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
};

// char tblElements3[SIZE][SIZE] = {
// 	{' ', ' ', '7', '5', ' ', '3', '6', ' ', ' '},
//     {' ', '5', '3', ' ', ' ', ' ', '1', '4', ' '},
//     {' ', '8', ' ', ' ', ' ', ' ', ' ', '2', ' '},
//     {' ', ' ', '1', '8', ' ', '7', '4', ' ', ' '},
//     {'5', ' ', ' ', ' ', '6', ' ', ' ', ' ', '1'},
//     {' ', ' ', '8', '2', ' ', '1', '5', ' ', ' '},
//     {' ', '7', ' ', ' ', ' ', ' ', ' ', '8', ' '},
//     {' ', '6', '5', ' ', ' ', ' ', '9', '1', ' '},
//     {' ', ' ', '4', '3', ' ', '8', '7', ' ', ' '}
// };

char tblElements3[SIZE][SIZE] = {
	{' ', ' ', '7', '5', '2', '3', '6', '9', '8'},
    {'2', '5', '3', '9', '8', '6', '1', '4', '7'},
    {'9', '8', '6', '1', '7', '4', '3', '2', '5'},
    {'6', '9', '1', '8', '5', '7', '4', '3', '2'},
    {'5', '3', '2', '4', '6', '9', '8', '7', '1'},
    {'7', '4', '8', '2', '3', '1', '5', '6', '9'},
    {'3', '7', '9', '6', '1', '5', '2', '8', '4'},
    {'8', '6', '5', '7', '4', '2', '9', '1', '3'},
    {'1', '2', '4', '3', '9', '8', '7', '5', '6'}
};

// char tblElements4[SIZE][SIZE]{
    
// };

// char tblElements5[SIZE][SIZE]{
    
// };

// char tblElements6[SIZE][SIZE]{
    
// };

// char tblElements7[SIZE][SIZE]{
    
// };

/* Array of pointer of tblElements arrays */

char arrayEval1[SIZE][SIZE] = {
	{'9', '2', '8', '1', '6', '7', '5', '4', '3'},
    {'1', '7', '5', '4', '9', '3', '2', '8', '6'},
    {'6', '4', '3', '2', '5', '8', '7', '1', '9'},
    {'8', '9', '6', '3', '2', '5', '4', '7', '1'},
    {'3', '1', '4', '8', '7', '9', '6', '2', '5'},
    {'7', '5', '2', '6', '4', '1', '9', '3', '8'},
    {'2', '3', '9', '5', '8', '4', '1', '6', '7'},
    {'5', '6', '1', '7', '3', '2', '8', '9', '4'},
    {'4', '8', '7', '9', '1', '6', '3', '5', '2'}
};

char arrayEval2[SIZE][SIZE] = {
	{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
};

char arrayEval3[SIZE][SIZE] = {
	{'4', '1', '7', '5', '2', '3', '6', '9', '8'},
    {'2', '5', '3', '9', '8', '6', '1', '4', '7'},
    {'9', '8', '6', '1', '7', '4', '3', '2', '5'},
    {'6', '9', '1', '8', '5', '7', '4', '3', '2'},
    {'5', '3', '2', '4', '6', '9', '8', '7', '1'},
    {'7', '4', '8', '2', '3', '1', '5', '6', '9'},
    {'3', '7', '9', '6', '1', '5', '2', '8', '4'},
    {'8', '6', '5', '7', '4', '2', '9', '1', '3'},
    {'1', '2', '4', '3', '9', '8', '7', '5', '6'}
};


  
