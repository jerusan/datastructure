#ifndef CIRCULAR
#define CIRCULAR
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
      head->prev = head;
      head->next = head;
      cout<< data <<" First element to the list "<< data<<" is added\n";
      return;
  }
  
    element* temp = insertElement(data);
    element* lastEl = head->prev; 
    head->prev = temp;
    temp->next = head;
    temp->prev = lastEl;
    lastEl->next = temp;
    head = temp;
    cout<< data <<" is added at front\n";
}

void insertAtEnd(int data){
  if(isEmpty(head)){
    insertAtFront(data);  
    return;
  }

  element* lastEl = head->prev;
  element* temp = insertElement(data);
  lastEl->next = temp;
  temp->next = head;
  temp->prev=lastEl;
  head->prev = temp;
  
  cout<<data<<" is added at end\n";
}

void insertNextTo(int addAfter, int data){
  if(isEmpty(head)){
    insertAtFront(data);
    return;
  }
  element* temp = insertElement(data);
  element* checker = head;
  do{
    if (checker->data == addAfter){
      checker->next->prev = temp;
      temp->next = checker->next;
      checker->next = temp;
      temp->prev = checker;
      return;
    }
    else{
      checker = checker->next;
    }
  }while(checker != head);
  if (checker == head)
    insertAtEnd(data);
}

void print(){
  element* temp = head;
  while(true){
    cout<<temp->data<<"\t";
      temp = temp->next;
      if (temp == head){
	cout<<endl;
	return;
      }
    }
}

#endif CIRCULAR
  int main(){
  
    insertAtFront(3);
    insertAtFront(2);
    insertAtFront(1);
    //insertAtEnd(4);
    insertAtEnd(5);
    print();
    insertNextTo(3,4);
    insertNextTo(5,6);
    insertNextTo(0,7);
     print();
  }
