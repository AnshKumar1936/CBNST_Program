#include<stdio.h>
float findValueAt(float x){
    return x*x*x - 2*x - 5;
}

float Bisect(float x1, float x2){
    return (x1+x2)/2;
}

int main(){
    int maxItr;
    int i=1;
    float x1,x2,x;
    printf("Enter the maximum iteration:");
    scanf("%d", &maxItr);


    do{
        printf("Enter the value of x1 and x2(start):");
        scanf("%f%f" , &x1,&x2);

        if(findValueAt(x1)*findValueAt(x2)>0)
        {
            printf("Roots are invalid\n");
            continue;
        }
        else
        {
            printf("Roots lie between %f and %f\n", x1 , x2);
            break;
        }

    }while (1);
    

    while (i<=maxItr)
    {
        x=Bisect( x1, x2);
        if(findValueAt(x)*findValueAt(x1)<0)  
           x2=x;
        else if(findValueAt(x)*findValueAt(x2)<0)
           x1=x;
        printf("Iteration = %d Roots= %f\n" , i,x);
        i++;
    }  
}
