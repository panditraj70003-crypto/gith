#include<iostream> 
#include<string>
#include<vector>
using namespace std;
class node{
  public:
  int data;
  node *next;
public:
node(int val){
  data = val;
  next = NULL;
}
 ~node(){
 
  if(next!=NULL){
    delete next;
    next = NULL;
  }
 }
};
class list{
  public:
  node*head;
  node*tail;
  public:
  list(){
    head = NULL;
    tail = NULL;
}
  ~list(){
    if(head!=NULL){
      delete head;
      head = NULL;
    }
  }
void push_front(int val){
  node *newnode = new node(val);
  if(head ==NULL){
    head = tail = newnode;
  }else{
    newnode->next = head;
    head = newnode; 
  }
}
void push_back(int val){
  node *newnode = new node(val);
  if(head==NULL){
    head=tail=newnode;
  }else{
    tail->next = newnode;
    tail=newnode;
  }
}
void print(){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ->"<<" ";
     temp =temp->next;
  }
}
void insert(int val, int pos){
  node* newnode = new node(val);
  node* temp = head;
  for(int i=0; i<pos-1; i++){
    if(temp==NULL){
       cout<<" galat jagah bhy"<<endl;
       return;
    }
    temp= temp->next;
  }
  // new temp at(pos-1);
  newnode->next = temp->next;
  temp->next = newnode;
}
void pop_front(){
  if(head==NULL){
    cout<<"empty";
  }
  node* temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;
}
int searchitr(int key){
  node*temp = head;
  int idx = 0;
  while(temp!=NULL){
  if(temp->data==key){
       return idx;
  }
  temp = temp->next;
  idx++;
}
  return -1;
}
int recursive(node*temp, int key){
  if(temp==NULL){
    return -1;
  }
  if(temp->data==key){
    return 0;
  }
 int idx = recursive(temp->next, key);
 if(idx==-1){
  return -1;
 }
 return idx+1;

}
int search(int key){
  return recursive(head,key);
}
void reverse(){
  node* curr = head;
  node* prev = NULL;
  while(curr!=NULL){
    node*next = curr->next;
    curr->next = prev;
    // upadatation after
    prev = curr;
    curr = next;
  }
  head  = prev;
}
int size(){
  int sz = 0;
  node* temp = head;
  while(temp!=NULL){
    temp = temp->next;
    sz++;
  }
  return sz;
}
void nth(int n){
  int s = size();
  node* prev = head;
  for(int i=1; i<(s-n); i++){
    prev = prev->next;
  }
node* todel = prev->next;
  cout<<" to deleting node = "<<todel->data<<endl;
  prev->next = prev->next->next;
}
 // remove nth cycle
 // detect a cycle
 void remove(node* head){
  node* slow = head;
  node* fast = head;
  bool iscycle = false;
  while(fast!=NULL&&fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast ){
      cout<< " cycle exists "<<endl;
      break;
    }
  }
  if(!iscycle){
    cout<<" cycle doesnt exists"<<endl;
    return;
  }
  slow = head;
  if(slow == fast){ // speacial case.
    while(fast->next!= slow){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL; //remove cycle;
  }else{
    node* prev = fast;
    while(slow!=fast){
      slow = slow->next;
      prev = fast;
      fast = fast->next;
    }
    prev->next = NULL;
  }
 }

};
  int main(){
    list ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // .print();
    // ll.nth(2)ll;
    // ll.print();
    // now for circular ll
    ll.tail->next = ll.head;
    ll.remove(ll.head);
    ll.print();
    
    return 0;
    }


    int main(){
      // hello
    }
  
