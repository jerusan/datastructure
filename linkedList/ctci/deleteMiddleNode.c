#include<iostream>
#include<stdlib.h>
#include"../singly_stack.h"

using namespace std;

void removeMiddleNode(element** head){
  element* midFinder = *head;
  element* endFinder = (*head)->next;
  element* prevP;
  
  while(endFinder){
    prevP = midFinder;
    midFinder = midFinder->next;
    if (endFinder->next->next)
      endFinder = endFinder->next->next;
    else
      endFinder = NULL;
  }

  prevP->next = midFinder->next;
  free(midFinder);
}

int main(){
  element* head = NULL;
  element* temp;
  
  push(1, &head);
  push(2, &head);
  push(3, &head);
  push(4, &head);
  push(5, &head);
  push(6, &head);
  
  removeMiddleNode(&head);

  temp = head;
  while(temp){   
    cout<<temp->data<<" ";
    temp = temp->next;
  }

  cout<<endl;
}
