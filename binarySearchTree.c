#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node *left, *right;
};

struct node *newNode(int value) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) 
{
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int value) 
{
  if (node == NULL) 
    return newNode(value);
  if (value < node->data)
    node->left = insert(node->left, value);
  else
    node->right = insert(node->right, value);
  return node;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
  printf("Inorder traversal: ");
  inorder(root);
}