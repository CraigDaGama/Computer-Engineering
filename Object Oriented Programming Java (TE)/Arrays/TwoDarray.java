package Arrays;

import java.util.Scanner;

public class TwoDarray {
    public static void main(String args[])
    {   int m,n;
        Scanner s=new Scanner(System.in);
        System.out.println("enter the no of rows and columns");
        m=s.nextInt();
        n=s.nextInt();
        int a[][]=new int[m][n];
        System.out.println("enter "+ (m*n)+" nos");
        for(int i=0;i<m;i++)
        {   System.out.print("row"+i+":\t");
            for(int j=0;j<n;j++)
            {   a[i][j]=s.nextInt();    }
            System.out.println();
        }
        for(int i=0;i<m;i++)
        {   for(int j=0;j<n;j++)
            {   System.out.print(a[i][j]+"\t"); }
            System.out.println();
        }
        int b[][]={ {2,3,5},
                    { 4,6,9}
                  };
        System.out.println("second array");
        for(int i=0;i<b.length;i++)
        {   for(int j=0;j<3;j++)
            {   System.out.print(b[i][j]+"\t"); }
            System.out.println();
        }
        int c[][]=new int[3][];
        c[0]=new int[2];
        c[1]=new int[3];
        c[2]=new int[4];
        int  k=2;
        for(int i=0;i<c.length;i++)
        {   System.out.println("row "+i+":(enter "+k+" nos)");
            for(int j=0;j<k;j++)
            { c[i][j]=s.nextInt();}
            k++;
        }
        k=2;
        System.out.println("Third array:");
        for(int i=0;i<c.length;i++)
        {   for(int j=0;j<k;j++)
            { System.out.print(c[i][j]+"\t");}
            k++;
            System.out.println();
        }
    }
}
