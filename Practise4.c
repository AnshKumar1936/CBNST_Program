#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float f(float x){
    return x*x*x - 3*x -5;
}

float diff(float x){
    return 3*x*x - 3;
}

int main()
{
    int maxItr,i;
    float x1,x2,x,x0;
    printf("Enter the no of Iterations:");
    scanf("%d", &maxItr);


    do
    {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)>0)
        {
            printf("Boundary are invalid\n");
            continue;
        }
        else
        {
            printf("Roots lie between %f and %f\n" ,x1,x2);
            break;
        }

    }while(1);

    if(fabs(f(x1)) < fabs(f(x2)))
        x0=x1;
    else
        x1=x2;
    
    for(i=1; i<maxItr;i++)
    {
        x=x0-(f(x0)/diff(x0));

        if (fabs(x - x0) <EPSILON) {
            printf("Iteration=%d  final root=%f\n",i,x);
        }
        printf("Iteration=%d  Roots=%f\n", i,x);
        x0=x;

    }
    printf("Roots=%f  Total Iteration=%d", x,--i);
    return 0;
    
}