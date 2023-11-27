#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,i,j,k;
    cout.precision(4);        //set precision
    cout.setf(ios::fixed);

    n = 3; // the number of equations

    float a[n][n+1] = {{25, 5, 1, 106.8},{64, 8, 1, 177.2},{144, 12, 1, 279.2}};
    float x[n];        //to store the elements of the augmented-matrix

    for (i=0;i<n;i++)
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    for (i=0;i<n-1;i++)            //loop to perform the gauss elimination
        for (k=i+1;k<n;k++)
            {
                double t=a[k][i]/a[i][i];
                for (j=0;j<=n;j++)
                    a[k][j]=a[k][j]-t*a[i][j];
            }


    for (i=n-1;i>=0;i--)                //back-substitution
    {
        x[i]=a[i][n];
        for (j=i+1;j<n;j++)
            if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
    }

    cout<<"\nThe values of the variables a1, a2 and a3 are as follows:\n";
    for (i=0;i<n;i++)
        cout <<"a"<<i+1<< " " << "=" << " " << x[i] << endl;

    //for finding the velocity at t=6 seconds
    float v_6 = x[0]*6*6+x[1]*6+x[2];
    cout<<endl << "The velocity at t=6 seconds: " << endl;
    cout<< v_6 << " " << "m/s" << endl;
    return 0;
}
