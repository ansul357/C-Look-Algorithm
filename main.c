#include <stdio.h>
#include <stdlib.h>
int absolute(int a,int b)
    {int c;
     c=a-b;
     if(c<0)
            return -c;
     else
         return c;
         }

int main()
{
    int m,n,x,start,i,j,pos,a[15],count;
     count=0;
     printf("\nEnter the number of cylinders :");
     scanf("%d",&m);
     printf("\nEnter the number of requests :");
     scanf("%d",&n);
     printf("\nEnter current position :");
     scanf("%d",&start);
     printf("\nEnter the request queue :");
     for(i=0;i<n;i++)
                     {
                         scanf("%d",&a[i]);
                      if(a[i]>=m)
                       {  printf("\ninvalid input\n");
                                  scanf("%d",&a[i]);
                        }
                     }
    printf("Scheduling Services the request in the order that follows:\n%d\t",start);
                              count=0;
                              pos=0;
                              //for sorting the  request queue
                              for(i=0;i<n;i++)
                               {
                                   for(j=0;j<n-i-1;j++)
                                    {
                                       if(a[j]>a[j+1])
                                      {
                                          x=a[j];
                                          a[j]=a[j+1];
                                          a[j+1]=x;
                                       }

                                  }

                               }

                             for(i=0;i<n;i++)
                                             if(a[i]<start)
                                                           pos++;
                             x=start;
                             for(i=pos;i<n;i++)
                                               {count+=absolute(x,a[i]);
                                                x=a[i];
                                                printf("%d\t",x);
                                                }
                             for(i=0;i<pos;i++)
                                                {count+=absolute(x,a[i]);
                                                 x=a[i];
                                                 printf("%d\t",x);
                                                 }
                             for(i=0;i<n;i++)
                                             printf("%d\t",a[i]);
                             printf("\nTotal Head movement: %d Cylinders",count);


}
