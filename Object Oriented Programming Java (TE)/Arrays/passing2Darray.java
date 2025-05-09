package Arrays;

public class passing2Darray {
    static void computeTranpose(int a[][],int m)
    {   int temp[][]=new int[m][a.length];
        for(int i=0;i<m;i++)
        {   for(int j=0;j<a.length;j++)
            {   temp[i][j]=a[j][i];            }
            System.out.println();
        }
        for(int i=0;i<m;i++)
        {   for(int j=0;j<a.length;j++)
            {   System.out.print(temp[i][j]+"\t");}
            System.out.println();
        }
    }
    public static void main(String args[])
    {   int a[][]={ {2,3},
                    {2,5},
                    {2,8}
                  };
        for(int i=0;i<a.length;i++)
        {   for(int j=0;j<2;j++)
            {   System.out.print(a[i][j]+"\t");}
            System.out.println();
        }
        computeTranpose(a,2);
    }
}
