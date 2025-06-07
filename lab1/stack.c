#include<stdio.h>
#define MAX 5
#define true 1
#define false 0

struct stack{
    int TOS;
    int arr[MAX];
};
int isFull(struct stack *s){
    if(s->TOS == MAX-1){
        return true;
    } else{
        return false;
    }
}
int isEmpty(struct stack *s){
    return (s->TOS==-1)?true:false;
    
}
void push(struct stack *s,int element){
    s->TOS++;
    s->arr[s->TOS]=element;
}
int pop(struct stack *s){
     int element;
     element=s->arr[s->TOS];
     s->TOS--;
     return element;
}
int peek(struct stack *s){
    return s->arr[s->TOS];
}
void main(){
    int choice,value;
    struct stack s;
    s.TOS=-1;
    do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(isFull(&s)){
                    printf("Stack is full!\n");
                } else {
                    printf("Enter value to push: "); 
                    scanf("%d", &value);
                    push(&s, value);
                    printf("Pushed %d onto stack.\n", value);
                }
                break;
            case 2:
                if(isEmpty(&s)){
                    printf("Stack is empty!\n");
                } else {
                    value = pop(&s);
                    printf("Popped %d from stack.\n", value);
                }
                break;
            case 3:
                if(isEmpty(&s)){
                    printf("Stack is empty!\n");
                } else {
                    value = peek(&s);
                    printf("Top element is %d.\n", value);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }while(choice != 4);
}
