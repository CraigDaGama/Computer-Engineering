package Math;
import java.util.Scanner;
public class math2 
{   public static void main(String args[])
    {   char opt='y';
        double oper1,oper2;
        while(opt!='n')
        {   System.out.println("Maths operation:");
            System.out.println("enter 1 to compute x^y");
            System.out.println("enter 2 to find squareroot of a number");
            System.out.println("enter 3 to find log of number(base10)");
            System.out.println("enter 4 to find log of number(natural log)");
            System.out.println("enter 5 to find e^x");
            Scanner s=new Scanner(System.in);
            int ch;
            ch=s.nextInt();
            switch(ch)
            {   case 1:
                System.out.println("enter the base and index");
                oper1=s.nextDouble();
                oper2=s.nextDouble();
                System.out.println("ans="+Math.pow(oper1, oper2));
                break;
                case 2:
                System.out.println("enter the number");
                oper1=s.nextDouble();
                System.out.println("ans="+Math.sqrt(oper1));
                break;
                case 3:
                System.out.println("enter the number");
                oper1=s.nextDouble();
                System.out.println("ans="+Math.log10(oper1));
                break;
                case 4:
                System.out.println("enter the number");
                oper1=s.nextDouble();
                System.out.println("ans="+Math.log(oper1));
                break;
                case 5:
                System.out.println("enter the number");
                oper1=s.nextDouble();
                System.out.println("ans="+Math.exp(oper1));
                break;
            }
            System.out.println("enter y to continue or n to exit");
            opt=s.next().charAt(0);
        }
    }
}
