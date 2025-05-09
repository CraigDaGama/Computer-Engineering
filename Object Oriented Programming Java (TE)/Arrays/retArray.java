package Arrays;

public class retArray {
    static int [][] multiplyMat(int m1[][],
    int m2[][],int c1,int c2)
{   int temp[][]=new int [m1.length][c2];
    int row1=m1.length,row2=m2.length,
            col1=c1,col2=c2;
    for (int i = 0; i < row1; i++) 
    {   for (int j = 0; j < col2; j++) 
        {   for (int k = 0; k < row2; k++)
                temp[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return temp;
}
public static void main(String args[])
{   int a[][]={{1,1,1},
                {1,1,1}
              };
    int b[][]={ {1,1},
                {1,1},
                {1,1}
              };
    System.out.println("matrix1:");
    for(int i=0;i<a.length;i++)
    {   for(int j=0;j<3;j++)
        {   System.out.print(a[i][j]+"\t");}
        System.out.println();
    }
     System.out.println("matrix2:");
    for(int i=0;i<b.length;i++)
    {   for(int j=0;j<2;j++)
        {   System.out.print(b[i][j]+"\t");}
        System.out.println();
    }
    int c[][];
    System.out.println();
    c=retArray.multiplyMat(a,b,3,2);
    System.out.println("matrix3:");
    for(int i=0;i<a.length;i++)
    {   for(int j=0;j<2;j++)
        {   System.out.print(c[i][j]+"\t");}
        System.out.println();
    }
}
}
