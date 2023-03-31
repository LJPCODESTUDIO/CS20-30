#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;


int clamp(int val, int min, int max) {
	if (val < min) {
		val = min;
	}
	else if (val > max) {
		val = max;
	}

	return val;
}


void get_user_data(string &firstname, char lastname[], int &birthmonth, int &birthday) {
	string months[12][2] = {
		{"january", "01"},
		{"february", "02"},
		{"march", "03"},
		{"april", "04"},
		{"may", "05"},
		{"june", "06"},
		{"july", "07"},
		{"august", "08"},
		{"september", "09"},
		{"november", "10"},
		{"october", "11"},
		{"december", "12"},
	};

	bool valid = false;
	string input;
	string lowercase;
	cout << "What is your firstname? ";
	getline(cin, input);
	firstname = input;
	cout << "What is your lastname? ";
	cin >> lastname;
	cin.ignore();
	while (valid == false) {
		cout << "What month were you born in(01-12)? ";
		getline(cin, input);
		try {
			stoi(input);
		}
		catch (exception e) {
			cout << "Please only input numbers" << endl;
			continue;
		}
		if (input.size() == 2 && stoi(input) <= 12) {
			valid = true;
			birthmonth = stoi(input);
			continue;
		}
		cout << "That is not a valid month." << endl;
	}
	valid = false;

	while (valid == false) {
		cout << "What day were you born? ";
		getline(cin, input);
		try {
			stoi(input);
		}
		catch (exception e) {
			cout << "Please only input numbers" << endl;
			continue;
		}
		if (stoi(input) <= 31 && stoi(input) > 0) {
			valid = true;
			birthday = stoi(input);
			continue;
		}
		cout << "That is not a valid day." << endl;
	}
}


