struct Node {
  int value;
  Node* next;
  Node* skip; // note that skip == next->next
};

// Please implement a thread-safe implementation of node deletion.

// assume function lock_node()

// delete node containing value
void delete_node(Node* head, int value){
  lock_node(head); //head will be unlocked while doing hand over hand lookup
  Node *curr = head;
  
  //hand over hand to find the target node's pre and prev
  while(curr->skip->value ! =value){
    Node *next = curr->next;
    //lock next before unlock curr node, 
    lock_node(next);
    unlock(curr);
    curr=next;
  }
  
  //cur is locked when exiting the while loop
  
  //delete the node
  Node* to_delete = curr->skip;
  Node* next = curr->next;
  lock_node(next);
  lock_node(to_delete);
  cur->skip = to_delete->next;
  next->next = to_delete->next;
  next->skip = to_delete->skip;
  delete(to_delete);
  unlock_node(to_delete);
  unlock_node(next);
  unlock_node(curr);
}
