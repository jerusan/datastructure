#include<iostream>
#include<stdlib.h>

using namespace std;

struct element{
  int data;
  element *next;
};

element* insert(){
   element* temp = (element*) malloc(sizeof(element));
   temp->next = NULL;
   return temp;
}
  
void loopLinkedList(element** head){
  element* temp;
  element* loop;

  *head = insert();
  temp = *head;
  temp->data = 1;
  
  for(int i = 1; i < 10; i++){
    temp->next = insert();
    temp = temp->next;
    temp->data = i;
        
    if (i == 6)
       loop = temp;
  }
  //  temp->next = loop;
  temp = *head;

  while(temp != loop){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}
    
    
  
int loopDetection(element** head){
  element *walker, *runner;
  walker = *head;
  runner = (*head)->next->next;
  
  while(true){
    if(walker == runner){
      cout<<"It is a loop: "<<walker->data<<" "<<runner->data<<endl;
      break;
  }
    walker = walker->next;
    runner = runner->next->next;
       if(runner->next == NULL || runner->next->next == NULL){
      cout<<"No loop is found in this Linked list"<<endl;
      break;
    }
  }
   
  if (runner->next && runner->next->next){
    runner = runner->next;
    walker = *head;

    while(runner != walker){
      walker = walker->next;
      runner = runner->next;
    }
    cout<<"Loop starts at: "<<walker->data<<endl;
  }
}
  
int main(){
  element* head = NULL;

  loopLinkedList(&head);

  loopDetection(&head);
  return 0;
}
  
