/*
1.Implement Euclid’s, Consecutive integer checking and Modified Euclid’s algorithms 
to find GCD of two nonnegative integers and perform comparative analysis by 
generating best case and worst case data.*/
#include <stdio.h>
#include <stdlib.h>
#define x 10
#define y 100

int modifiedeuclid(int m, int n)
{
    int r;
    int count = 0;
    while (n)
    {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    return count;//m is gcd
}

int consec(int m, int n)
{
    int min=m;
    int count = 0;
    if (n < min)
        min = n;
    while (1)
    {
        count++;
        if (m % min == 0)
        {
            count++;
            if (n % min == 0)
                break;
            min -= 1;
        }
        else
            min -= 1;
    }
    return count;//min is gcd
}

int euclid(int m, int n)
{
    int temp;
    int count = 0;
    while (n > 0)
    {
        count++;
        if (n > m)
        {
            temp = m;
            m = n;
            n = temp;
        }
        m = m - n;
    }
    return count; // m is the GCD
}

void analysis(int ch)
{
    int m, n, i, j, k,count, maxcount, mincount;
    FILE *fp1, *fp2;
    for (i = x; i <= y; i += 10)
    {
        maxcount = 0;
        mincount = 10000;
        for (j = 2; j <= i; j++) // To generate data
        {
            for (k = 2; k <= i; k++)
            {
                count = 0;
                m = j;
                n = k;

                switch (ch)
                {
                case 1: count = modifiedeuclid(m, n);
                        break;
                case 2: count = consec(m, n);
                        break;
                case 3: count = euclid(m, n);
                        break;
                }

                // To find maximum basic operations among all combinations between 2 to n
                if (count > maxcount)
                    maxcount = count;
                // To find minimum basic operations among all combinations between 2 to n
                if (count < mincount)
                    mincount = count;
            }
        }
        switch (ch)
        {
        case 1: fp1 = fopen("me_b.txt", "a");
                fp2 = fopen("me_w.txt", "a");
                break;
        case 2: fp1 = fopen("c_b.txt", "a");
                fp2 = fopen("c_w.txt", "a");
                break;
        case 3: fp1 = fopen("e_b.txt", "a");
                fp2 = fopen("e_w.txt", "a");
                break;
        }
        fprintf(fp1, "%d\t%d\n", i, mincount);
        fclose(fp1);
        fprintf(fp2, "%d\t%d\n", i, maxcount);
        fclose(fp2);
    }
}

void main()
{
    analysis(1);
    analysis(2);
    analysis(3);

    system("gnuplot>load 'gcd_plot.txt' ");
}