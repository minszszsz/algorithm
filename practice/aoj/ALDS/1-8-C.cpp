#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
struct Node{
  int value;
  Node *left;
  Node *right;
  Node *parent;
};

struct Node *NIL;

class BinarySearchTree{
  private:
    Node *root;
    Node* find_node(int value){
      Node *node = root;
      while(node != NIL && node->value != value){
        if(value < node-> value)node = node->left;
        else node = node->right;
      }
      return node;
    }
    void delete_node(Node *node){
      if(node==NIL)return;
      if(node==root){
        root=NIL;return;
      }
      Node *parent = node->parent;
      if(parent->left == node){
        if(node->left == NIL && node->right == NIL){
          parent->left = NIL;
          free(node);
        }
        else if(node->right == NIL){
          parent->left = node->left;
          node->left->parent = parent;
          free(node);
        }
        else if(node->left == NIL){
          parent->left = node->right;
          node->right->parent = parent;
          free(node);
        }
        else{
          node->value = node->left->value;
          delete_node(node->left);
        }
      }
      else{
        if(node->left == NIL && node->right == NIL){
          parent->right = NIL;
          free(node);
        }
        else if(node->right == NIL){
          parent->right = node->left;
          node->left->parent = parent;
          free(node);
        }
        else if(node->left == NIL){
          parent->right = node->right;
          node->right->parent = parent;
          free(node);
        }
        else{
          node->value = node->left->value;
          delete_node(node->left);
        }
      }
    }
  public:
    BinarySearchTree(){
      root=NIL;
    }
    void insert(int value){
      Node *node = (Node*)malloc(sizeof(Node));
      node->value = value;
      node->right = NIL;
      node->left = NIL;
      Node* x=root;
      Node* y=NIL;
      while(x!=NIL){
        y = x;
        if(node->value < x->value){
          x = x->left;
        }
        else{
          x = x->right;
        }
      }
      node->parent = y;
      if(y==NIL)root = node;
      else if(node->value < y->value)y->left = node;
      else y->right = node;
    }
    bool find(int value){
      return find_node(value)!=NIL;
    }
    void del(int value){
      Node *node = find_node(value);
      delete_node(node);
    }
    void print(){
      inorderWalk(root);
      cout << endl;
      preorderWalk(root);
      cout << endl;
    }
    void inorderWalk(Node *node){
      if(node == NIL)return;
      inorderWalk(node->left);
      cout << ' ' << node->value;
      inorderWalk(node->right);
    }
    void preorderWalk(Node *node){
      if(node == NIL)return;
      cout << ' ' << node->value;
      preorderWalk(node->left);
      preorderWalk(node->right);
    }
};


int main(){
  int n;cin >> n;
  string com;
  BinarySearchTree T;
  for(int i=0;i<n;i++){
    cin >> com;
    if(com == "insert"){
      int num;cin >> num;
      T.insert(num);
    }
    else if(com == "print"){
      T.print();
    }
    else if(com == "find"){
      int num;cin >> num;
      cout << (T.find(num)?"yes": "no") << endl;
    }
    else if(com == "delete"){
      int num;cin >> num;
      T.del(num);
    }
  }
}

