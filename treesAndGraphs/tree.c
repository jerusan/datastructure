#include<iostream>
#include<stdlib.h>
#include<stdint.h>

using namespace std;

struct Node{
  int value;
  int counter;
  Node* adjList[20];
};

struct Node*  add(int value){
  Node* temp = (Node*) malloc(sizeof(Node));
  temp->value = value;
}

void insertAt(Node** node, int value){
  if(*node){
    Node* temp = add(value);
    (*node)->adjList[(*node)->counter] = temp;
    (*node)->counter += 1;
  }
  else{
    Node* temp = add(value);
    temp->counter = 0;
    *node = temp;    
  }
}

Node* head = NULL;

int main(){
  srand(45);   
  insertAt(&head, 1);
  insertAt(&head, 2);
  insertAt(&head, 3);
  insertAt(&head, 4);
  insertAt(&head, 5);
  
  cout<< "Value of head: "<<head->value<<endl;
  
  for(int i = 0; i < head->counter; i++){
    cout<< "Adjacent of head values: "<< head->adjList[i]->value<<endl;
  }

  int temp;
  int counter = rand() % 30;

  for(int i = 0; i < counter; i++){
    if(i % 2 == 0){
      temp = rand() % 4;
    }

    if (head->adjList[temp]->value < 5){    
	insertAt(&head->adjList[temp], rand() % 5);
    }
    
    else{
	insertAt(&head->adjList[temp], 99);
    }    
  }

  return 0;
}
