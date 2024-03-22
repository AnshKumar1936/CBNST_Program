#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float findValueAt(float x){
    return x*x*x - 5*x + 1;
}

float findX(float x1 , float x2){
    return (x1*findValueAt(x2) - x2 * findValueAt(x1)) / (findValueAt(x2) - findValueAt(x1));
}

int main(){
    int maxItr,i=1;
    float x1,x2,x;
    printf("Enter x1 and x2\n");
    scanf("%f%f",&x1,&x2);
    printf("Enter the no of Iterations:");
    scanf("%d",&maxItr);

    x=findX(x1,x2);
    do
    {
        x1=x2;
        x2=x;
        printf("Iterations=%d  Root=%f\n" ,i,x);
        x = findX(x1,x2);
        if(fabs(x-x2)<EPSILON)
        {
            printf("Final Root=%f Total Iteration=%d",x,i+1);
            return 0;
        }
        i++;

    }while(i<=maxItr);
 
 
    printf("Final Root=%f",x);
    return 0;

    



}