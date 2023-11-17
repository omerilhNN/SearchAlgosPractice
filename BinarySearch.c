#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *data;
    int size;
};
void initializeArray(struct Array *arr,int size){
    arr->data = (int *)malloc(size*sizeof(int));
    arr->size = size;
}
void freeArray(struct Array *arr){
    free(arr->data);
}
void printArray(struct Array *arr){
    printf("Array elements: \n");
    for(int i = 0; i<arr->size;i++){
        printf("%d",arr->data[i]);
    }
    printf("\n");
}

int binarySearch(struct Array *arr, int keyValue) {
    int left = 0;
    int right = arr->size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr->data[mid] == keyValue)
            return keyValue;
        else if (arr->data[mid] < keyValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    //If target is not present in the array;
    return -1;
}

int main(){
        struct Array array;
        int keyValue;
        printf("Please enter the size of the array:\n");
        scanf("%d",&array.size);

        initializeArray(&array,array.size);

        printf("Enter the elements of the array:\n");
        for(int i=0;i< array.size; i++){
            scanf("%d",&array.data[i]);
        }

        printArray(&array);

        printf("Enter the key value to search\n");
        scanf("%d",&keyValue);

        int result = binarySearch(&array, keyValue);

        if(result ==-1){
            printf("Element is not present in the array\n");
        }else {
            printf("Element found in the array and it is %d\n",result);
        }
        freeArray(&array);

        return 0;
}
