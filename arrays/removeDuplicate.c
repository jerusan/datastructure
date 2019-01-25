#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<bitset>

using namespace std;

void removeDuplicate(string &word){
  bitset<256> removeArray;
  //bool removeArray[256] = {0};
  for(int i = 0; i < word.length(); i++){
      if(removeArray.test(word[i])){
	word[i] = '#';
     }
      removeArray.set(word[i]); 
    //if (removeArray[word[i]])
    //word[i] = '#';
    //removeArray[word[i]] = true;
  }
}

int main(){
  string word = "Hhhhhhh";
  removeDuplicate(word);
  cout<<word<<endl;
}
