 #include<iostream>
 using namespace std;

class Date
   {
     int day,month,year;
     public:
      void setDay(int d);
      void setMonth(int m);
      void setYear(int y);
      int getDay();
      int getMonth();
      int getYear();
     int dispDate();
   };

 void Date :: setDay(int d){day=d;}
 void Date :: setMonth(int m){month=m;}
 void Date :: setYear(int y){year=y;}

 int Date :: getDay()
   {return day;}

 int Date :: getMonth()
   {return month;}

 int Date :: getYear()
   {return year;}

 int Date :: dispDate()
   {
     cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<endl;
   }

 int main()
  {
     Date d1,d2;
     d1.setDay(17);
     d1.setMonth(8);
     d1.setYear(2023);
      d1.dispDate();

     d2.setDay(23);
     d2.setMonth(9);
     d2.setYear(2000);
       d2.dispDate();

       return (0);
