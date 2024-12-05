\\Dynamic array.
#include<stdio.h> 
#include<stdlib.h>
# define MAX_CAP10

typedef Struct {
    int *data;
    int size;
    int capacity;  
    }
    Dynamic Array;

Dynamic Array i* createDynamicArray()
{
    Dynamic Array*arr = (DynamicArray*)
        malloc(sizeof(DynamicArray));
    if (arr==NULL)   
        {
        printf (Std err, " Memory alocation fail\n);
        exit (1);
        }
    arr→data =(int*)malloc(sizeof(int)*MAX_CAP);
    if (arr→data= = NULL)
        {
        printf (Std err, "Memory allocation fail":) 
        exit (1);
        }
    }
arr → size =0;
arr → capacity = MAX_CAP 
return arr;

void freeDynamicArray(DynamicArray*arr){
    free(arr-->data);
    free(arr);
}
int main(){
    DynamicArray*dynamicArray = createDynamicArray()
    for(int i=1; i<=10; i++)
    {
        addElement(dynamicArray,i*10);
    }
    for(int i=0;i<dynamicArray-->Size;i++){
        printf("%d",dynamicArray-->data[i]);
    }
    freeDynamicArray(dynamicArray);
    return 0;
    }
}