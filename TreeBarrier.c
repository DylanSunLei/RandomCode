struct Barrier_t {
  LOCK lock;
  int entering_counter;  //initialize to 0
  int leaving_counter;
  int flag; //padded to sit on it's own cache line
  
  Barrier_t *left;
  Barrier_t *right;
}


struct Barrier_Tree{
  Barrier_t* root;
}

//assume P is 2^k
void Barrier(Barrier_Tree* root){
  //DFS lookup to a leaf barrier which enter_count < 2;
}


