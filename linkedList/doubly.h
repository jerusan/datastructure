#ifndef DOUBLY
#define DOUBLY
#include<iostream>
#include<stdlib.h>
using namespace std;
struct element{
   int data;
   element *prev;
   element *next;
 };

element* head = NULL;

bool isEmpty(element *root){
  return (!root);
}

element* insertElement(int data){
  element* temp = (element*) malloc(sizeof(element));
  temp->data = data;
  temp->prev = NULL;
  temp->next = NULL;
  return temp;
}

void insertAtFront(int data){
  
  if(isEmpty(head)){
      head = insertElement(data);
      cout<< data <<" First element is added\n";
      return;
  }
  
    element* temp = insertElement(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
    cout<<data<<" is added at front\n";
}

void insertAtEnd(int data){
  if(isEmpty(head)){
    insertAtFront(data);  
    return;
  }
  
  element* temp = head;
  
  while(!isEmpty(temp->next)){
      temp = temp->next;
  }
  temp->next = insertElement(data);
  temp->next->prev = temp;
  cout<<data<<" is added at end\n";
}

void insertNextTo(int addAfter, int data){
  if(isEmpty(head)){
    cout<<"shouldn't be empty\n";
    insertAtFront(data);
    return;
  }
  element* temp = insertElement(data);
  element* checker = head;
  while(!isEmpty(checker)){
    if(checker->data == addAfter){
      element* addAfterEl = checker;
      temp->prev = addAfterEl;
      if(!isEmpty(addAfterEl->next)){
	temp->next = addAfterEl->next;
        addAfterEl-> next = temp;
      }
      else{
	insertAtEnd(data);
      }
      return;
    }
    checker=checker->next;
  }
   insertAtEnd(data);
}

void print(){
  element* temp = head;
  while(!isEmpty(temp)){
    cout<<temp->data<<"\t";
      temp = temp->next;
    }
  cout<<endl;
}
#endif 
/*
  int main(){
  
    insertAtFront(3);
    insertAtFront(2);
    insertAtFront(1);
    insertAtEnd(5);
    print();
    insertNextTo(3,4);
    insertNextTo(5,6);
    insertNextTo(0,7);
    print();
  }

*/  
