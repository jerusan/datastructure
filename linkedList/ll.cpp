#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
  int val;
  Node* next;
};

Node* push(int val, Node* head){
  Node* node = new Node;
  node->val = val;
  node->next = head;

  return node;

}

Node* construct(vector<int> const& keys){
  Node* head = nullptr;
  for(int key: keys)
    head = push(key, head);

  return head;
 }

int main(){
  vector<int> list = {6,5,4,3,2,1};
  Node* start = construct(list);

  while(start){
    cout<<start->val<<"\t";
    start = start->next;
  }
  cout<<endl;

  return 0;
}
