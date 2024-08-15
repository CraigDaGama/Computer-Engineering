#include<iostream>
#include<string>
using namespace std;

int Patternmatching(string text, string pattern, int n, int m)
{   int flag = 0;
    for (int i=0; i< n-m ;i++)
    {
        int j=0;
        while(j<m && pattern[j]==text[i+j])
            j++;
        if (j==m){
         cout<<"pattern found at "<<i+1<<endl;
         flag++;
        }


    }
    if(flag == 0)
        cout<<"pattern not found"<<endl;
}
int main()
{
    int n,m,p;
    string text,pattern;
    cout<<"Enter some text"<<endl;
    getline(cin,text);
    cout<<"Enter pattern to be found"<<endl;
    getline(cin,pattern);

    n=text.size();
    m=pattern.size();
    p=Patternmatching(text, pattern, n, m);

    return 0;
}
