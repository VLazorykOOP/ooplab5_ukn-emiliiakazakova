#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

class Point 
{
protected:
	int x;
	double y;
public:
	Point(int valuex, double valuey) :x(valuex), y(valuey) { };
	Point() :x(0), y(0) {};
	Point(int valuex) : x(valuex), y(0) {};
	Point(double valuey) :x(0), y(valuey) {};
	~Point()
	{
		cout << "Dest is called" << endl;
	}
	void SetCord(int valuex,double valuey)
	{
		x = valuex;
		y = valuey;
	}
	void GetCord()
	{
		cout << "Point Coordinates " << "[" << x << ", " << y << "]" << endl;
	}
};

class cPoint : public Point
{
private:
	string color;
public:
	cPoint() : color("red"), Point() {};
	cPoint(int valuex, double valuey) :color("red"),Point(valuex,valuey) {};
	cPoint(double valuey, string color) :color(color), Point(valuey) {};
	cPoint(string color) :color(color), Point() {};
	cPoint(int valuex, string color) :color(color),Point(valuex) {};
	cPoint(double valuey) :color("red"), Point(valuey) {};
	cPoint(int valuex) :color("red"), Point(valuex) {};
	cPoint(int valuex, double valuey, string color) :color(color), Point(valuex, valuey) {};

	void Printc()
	{
		cout << "------------------------------" << endl<< "Point color : "<< color<<endl;
		Point::GetCord();
	}
	void SetColor(string ccolor)
	{
		color = ccolor;
	}
	~cPoint()
	{
		cout << "cDest is called" << endl;
	}
};
////
///
//
//
class Proc
{
protected:
	double Mgc;
	int price;
	string marca;
public:
	Proc()
	{
		Mgc = 0;
		price = 0;
		marca = "";
		cout << "Empty computer create" << endl;
	}
	Proc(double mgc, int p, string m) : Mgc(mgc), price(p),marca(m)
	{ 
		cout << "Constructor Proc(double mgc, int p, string* m)" << endl;
	}
	Proc(double mgc, int p) : Mgc(mgc), price(p)
	{
		marca = "";
		cout << "Constructor Proc(double mgc, int p)" << endl;
	}
	~Proc()
	{
		cout << "Destructor Person\n";
	}
	string Print()
	{
		string m, p,pr;
		m = to_string(Mgc);
		p = to_string(price);
		if (marca == "") pr = " No set marca Mgc: " + m + " price: " + p + " ";
		else pr = " Marca " + marca + " Mgc: " + m + " price : " + p + " ";
		return pr;
	}
	void Input()
	{
		cout << "Input marca: "; cin >> marca;
		cout << "Input Mgc ";  
		while (!(cin >> Mgc) || Mgc < 0) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << "bad  input Mgc is 0 and > \n";
		};
		cout << "Input Price 100>";  
		while (!(cin >> price) || price < 100) {
			cin.clear();
			cin.ignore(MAXSHORT, '\n');
			fflush(stdin);
			cout << "bad  input Proce is 100 and > \n";
		};
	}
};

class Comp : public Proc
{
private: 
	class Monitor
	{
	protected:
		int l; long w;
	public:
		Monitor() : l(10), w(10) {};
		Monitor(int la) : l(la), w(10) {};
		Monitor(long we) : l(10), w(we) {};
		Monitor(int la, long we) :l(la), w(we) {};

		~Monitor()
		{
			"Destructor Monitor\n";
		}

		string Print()
		{
			string la, we, pre;
			la = to_string(l);
			we = to_string(w);
			pre = "Monitor sizes  l:" + la + " we:" + we;
			return pre;
		}
		void Input()
		{
			cout << "Input l ";
			while (!(cin >> l) || l < 0) {
				cin.clear();
				cin.ignore(MAXSHORT, '\n');
				fflush(stdin);
				cout << "bad  input l  \n";
			};
			cout << "Input w ";
			while (!(cin >> w) || w < 0) {
				cin.clear();
				cin.ignore(MAXSHORT, '\n');
				fflush(stdin);
				cout << "bad  input w  \n";
			};
		}
	} mon;
public:
	Comp() {	
		cout << " Default Comp\n";
	}
	Comp(double mgc, int p, string m, int la, long we) :Proc(mgc, p, m), mon(la,we)
	{
		cout << "Adult(int a, int w, PIB & pib, long long i, int kC, string *nameC ) \n";
	}
	~Comp()
	{
		"Destructor Computer\n";
	}
	string Print()
	{
		string co = "My Comuter: " + Proc::Print() + mon.Print();
		return co;
	}
	void Input()
	{
		Proc::Input();
		mon.Input();
	}
};


int main()
{
	cout << "Exercise 1.10" << endl;
	cPoint obj;
	obj.Printc();
	cout << "------------------------------" << endl;
	int in_x; double in_y; string in_color;
	cout << "Input Coordinates, color "; cin >> in_x >> in_y >> in_color;
	cPoint obj1(in_x), obj7(in_y), obj2(in_x, in_y), obj3(in_y), obj4(in_color), obj5(in_x, in_color), obj6(in_y, in_color);
	obj1.Printc();
	obj7.Printc();
	obj2.Printc();
	obj3.Printc();
	obj4.Printc();
	obj5.Printc();
	obj6.Printc();
	obj.SetColor("blue");
	obj.Printc();
	obj.SetCord(14, 7);
	obj.Printc();
	cout << "------------------------------" << endl;
	obj2.GetCord();
	cout << "Exercise 2.10" << endl;
	Comp comp1;
	cout << comp1.Print() << "  \n";
	comp1.Input();
	cout <<comp1.Print() << "  \n";
	Comp comp2(321,321,"gdsdf",21,21);
	cout << comp2.Print() << "  \n";
	return 0;
}
