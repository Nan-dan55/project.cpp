#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<ctime>
#include<fstream>
using namespace std;
int main()
{
    ifstream tru("truths.txt");
    ifstream li("lie.txt");
    string txt;
    
    int tru_count = 0;
    int lie_count = 0;

    while(getline(tru,txt))
    {
        tru_count++;
    }
    while(getline(li,txt))
    {
        lie_count++;
    }

    srand(time(0));
    int t1=0,t2=0,l=0;
    t1=rand()%tru_count;
    t2=rand()%tru_count;
    l=rand()%lie_count;

    ifstream truths("truths.txt");
    ifstream lies("lie.txt");

    string truth1, truth2, lie;
    for(int i=0;i<=max(t1,t2);i++)
    {
        string txt;
        getline(truths,txt);
        if (i==t1)
        {
            truth1=txt;
        }
        else if(i==t2)
        {
            truth2=txt;
        }    
    }
    for(int i=0;i<=max(t1,l);i++)
    {
        getline(lies,txt);
    }

    int bullet=1;
    int liechecker;
    for(int i=0;i<=max(t1,t2);i++)
    {
        if (i==t1)
        {
            cout<<bullet<<". "<<truth1<<endl;
            bullet++;
        }
        else if(i==t2)
        {
            cout<<bullet<<". "<<truth2<<endl;
            bullet++;
        }
        else if(i==l)
        {
            cout<<bullet<<". "<<lie<<endl;
            liechecker=bullet;
            bullet++;
        }   
    }
    int number;
    cout<<"Enter the lie u think is";
    cin>>number;
    if(number==liechecker)
    {
        cout<<"woahhh thats RIGHT";
    }
    else
    {
        cout<<"U missed it, The lie is "<<lie<<endl;
        cout<<"BETTER LUCK NEXT TIME";
    }
    return 0;
}