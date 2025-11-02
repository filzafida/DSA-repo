#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}


int is_full(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}


void push(struct stack *ptr,int value){
    if(is_full(ptr)){
        printf("stack overflow\n");
    }else{
        ptr->top++; //update top by 1
        ptr->arr[ptr->top]=value; //insertion of value into top (which is already increased)

    }
}

int Stackbottom(struct stack *ptr){
    if(is_empty(ptr)){
        printf("\nstack is empty\n");
        return -1;
    }else{
        return ptr->arr[0];

    }

}
int StackTop(struct stack *ptr){
    if(is_empty(ptr)){
        printf("\nstack is empty\n");
        return -1;
    }else{
        return ptr->arr[ptr->top];
    }
}
int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size=5;
    sp->top=-1;
    sp->arr= (int *)malloc(sp->size*sizeof(int));
    printf("Stack is created succesfully\n");

    push(sp,89);
    push(sp,78);
    push(sp,7);
    push(sp,6);
    push(sp,90);

    printf("The bottom value of this stack is %d\n",Stackbottom(sp));
    printf("The topmost value of this stack is %d\n",StackTop(sp));

}