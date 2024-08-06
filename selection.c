#include<stdio.h>
#include<stdlib.h>
#include<time.h>
voidSelectionSort(int arr[],int n){
int i,j,min,temp;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++){
if(arr[j]<arr[min]){
min=j;}}
temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;}}
int man()
{
int n,i;
clock_t start,end;
double cpu_time_used;
printf("enter th enuber of element(n):");
scanf("%d",&n);
if(n<5000){
printf(:enter the value of n greater than 5000.\n");
return 1;}
int*arr=(int*)malloc(n*sizeof(int));
if(arr=NULL){
printf("memory allocation falied\n");
return 1;}
srand(time(NULL));
for(i=0;i<n;i++){
arr[i]=rand()%10000;}
start=clock();
SelectionSort(arr,n);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC:
printf("time taken :%if seconds\n",cpu_time_used);
free(arr);
return 0;
}
