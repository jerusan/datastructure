#include "singly_stack.h"
#include<iostream>

using namespace std;

void buildtest(element** elem){
  for(int i = 0; i < 10; i++)
    push(i, elem);
}

int main(){
  element* head = NULL;
  element** test;

  push(12, &head);
  test = &head;

  push(13, &head);
  push(14, &head);
  cout<<"Address of *head is %p"<< (void *)head<<endl;
  buildtest(&head);
  
  while(*test != NULL){
    cout<<(*test)->data<<" ";
    test = &((*test)->next);
  }
}
