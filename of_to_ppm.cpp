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
	else cout << format << endl;
	
	//take and outstream amount of colors
	getline(cin, line);
	std::stringstream amount(line);
	amount >> colors_amount;
	cout << colors_amount << endl;
	
	//outstrea the pallete
	getline(cin, line);
	char color;
	while(line[0] != '?')
	{
		cout << line << endl;
		getline(cin, line);
	}
	
	cout << line << endl;
	
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
	
	//outstream pixels in .of format from .of input
	while(getline(cin,line)) cout << line << endl;
	return 0;
}
