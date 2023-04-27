#include <iostream>
using namespace std;

struct node {   //structure of the node
  int key;
  struct node *left, *right;
};

//making a new node
struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));  //explicitly allocate memory to the new node
    temp -> key =item; //setting the key value of the new node
    temp ->left =NULL;  //setting the left subtree of the new node
    temp ->right =NULL;  //setting the right subtree of the new node
    return temp;
}

// Getting the minimum value of a node
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL){
        return;
    }
    traverseInOrder(root->left); //traverse through the left subtree
    cout<< root->key << " ";
    traverseInOrder(root-> right); //traverse through the right subtree
}

// Inserting a node
struct node *insertNode(struct node *node, int key) {
    if (node==NULL){  //if node is empty
        return newNode(key);
    }
    if(key <node->key) //inserting a value into left subtree
      node ->left =insertNode(node->left,key);
    else if (key >node->key) //inserting a value into right subtree
      node ->right =insertNode(node->right ,key);

    return node;
}

// Deleting a node
//this code delete the code and returns the new root 
struct node *deleteNode(struct node *root, int key) {
  if(root ==NULL){
    return root;
  }
  if (key < root->key){
    root->left = deleteNode(root->left ,key);
  }
  else if (key>root->key){
    root->right =deleteNode(root->right ,key);
  }
  //if the key = root's key
  else{
    // if the node has no child
    if(root->left ==NULL && root->right==NULL){
      free(root);
      return NULL;
    }
    
    // Node with one child
    else if(root->left == NULL){
      struct node *temp =root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      struct node *temp =root->left;
      free(root);
      return temp;
    }

    // Node has two children
    else{
      struct node *temp = minValueNode(root->right); //finding the inorder successor to replace with root
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  return root;  
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  return 0;
}
