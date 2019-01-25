#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void rmChar(char string[], char lookup[]){
  int removeArray[256] = {0};
  int i = 0;
  for(i;i < strlen(lookup); i++)
    removeArray[lookup[i]] = 1;

  for(i = 0; i<strlen(string); i++)
    if (removeArray[string[i]])
      string[i] = '#';
  
}

int main(){
  char ar[10] = "Helloho";
  char lookup[6] = "Hhelo";
  rmChar(ar, lookup);
  cout<<ar<<endl;
}
