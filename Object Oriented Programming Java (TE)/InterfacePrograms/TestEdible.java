package InterfacePrograms;

interface Edible
{   String howToEat();}
abstract class Animal3
{   abstract String sound(); }
class Tiger extends Animal3
{  String sound()
    {return "roar";}
}
class Cow extends Animal3 implements Edible
{   public String howToEat() { return "cheese";}
    String sound()  {   return "moo moo";}
}
abstract class Fruit implements Edible  {}
class Orange extends Fruit
{   public String howToEat() {   return "orange squash";} }
class Apple extends Fruit
{   public String howToEat()  {   return "apple cider";}  }
public class TestEdible 
{   public static void main(String args[])
    {   Object obj[]={new Tiger(),new Apple(),new Cow()};
        for(Object temp:obj)
        {   if(temp instanceof Edible)
            {   System.out.println("class:"+temp.getClass());
        System.out.println("\t"+((Edible)temp).howToEat());
            }
            if(temp instanceof Animal3)
            {   System.out.println("class:"+temp.getClass());
            System.out.println("\t"+((Animal3)temp).sound());
            }  
        } 
    }
}
