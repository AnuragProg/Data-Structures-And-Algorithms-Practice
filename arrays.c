#include <stdio.h>
#include <stdlib.h>

int SIZE = 0;
int CAPACITY = 0;
int *arr = NULL;


int createArray(int size){
    arr = calloc(size, sizeof(int));
    CAPACITY = size;
    return 1;
}

int at(int index){
    if(index<0 || index>=SIZE){
        return 0;
    }
    return *(arr+index); 
}

int set(int index, int value){
    if(index<0 || index>=CAPACITY) return 0;
    *(arr+index) = value;
}

void newLine(){
    printf("\n");
}

int push_back(int value){
    if(SIZE == CAPACITY){
        arr = realloc(arr, CAPACITY*2*(sizeof(int)));
        CAPACITY *= 2;
        arr[SIZE] = value;
        
        SIZE++;
    }
    else{
        *(arr+(SIZE++)) = value;
        return 1;
    }
}

int size(){
    return SIZE;
}

int capacity(){
    return CAPACITY;
}


void printArray(){
    printf("\n");
    printf("Elements of Array are : \n");
    for(int i=0; i<50; i++) printf("-");
    printf("\n");
    for(int i=0; i<SIZE; i++){
        printf("%d\t", *(arr+i));
    }
    printf("\n");
    for(int i=0; i<50; i++) printf("-");
    printf("\n");
}

int find(int value){
    for(int i=0; i<SIZE; i++){
        if(*(arr+i) == value) return i;
    }
    return -1;
}

int insertAtIndex(int index, int value){
    
    if(index<0 || index>=CAPACITY){
        return 0;
    }else if(SIZE==CAPACITY){
        int *new_arr = calloc(SIZE*2, sizeof(int));
        for(int i=0; i<index; i++) *(new_arr+i) = *(arr+i);
        *(new_arr+index) = value;
        for(int i=index+1; i<=SIZE; i++){
            *(new_arr+i) = *(arr+i-1);
        }
        CAPACITY *= 2;
        free(arr);
        arr = new_arr;
    }else{
        int *new_arr = calloc(CAPACITY, sizeof(int));
        for(int i=0; i<index; i++) *(new_arr+i) = *(arr+i);
        *(new_arr+index) = value;
        for(int i=index+1; i<=SIZE; i++) *(new_arr+i) = *(arr+i-1);
        SIZE++;
        free(arr);
        arr = new_arr;
    }
    return 1;

}

int deleteAtIndex(int index){
    if(index<0 || index>=SIZE){
        return 0;
    }else{
        int* new_arr = calloc(CAPACITY, sizeof(int));
        for(int i=0; i<index; i++) *(new_arr+i) = *(arr+i);
        for(int i=index+1; i<SIZE; i++) *(new_arr+i-1) = *(arr+i);
        free(arr);
        arr = new_arr;
        SIZE--;
        return 1;
    }
}

int removeValue(int value){
    int *new_arr = calloc(CAPACITY, sizeof(int));
    int i=0,j=0;
    while(i<SIZE){
        if(arr[i] != value){
            new_arr[j] = arr[i];
            j++;
            i++;
        }else{
            i++;
        }
    }
    SIZE -= (i-j);
    free(arr);
    arr = new_arr;
}

int pop(){
    *(arr+(--SIZE)) = 0;
    
}

int isEmpty(){
    return SIZE == 0;
}

int clear(){
    for(int i=0; i<SIZE; i++) *(arr+i) = 0;
    SIZE = 0;
}

int prepend(int value){
    if(SIZE==CAPACITY){
        int* new_arr = calloc(CAPACITY*2, sizeof(int));
        *(new_arr) = value;
        for(int i=1; i<=SIZE; i++) *(new_arr+i) = *(arr+i-1);
        free(arr);
        CAPACITY *= 2;
        SIZE++;
        arr = new_arr;
        return 1;
    }else{
        int *new_arr = calloc(CAPACITY, sizeof(int));
        *(new_arr) = value;
        for(int i=1; i<=SIZE; i++) *(new_arr+i) = *(arr+i-1);
        free(arr);
        SIZE++;
        arr=new_arr;
        return 1;
    }
}



int resize(int new_capacity){
    arr = realloc(arr, new_capacity*sizeof(int));
    CAPACITY = new_capacity;
    return 1;
}


int main(){
    if(arr == NULL){
        createArray(10);
    }

    for(int i=0; i<10; i++){
        push_back(i);
    }

    printArray();

    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());

    printf("\nAfter pushing another value in arr\n");
    push_back(10);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nInserting 9 more elements");
    for(int i=10; i<19; i++) push_back(i);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nAdding one value at end");
    push_back(99);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nAfter inserting element at index 2");
    insertAtIndex(2, 100);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nAfter deleting one element at index 2");
    deleteAtIndex(2);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nNumber at index 2 is %d", at(2));
    printf("\nIs array empty %s", (isEmpty())?"True": "False");
    printf("\nPrepending value in arr with 2");
    prepend(2);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nPrepending another value 3");
    prepend(3);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nPopping value from array");
    pop();
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nRemoving all 10's in the array");
    removeValue(10);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nFind index of value 9 and 1");
    printf("\n9=%d and 1=%d", find(9), find(1));
    printf("\nFind first index of value 2 is %d", find(2));
    printf("\nResizing the arr to 60");
    resize(60);
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    printf("\nClearing the entire array");
    clear();
    printArray();
    printf("\nCapacity is %d", capacity());
    printf("\nSize is %d", size());
    
    
}