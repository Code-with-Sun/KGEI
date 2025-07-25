// WAP to sort a array in ascending but even comes first
#include<stdio.h>
int main(){
    int n,arr[10],i,j,temp;
    printf("Enter the length of the array : ");
    scanf("%d",&n);
    printf("Enter the array elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i= 1;i<n;i++){
        j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(arr[j] % 2 == 0){
                if(arr[j-1] % 2 != 0){
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
                else
                    continue;
            }
        }
    }
    printf("After sorting the array are : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}