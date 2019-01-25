#include<iostream>
#include<stdlib.h>
#include"../singly_stack.h"

using namespace std;

int sumList(element* augend, element* addend){
  int aug = 0, add = 0;
  int digit = 1;
  cout<<"Augend number: ";
  while(augend){
    cout<<augend->data<<" ";
    aug += augend->data * digit;
    digit *= 10;
    augend = augend->next;
  }
  cout<<endl<<"Addend number: ";
  digit = 1;
  while(addend){
    cout<<addend->data<<" ";
    add += addend->data * digit;
    digit *= 10;
    addend = addend->next;
  }
  cout<<endl;
  return aug+add;
}

int main(){
  element* first = NULL;
  element* second = NULL;
  time_t t;

  srand((unsigned) time(&t));
  
  for (int i = 0; i < 6; i++){
    if(i < 3)
      push(rand() % 10, &first);
    else
      push(rand() % 10, &second);
  }

  cout<<"Sum: "<<sumList(first, second)<<endl;
};
