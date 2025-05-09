package ExceptionHandling;
import java.util.Scanner;
public class NumberFormatExceptionExample 
{   public static void main(String args[])
    {   String s1; int n1;
        try
        {   System.out.println("enter "
                + "a number");
            Scanner s=new Scanner(System.in);
            s1=s.next();
            n1=Integer.parseInt(s1);
        }
        catch(NumberFormatException e)
        {   System.out.println("invalid "
                + "integer string");}
    }
}
