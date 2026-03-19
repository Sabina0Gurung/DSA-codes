//Selection sort code in c
#include<stdio.h>
void selectionSort(int arr[],int n){
	int i,j,minindex,temp;
	
	for(i=0;i<n-1;i++){
		//current index is minimum
		minindex=i;
		
		//Search for minimum element in rest of the array
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		if(minindex!=i){
			temp=arr[i];
			arr[i]=arr[minindex];
			arr[minindex]=temp;
		}
	}
}
void printArray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[]={3,2,6,5,4};
	int n=5;
	
	printf("Orginal array:\n");
	printArray(arr,n);
	
	selectionSort(arr,n);
	
	printf("Sorted Array:\n");
	printArray(arr,n);
	
	return 0;
}