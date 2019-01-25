#include<iostream>
#include<string.h>

using namespace std;

bool isPermutation(char *string1, char *string2){
  int charCounter1[128] = {0}, i;
  int charCounter2[128] = {0};
  
  if(strlen(string1) != strlen(string2))
    return false;

  for(i = 0; i<strlen(string1); i++){
    charCounter1[string1[i]]++;
    charCounter2[string2[i]]++;
  }

  for(i = 0; i < 128; i++)
    if(!(charCounter1[i] != charCounter2[i]))
      return false;

  return true;
}

int main(){
  char string1[9] = "hqllfdo";
  char string2[9] = "lloefdh";

  cout<<isPermutation(string1, string2)<<endl;
  
  return 0;
}
