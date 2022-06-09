#include<stdio.h>
#include<conio.h>

void knapsack(int n,float capacity,float weight[],float profit[])
{
    float x[20],tp=0;
    int i,j,u;
    u=capacity;
    for(i=0;i<n;i++)
    {
        x[i]=0.0;
    }
    for(i=0;i<n;i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            tp+=profit[i];
            u-=weight[i];
        }
    }
    if(i<n)
    {
        x[i]=u/weight[i];
    }
    tp=tp+(x[i]*profit[i]);
    printf("Solution vector:");
    for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
    }
    printf("\nMaximum Profit:%f",tp);
}

int main()
{
    float capacity,weight[20],profit[20];
    int i,j,num;
    float ratio[20],temp;
    printf("Enter the number of objects:");
    scanf("%d",&num);
    printf("Enter the weights and profits of the objects:");
    for(i=0;i<num;i++)
    {
        scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("Enter the capacity of knapsack:");
    scanf("%f",&capacity);
    for(i=0;i<num;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<num;i++)
    {
        for(j=0;j<i;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
                
                temp=weight[i];
                weight[i]=weight[j];
                weight[j]=temp;
                
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;
            }
        }
    }
    knapsack(num,capacity,weight,profit);
    return 0;
}