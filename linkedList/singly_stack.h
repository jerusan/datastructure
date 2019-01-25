#ifndef SINGLY_STACK
#define SINGLY_STACK

#include<iostream>
#include<stdlib.h>

using namespace std;

struct element{
  int data;
  element *next;
};

element* InsertElement(int data){
  element* el = (element *) malloc(sizeof(element));
  el->data = data;
  el->next = NULL;
  return el;
}

bool isEmpty(element* head){
  return (!head);
}

void push(int data, struct element** head){
  element* temp = InsertElement(data); 
  temp->next = *head;
  *head = temp;
}

void pop(element *head){
  while(head){
    cout<<"Popped: "<<head->data<<endl;
    head = head->next;
  }
}

#endif
/*
int main(){
  element* head = NULL;
  
  cout<<isEmpty(head)<<endl;

  push(12, &head);
  push(13, &head);
  push(14, &head);
  pop(head);
  return 0;
}
*/

