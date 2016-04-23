struct Node {
    int value;
    Node *left;
    Node *right;
    Lock* lock;
};

struct BTree {
    Node *root;
};

Node* new_node(){
    Node *n = new Node;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(Node *root, int value){
    //tree is empty
    if (!root) {
        root = new_node();
        return;
    }else{
        // on the left
        if(root->value>value){
            if(root->left){
                insert(root->left, value);
            }
            else{
                root->left = new_node();
            }
        } else if(root->value<value){
            //on the right of the tree
            if(root->right){
                insert(root->right, value);
            }
            else{
                root->right = new_node();
            }
        }
    }
}

void delete_node(Node* node, Node* child){
    Node *n = node;
    node=child;
    delete n;
}

Node* min_node(Node* root){
    if(root){
        if(root->left)
            return min_node(root->left);
        else
            return root;
    }else{
        return root;
    }
}

void delete(Node* root, int value){
    if (!root)
        return;
    else{
        if(root->value==value){
            if(!root->left && !root->right){
                delete_node(root, NULL);
            }
            //has right ro left
            else if(!root->left && root->right){
                delete_node(root, root->right);
            }
            else if(root->left && !root->right){
                delete_node(root, root->left);
            }
            //both
            else{
                //replace root with smallest value greater than root
                new_root = min_node(root->right);
                root->value = new_root->value;
                root->right = delete(root->right, root->value);
            }
        }
        else if (root-> value > value){
            delete(root->left, value);
        }else{
            delete(root->right, value);
        }
    }
}
