#include<stdio.h>
#include<stdlib.h>
struct SLL{
int data ;
struct SLL *next;
};
struct SLL *first,*last=NULL;
void insert_at_beginning(int element){
   struct SLL *Newnode= (struct SLL *)malloc(sizeof(struct SLL));
   Newnode->next=NULL;
   Newnode->data=element;
   if(first==NULL){
    first=last=Newnode;
   }
   else{
    Newnode->next=first;
    first=Newnode;
   }
   printf("%d was inserted! \n",first->data);
}
void insert_at_end(int element){
   struct SLL *Newnode=(struct  SLL *)malloc(sizeof(struct SLL));
   Newnode->next=NULL;
   Newnode->data=element;
   if(first==NULL){
      first=last=Newnode;
   }
   else{
      last->next=Newnode;
      last=Newnode;
   }
   printf("%d was inserted at the end . \n",last->data);
   
}
void insert_at_sp(int element,int  pos){
   struct SLL *Newnode= (struct SLL *)malloc(sizeof(struct SLL));
   Newnode->next=NULL;
   Newnode->data=element;
   int i ;
   int temp;
   if(pos<=0){
      printf("Invalid position ! ");
   }
   else if (pos==1){
      insert_at_beginning(element);
   }
   else{
       struct SLL  *temp=first;
         for(i=1;(i<pos-1)&& (temp->next!=NULL);i++){
             temp=temp->next;
   }
   if(temp==last){
        insert_at_end(element);
   }
   else{
      Newnode->next=temp->next;
      temp->next=Newnode;
   
   }
      
   }  
   printf("%d was inserted at %d position",element,pos);
}
void display(){
   struct SLL *temp;
   if(first==NULL){
      printf("List is empty. \n");
   }
   else{
      temp=first;
      while(temp!=NULL){
         printf("%d ->",temp->data);
         temp=temp->next;
      
      }
      printf("NULL \n");
   
   }
}
int main(){
  insert_at_beginning(100);
  insert_at_beginning(200);
  insert_at_end(30);
  insert_at_sp(40,3);
  display();
  return 0;
}
