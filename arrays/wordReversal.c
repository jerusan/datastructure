#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void reverse(char *, int, int);

void reverseWords(char *string){
  char temp;
  int length = strlen(string);
  int space[length];
  int spaceIndex = 0;
  int end = length-1;

  //reverse the whole string before reversing each words
  reverse(string, 0, end);
  
  space[spaceIndex] = 0;
  for(end = 0; end < length; end++){
    if(string[end] == ' '){
      space[++spaceIndex] = end-1;
      reverse(string, space[spaceIndex-1], space[spaceIndex]);
      space[++spaceIndex] = end+1;
    } 
  }
  space[++spaceIndex] = length-1;
  reverse(string, space[spaceIndex-1], space[spaceIndex]);
}

void reverse(char *string, int start, int end){
  while(start<=end){
    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;
    start++;
    end--;
  }
}

int main(){
  char string[] = "Hello how is it going";
  cout<<"Given string:"<<string<<endl;
  reverseWords(string);
  cout<<"reversed string: "<<string<<endl;  
}
