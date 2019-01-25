#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
  int data;
  struct node* next;
};

struct node* buildonetwothree(struct node** tail){
  node* first = new node;
  node* second = new node;
  node* third = new node;
  
  first->data = 1;
  second->data = 3;
  third->data = 14;
  
  first->next = second;
  second->next = third;
  third->next = NULL;

  *tail = third;
  
  return first;  
}

int length(struct node* top){
  int count = 0;
  while(top){
    count++;
    top = top->next;
  }
  return count;
}

void push(struct node** headref, int value){
  struct node* temp = new node;
  temp->data = value;
  temp->next = *headref;
  *headref = temp;
}

int count(struct node* headref, int num){
  int count = 0;
  for(headref; headref; headref=headref->next)
    if (num == headref->data) count++;
  return count;
}

struct node* getNth(struct node **headref, int index){
  int count = 0;
  struct node* temp = *headref;
  for(temp;  temp, count < index; temp=temp->next, count++);
  cout<<"address in the callee :"<<temp<<endl;
  return temp;    
}

void deletelist(struct node** headref){
  node *temp = new node;
  while(*headref){
    temp = *headref;
    *headref = (*headref)->next;
    delete temp;
  }
}

int pop(struct node **headref){
  node *temp = new node;
  temp =  *headref;
  int value = (*headref)->data;
  delete *headref;
  *headref = temp->next;
  return value;
}

void insertNth(struct node** headref, int index, int value){
  struct node *current = *headref;
  int i = 0;
  for (i=0; i<index-1; i++){
    current = current->next;
  }
  push(&(current->next), value);
}

void frontbacksplit(node **source, node **front, node **back){
  *front = *source;
  node *fastptr = *source;
  
  while(true){
    if (fastptr->next && fastptr->next->next)
	fastptr = fastptr->next->next;
    else
      break;

    *source = (*source)->next;
  }

  *back = (*source)->next;
  (*source)->next = NULL;
   
}

void merge(struct node** cur, struct node** nextt){
  node *a_temp = ((*cur)->next) ? (*cur)->next : NULL;
  node *b_temp = ((*nextt)->next) ? (*nextt)->next : NULL;
  cout<<"value of b_temp:::: "<<b_temp<<endl;
  (*cur)->next = *nextt;
  (*nextt)->next = a_temp;
  *nextt = b_temp;
  *cur = (*cur)->next; 
}

node* sortedMerge(struct node* a, struct node* b){
  node *start;
  node *curr = NULL;
  node *prev = NULL;
  if (a->data > b->data){
    curr = a;
    a = b;
    b = curr;
  }
  start = a;
  while(a && b){
    if(a->data <= b->data){
      prev = a;
      if (a->next) a = a->next;
      else{
	a->next = b;
	b = NULL;
      }
    }
    else{
      cout<<"value of b before: "<<b->data<<endl;
      merge(&prev, &b);
      cout<<"value of a & b" << a->data<<" "<<b->data<<endl;
      if (a->next){
	a = a->next;
      }
      else{
	a->next = b;
        cout<<"value of a"<<a<<endl;
        b = NULL;
      }
    }
  }
  return start;
}

node* shuffleMerge(node* a, node* b){
  node* result = NULL;
  node* recur;
  if (!a)
    return b;
  else if (!b)
    return a;
  else{
    recur = shuffleMerge(a->next, b->next);
    result = a;
    a->next = b;
    b->next = recur;
    return result;
  }
}


node* mergeSort(node* a, node* b){
  node* result = NULL;
  if (!a)
    return b;
  else if (!b)
    return a;

  if (a->data <= b->data){
    result = a;
    result->next = mergeSort(a->next, b);
  }
  else{
    result = b;
    result->next = mergeSort(a, b->next);
  }
  return result;
}

int main(){
  struct node* head;
  struct node* tail;
  struct node* temp;
 
  head = buildonetwothree(&tail);

  for (int i=4; i > 0; i--){
    push(&head, i);
  }
  
  temp = head;
  for (temp; temp; temp=temp->next)
    cout<<temp->data<<"\t";
  cout<<endl;
 
  cout<<"Length of the given node is : "<<length(head)<<endl;
  cout<<"Current data in the end is :" << tail->data<<endl;
  cout<<"Number of 3 in the given list is "<<count(head, 3)<<endl;
  node *nth = getNth(&head, 3);
  cout<<"Nth value is "<<nth->data <<endl;
  /*
  deletelist(&head);

    temp = head;
  for (temp; temp; temp=temp->next)
    cout<<temp->data<<"\t";
  cout<<endl;
  */
  //cout<<"Popped elemetn is : " <<pop(&head)<<endl;
  //  insertNth(&head,4,90);
  temp = head;
  for (temp; temp; temp=temp->next)
    cout<<temp->data<<"\t";
  cout<<endl;

  node *tempp = new node;
  node *taill = new node;
  node *sort = new node;

  frontbacksplit(&head, &taill, &tempp);
  /*
  
  cout<<"tempp data"<<endl;
  for (tempp; tempp; tempp=tempp->next)
        cout<<tempp->data<<"\t";
  cout<<endl;
  cout<<"Taill data"<<endl;
    for (taill; taill; taill = taill->next)
        cout<<taill->data<<"\t";
  cout<<endl;
  */
  sort = shuffleMerge(taill, tempp);
  cout<<"sort merge output:"<<endl;
  for(sort; sort; sort= sort->next)
    cout<<sort->data<<"\t";
  cout<<endl;
  
}
