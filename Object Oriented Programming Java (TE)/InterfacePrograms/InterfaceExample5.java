package InterfacePrograms;

interface Vehicle
{   default void dispVehicle()
    {   System.out.println
        ("Vehicle interface");}
    static void showVehicle()
    {   System.out.println
        ("vehicle types:car,bike,truck");
    }
}
class Car implements Vehicle
{   public void dispVehicle()
    {  Vehicle.super.dispVehicle();
        System.out.println("car properties");
    }
    public void showVehicle()
    {   Vehicle.showVehicle();
        System.out.println("car :sedan,hatchback");
    }
}
public class InterfaceExample5 
{   public static void main(String args[])
    {   Car c1=new Car();
        c1.dispVehicle();
        c1.showVehicle();
        
    }
}