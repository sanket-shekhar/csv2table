#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

/*
This program reads csv file and and exports data in a tabular form.
There could be some errors while running on different platforms although I tried to minimise
them with correct syntax usage. I am including a sample input csv file named "filename.csv"
with which I tested  the code and the output goes to a file named "table.txt"
*/

vector<vector<string> > csv2table(string filename){
	vector<vector<string> > data;
	ifstream file("filename.csv");
	int l;
	while(file)
	{
		l++;
		string str;
		if (!getline(file, str)) break;
		stringstream ss(str);
		vector<string> record;
		while(ss){
			string line;
			if(!getline(ss,line,',')) break;
			//record.push_back(line);
			try{																		
				record.push_back(line);
			}
			catch (const char* msg) {
                cerr << msg<< " line " << l<<endl;
               // e.what();
            }
		}
		data.push_back(record);
	}
	return data;
}

int main()
{
	vector<vector<string> > data= csv2table("filename.csv");
	ofstream outfile;
	vector< vector<string> >::iterator row;
	vector<string>::iterator col;
	outfile.open("table.txt",ios::app);
	for (row = data.begin(); row != data.end(); row++) {
    	for (col = row->begin(); col != row->end(); col++) {
        cout<<*col<<"  ";
        outfile<<*col<<"  ";
    	}
    	cout<<endl;
    	outfile<<endl;
	}
	outfile.close();
}