void by_value(string firstname, char lastname[], int month, int day, string zodiacs[][5]) {
	string firstnames[5] = {
		"Bob",
		"Jim",
		"Tim",
		"Jill",
		"Ben",
	};
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int ranval;
	int ranpos;
	string zodiac;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (month == stoi(zodiacs[i][1])) {
			if (day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "\n==================by_value()====================\n\n";
	cout << "firstname | Address: " << &firstname << " | Value: " << firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << &month << " | Value: " << month << endl;
	cout << "day | Address: " << &day << " | Value: " << day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;

	cout << "\nAll this data is junk. Don't worry, I know better.\n" << endl;

	ranval = rand() % 4;
	firstname = firstnames[ranval];
	for (int i = 0; i < 10; i++) {
		ranval = rand() % strlen(lastname);
		ranpos = rand() % 26;
		lastname[ranval] = alphabet[ranpos];
	}
	ranval = rand() % 12;
	month = ranval;
	ranval = rand() % 31;
	day = ranval;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (month == stoi(zodiacs[i][1])) {
			if (day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "firstname | Address: " << &firstname << " | Value: " << firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << &month << " | Value: " << month << endl;
	cout << "day | Address: " << &day << " | Value: " << day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;
}


void by_ref(string& firstname, char lastname[], int& month, int& day, string zodiacs[][5]) {
	string firstnames[5] = {
		"Bob",
		"Jim",
		"Tim",
		"Jill",
		"Ben",
	};
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int ranval;
	int ranpos;
	string zodiac;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (month == stoi(zodiacs[i][1])) {
			if (day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "\n==================by_ref()======================\n\n";
	cout << "firstname | Address: " << &firstname << " | Value: " << firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << &month << " | Value: " << month << endl;
	cout << "day | Address: " << &day << " | Value: " << day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;

	cout << "\nAll this data is junk. Don't worry, I know better.\n" << endl;

	ranval = rand() % 4;
	firstname = firstnames[ranval];
	for (int i = 0; i < 10; i++) {
		ranval = rand() % strlen(lastname);
		ranpos = rand() % 26;
		lastname[ranval] = alphabet[ranpos];
	}
	ranval = rand() % 12;
	month = ranval;
	ranval = rand() % 31;
	day = ranval;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (month == stoi(zodiacs[i][1])) {
			if (day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "firstname | Address: " << &firstname << " | Value: " << firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << &month << " | Value: " << month << endl;
	cout << "day | Address: " << &day << " | Value: " << day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;
}


void by_pointer(string* firstname, char lastname[], int* month, int* day, string zodiacs[][5]) {
	string firstnames[5] = {
		"Bob",
		"Jim",
		"Tim",
		"Jill",
		"Ben",
	};
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int ranval;
	int ranpos;
	string zodiac;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (*month == stoi(zodiacs[i][1])) {
			if (*day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "\n================by_pointer()====================\n\n";
	cout << "firstname | Address: " << firstname << " | Value: " << *firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << month << " | Value: " << *month << endl;
	cout << "day | Address: " << day << " | Value: " << *day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;

	cout << "\nAll this data is junk. Don't worry, I know better.\n" << endl;

	ranval = rand() % 4;
	*firstname = firstnames[ranval];
	for (int i = 0; i < 10; i++) {
		ranval = rand() % strlen(lastname);
		ranpos = rand() % 26;
		lastname[ranval] = alphabet[ranpos];
	}
	ranval = rand() % 12;
	*month = ranval;
	ranval = rand() % 31;
	*day = ranval;
	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (*month == stoi(zodiacs[i][1])) {
			if (*day >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	cout << "firstname | Address: " << firstname << " | Value: " << *firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "month | Address: " << month << " | Value: " << *month << endl;
	cout << "day | Address: " << day << " | Value: " << *day << endl;
	cout << "zodiac | Address: " << &zodiac << " | Value: " << zodiac << endl;
}


int main() {
	// Because Pseudorandom nonsense and what not
	srand(time(NULL));
	// There are 12 arrays, each array has 3 arrays, and each of those arrays have at most 2 values
	string zodiacs[12][5] = {
		{"Aries", "03", "21", "04", "19"},
		{"Tauros", "04", "20", "05", "20"},
		{"Gemini", "05", "21", "06", "21"},
		{"Cancer", "06", "23", "07", "22"},
		{"Leo", "07", "23", "08", "22"},
		{"Virgo", "08", "23", "09", "22"},
		{"Libra", "09", "24", "10", "23"},
		{"Scorpius", "10", "22", "11", "21"},
		{"Sagittarius", "11", "22", "12", "21"},
		{"Capricornus", "12", "22", "01", "19"},
		{"Aqaurius", "01", "20", "02", "18"},
		{"Pisces", "02", "19", "03", "20"}
	};
	string firstname;
	char lastname[100] = "";
	int birthmonth;
	int birthday;
	
	//string (*zodiac_p)[5] = &zodiacs[0];
	string zodiac;
	string* firstname_p = &firstname;
	char* lastname_p = &lastname[0];
	int* month_p = &birthmonth;
	int* day_p = &birthday;
	//\n=======================|=========================\n\n
	cout << "================GETTING USER DATA================\n\n";
	get_user_data(firstname, lastname, birthmonth, birthday);

	cout << "\n=================BACK IN MAIN===================\n\n";
	cout << "firstname | Address: " << &firstname << " | Value: " << firstname << endl;
	cout << "lastname | Address: " << &lastname << " | Value: " << lastname << endl;
	cout << "birthmonth | Address: " << &birthmonth << " | Value: " << birthmonth << endl;
	cout << "birthday | Address: " << &birthday << " | Value: " << birthday << endl;

	for (int i = 0; i < 12; i++) {
		//First find the beginning month
		//Then check if the day is within the bounds
		if (birthmonth == stoi(zodiacs[i][1])) {
			if (birthday >= stoi(zodiacs[i][2])) {
				zodiac = zodiacs[i][0];
				break;
			}
		}
	}

	by_value(firstname, lastname, birthmonth, birthday, zodiacs);
	cout << "\n=================BACK IN MAIN===================\n\n";
	by_ref(firstname, lastname, birthmonth, birthday, zodiacs);
	cout << "\n=================BACK IN MAIN===================\n\n";
	by_pointer(firstname_p, lastname_p, month_p, day_p, zodiacs);

	return 0;
}
