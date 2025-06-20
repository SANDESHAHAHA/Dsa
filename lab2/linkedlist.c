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
void delete_from_beg(){
   if(first==NULL){
      printf("empty list! \n");
   }
   else if (first->next==NULL){
      free(first);
      first=last=NULL;
   }
   else{
      struct SLL *temp=first;
      first=first->next;
      printf("%d is going to be deleted\n",temp->data);
      free(temp);
   }
}
void del_from_end(){
   struct SLL *temp;
   if(first==NULL){
      printf("empty list !");

   }
   else if(first->next==NULL){
    delete_from_beg();
   }
   else{
      
      temp=first;
      while(temp->next!=last){
         temp=temp->next;
      }
      last=temp;
      temp=temp->next;
      printf("%d is going to be delted \n",temp->data);
      free(temp);
      last->next=NULL;
   }
  
}
void del_at_sp(int pos){
   struct SLL *temp;
   if(pos<=0) printf("Can't perform deletion on empty list! \n");
   else if (pos==1 || first->next==NULL) {
      delete_from_beg();
   }
   else{
      temp=first;
      int i ;
      for(i=1;i<(pos-1) && (temp->next!=last);i++){
         temp=temp->next;
      }
      if(temp->next==last){
         del_from_end();
      }
      else{
         struct SLL *tempP;
         tempP=temp->next;
         temp->next=tempP->next;
         printf("%d is going to delete from the list. \n",tempP->data);
         free(tempP);
      }
   
   }
}
int main(){
  insert_at_beginning(100);
  insert_at_beginning(200);
  insert_at_end(30);
  insert_at_sp(40,3);
  display();
  insert_at_sp(400,1);
  display();
  insert_at_sp(500,6);
  display();
  del_from_end();
  display();
  del_at_sp(1);
  display();
  return 0;
}
