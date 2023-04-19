#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;


void wrap(int &start, int size, int min, int max) {
	if (start > max) {
		start = min;
	}
	if (start < min) {
		start = max;
	}
}


void user_validation(string diff, bool& valid) {
	string valid_entries[4] = { "Easy", "Mild", "Spicy", "Turbo" };
	for (int i = 0; i < 4; i++) {
		if (diff == valid_entries[i]) {
			valid = true;
			break;
		}
	}
	if (!valid) {
		cout << "That is not valid" << endl;
	}
}


void user_validation(int cards, bool &valid) {
	if (cards <= 9 && cards >= 3) {
		valid = true;
	}
	else {
		valid = false;
		cout << "That is not valid" << endl;
	}
}


void user_input(int &cards, string &diff, int dime[]) {
	bool valid = false;
	string input;
	int intput;
	while (valid == false) {
		cout << "How many cards do you want(3-9)? ";
		cin >> intput; cin.ignore();
		user_validation(intput, valid);
	}
	cards = intput;
	valid = false;
	while (valid == false) {
		cout << "What is the difficulty(Easy, Mild, Spicy, Turbo)? ";
		cin >> input; cin.ignore();
		user_validation(input, valid);
	}
	string valid_entries[4] = { "Easy", "Mild", "Spicy", "Turbo" };
	int i = 0;
	for (i = 0; i < 4; i++) {
		if (input == valid_entries[i]) {
			break;
		}
	}
	diff = input;
	int amount = (i * 4) + 12;
	dime[0] = amount;
	dime[1] = amount;
}


void cards_input(int** collection, int total, int dime[], string diff) {
	int window_size;
	int window_start;
	if (diff == "Easy") {
		window_size = 31;
		window_start = rand() % 127 + 33;
		wrap(window_start, window_size, 33, 126);
	}
	else if (diff == "Mild") {
		window_size = 47;
		window_start = rand() % 93 + 33;
		wrap(window_start, window_size, 33, 126);
	}
	else if (diff == "Spicy") {
		window_size = 61;
		window_start = rand() % 126 + 33;
		wrap(window_start, window_size, 33, 126);
	}
	else {
		window_size = 93;
		window_start = rand() % 126 + 33;
		wrap(window_start, window_size, 33, 126);
	}
	for (int i = 0; i < 3; i++) {
		collection[i] = new int[dime[0]];
	}
	collection[0][0] = total;
	for (int i = 0; i < dime[0]; i++) {
		collection[1][i] = rand() % window_size + window_start;
	}
	for (int i = 0; i < dime[1]; i++) {
		collection[2][i] = rand() % window_size + window_start;
	}
}


void cards_display(int** collection, int dime[]) {
	string x_line = " ";
	string y_line;
	string y_grid = "--";
	string y_offset;
	string card = "|";
	int per_row = floor(100 / ((dime[0] * 2) + 6));
	int rows = floor(collection[0][0] / per_row);
	int remainder = collection[0][0] % per_row;

	// Set up cards to print
	for (int i = 0; i < dime[0]; i++) {
		card += collection[1][i];
		card.append("|");
	}
	for (int y = 0; y < dime[0]; y++) {
		y_offset += " |";
		y_grid += "--";
	}
	for (int y = 0; y < 5; y++) {
		y_offset += " ";
		y_grid += " ";
	}
	for (int i = 0; i < per_row; i++) {
		x_line += card + "      ";
	}

	// Print the cards
	cout << endl;
	for (int row = 0; row < rows; row++) {
		cout << x_line << setw(100) << endl;
		cout << setw(0);
		for (int i = 0; i < per_row; i++) {
			cout << y_grid;
		}
		cout << endl;
		for (int y = 0; y < dime[0]; y++) {
			y_line = collection[2][y];
			y_line.append("|");
			y_line.append(y_offset);
			for (int i = 0; i < per_row; i++) {
				cout << y_line;
			}
			cout << endl;
			for (int i = 0; i < per_row; i++) {
				cout << y_grid;
			}
			cout << endl;
		}
		cout << endl;
	}
	// Check for any remaining cards, if there are, print them
	if (remainder > 0) {
		x_line = " ";
		cout << setw(0);
		for (int rem = 0; rem < remainder; rem++) {
			x_line += card + "     ";
		}
		cout << x_line << setw(100) << endl;
		cout << setw(0);
		for (int i = 0; i < remainder; i++) {
			cout << y_grid;
		}
		cout << endl;
		for (int y = 0; y < dime[0]; y++) {
			y_line = collection[2][y];
			y_line.append("|");
			y_line.append(y_offset);
			for (int rem = 0; rem < remainder; rem++) {
				cout << y_line;
			}
			cout << endl;
			for (int i = 0; i < remainder; i++) {
				cout << y_grid;
			}
			cout << endl;
		}
	}
}


int main() {
	srand(time(NULL));
	int cards_total = 3;
	int cards_dim[2] = { 12, 12 };
	string card_difficulty = "Easy";
	int** cards_collection = new int*[3];

	user_input(cards_total, card_difficulty, cards_dim);
	cards_input(cards_collection, cards_total, cards_dim, card_difficulty);
	cards_display(cards_collection, cards_dim);

	// While running code in IDE the window will not close automatically, running the .exe will. This prevents it from closing.
	string input;
	cout << "\nPress Enter to Exit...";
	getline(cin, input);

	return 0;
}