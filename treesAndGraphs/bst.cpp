#include<iostream>
#include<cstdlib.h>

using namespace std;

struct Tree{
  int val;
  Tree* parent;
  Tree* left;
  Tree* right;
};

Tree* newNode(int val){
  Tree* node = new Tree;
  node->val = val;
  node->parent = nullptr;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

Tree* lookUp(Tree* node, int val){
  if (node == nullptr)
    return nullptr;
  if(node->val == val)
    return node;
  else{
    if(node->val < val)
      return lookUp(node->right, val);
    else
      return lookUp(node->left, val);
  }
}

void insert(Tree* node, int val){
  if (node == nullptr){
      node = new Tree*
      node->val = val;
  }
  else if(node->val <= 
}

