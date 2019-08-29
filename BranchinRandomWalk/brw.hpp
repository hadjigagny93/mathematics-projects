#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <random>

class Point {
	private:
		int _x;
		int _y;
	public:
		Point():_x(),_y(){};
		Point(int x0, int y0){ _x = x0; _y = y0;};
		int x() const{ return _x;}
		int y() const{ return _y;}
		
	
		

};



class BRW{
	private:
		int _x;
		int _y;
		std::vector<Point> ensemble;//Qui va stocker les enfants 
		
	public:
		BRW(): ensemble(), _x(),_y(){}
		BRW(int x,int y): ensemble(), _x(x), _y(y){}
		BRW(Point p): ensemble(), _x(p.x()), _y(p.y()){}
		int x() const{ return _x;}
		int y() const{ return _y;}
		std::vector<Point> const ens(){ return ensemble;}
		unsigned int const size(){ ensemble.size();};
		void ajoute_enfant();
		void generation(int N, std::ostream & file);
		void condition();
		void condition2();
	
};
