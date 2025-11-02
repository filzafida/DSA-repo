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

void pop(struct stack *ptr){
    if(is_empty(ptr)){
        printf("Stack underflow");
    }else{
        int value = ptr->arr[ptr->top]; //puts last element  in value variable
        ptr->top--; //so now last element removed
        printf("\nlast element is :%d",value);
    }
}

int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("invalid value");
        return -1;
    }else{
        return ptr->arr[ptr->top-i+1];
    }
}

int main(){
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size=5;
    sp->top=-1;
    sp->arr= (int *)malloc(sp->size*sizeof(int));
    printf("Stack is created succesfully\n");

    printf("before pushing empty:%d\n",is_empty(sp));
    printf("before pushing full:%d\n",is_full(sp));

    printf("\nchecking after pushing an element\n");
    push(sp,89);
    push(sp,78);
    push(sp,7);
    push(sp,6);
    push(sp,90);  //i pushed 5 times, stack will be full
    push(sp,67); //stack is already full so stack overflow
    printf("after pushing empty:%d\n",is_empty(sp));
    printf("after pushing full:%d\n",is_full(sp));

    pop(sp);
    pop(sp);
    pop(sp);
    printf("\nafter poping empty:%d\n",is_empty(sp));
    printf("after poping full:%d\n",is_full(sp));



    printf("peeking in the stack\n");

    for(int j=1;j<=sp->top+1;j++){
        printf("the value at position %d is %d:\n",j,peek(sp,j));
    }

    return 0;
}