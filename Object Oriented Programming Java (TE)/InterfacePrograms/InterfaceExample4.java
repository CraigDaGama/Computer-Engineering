package InterfacePrograms;

interface Animal
{ void dispAnimal(String a);}
interface Herbivore extends Animal
{ void  dispHerbivore();}
interface Carnivore extends Animal
{ void dispCarnivore();}
public class InterfaceExample4 implements 
        Herbivore,Carnivore
{   public void dispAnimal(String a) 
    {   System.out.println("Animal:"+a);}
    public void dispHerbivore() 
    {   System.out.println("feeds "
            + "on vegetation");}
    public void dispCarnivore() 
    {   System.out.println("feeds "
            + "on other animals");}
    public static void main(String args[])
    {   InterfaceExample4 i1=new 
        InterfaceExample4();
        InterfaceExample4 i2=new 
        InterfaceExample4();
        i1.dispAnimal("Giraffe");
        i1.dispHerbivore();
        i2.dispAnimal("Lion");
        i2.dispCarnivore();      
    }
}