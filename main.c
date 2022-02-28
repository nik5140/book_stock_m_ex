// first example from book on algorithms (Real-World Algorithms)


#include <stdio.h>
#include <stdlib.h>

int main()
{
    // file pointer
    FILE *f;
    char name[] = "stock_data.txt";
    int i =0;
    float x;
    int n=0;

    // get number of random numbers from user
    printf("Enter number of random numbers\n");
    scanf("%d", &n);

    // dont use now
    float stocks[7] = {7.5, 10.2, 8.1, 5.8, 3.2, 8.1, 9.5};

    //use this array for reading data
    float stocks_read[n];

    //opening file
    if ((f = fopen(name,"w"))==NULL)
    {
        printf("Error file opening");
        system("PAUSE");
    }
    else
    {
        for(i = 0; i<n; i++)
        {
            if (i>=10&&i%10==0) fprintf(f,"\n");
            // random numbers generate
            x = rand()%38/3.5;
            fprintf(f, "%6.2f",x);
        }
    }

    //closing file...
    fclose(f);

    // open file to read data
    f = fopen(name,"r");

    if (f==NULL)
    {
        printf("Error file opening");
        system("PAUSE");
    }
    else
    {
           for(i = 0; i<n; i++)
        {
            //if (i>=10&&i%10==0) fprintf(f,"\n");
            fscanf(f, "%f", &stocks_read[i]);
        //This is very important: use %f, not %6.2f!
        }
    }

    for(i = 0; i<n; i++)
        {
            if (i>=10&&i%10==0) printf("\n");
            printf("%6.2f", stocks_read[i]);
        }


// part of algorithm ¹1 from book (slow)
    int spans[n];
    int k=0;
    int nn = sizeof(stocks_read)/sizeof(float);
    int span_end = 0;


    for (i = 0; i< n; i++)
    {
        k = 1;
        span_end = 0;
        while((i-k>=0)&&(!span_end))
        {
            if (stocks_read[i-k] <= stocks_read[i])
                k++;
            else
                span_end = 1;
        }
        spans[i] = k;

    }

//

    printf("Lets look on stock market!\n");
    for (i=0; i<n; i++)
    {
        printf("spans[%d] = %d\n", i, spans[i]);
    }

    return 0;
}

// to add - time measurement
// to add - quick algorithm with stack
