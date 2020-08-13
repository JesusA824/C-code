/*Program that uses multithreading. In this case the user enters the number
of elements, then followed by it's values. Then three threads calculate the respective average, maximum, and minimum values of that array of numbers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//member variables that hold the avg,min,max,number of elements, and the array
double avg;
int min;
int max;
int n;
int nums[100];

void *average(){ //average function that sums up elements and divides by n
int sum=0;
	for(int i=0; i<n;i++){
	sum=sum+nums[i];
	}
avg=sum/n;
printf("The average value is: %f",avg);

}

void *maximum(){// loops through array and prints max value
max=nums[0];
	for(int i=0; i<n; i++){
		if(nums[i]>max){
		max=nums[i];
		}
	}
printf("\nThe maximum value is: %d",max);
}

void *minimum(){//loops through array and prints max value
min=nums[0];
	for(int i=0; i<n; i++){
		if(nums[i]<min){
		min=nums[i];
		}
	}
printf("\nThe minimum value is: %d",min);
}

int main(){
	//asks user for number of elements
	printf("Enter the number of elements you want to use: ");
	scanf("%d",&n);
	//loops through to enter the elements
	for(int i=0; i<n; i++){
	printf("Enter number%d: ",i+1);
	scanf("%d",&nums[i]);
	}
	//declaring the the 3 threads
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
        int x;

	//creating and using the threads to use respective functions
 	x=pthread_create(&thread1,NULL,&average,NULL);
        pthread_join(thread1,NULL);

	
 	x=pthread_create(&thread2,NULL,&minimum,NULL);
        pthread_join(thread2,NULL);
	
	
 	x=pthread_create(&thread3,NULL,&maximum,NULL);
        pthread_join(thread3,NULL);
	
 	return 0;       
	

}
