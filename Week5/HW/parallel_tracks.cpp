	#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include <sstream>
#include <fstream>
#include <limits>
#include <cctype>


using std::string;
using namespace std;



bool is_double(const std::string& s)
{
	long double ld;
	return((std::istringstream(s) >> ld >> std::ws).eof());
}




bool is_number(const std::string& s)
{
	if (s.size() == 1 || s.size() == 2) {
		long int ld;
		return((std::istringstream(s) >> ld >> std::ws).eof());
	}
	else {
		return false;
	}
}



bool namevalidation(string str)
{
	if (!str.empty()) {
		long long unsigned l;
		for (l = 0; l < str.size(); ++l) {
			if (isalpha(str[l])) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}








bool countryvalidation(string str)
{
	if (!str.empty() && str.size() == 3) {
		int l;
		for (l = 0; l < 3; ++l) {
			if (!isupper(str[l])) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}







//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given 
//---------------------------------------------------------
void get_runner_data(const std::string& file, double timeArray[], std::string countryArray[],
	unsigned int numberArray[], std::string lastnameArray[])
{
	int i;
	int j;
	string checker;
	int t = 0;
	string mainarray[4];
	ifstream myfile(file);
	if (myfile.is_open()) {
		string line;
		string word;
		while (getline(myfile, line)) {
			if (line.size() == 0) {
				throw std::domain_error("File missing data");
			}
			istringstream iss(line, istringstream::in);
			while (iss >> word && i < 4)
			{
				mainarray[i] = word;
				switch (i) {
				case 0:
					if (is_double(word) == false || stod(word) <= 0) {
						throw std::domain_error("File contains invalid data (time)");
					}
					break;
				case 1:
					if (countryvalidation(word) == false) {
						throw std::domain_error("File contains invalid data (country)");
					}
					break;
				case 2:
					checker = word;
					checker = trim(checker);
					if (is_number(checker) == false) {
						throw std::domain_error("File contains invalid data (number)");
					}
					break;
				case 3:
					if (namevalidation(word) == false) {
						throw std::domain_error("File contains invalid data (name)");
					}
					break;
				}
				++i;

			}


			i = 0;
			for (j = 0; j < 1; ++j) {
				timeArray[t] = stod(mainarray[0]);
				countryArray[t] = mainarray[1];
				numberArray[t] = stoi(mainarray[2]);
				lastnameArray[t] = mainarray[3];
				++t;
			}
		}
	}
	else {
		throw std::invalid_argument("Cannot open file");
	}
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	int i;
	for (i = 0; i < 9; ++i) {
		ary[i] = 0.0;
	}
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	int i;
	for (i = 0; i < 9; ++i) {
		ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	int i;
	for (i = 0; i < 9; ++i) {
		ary[i] = "N/A";
	}
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	int i;
	int rnk;
	for (i = 0; i < 9; i++) {
		rnk = 0;
		for (int z = 0; z < 9; z++) {
			if (timeArray[z] < timeArray[i])
				rnk++;
		}
		rankArray[i] = rnk + 1;
	}


}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
	const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;

	// print the results, based on rank, but measure the time difference_type
	for (unsigned int j = 1; j <= SIZE; j++)
	{

		// go thru each array, find who places in "i" spot
		for (unsigned int i = 0; i < SIZE; i++)
		{
			if (rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}


			if (rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
			}

		}
	}
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
		ret.erase(0, 1);
	}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size() - 1))) {
		ret.erase(ret.size() - 1, 1);
	}

	return ret;
}