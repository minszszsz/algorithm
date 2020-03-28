#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

struct Node{
  int value;
  Node* nx;
  Node* prev;
};

Node *nil;

void init(){
  nil = (Node *) malloc(sizeof(Node));
  nil->nx = nil;
  nil->prev = nil;
}

void insert(int x){
  Node *n = (Node *)malloc(sizeof(Node));
  n->value = x;
  n->nx = nil->nx;
  n->prev = nil;
  nil->nx->prev = n;
  nil->nx = n;
}

void del(Node* n){
  n->prev->nx=n->nx;
  n->nx->prev=n->prev;
  free(n);
}

void del_key(int key){
  Node* cur=nil->nx;
  while(cur!=nil){
    if(cur->value == key){
      del(cur);
      break;
    }
    cur = cur->nx;
  }
}

void del_first(){
  del(nil->nx);
}

void del_last(){
  del(nil->prev);
}

int main(){
  init();
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string com;cin >> com;
    if(com == "insert"){
      int x;cin >> x;
      insert(x);
    }
    else if(com == "delete"){
      int x;cin >> x;
      del_key(x);
    }
    else if(com == "deleteFirst"){
      del_first();
    }
    else if(com == "deleteLast"){
      del_last();
    }
  }
  Node *cur=nil->nx;
  while(cur != nil){
    cout << cur->value;
    cur = cur->nx;
    cout << (cur == nil? '\n': ' ');
  }
}