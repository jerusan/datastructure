#ifndef NODE
#define NODE

struct node {
  int val;
  struct node* next;
}

int length(struct node* head);

struct node* buildonetwothree();

void push(struct node** headref, int newData);

#endif
