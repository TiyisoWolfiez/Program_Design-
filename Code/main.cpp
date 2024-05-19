#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string ** building_Data = NULL;
int * visiting_Order = NULL;
int * column_Sizes = NULL;
int stringToInt(string tiyiso_hlungwan);
void deleteFunction(int);
int stringToInt(string tiyiso_hlungwan){
	stringstream s1(tiyiso_hlungwan);
	int temp = 0;
	s1 >> temp;
	return temp;
}
void deleteFunction(int number_of_rows){
    int k_iterator = 0;
    while(k_iterator<number_of_rows){
		if(building_Data[k_iterator]!=NULL){
			delete [] building_Data[k_iterator];
			building_Data[k_iterator] = NULL;
		}
        k_iterator++;
	}
	delete [] building_Data;
	building_Data = NULL;
	delete [] visiting_Order;
	visiting_Order = NULL;
	delete [] column_Sizes;
	column_Sizes = NULL;
}
int main(int argc, char *argv[], char *envp[]){
	fstream first_Input_File("building.data"), second_Input_File("building.data");
	int number_of_rows=0;
	string file_data("");
	while(getline(second_Input_File,file_data))number_of_rows++;
	number_of_rows = (number_of_rows-1)/2;
	second_Input_File.close();
	string tiyiso_hlungwan("");
    string lineOne("");
    string numOflines("");
	int number_of_floors_to_be_printed = 0;
	building_Data = new string*[number_of_rows];
	column_Sizes = new int[number_of_rows];
	visiting_Order = new int[number_of_rows];
    int l_iterator = 0;
	while(l_iterator<number_of_rows)
    building_Data[l_iterator++]=NULL;
	if(first_Input_File.is_open()){
		first_Input_File>>lineOne;
		stringstream temp_stream_var(lineOne);
		string temp_offices("");
        int row_number = 0;
		while(getline(temp_stream_var,temp_offices,',')) visiting_Order[row_number++] = stringToInt(temp_offices);
        number_of_floors_to_be_printed = row_number;
		int count = 0;
		getline(first_Input_File,tiyiso_hlungwan);
		while(!first_Input_File.eof()){
		    getline(first_Input_File,tiyiso_hlungwan);
			int floor_Number = 0;
			int number_Of_Offices=0;
			stringstream temp_stream_var(tiyiso_hlungwan);
			getline(temp_stream_var,tiyiso_hlungwan,':');
			temp_stream_var>>tiyiso_hlungwan;
			floor_Number = stringToInt(tiyiso_hlungwan);
			getline(first_Input_File,tiyiso_hlungwan);
			stringstream temp_stream_vard(tiyiso_hlungwan);
			stringstream offices_stream_variable (tiyiso_hlungwan);
			while(getline(temp_stream_vard,tiyiso_hlungwan,','))
            number_Of_Offices++;
			building_Data[floor_Number] = new string[number_Of_Offices];
			number_Of_Offices = 0;
			while(getline(offices_stream_variable,tiyiso_hlungwan,','))
            building_Data[floor_Number][number_Of_Offices++]=tiyiso_hlungwan;
			column_Sizes[floor_Number]=number_Of_Offices;
			count+=1;
		}
		first_Input_File.close();
	}
    int g_iterator = 0;
	while(g_iterator<number_of_floors_to_be_printed){
        int p_iterator=column_Sizes[visiting_Order[g_iterator]]-1;
		while(p_iterator>=0){
			cout<<building_Data[visiting_Order[g_iterator]][p_iterator];
			if(p_iterator>0) cout<<",";
            p_iterator-=1;
		}
		cout<<endl;
        g_iterator++;
	}
    int k_iterator = 0;
    while(k_iterator<number_of_rows){
		if(building_Data[k_iterator]!=NULL){
			delete [] building_Data[k_iterator];
			building_Data[k_iterator] = NULL;
		}
        k_iterator++;
	}
	delete [] building_Data;
	building_Data = NULL;
	delete [] visiting_Order;
	visiting_Order = NULL;
	delete [] column_Sizes;
	column_Sizes = NULL;
	return 0;
}
// main:
// 	g++ *.cpp -std=c++98 -pedantic -o main
// run:
// 	valgrind --leak-check=full ./main
// clean:
// 	rm -f *.o *.tar main
// tar:
// 	tar -cvz makefile *.cpp *.data -f u21598127.tar
// zip:
// 	tar -cvz makefile *.cpp *.data -f u21598127.zip
// tar_gz:
// 	tar -cvz makefile *.cpp *.data -f u21598127.tar.gz
// untar:
// 	tar -zxvf *.tar
// unzip:
// 	tar -zxvf *.zip
// untargz:
// 	tar -zxvf *.tar.gz
