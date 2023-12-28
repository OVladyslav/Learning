#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
//#include <vector>

using std::cout;
using std::endl;
using std::fstream;
using std::getline;
using std::string;
using std::unordered_map;

char color_code_to_symbol(int color_code, unordered_map<int, char> &color_symbols)
{
	return color_symbols.find(color_code) == color_symbols.end() ? '?' : color_symbols[color_code];
}

int main(int argc, char *argv[])
{
	unordered_map<int, char> color_symbols
	{{0, 'b'},
	 {255, 'B'},
	 {255 * 256 * 256, 'R'},
	 {255 * 256, 'G'},
	 {255 * (1 + 256 + 256 * 256), 'W'}};
	fstream my_file(argv[1]);
	if(my_file.is_open())
	{
		string line;
		int width, height;
		
		getline(my_file, line);
		if (line != "P6")
		{
            		cout << "Error. Unrecognized file format." << endl;
            		return 1;
            	}
            	cout << line << endl;
		
		//comments starting with '#'
		getline(my_file, line);
	        while (line[0] == '#')
	        {
	        	cout << line << endl;
	        	getline(my_file, line);
	        }
	        
	        //width and height
	        std::stringstream dimensions(line);
	        cout << line << endl;
		dimensions >> width;
            	dimensions >> height;
	        
	        
	        //max color value
	        getline(my_file, line);
	        cout << line << endl;
		
		//rgb colors
		int size = width * height;
		char aux;
		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				char red, green, blue;
				my_file.read(&red, 1);
				my_file.read(&green, 1);
				my_file.read(&blue, 1);
				int color_code = (unsigned char)red * 256 * 256
					       + (unsigned char)green * 256
					       + (unsigned char)blue;
				char color_symbol = color_code_to_symbol(color_code, color_symbols);
				cout << color_symbol;
			}
			cout << endl;
		}
		
	}
	else cout << "File didn't open\n";
	return 0;
}

