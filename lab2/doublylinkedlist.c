#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct DLL{
    int data;
    struct DLL *next,*prev;
};
struct DLL *first,*last=NULL;
void insertion_at_beginning(int element){
    struct DLL *Newnode;
    Newnode=(struct DLL *)malloc(sizeof(struct DLL));
    Newnode->data=element;
    Newnode->next=NULL;
    Newnode->prev=NULL;
    if(first==NULL)
    {
        //No nodes found so our newnode becomes the first, and last at the same time.
        first=last=Newnode;
    }
    else{
        Newnode->next=first;
        first->prev=Newnode;
        first=Newnode;
    }
    printf("%d was inserted . \n",first->data);

}
void insertion_at_end(int element){
    struct DLL *Newnode;
    Newnode=(struct DLL *)malloc(sizeof(struct DLL));
    Newnode->next=NULL;
    Newnode->prev=NULL;
    Newnode->data=element;
    if(first==NULL){
        first=last=Newnode;
    }
    else{
        Newnode->prev=last;
        last->next=Newnode;
        last=Newnode;
    }
    printf("%d has been inserted . \n",last->data);
}
void insertion_at_sp(int element,int pos){
     struct DLL *Newnode;
         int i;
    Newnode=(struct DLL *)malloc(sizeof(struct DLL));
    Newnode->next=NULL;
    Newnode->prev=NULL;
    Newnode->data=element;
    if(pos<=0) printf("Invalid postion.\n");
    else if(pos==1 || first==NULL) insertion_at_beginning(element);
    else{
        struct DLL *temp;
          temp=first;
        for(i=1;i<pos-1 && temp->next!=NULL;i++){
           temp=temp->next;
        }
        if(temp==last){
            insertion_at_end(element);
        }
        else{
            struct DLL *tempP;
            tempP=temp->next;
            temp->next=Newnode;
            Newnode->prev=temp;
            Newnode->next=tempP;
            tempP->prev=Newnode;
        }
        printf("%d was inserted at %d postion.\n",element,pos);
    }
}
void display(){
   struct DLL *temp;
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
void del_from_beg(){
    if(first==NULL){
        printf("List is empty ! ");
    }
    else if (first->next==NULL){
        struct DLL *temp;
        temp=first;
        first=last=NULL;
        free(temp);
    }
    else{
        struct DLL *temp;
        temp=first;
        first=first->next;
        printf("%d has been deleted \n",temp->data);
        free(temp);
        first->prev=NULL;
    }
}
void del_from_end(){
      if(first==NULL){
        printf("List is empty ! ");
    }
    else if (first->next==NULL){
       del_from_beg();
    }
    else{
        struct DLL *temp;
        temp=last;
        last=last->prev;
        printf("%d is going to be delted \n",temp->data);
        free(temp);
        last->next=NULL;
      
    }
}
void del_at_sp(int pos){
    int i;
    if(pos<=0 || first==NULL){
        printf("Invalid postion for deletion ! \n");
    }
    else if(pos==1 ||first->next==NULL){
        del_from_beg();
    }
    else{
        struct DLL *temp;
        temp=first;
       for(i=1;i<pos-1 && temp->next!=last;i++){
        temp=temp->next;
       } 
       if(temp->next==last){
        del_from_end();
       }
       else{
        struct DLL *tempP;
        tempP=temp->next;
        temp->next=tempP->next;
        (temp->next)->prev=temp;
        printf("%d is going to delete from the list. \n",tempP->data);
        free(tempP);
       }
    }
}
int main(){
  insertion_at_beginning(100);
  insertion_at_beginning(200);
  insertion_at_end(30);
  insertion_at_sp(40,3);
  display();
  insertion_at_sp(400,1);
  display();
  insertion_at_sp(500,6);
  display();
  del_from_end();
  display();
  del_at_sp(1);
  display();
  del_at_sp(2);
  display();
  return 0;
}