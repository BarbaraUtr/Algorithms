#include <bits/stdc++.h>

using namespace std;



int main ()
{
    long long int f1=1, f2=1;

    int t[30];


    for(int i=0; i<6;i++)
    {
        t[2*i]=f1;
        t[2*i+1]=f2;

        cout << f1 << endl;
        cout << f2 << endl;

        f1+=f2;
        f2+=f1;
    }

    int a =200;//t[12]+1;

    int *p = new int[a];

    for(int i=0; i<a; i++)
    {
        p[i]=i;
    }

    for(int i=2; i<a; i++)
    {
        if (p[i]!= -1)
        {
            int b = p[i]+1;
            for (int k=b; k<a; k++)
            {
                if(p[k]%p[i]==0)
                {
                    p[k]=-1;
                }
            }
        }
    }
    int l=0;
    for(int i=0; i<200; i++)
    {
        if(p[i]!= -1)
        {
            ++l;
        }
        //cout << p[i] << endl;
    }
    cout << l << endl;



}
