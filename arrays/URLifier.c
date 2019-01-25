#include<iostream>
#include<string.h>

using namespace std;
//Naive implementation
// 1-> Copy string into temporary string
// 2-> Copy back to original string
// ---- If space is detected call the addOn function to insert %20

/* void addOn(char* string, char* addOns){ */
/*   strncpy(string, addOns, strlen(addOns)); */
/* } */

/* void URLifier(char* string, int length){ */
/*   int dest = 0, src = 0; */
/*   char temp[strlen(string)]; */
  
/*   strncpy(temp, string, length); */
  
/*   while(src <= length){ */
/*     if(temp[src] == ' '){ */
/*       addOn(string+dest, "%20"); */
/*       dest+=strlen("%20"); */
/*       src++; */
/*     } */
/*     else{ */
/*       string[dest++] = temp[src++]; */
/*     }     */
/*   } */
/* } */
    
/* int main(){ */
/*   char string[21] = "you can do it       "; */
/*   URLifier(string, 13); */
/*   cout << "URLified string is " << string << endl; */
/* } */



//String is copied from end so that it can be implemented in O(N) times
void addOn(char* string, char* addOns){
  strncpy(string, addOns, strlen(addOns));
}

char* URLifier(char* string, int length){
  int dest, src;
  dest = strlen(string)-1;
  src = length -1 ;
  
  while(src >= 0){
    if(string[src] == ' '){
      addOn(string+dest-2, "%20");
      dest -= strlen("%20");
      /* string[dest--] = '0'; */
      /* string[dest--] = '2'; */
      /* string[dest--] = '%' */;
      src--;
    }
    else{
      string[dest--] = string[src--];
    }    
  }
  return string+dest+1;
}
    
int main(){
  char string[28] = "This is the test          ";
  cout<<"URLified URL output: "<<URLifier(string, 16)<<endl;
}
