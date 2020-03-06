#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByValDesc(const pair<string, int> &a, const pair<string, int> &b)
{
	return a.second > b.second;
}

int main()
{
	ifstream in_file;
	ofstream out_file;

	multimap<string, string> m;
	string key, value;
	in_file.open("list.txt");
	while (!in_file.eof())
	{
		in_file >> value >> key;
		m.insert(pair<string,string>(key,value));	
	}
	in_file.close();

	out_file.open("output.txt");
	out_file << "List sorted by colour\n";
	auto itr = m.begin();
	for (; itr != m.end(); itr++)
		out_file << itr->first << " " << itr->second << endl;
	
	out_file << "\nNumber of people for each colour sorted by key(colour)\n";
	map<string, int> each_colour_amount;
	for (itr = m.begin(); itr != m.end(); itr++)
		each_colour_amount[itr->first]++;

	auto itr2 = each_colour_amount.begin();
	for (; itr2 != each_colour_amount.end(); itr2++)
	{
		out_file << itr2->first << ": " << itr2->second;
		if (itr2->second != 1)
			out_file << " people\n";
		else
			out_file << " person\n";
	}

	out_file << "\nNumber of people for each colour sorted by value(#people)\n";
	vector<pair<string, int>> v;
	for (itr2 = each_colour_amount.begin(); itr2 != each_colour_amount.end(); itr2++)
		v.push_back(make_pair(itr2->first, itr2->second));

	sort(v.begin(), v.end(), sortByValDesc);
	for (int i = 0; i < v.size(); i++)
	{
		out_file << v[i].first << ": " << v[i].second;
		if (v[i].second != 1)
			out_file << " people\n";
		else
			out_file << " person\n";
	}

	out_file << "\nTotal number of people: " << m.size() << endl;
	out_file << "Total number of colours: " << each_colour_amount.size() << endl;
	
	out_file.close();

	return 0;
}