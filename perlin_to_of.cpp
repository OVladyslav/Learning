#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

string format = "Our format";
int width, height;

unordered_map<int, string> color
{
	{0, "o 0 0 120"},
	{1, "s 0 20 200"},
	{2, "l 0 30 255"},
	{3, "S 255 255 100"},
	{4, "G 60 255 0"},
	{5, "F 0 150 0"},
	{6, "J 0 255 100"},
	{7, "M 100 60 0"},
	{8, "I 255 255 255"},
	{9, "I 255 255 255"}
};

int main()
{
	string line;
	
	//outstream format
	cout << format << endl;
	
	//take width and height
	getline(cin, line);
	std::stringstream dimensions(line);
	dimensions >> width;
	dimensions >> height;
	
	//build string that represents the image  
	unordered_set<int> pallete;
	string image;
	std::vector<std::vector<float>> v;
	float mx = 0.0f, mn = 1.0f;
	float gen_color;
	for (int i = 0; i < height; ++i)
	{
		std::vector<float> line;
		for (int j = 0; j < width; ++j)
		{
			cin >> gen_color;
			line.push_back(gen_color);
			mx = std::max(mx, gen_color);
			mn = std::min(mn, gen_color);
		}
		v.push_back(line);
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			pallete.insert((int)(((v[i][j] - mn) / (mx - mn)) * (color.size() - 1)));
			image += color[(int)(((v[i][j] - mn) / (mx - mn)) * (color.size() - 1))][0];
		}
		image += "\n";
	}
	
	//outstream size of palette and the necessary pallete
	cout << pallete.size() << endl;
	for(auto c : pallete)
	{
		cout << color[c] << endl;
	}
	cout << "? 255 0 255\n";
	
	//outstream dimensions
	cout << width << " " << height << endl;
	
	//outstream pixels in .of format
	cout << image << endl;
	return 0;
}
