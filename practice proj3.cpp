#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;
class bracket;



class bracket
{
   public:
//int number;
    string first;
    string last;
    int    year; //born Year

    bracket() {};
    bracket(string &myFirst, string &myLast, string &myYear)
    {
        first = myFirst;
        last = myLast;
        year = stoi(myYear);
    }
};


void split(string& s, vector<string>& vec, string delimiter)
{
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
    token = s.substr(0, pos);
    vec.push_back(token);
    s.erase(0, pos + delimiter.length());
    }
    vec.push_back(s);
}

void readCsvFile(vector<bracket>&vector2)
{
string path = "c:/temp/data.txt";
ifstream  myfile(path);
string line;
vector <string> vec1;
int count = 0;

while (getline(myfile, line))
{
    vec1.clear();
    split(line, vec1, ",");
    if (vec1.size() == 3)
    {
        bracket* pbracket = new bracket(vec1[0], vec1[1], vec1[2]);
        printf(" class Pointer =%x\n", pbracket);
        vector2.push_back( *pbracket);
    }
    count++;
    }
    myfile.close();
}

void printNames(vector<bracket> vec1)
{
    for (auto& i : vec1) {
      cout << i.first << endl;
    }
}

int main()
{
vector<bracket> vector1;
readCsvFile(vector1);
cout << "Size = " << vector1.size() << endl;
cout << "Object 0 " << vector1[1].first<<endl;
printNames(vector1);
return 0;
}