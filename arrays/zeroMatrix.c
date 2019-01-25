#include<iostream>

using namespace std;

#define N 4
#define M 6

void Nullify(int matrix[][N], int, char, int);

void zeroTheRowNColumn(int matrix[][N]){
  int row[M], column[N], index = 0;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if (!matrix[i][j]){
	cout<<"Storing " << i << "&" <<j<<endl;
	row[index] = i;
	column[index] = j;
	index++;
      }
    }
  }
  for(int i = 0; i < index; i++){
	Nullify(matrix, row[i], 'r', N);
	Nullify(matrix, column[i], 'c', M);
  }
}

void Nullify(int matrix[][N], int num, char a, int length){
  for(int i = 0; i < length; i++)
    if(a == 'r')
      matrix[num][i] = 0;
    else if(a == 'c')
      matrix[i][num] = 0;
    else
      break; 
}

void print(int matrix[][N], int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      cout<<matrix[i][j]<<" ";
  cout<<endl;
  }
}

int main(){
  int matrix[][N] = {{1,0,3,4},
		     {5,6,7,8},
		     {9,0,11,12},
		     {13,14,15,16},
                     {17,18,19,20},
                     {21,22,23,24}};
  zeroTheRowNColumn(matrix);
  print(matrix, M, N);
  
}
