#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void intToStr(int number, char ar[]){
  char temp[256];
  int i = 0, isNeg = 0, j = 0;

  if(number < 0){
    isNeg = 1;
    number *= -1;
  }
  
  while(number > 0){
    temp[i++] = (number % 10) + '0';
    number /= 10;
  }

  if(isNeg)
    temp[i++] = '-';

  while(i > 0)
    ar[j++] = temp[--i];

  ar[j] = '\0';
}

int main(){
  char string[256];
  intToStr(1324322, string);
  cout<<string<<endl;
}
