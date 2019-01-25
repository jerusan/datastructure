#include<iostream>
#include"../singly_stack.h"

using namespace std;

void removeDups(struct element** head){
  int indexArray[256] = {0};

  element* currP = *head;
  element* prevP = NULL;
  for(currP; currP != NULL; prevP = currP, currP = currP->next){
    indexArray[currP->data] += 1;
    if (indexArray[currP->data] > 1){
      if(currP->next){
	prevP->next = currP->next;
	free(currP);
	currP = prevP;
      }
      else{
	prevP->next = NULL;
	free(currP);
      }
    }
  }
  

  /* element* runner;// = (*head)->next; */
  /* element* walker; */
  /* for(walker = *head; walker->next; walker = walker->next){ */
  /*   for(runner = *head; runner->next; runner = runner->next){ */
  /*     if(walker->data == runner->next->data){ */
  /* 	if(runner->next->next){ */
  /* 	  element* temp = runner->next; */
  /* 	  runner->next = temp->next; */
  /* 	  free(temp); */
  /* 	} */
  /* 	else{ */
  /* 	  free(runner); */
  /* 	} */
  /*     } */
  /*   } */
  /* } */
}

int main(){
  element* head = NULL;
  element* temp;
  push(1, &head);
  push(2, &head);
  push(3, &head);
  push(4, &head);
  push(1, &head);
  push(2, &head);
  push(3, &head);
  push(6, &head);

  temp = head;
  while(temp){
    cout<<temp->data<<" ";;
      temp = temp->next;
  }
  cout<<endl;  
  removeDups(&head);

  temp = head;
  while(temp){
    cout<<temp->data<<" ";;
    temp = temp->next;
  }
  cout<<endl;
  return 0;
}
