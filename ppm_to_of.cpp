#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::fstream;
using std::getline;
using std::string;
using std::unordered_map;
using std::cin;

char color_code_to_symbol(int color_code, unordered_map<int, char> &color_symbols)
{
	return color_symbols.find(color_code) == color_symbols.end() ? '?' : color_symbols[color_code];
}

unordered_map<int, char> color_symbols
	{{0, 'b'},
	 {255, 'B'},
	 {255 * 256 * 256, 'R'},
	 {255 * 256, 'G'},
	 {255 * (1 + 256 + 256 * 256), 'W'}};

int main(int argc, char *argv[])
{	
	string line;
	int width, height;
	std::getline(std::cin, line);
	if (line != "P6")
	{
		cout << "Error. Unrecognized file format." << endl;
            	return 1;
	}
        cout << line << endl;	
		
	//comments starting with '#'
	std::getline(std::cin, line);
	while (line[0] == '#')
	{
		cout << line << endl;
		std::getline(std::cin, line);
	}
	        
	//width and height
	std::stringstream dimensions(line);
	cout << line << endl;
	dimensions >> width;
	dimensions >> height;
	                
	//max color value
        std::getline(std::cin, line);
        cout << line << endl;
		
	//rgb colors
	int size = width * height;
	char red, green, blue;
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			cin.read(&red, 1);
			cin.read(&green, 1);
			cin.read(&blue, 1);
			int color_code = (unsigned char)red * 256 * 256
				       + (unsigned char)green * 256
				       + (unsigned char)blue;
			char color_symbol = color_code_to_symbol(color_code, color_symbols);
			cout << color_symbol;
		}
		cout << endl;
	}
	return 0;
}

