package InterfacePrograms;

import java.util.*;
class student
{   String studname,branch;
    int sem;
    Scanner s;
    void initStudData()
    {   s=new Scanner(System.in);
        System.out.println("enter student name branch and sem");
        studname=s.next();
        branch=s.next();
        sem=s.nextInt();
    }
    void dispStudData()
    {   System.out.println("student name:\t"+studname);
        System.out.println("branch:"+branch);
        System.out.println("sem:"+sem);
    }
}
interface sports
{   void calSportsMarks();
}
class Marks extends student implements sports
{   double sportsmrks,mrks[];
    public void calSportsMarks()
    {   System.out.println("enter the sports marks");
        s=new Scanner(System.in);
        sportsmrks=s.nextDouble();
    }
    void calMarks()
    {   System.out.println("enter the number of subjects");
        s=new Scanner(System.in);
        int n=s.nextInt();
        System.out.println("enter the marks of "+n+" subjects");
        mrks=new double[n];
        for(int i=0;i<n;i++)
        {   mrks[i]=s.nextInt();}
    }
    void dispMarks()
    {   double per=0;
        for(int i=0;i<mrks.length;i++)
        {   System.out.println("Subject "+i+":"+mrks[i]);
            per+=mrks[i];
        }
        per=(per/(mrks.length*100))*100;
        System.out.println("Sports Marks:"+sportsmrks);
        System.out.println("percentage:"+per);
    }
}
public class StudentReport extends Marks
{   public static void main(String args[])
    {   StudentReport s1=new StudentReport();
        s1.initStudData();
        s1.calMarks();
        s1.calSportsMarks();
        s1.dispStudData();
        s1.dispMarks();
    }
}
