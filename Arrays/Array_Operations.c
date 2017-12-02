#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert(int *, int pos, int num);
void del(int *, int pos);
void reverse(int *);
void display(int *);
void search(int *, int num);

int main() {
    int arr[5];

    system("cls");

    insert(arr, 1,11);
    insert(arr, 2, 12);
    insert(arr, 3,13);
    insert(arr,4,14);
    insert(arr, 5,15);

    printf("Element of Array:\n");
    display(arr);

    del(arr,5);
    del(arr,2);
    printf("After Deletion:\n");
    display(arr);

    insert(arr,2,222);
    insert(arr,5,555);
    printf("After insertion:\n");
    display(arr);
    reverse(arr);
    printf("After Reversing:\n");
    display(arr);
    search(arr,222);
    search(arr,666);

    return 0;
}

//Insert an element num at given position pos
void insert(int *arr, int pos, int num) {
    // shift element to right
    int i;
    for(i = MAX-1;i>=pos;i--) {
        arr[i] = arr[i-1];
    }
    arr[i] = num;
}

// deletes an element from given position pos
void del(int *arr, int pos) {
    // skip to desired position 
    int i;
    for(i=pos;i<MAX;i++) {
        arr[i-1] = arr[i];
    }
    arr[i-1] = 0;
}

//reverse the entire array
void reverse(int *arr) {
    int i;
    for(i=0;i<MAX/2;i++) {
        int temp = arr[i];
        arr[i] = arr[MAX-1-i];
        arr[MAX-1-i] = temp;
    }
}

//searches array for given element num
void search(int *arr, int num){
    //Traverse the array
    int i;
    for(i=0;i<MAX;i++){
        if(arr[i]==num){
            printf("The element %d is present at %dth position.\n\n",num,i+1);
            return;
        }
    }
    if (i==MAX) {
        printf("The element %d is not present in the array.\n\n", num);
    }
}

//Display the contents of a array
void display(int *arr){
    //traverse the entire array
    int i;
    for(i=0;i<MAX;i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

