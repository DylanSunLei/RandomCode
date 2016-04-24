struct Lock;

struct Node {
    int value;
    Node *left;
    Node *right;
    Lock* lock;
};


//assume lock(Node* node) function

void delete_node(Node* root, int value){
  Node** prev_link = NULL; // pointer to link to current node
  Node* cur = root; // current node during traversal (the node we look at for value comparison)
  Node* prev = NULL; // comes before the curr node (this is the node we hold the lock on)
  
  while(cur){
    if(value==vur->value) //found the node
    {
      lock(cur);
      //this is a leaf
      if(cur->left == NULL && cur>right==NULL){
        *prev_link = NULL;
        free(cur);
        return;
      }
      //exists left child
      else if (cur->right==NULL){
        *prev_link=cur->right;
        free(cur);
        return;
      }else if (cur->left==NULL){
        *prev_link=cur->left;
        free(cur);
        return;
      }else{
        unlock(prev);
        cur->value = delete_help(cur->right, &cur->right);
        unlock(cur);
        return;
      }
    }else if(vale< cur->value){
      //on the left
      lock(cur);
      unlock(prev->lock);
      prev_link = &cur->left;
      prev=cur;
      cur=cur->left;
    }else{
      //traverse right
    }
  }
}


// The helper method removes the smallest node in the tree rooted at node n.
// It returns the value of the smallest node.
int delete_help(Node* n, Node** prev){
  Node** prev_link = prev;
  Node* cur = n;
  Node* prev = NULL;
  
  while(cur->left){
    prev_link = &cur->left;
    lock(cur);
    unlock(prev);
    prev=cur;
    cur=cur->left;
  }
  
  int value = cur->value;
  if(cur->right==NULL){
    *prev_link=NULL;
    free(cur);
  }else {
    lock(cur);
    *prev_link = cur->right;
    unlock(cur);
    unlock(prev);
    free(cur);
  }
  return value;
  
  
  
  
}
