#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

char* stringCompression(char* string){
  char temp[strlen(string)];

  char chr = string[0];
  int counter = 0, index = 0;
  chr = string[index];
  
  for(int i = 0; i < strlen(string); i++){
    if(chr == string[i])
      counter += 1;
    else{
      temp[index++] = chr;
      sprintf(temp+index, "%d", counter);
      //temp[index++] = counter;
      while(counter > 0){
	counter %= 10;
	index++;
      }
      counter = 1;
      chr = string[i];
    }
  }

  if (strlen(temp) < strlen(string))
    cout<<temp<<endl;
   else
     return string;     
}

  int main(){
    char string[20] = "aaaaaaaaaabbccddee";

    cout<<stringCompression(string)<<endl;

    return 0;
  }
