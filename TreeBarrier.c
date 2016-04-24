struct Barrier_t {
  LOCK lock;
  int entering_counter;
  int leaving_counter;
  int flag;
  
  Barrier_t *left;
  Barrier_t *right;
}


struct Barrier_Tree

void Barrier(Barrier_t* b, int p)


