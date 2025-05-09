package Math;

import java.util.Random;
public class math5 
{   public static void main(String args[])
    {   System.out.println("Roll dice:");
        Random r=new Random();
        for(int i=0;i<6;i++)
        { System.out.println("dice outcome:"
                +(r.nextInt(6)+1));
        }
    }
}
