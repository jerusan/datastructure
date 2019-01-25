#include<iostream>
#include<string.h>

using namespace std;

bool isItRotatedString(char* mainString, char* subString){
  int length = strlen(mainString);
  if (length != strlen(subString))
    return false;

  int indexer = 0;

  while(subString[indexer] != mainString[0]){
    indexer++;

    if(indexer > length-1)
       return false;
  }
  indexer++;
  for(int i = 1; i < length; i++){
    if(mainString[i] != subString[indexer % length])
      return false;
    else
      indexer++;
  } 
  return true;
}

int main(){
  char* string = "Jerusan";
  char* subString = "saneeru";
  cout<< isItRotatedString(string, subString)<<endl;
  return 0;
}
