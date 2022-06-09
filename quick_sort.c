#include <stdio.h>
#include <conio.h>

int a[100];

void quick_sort(int first,int last,int a[])
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(a[i]<=a[pivot] && i<last)
            {
                i++;
            }
            while(a[j]>a[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quick_sort(first,j-1,a);
        quick_sort(j+1,last,a);
    }
}


int main()
{
    int num,i;
    printf("Enter the number of elements in an array:");
    scanf("%d",&num);
    printf("Enter the numbers:\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(0,num-1,a);
    printf("Array after quick sort:\n");
    for(i=0;i<num;i++)
    {
        printf("%d\n",a[i]);
    }
}

TIME COMPLEXITY :
WORST CASE : O(n^2)[When smallest or largest element is selected as the pivot element]
BEST CASE : O(nlogn)[When the middle element is selected as pivot element]