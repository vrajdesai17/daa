#include<stdio.h>
#include<conio.h>

int max,min;
int a[100];

void max_min(int i,int j)
{
    int max1,min1,mid;
    if(i==j)
    {
        max=min=a[j];
    }
    else
    {
        if(i==j-1)
        {
            if(a[i]>a[j])
            {
                max=a[i];
                min=a[j];
            }
            else
            {
                max=a[j];
                min=a[i];
            }
        }
        else
        {
            mid=(i+j)/2;
            max_min(i,mid);
            max1=max;
            min1=min;
            max_min(mid+1,j);
            if(max1>max)
            {
                max=max1;
            }
            if(min1<min)
            {
                min=min1;
            }
        }
    }
}


int main()
{
    int i,num;
    printf("Enter the number of elements in the array:");
    scanf("%d",&num);
    printf("Enter the numbers:\n");
    for(i=1;i<=num;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    max_min(1,num);
    printf("Maximum element in the array:%d\n",max);
    printf("Minimum element in the array:%d\n",min);
    return 0;
}




TIME COMPLEXITY = O(n)[Recursion Tree]