#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class readCSV{
	public:
    vector<vector<string>> content;
	vector<vector<float>> data;
	vector<string> row;
	string line, word;
	float fdata;
	vector<float> rw;
	readCSV(){
		string fname;
		cout<<"Enter the file name: ";
		cin>>fname;
		fstream file (fname, ios::in);
		if(file.is_open()){
			while(getline(file, line)){
				row.clear();
				stringstream str(line);
				while(getline(str, word, ',')){
					row.push_back(word);
				}
				content.push_back(row);
			}
		}
		else{
			cout<<"Could not open the file\n";
		}
		cout<<content[0].size()<<" "<<content.size()<<endl; 
		for(int i=1;i<content.size();i++){
			rw.clear();
			for(int j=1;j<content[i].size();j++){
				fdata = stoi(content[i][j]);
				rw.push_back(fdata);
			}
			data.push_back(rw);
		}
		for(int i=0;i<content.size()-1;i++){
			for(int j=0;j<content[i].size()-1;j++){
				cout<<data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
class calc:protected readCSV{
	protected:
	float *mn,*sum,*var,*stdDev;
	public:
	calc(){
		mn = new float[content[0].size()-1];
		sum = new float[content[0].size()-1];
		var = new float[content[0].size()-1];
		stdDev = new float[content[0].size()-1];
	}
	void mean(){
		for(int i=0;i<content[0].size()-1;i++){
			sum[i]=0;
		}
		for(int i=0;i<content[i].size()-1;i++){
			for(int j=0;j<content.size()-1;j++){
				sum[i] = sum[i] + data[j][i];
			}
			mn[i]=sum[i]/(content.size()-1);
		}
		cout<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<" ";
		for(int i=0;i<content[0].size()-1;i++){
			cout<<"Mean for "<<i+1<<" sample: "<<mn[i]<<endl;
			sum[i]=0;
		}
	}
	void variance(){
		for(int i=0;i<content[i].size()-1;i++){
			for(int j=0;j<content.size()-1;j++){
				sum[i] = sum[i] + ((data[j][i]-mn[i])*(data[j][i]-mn[i]));
			}
			var[i]=sum[i]/(content.size()-2);
		}
		for(int i=0;i<content[0].size()-1;i++){
			cout<<"Variance for "<<i+1<<" sample: "<<var[i]<<endl;
		}
	}
	void StandardDeviation(){
		for(int i=0;i<content[0].size()-1;i++){
			stdDev[i] = sqrt(var[i]);
		}
		for(int i=0;i<content[0].size()-1;i++){
			cout<<"Standard Deviation for "<<i+1<<" sample: "<<stdDev[i]<<endl;
		}
	}
};
int main(){
	calc cl;
	cl.mean();
	cl.variance();
	cl.StandardDeviation();
}