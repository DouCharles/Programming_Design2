#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;
double rounding (double i){
    double a ;
    if (i<0 && i>=-0.004){
        return 0;
    }
    i=i*100;
    a= round(i);
    return a/100;
}
int main()
{
    int t;
    int m, n;

    FILE *fp;
    fp = fopen("output.txt", "w");

    ifstream inFile("input.txt", ios::in);
    if (!inFile)
    {
        cerr << "error";
        exit(1);
    }
    if (!fp)
    {
        cerr << "failed opening" << endl;
        exit(1);
    }

    inFile >> t;
    fprintf(fp, "%d\n", t);
    for (int g = 0; g < t; g++)
    {
        inFile >> m >> n;
        double question[m][n];
        double q[m][n]; // ANS -> Q
        double r[n][n]; // ANS -> R
        double p[m][n];
        double sum = 0;
        double dot = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //read data
                inFile >> question[i][j];
                //initialize
                q[i][j] = 0;
                p[i][j] = 0;
            }
        }
        //initialize
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                r[i][j] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            //Rkk = Ak
            for (int i = 0; i < m; i++)
            {
                sum += question[i][k] * question[i][k];
            }
            sum = sqrt(sum);
            r[k][k] = sum;
            //Qk = Ak/Rkk
            for (int i = 0; i < m; i++)
            {
                q[i][k] = question[i][k] / r[k][k];
            }
            // for loop j =k+1....n set
            for (int j = k + 1; j < n; j++)
            {
                //Rkj = Qk *Aj
                for (int l = 0; l < m; l++)
                {
                    dot += q[l][k] * question[l][j];
                }
                r[k][j] = dot;
                dot = 0;

                //Aj=Aj-Rkj * Qk
                for (int l = 0; l < m; l++)
                {
                    question[l][j] = question[l][j] - r[k][j] * q[l][k];
                }
            }
            // check loop round!!!
            sum = 0;
        }
        fprintf(fp, "%d %d\n", m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //new
                q[i][j] = rounding(q[i][j]);
                //new
                fprintf(fp, "%.2lf ", q[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp,"%d %d\n",n,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //new
                r[i][j] = rounding(r[i][j]);
                //new
                fprintf(fp, "%.2lf ", r[i][j]);
            }
            fprintf(fp, "\n");
        }
    }
}