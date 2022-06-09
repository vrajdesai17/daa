/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int a[100],aux[100];

//FUNCTION FOR SORTING THE SUBPART a[i..j] of a[]
void merge_sort(int i,int j,int a[],int aux[])
{
    if(j<=i)
    {
        return;  //SUBPART IS EMPTY OR CONTAINS ONLY SINGLE ELEMENT
    }
    else
    {
        int mid=(i+j)/2;  //LEFT SUBARRAY:a[i..mid] and RIGHT SUBARRAY:a[mid+1..j]
        merge_sort(i,mid,a,aux);  //SORTING LEFT SUBARRAY RECURSIVELY
        merge_sort(mid+1,j,a,aux);  //SORTING RIGHT SUBARRAY RECURSIVELY
        int left_pointer=i;  //POINTER POINTING THE BEGININIG OF THE LEFT SUBARRAY
        int right_pointer=mid+1;  //POINTER POINTING THE BEGINING OF THE RIGHT SUBARRAY
        int k; //k IS THE LOOP COUNTER 
        //WE WILL LOOP FROM i to j
        for(k=i;k<=j;k++)
        {
            if(left_pointer==mid+1)  //LEFT PONTER HAS REACHED THE LIMIT
            {
                aux[k]=a[right_pointer];
                right_pointer++;
            }
            else if(right_pointer==j+1)  //RIGHT PONTER HAS REACHED THE LIMIT
            {
                aux[k]=a[left_pointer];
                left_pointer++;
            }
            else if(a[right_pointer]>a[left_pointer])  //LEFT POINTER IS SMALLER THAN RIGHT POINTER
            {
                aux[k]=a[left_pointer];
                left_pointer++;
            }
            else  //RIGHT POINTER IS SMALLER THAN LEFT POINTER
            {
                aux[k]=a[right_pointer];
                right_pointer++;
            }
        }
        for(k=i;k<=j;k++)
        {
            a[k]=aux[k]; //COPYING ELEMENTS FROM aux[] to a[]
        }
    }
}


int main()
{
    int i,num;
    printf("Enter the number of elements in the array to be sorted:");
    scanf("%d",&num);
    printf("Enter the numbers:\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(0,num-1,a,aux);  //FUNCTION CALL
    printf("Array after merge sort:");
    for(i=0;i<num;i++)
    {
        printf("%d\n",a[i]);
    }
}

TIME COMPLEXITY : O(nlogn) in all cases