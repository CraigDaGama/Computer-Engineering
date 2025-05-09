package Math;
public class math4 
{   public static void main(String args[])
    {   System.out.println("Roll dice:");
      for(int i=0;i<6;i++)
      {   double dice=
                Math.random()*(6-1)+1;
  //Math.random()*(max-min)+min----[min,max]
        System.out.println("dice outcome:"
                    +Math.round(dice));
      }
    }
}
