package Math;
import java.util.Scanner;
public class math3 
{   public static void main(String args[])
    {   double radians1,degree1;
        Scanner s=new Scanner(System.in);
        System.out.println("enter value in degree");
        degree1=s.nextDouble();
        System.out.println("enter value in radians");
        radians1=s.nextDouble();
  System.out.println("toRadians("+degree1+")="
          +Math.toRadians(degree1));
 System.out.println("to("+radians1+")="+Math.toDegrees(radians1));
     System.out.println("sin("+radians1+")="+Math.sin(radians1));
     System.out.println("Math.acos(1)="+Math.acos(1));
    }
}