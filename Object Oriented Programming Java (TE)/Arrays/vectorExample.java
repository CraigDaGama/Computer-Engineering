package Arrays;
import java.util.*;
public class vectorExample {
    public static void main(String args[]) 
    {   Vector<Integer> v = new Vector<Integer>(3, 2);
        System.out.println("Initial size: " + v.size()); 
        System.out.println("Initial capacity: " 
                +v.capacity());
        v.addElement(1); 
        v.addElement(1); 
        v.addElement(3); 
        v.addElement(4);
        for(int k1:v)
        {    System.out.println(k1);}
System.out.println("Capacity after four additions: " 
        +v.capacity());
        v.addElement(5); 
        v.insertElementAt(6,3);
        for(int k1:v)
        {    System.out.println(k1);}
        System.out.println("Current capacity: " 
                +v.capacity());
        v.removeElement(1);
        System.out.println("First element: " + 
                v.firstElement());
        System.out.println("Last element: " + 
                v.lastElement());
        if(v.contains(3)) 
            System.out.println("Vector contains 3.");
        System.out.println("Using Iterators");
        Iterator<Integer> itr = v.iterator();
        while(itr.hasNext())
        {System.out.println(itr.next());}
    }
}
