#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::fstream;
using std::string;

int main(int argc, char *argv[])
{
	fstream my_file(argv[1]);
	if(my_file.is_open())
	{
		string line;
		while(true)
		{
			std::getline (my_file, line);
			if (!my_file) break;
			cout << line << endl;
		}
		
	}
	else cout << "File didn't open\n";
	return 0;
}

