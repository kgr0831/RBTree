#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) 
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  p -> root = NULL;
  p -> nil = NULL;
  return p;
}

void delete_rbtree(rbtree *t) 
{
  t = NULL;
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key) 
{
  if(t->root == NULL)
  {
    InsertCase_1(t, key);
  }
  return t->root;
}

void InsertCase_1(rbtree *t, const key_t key)
{
  t -> root -> color = RBTREE_BLACK;
  t -> root -> key = key;
  t -> root -> left = t->nil;
  t -> root -> right = t->nil;
  t -> root -> parent = NULL;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
