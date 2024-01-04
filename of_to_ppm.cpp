#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <string>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;

string format = "Our format";
int width, height, colors_amount;

struct color_values
{
	unsigned int r, g, b;
};

int main()
{
	string line;
	
	//outstream format or incorrect format and exit
	getline(cin, line);
	if(line != format)
	{
		cout << "Incorrect format\n";
		return 1;
	}
	else cout << "P6" << endl;
	
	//take amount of colors
	getline(cin, line);
	std::stringstream amount(line);
	amount >> colors_amount;
	
	//form the pallete
	unordered_map<char, color_values> pallete;
	getline(cin, line);
	char color;
	while(line[0] != '?')
	{
		std::stringstream colors(line);
		colors >> color;
		color_values cv;
		colors >> cv.r;
		colors >> cv.g;
		colors >> cv.b;
		pallete[color] = cv;
		getline(cin, line);
	}
	
	std::stringstream colors(line);
	colors >> color;
	color_values cv;
	colors >> cv.r;
	colors >> cv.g;
	colors >> cv.b;
	pallete[color] = cv;
	
	//outstream comment
	cout << "#Converted from .of format\n";
	
	//outstream dimensions
	getline(cin, line);
	std::stringstream dimensions(line);
	cout << line << endl;
	dimensions >> width;
	dimensions >> height;
	
	//outstream max color value
	cout << "255\n";
	
	//outstream pixels in .ppm format converted from .of format
	int size = width * height;
	char aux;
	for (int i = 0; i < height; i++)
	{
		getline(cin,line);
		for(int j = 0; j < width; j++)
		{
			cout << (char)pallete[line[j]].r;
			cout << (char)pallete[line[j]].g;
			cout << (char)pallete[line[j]].b;
		}
	}
	return 0;
}
