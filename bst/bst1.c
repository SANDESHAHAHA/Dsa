#include<stdio.h>
#include<stdlib.h>
struct BinaryTree{
    int data;
    int height;
    struct BinaryTree *left;
    struct BinaryTree *right;
    struct BinaryTree *parent;

};
struct BinaryTree *root = NULL;

struct BinaryTree* createNode(int value){ //node ko address return gareko
 struct BinaryTree* Newnode=(struct BinaryTree*)(malloc(sizeof(struct BinaryTree)));
 Newnode->data=value;
 Newnode->left=NULL;
 Newnode->right=NULL;
 Newnode->parent=NULL;
 Newnode->height=0;
 return Newnode; 
}
int  height(struct BinaryTree *root){
    if(root==NULL) return -1;
    else{
        return root->height;
    }
}
int getBalance(struct BinaryTree* root){
    if(root==NULL) return 0;
    else{
        return height(root->left)-height(root->right);
    }
}
int max(int a,int b){
    return (a>b)?a:b;
}
void updateHeight(struct BinaryTree *root){
    if(root){
        root->height=1+max(height(root->left),height(root->right));
    }
}
struct BinaryTree* leftrotate(struct BinaryTree *x){
    struct BinaryTree *y=x->right;
    struct BinaryTree *T2=y->left;
    y->left=x;
    x->right=T2;
    y->parent=x->parent;
    x->parent=y;
    if(T2) T2->parent=x;
    updateHeight(x);
    updateHeight(y);
    return y;
}
struct BinaryTree *rightrotate(struct BinaryTree * y){
    struct BinaryTree *x=y->left;
    struct BinaryTree *T2=x->right;
    x->right=y;
    y->left=T2;
    x->parent=y->parent;
    y->parent=x;
    if(T2) T2->parent=y;
    updateHeight(y);
    updateHeight(x);
    return x;
}
//Traversal 
void preorder(struct BinaryTree *root){
   
    if(root !=NULL)
    {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
   
}
void inorder(struct BinaryTree *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct BinaryTree *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct BinaryTree *insert(struct BinaryTree *root,int data){
    if (root==NULL) 
    return createNode(data);
    else if (data< root->data){
      root->left=insert(root->left,data);
      root->left->parent=root;
    }
    else{
        root->right=insert(root->right,data);
        root->right->parent=root;
    }
    // return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);
    if (balance>1 && data<root->left->data) return rightrotate(root); //rigth rotation
    if(balance<-1 && data>root->right->data) return leftrotate(root); //left rotation
    if(balance>1 && data>root->left->data) { //left-right rotation
        root->left=leftrotate(root->left);
        return rightrotate(root);
    } 
    if(balance<-1 && data<root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }  
    return root;
}
struct BinaryTree* Search(struct BinaryTree *root,int key){
    if (root == NULL || key==root->data) return root;
    if (key<root->data){
     return Search(root->left,key);
    }
    else {
        return  Search(root->right,key);
    }
}
struct BinaryTree* min(struct BinaryTree *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct BinaryTree* find_max(struct BinaryTree *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct BinaryTree* delete_Node(struct BinaryTree *root,int value){
if (root==NULL){
    return NULL;
}
else if (value<root->data){
    root->left=delete_Node(root->left,value);
    if(root->left) root->left->parent=root;
}
else if (value>root->data){
    root->right=delete_Node(root->right,value);
    if(root->right) root->right->parent=root;
}
else{ //bhetisake paxi k garney bhane kura ho yeta 
    if(root->left == NULL){
        struct BinaryTree *temp=root->right;
        if (temp){
            temp->parent=root->parent;
        }
        free(root);
        return temp;

    }
    else if(root->right==NULL){
        struct BinaryTree *temp=root->left;
        if(temp){
            temp->parent=root->parent;
        }
        free(root);
        return temp;
    }
    else{
        //case 3 having both children. 
        struct BinaryTree *temp=min(root->right);
        root->data=temp->data;
        root->right=delete_Node(root->right,temp->data);
        if(root->right) root->right->parent=root;
    }
}
if(root==NULL){
    return root;
}
root->height=1+max(height(root->left),height(root->right));
int balance=getBalance(root);
//roattions after delete
if(balance>1 && getBalance(root->left)>=0) return rightrotate(root); //r0,r1 rotation
if(balance>1 && getBalance(root->left)<0) { //R-1 rotation
    root->left=leftrotate(root->left);
    return rightrotate(root);
}
if(balance<-1 && getBalance(root->right)<=0) return leftrotate(root); //l1 or l0 rotation 
if (balance<-1 && getBalance(root->right)>0){
    root->right=rightrotate(root->right);
    return leftrotate(root);
}
return root;
}
int main(){
    int i,element,choice;
    struct BinaryTree *temp;
    int arr[]={8,3,10,1,6,14,4,7,13};
    do
    {
        printf("\n1.Insert\n2.DELETE\n3.search\n4.Inorder\n5.preorder\n6.postorder\n7.find max\n8.find min\n9.Create Tree\n10.Exit");
          printf("\nEnter choice : \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: \n");
            scanf("%d",&element);
            root=insert(root,element);
            break;
        case 2:printf("Enter the element to delete: ");
        scanf("%d",&element);
        root=delete_Node(root,element);
        printf("%d deleted",element  );
        break;
        case 3:
        printf("Enter the element to search: ");
        scanf("%d",&element);
        temp=Search(root,element);
        if(temp==NULL){
            printf("%d not found\n",element);

        }
        else {
            printf("%d found",element);
        }
        break;
        case 4: inorder(root);
        break;
        case 5:preorder(root);
        break;
        case 6:postorder(root);
        break;
        case 7: temp=find_max(root);
             if(temp!=NULL){
                printf("%d is the largest element",temp->data);
             }
            
        break;
        case 8: temp=min(root);
        if(temp!=NULL){
            printf("%d is the smallest element in the bst. ",temp->data);
        }
        break;
        case 9:
            for (i=0;i<9;i++){
                root=insert(root,arr[i]);
                
            }
            printf("all elements inserted successfully");
        break;
        case 10:
        printf("Exiting..\n");
        exit(0);

        default: printf("Enter the valid input");
            break;
        }
    } while (choice!=10);
    return 0;
}