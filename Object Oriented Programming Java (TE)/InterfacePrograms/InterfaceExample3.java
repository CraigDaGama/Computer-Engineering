package InterfacePrograms;

interface Shape
{   void area();}
abstract class quad implements Shape
{   double dim1,dim2;}
class Rectangle extends quad
{   public void area()
    { System.out.println("area of rectangle:"+(dim1*dim2));}
}
class Square extends quad
{   public void area()
    { System.out.println("area of square:"+(dim1*dim1));}
}
public class InterfaceExample3 
{   public static void main(String args[])
    {   Rectangle r=new Rectangle();
        r.dim1=3;r.dim2=3;
        r.area();
        Square s=new Square();
        s.dim1=2;s.dim2=2;
        s.area();
    }}
