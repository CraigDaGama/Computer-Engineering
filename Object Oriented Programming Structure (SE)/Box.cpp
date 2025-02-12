/*Create a class called Box with data member length,breadth and height. Use setter and getter functions
and display the volume and surface area of different box objects.*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class Box{
	float length, breadth, height;
	public:
		void setDimensions(float l, float b, float h){
			length = l;
			breadth = b;
			height = h;
		}
		void calcSurfaceArea(){
		float s;
		s=2*((length*breadth)+(length*height)+(breadth*height));
		cout<<"The surface area of box is: "<<s<<endl;
		}
		void calcVolume(){
		float v;
		v= (length*breadth*height);
		cout<<"The volume of box is: "<<v<<endl;
		}
		void getResult(){
		calcSurfaceArea();
		calcVolume();
		}
};

int main(){
	Box b;
	int c;
	int a, r, d;
	while(1){
		cout<<"\t\tWelcome to Box Calculator\t\t\n";
		cout<<"Enter length, breadth and height respectively: ";
		cin>>a>>r>>d;
		b.setDimensions(a, r, d);
		b.getResult();
		cout<<"do you wish to continue?(1/0)"<<endl;
		cin>>c;
		if(c==1){
			continue;
		}
		else{
			exit(1);
		}
	}
	return 0;
}
