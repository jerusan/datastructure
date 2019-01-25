#include<iostream>
#include<stdlib.h>

#include"../singly_stack.h"

using namespace std;

void partition(element** head, int partition){
  
}

int main(){
  element* head = NULL;
  time_t t;
  element* temp;
  
  srand((unsigned) time (&t));
  
  for(int i = 0; i < 6; i++){
    push(rand() % 50, &head);
    if (i == 1 || i == 4)
      push(5, &head);
  }

  temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }

  //partition(&head, 5)
  
}

