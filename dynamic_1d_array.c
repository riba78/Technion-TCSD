#include <stdio.h>
#include <stdlib.h>
#define ACCEPTABLE 1
#define NONACCEPTABLE 0

//deallocate 2D matrix
void Deallocate2dMatrix(char **mat, int size){
  for (int i=0; i<size; ++i){
    free(mat[i]);
  }
}

//allocate 3d matrix of arrays of pointers
char **Create2DMatrix(int size){
  //allocate memory for 2D matrix
  char **mat=malloc(size*sizeof(char *));
  //deallocate memory for 2D matrix
  if (mat==NULL){
    return NULL;
  }
  for (int i=0; i<size; ++i){
    mat[i]=malloc(size*sizeof(char ));
    if (mat[i]==NULL){
      return NULL;
    }
  }
  return mat;
}

//fill matrix with chars
void **Fill2DMatrix(char **mat, int size){
  for (int i=0; i<size; ++i){
    for (int j=0; j<size; ++j){
      mat[i][j]='*';
    }
  }
}

//print 2D matrix
void **Print2DMatrix(char **mat, int size){
  for (int i=0; i<size; ++i){
    for (int j=0; j<=size; ++j){
      if (j==size){
        printf("\n");
        break;
      }
      else{
        printf("%c", mat[i][j]);
      } 
    }
        
  }
}

//replace memory of move with * of 2Dmatrix
void **Undo(char **mat, int size, int move){
  for (int i=size-1; i>move; --i){
    for (int j=size-1; j>move; --j){
      mat[i][j]='*';
    }
  }
}

//fill 2D matrix with players moves
void  **PlayerMove(char **mat, int size){
  int player=1, x, y;
  static int move=0;
  while (move>=0 && move<=size){
    if (player%2!=0){
      printf("Player 1, enter next move\n");
      ++player;
      scanf("%d%d", &x, &y);
      if (x<0){
        move=move+x;
        Undo(mat, size, move);
        printf("move=%d\n",move);
        Print2DMatrix(mat, size);
        break;
      }
      if (mat[x-1][y-1]!='*'){
          printf("Bad move, retry\n");
          --player;
          --move;
          break;
        }
        else{
          mat[x-1][y-1]='X';
        }
    printf("move=%d\n",move);
    Print2DMatrix(mat, size);
    }
    else if (player%2==0){
      printf("Player 2, enter next move\n");
      ++player;
      scanf("%d%d", &x, &y);
      if (x<0){
        break;
      }
      if (mat[x-1][y-1]!='*'){
          printf("Bad move, retry\n");
          --player;
          --move;
          break;
        }
        else{
          mat[x-1][y-1]='O';
          //moves[move]=mat;
          //Print2DMatrix(moves[move-1], size);
        }
      printf("move=%d\n", move);
      Print2DMatrix(mat, size);
    }
  ++move;
  } 
}

int main(){
  char **board;
  int size, move=0;
  printf("Enter board size (1 to 10)\n");
  scanf("%d", &size);
  board=Create2DMatrix(size);
  Fill2DMatrix(board, size);
  PlayerMove(board, size);
  //Print2DMatrix(board, size);
  Deallocate2dMatrix(board, size);
  return 0;
}

  

/*
void DellocateArray(int* mat) {
  free(mat);
}

int* AllocateArray(int n) {
  int* mat;
  mat = malloc(n * sizeof(int));
  return mat;
}

void FillArray(int* mat, int n) {
  static int k;
  for (int i = 0; i < n; ++i) {
    mat[i] = k++;
  }
}

void PrintArray(int* mat, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%3d", *(mat+i));
  }
  printf("\n");
}


#define N 4
int main() {
  int* mat = AllocateArray(N);
  FillArray(mat, N);
  PrintArray(mat, N);
  DellocateArray(mat);
  return 0;
}*/
/*
int *AllocateArray(int size){
  int *pointer;
  pointer=malloc(size * sizeof(int*));
  return pointer;
}

int main(){
  int size, i;
  int *array;
  
  printf("enter the array size:");
  scanf("%d", &size);
  array=AllocateArray(size);
  int row[size];
  for (i=0; i<size; ++i){
    array[i]=(int*)malloc(size*sizeof(int));
  }
  for (i=0; i<size; ++i){
    for (j=0; j<size; j++){
      printf("%d\n", array[i][j]);
    }
  }
  
}*/


/*
int ** Create2dMatrix(int rows, int columns){
  //create array of rows
  int i;
  //declare and create in memmory 2d matrix
  int **matrix=malloc(rows*sizeof(int *));
  for (i=0; i<rows; ++i){
    matrix[i]=malloc(rows*sizeof(int *));
  }
  //create 2d matrix
  int j;
  for (i=0; i<rows; ++i){
    for (j=0; j<columns; ++j){
      matrix[i][j]=i*columns+j+1;
    }
  }
  return matrix;
}*/

/*
int ***Creat3dMatrix(int **matrix, int n){
  matrix=Create2dMatrix(5,5);
  int ***threedmatrix=malloc(n*sizeof(int*));
  int i, j, k;
  for (i=0; i<n; ++i){
    for (j=0; j<n; ++j){
      for (k=0; k<n; ++k){
        matrix[i][j][k]=j*n+k+1;
      }
    }
  }
}*/
/*
void FillMatrix(int **matrix, int rows, int columns){
  int i; 
  int j;
  static int k;
  for (i=0; i<rows; ++i){
    for (j=0; j<columns; ++j){
      matrix[i][j]=k;
      k++;
    }
  }
}

void PrintMatrix(int **matrix, int size){
  int i, j;
  for (i=0; i<size; ++i ){
      for (j=0; j<size; ++j){
        printf("%3d", matrix[i][j]);
      }
      printf("\n");
  }
}

int main(){
  int **matrix;
  matrix=Create2dMatrix(5,5);
  FillMatrix(matrix, 5, 5);
  PrintMatrix(matrix, 5);
}*/