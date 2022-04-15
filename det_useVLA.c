void subMatrix(int n, double m[n][n], int I, int J,double M[n-1][n-1])
{
    int i, a = 0, b = 0;
    int j;
    for (i = 0; i < n; i++)
    {
        if (i == I)
        {
            continue;
        }

        b = 0;//in-order to start fresh for new row
        for (j = 0; j < n; j++)
        {
            if (J == j)
            {
                continue;
            }
            M[a][b] = m[i][j];
            b++;
        }
        a++;
    }
}

//this recursive function calculates the determinant 
double  determinant(int n, double M[n][n])
{
    double det = 0;
    //the functions continues to call its self until n=2
    if(n==1)
    {
        return M[0][0];
    }
    if (n == 2)
    {
        det = M[0][0] *M[1][1]-M[0][1]*M[1][0];
    }
    else
    {
        double subArray[n-1][n-1];
        for (int i = 0; i < n; i++)
        {
            //subMatrix is filling the subArray
            subMatrix(n,M,0,i,subArray);
            det += M[0][i] * ((i&1)?-1:1)*determinant(n - 1,subArray);
        }
    }
    return det;
}

int main()
{
    int n, k = 0;

    printf("how many rows does the matrix have"); 
    scanf("%d", &n);

    double Matrix[n][n];
    printf("enter the numbers in order with an enter after each one");

   //Taking user input for 2D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &Matrix[i][j]);
        }
    }

    printf("%f",determinant(n,Matrix));
    return 0;
}