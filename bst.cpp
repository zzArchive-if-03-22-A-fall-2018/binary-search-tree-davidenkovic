/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "bst.h"
#include "general.h"
#include <stdlib.h>

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

Bst new_bst(){
  Bst newBst=(Bst)malloc(sizeof(struct Node));
  newBst->left=0;
  newBst->right=0;
  newBst->value=0;
  newBst=0;
  return newBst;
}

void delete_bst(Bst bst){
  if(bst!=0)
  {
    delete_bst(bst->left);
    delete_bst(bst->right);
    sfree(bst);
 }
}

int get_depth(Bst bst){
  if (bst == 0) {
    return 0;
  }
  else{
    int leftDepth = get_depth(bst->left);
    int rightDepth = get_depth(bst->right);
    if(leftDepth > rightDepth){
      return leftDepth+1;
    }
    else{
      return rightDepth+1;
    }
  }
}

void add(Bst* bst, int value){
  if((*bst)==0){
    Bst currBst=(Bst)malloc(sizeof(struct Node));
    currBst->left=0;
    currBst->right=0;
    currBst->value=value;
    *bst=currBst;
  }
  else if(value<=(*bst)->value){
    add(&(*bst)->left,value);
  }
  else {
    add(&(*bst)->right,value);
  }
}

int root_value(Bst bst){
  return bst->value;
}

Bst left_subtree(Bst root){
  return root->left;
}

Bst right_subtree(Bst root){
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst != 0){
    elements[start] = bst->value;
    if(get_depth(bst) > 0){
       start = start + 1;
       start = traverse_pre_order(bst->left, elements, start);
       start = traverse_pre_order(bst->right, elements, start);
    }
  }
  return start;
}

int traverse_in_order(Bst bst, int *elements, int start){
  if(bst != 0){
    if(bst->left != 0){
      start = traverse_in_order(bst->left, elements, start);
    }
    elements[start] = bst->value;
    start = start + 1;
    if(bst->right != 0){
      start = traverse_in_order(bst->right, elements, start);
    }
  }
  return start;
}

int traverse_post_order(Bst bst, int *elements, int start){
  if(bst != 0){
      if(bst->left != 0){
        start = traverse_post_order(bst->left, elements, start);
      }
      if(bst->right != 0){
        start = traverse_post_order(bst->right, elements, start);
      }
      elements[start] = bst->value;
      start = start + 1;
  }
  return start;
}

bool are_equal(Bst bst1, Bst bst2){

  if(bst1 == 0){
    return bst2 == 0;
  }
  else if(get_depth(bst1) == get_depth(bst2)){
    if(bst1->value == bst2->value){
      return are_equal(bst1->left, bst2->left) && are_equal(bst1->right, bst2->right);
    }
  }
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){
  if(bst == 0){
    return;
  }
  add(branch, bst->value);
  get_depth(bst->left) >= get_depth(bst->right) ? most_left_longest_branch(bst->left, branch):most_left_longest_branch(bst->right, branch);
}

int get_number_of_subtrees(Bst bst){
  if(bst == 0)
  {
    return -1;
  }
  return get_number_of_subtrees(bst->left) +1+ get_number_of_subtrees(bst->right)+1;
}
