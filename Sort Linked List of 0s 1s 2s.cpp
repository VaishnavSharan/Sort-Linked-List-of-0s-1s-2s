
#include <iostream>
#include<vector>
using namespace std;


void insertAtTail(Node* &tail,Node* curr)
{
    tail->next=curr;
    tail=curr;
    
}
Node* sortList(Node *head){
   Node* zeroHead=new Node(-1);
   Node* zeroTail=zeroHead;
   Node* oneHead=new Node(-1);
   Node*oneTail=oneHead;
   
   Node*twoHead=new Node(-1);
   Node*twoTail=twoHead;
   
   Node*curr=head;
   //create seaparate list 0s,1s and 2s
   while(curr!=NULL)
   {
       int value=curr->data;
       if(value==0)
       {
           insertAtTail(zeroTail,curr);
       }
       else if(value==1)
       {
           insertAtTail(oneTail,curr);
       }
       else{
           insertAtTail(twoTail,curr);
       }
       curr=curr->next;
       
   }
   if(oneHead->next!=NULL)
   {
       zeroTail->next=oneHead->next;
   }
   else{
       zeroTail->next=twoHead->next;
   }
   
   oneTail->next=twoHead->next;
   twoTail->next=NULL;
   //setup head
   head=zeroHead->next;
   //delete dummy Nodes
   delete zeroHead;
   delete oneHead;
   delete twoHead;
   
   return head;
}