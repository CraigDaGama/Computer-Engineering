package Strings;
import java.util.StringTokenizer;
public class prog5 {
    public static void main(String args[])
    {   String message="Java is an OOP language";
        StringTokenizer str=new StringTokenizer(message," ");
        while(str.hasMoreTokens())
        {System.out.println(str.nextToken());}
    }
}
