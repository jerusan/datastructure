#include<iostream>
#include<stdio.h>

using namespace std;

#define N 4

//Naive implementation
/* void rotate90(int array[][N]){ */
/*   int temp[N][N]; */

/*   for(int i = 0; i < N; i++){ */
/*     for(int j = 0; j < N; j++){ */
/*       temp[i][j] = array[N-j-1][i]; */
/*     } */
/*   } */

/*   for(int i = 0; i < N; i++){ */
/*     for(int j = 0; j < N; j++) */
/*       cout<<temp[i][j]<<" "; */
/*     cout<<endl; */
/*   } */
/* } */

void rotate90(int array[][N], int n){
  for(int layer = 0; layer < n/2; layer++){
    int first = layer, last = n - 1 - layer;

    for(int i = first; i < last; i++){
      int offset = i - first;

      int top = array[first][i];
      array[first][i] = array[last - offset][first];
      array[last - offset][first] = array[last][last-offset];
      array[last][last-offset] = array[i][last];
      array[i][last] = top;
    }
  }
    for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++)
      cout<<array[i][j]<<" ";
    cout<<endl;
    }
}

int main(){
  int array[][4]={{1,2,3,4},
		  {5,6,7,8},
		  {9,10,11,12},
		  {13,14,15,16}};
  rotate90(array, 4);
  return 0;
}
