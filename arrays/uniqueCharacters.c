#include<iostream>
#include<string.h>
#include<bitset>
#include<vector>

using namespace std;

bool isUnique(char *string){
  int length = strlen(string);
  
  if(length > 127)
    return false;

  bitset<128> counter;
  vector<bool> count(false, 128);
  for(int i=0; i < length; i++){
    if(count[string[i]])
      return false;
    count[string[i]] = true;
  }
  return true;
}

int main(){
  char temp[20] = "Underr t";

  cout<<isUnique(temp)<<endl;
  
  return 0;
}
