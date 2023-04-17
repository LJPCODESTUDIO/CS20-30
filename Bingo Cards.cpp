#include <iostream>
#include <iomanip>
#include <string>

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


void cards_input(int collection_amount[], int collection_x[], int collection_y[], int total, int dime[], string diff) {
	collection_amount[0] = total;
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
	for (int i = 0; i < dime[0]; i++) {
		collection_x[i] = rand() % window_size + window_start;
	}
	for (int i = 0; i < dime[1]; i++) {
		collection_y[i] = rand() % window_size + window_start;
	}
}
 

void cards_display(int collection_amount[], int collection_x[], int collection_y[], int total, int dime[], string diff) {
	string xline;
	string yline;
	string y_offset;
	string card;
	int per_row = floor(100 / (dime[0] + 5));
	int rows = floor(total / per_row);
	int remainder = total % per_row;
	for (int i = 0; i < dime[0]; i++) {
		card += collection_x[i];
	}
	for (int y = 0; y < (dime[0] + 5); y++) {
		y_offset += " ";
	}
	for (int row = 0; row < rows; row++) {
		xline = " ";
		cout << setw(0);
		for (int i = 0; i < per_row; i++) {
			xline += card + "     ";
		}
		cout << xline << setw(100) << endl;
		for (int y = 0; y < dime[0]; y++) {
			yline = collection_y[y];
			for (int y_offset = 0; y_offset < (dime[0] + 5); y_offset++) {
				yline += " ";
			}
			cout << yline << setw(100) << endl;
		}
	}
	xline = " ";
	cout << setw(0);
	for (int rem = 0; rem < remainder; rem++) {
		xline += card + "     ";
	}
	cout << xline << setw(100) << endl;
	cout << setw(0);
	yline = "";
	for (int y = 0; y < dime[0]; y++) {
		y_offset = "";
		for (int y2 = 0; y2 < (dime[0] + 5); y2++) {
			y_offset += " ";
		}
		for (int rem = 0; rem < remainder; rem++) {
			yline += collection_y[y];
			yline.append(y_offset);
			y_offset.erase(y_offset.end() - 2, y_offset.end());
		}
		cout << yline << endl;
	}
}


int main() {
	srand(time(NULL));
	int cards_total = 3;
	int cards_dim[2] = { 12, 12 };
	string card_difficulty = "Easy";
	int cards_collection[3][24] = {
		{3},
		{36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
		{36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36}
	};

	user_input(cards_total, card_difficulty, cards_dim);
	cards_input(cards_collection[0], cards_collection[1], cards_collection[2], cards_total, cards_dim, card_difficulty);
	cards_display(cards_collection[0], cards_collection[1], cards_collection[2], cards_total, cards_dim, card_difficulty);

	return 0;
}