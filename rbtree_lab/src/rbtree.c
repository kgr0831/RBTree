#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) 
{
  rbtree *t = calloc(1, sizeof(rbtree));
  t->nil = calloc(1, sizeof(node_t));
  t->nil->color = RBTREE_BLACK;
  t->root = t->nil;
  return t;
}

void delete_rbtree(rbtree *t) 
{
  if (!t) return;
  free(t->nil);
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{
    node_t *parentNode = t->nil; // 부모가 될 노드
    node_t *vNode = t->root; // 현재 비교하는 노드 -> 자식이 있다면 자식으로 변경, 없으면 자식으로 삽입

    while (vNode != t->nil) // 부모 탐색
    {
        parentNode = vNode;
        if (key < vNode->key)
        {
            vNode = vNode->left;
        }
        else
        {
          vNode = vNode->right;
        }
    }

    node_t *insertNode = malloc(sizeof(node_t)); // 삽입 될 노드 
    insertNode -> key = key;
    insertNode -> color = RBTREE_RED;
    insertNode -> left = insertNode -> right = t -> nil;
    insertNode -> parent = parentNode;

    if (parentNode == t -> nil) 
    {
      t->root = insertNode;
    }
    else if (key < parentNode -> key)
    {
      parentNode -> left = insertNode;
    }
    else
    {
      parentNode -> right = insertNode;
    }
    
    // (다음 단계) 보정 함수 호출
    // insert_fixup(t, z);
    return insertNode;
}

node_t *rbtree_find(const rbtree *t, const key_t key) 
{
  node_t* curNode = t -> root;
  while(curNode != t->nil)
  {
    if(curNode -> key == key)
    {
      return curNode;
    }
    curNode = curNode -> key < key ? curNode -> right : curNode -> left;
  }
  return NULL;
}

node_t *rbtree_min(const rbtree *t) 
{
  node_t* curNode = t -> root;
  while(curNode -> left != t -> nil)
  {
    curNode = curNode -> left;
  }
  return curNode;
}

node_t *rbtree_max(const rbtree *t) 
{
  node_t* curNode = t -> root;
  while(curNode -> right != t -> nil)
  {
    curNode = curNode -> right;
  }
  return curNode;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
