#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int strToInt(char string[]){
  int number = 0, isNeg = 0, i = 0;
  
  if(string[0] == '-'){
    isNeg = 1;
    i = 1;
  }
  cout<<"Length of the string is "<<strlen(string)<<endl;
  for(i; i < strlen(string); i++){
    number *= 10;
    number += (string[i] - '0');
  }
  return number;
  
}

int main(){
  char a[] = "2048";
  char b[] = "1024";

  cout<<strToInt(a)<<" "<< strToInt(b)<<endl;
}
