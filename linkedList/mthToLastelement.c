#include<iostream>
#include<stdlib.h>

#include "doubly.h"

using namespace std;

int main(){
  int m;
  cout<<"How many elements from last want to be printed:\n";
  cin>>m;

  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(4);
  insertAtEnd(5);
  insertAtEnd(6);
  insertAtEnd(7);
  print();
  int counter= 0;
  element* printer = head;
  element* temp;

  for (temp= head; temp; temp=temp->next){
    if (counter < m)
      counter++;
    else
      printer=printer->next;
  }
  
  for (printer;printer;printer=printer->next){
    if (counter != m) return NULL;
    cout<<printer->data<<" ";
  }
  cout<<endl;
}
