#include<iostream>
#include<string.h>

using namespace std;


bool isOneAway(char* string1, char* string2){
  if(strlen(string1) != strlen(string2) + 1)
    return false;

  int mainString = 0, subString = 0;
  bool oneOff = false; 

  while(mainString != strlen(string1)){
    if(string1[mainString] != string2[subString]){
      if (oneOff)
	return false;
      else
	oneOff = true;
      mainString++;
    }
    else{
      mainString++;
      subString++;
    }
  }
  return true;
}

int main(){
  char mainString[8] = "pale";
  char subString[7] = "bake";
  cout<<isOneAway(mainString, subString)<<endl;
}
