#include <iostream>
#include <string.h>

using namespace std;


void encrypt(int dest[], char source[]) {
    for (int i = 0; i < strlen(source); i++) {
        dest[i] = source[i];
    }
}


bool check_input(char input[]) {
    bool valid = false;
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i]) == 0) {
            cout << "Invalid input." << endl;
            valid = false;
            break;
        }
        else {
            valid = true;
            continue;
        }
    }
    return valid;
}


void input_validate(char input[]) {
    bool validated = false;
    while (validated == 0) {
        cout << "Please input a password using letters only, 4-25 characters long: ";
        cin >> input;
        cin.ignore();
        if (strlen(input) < 4) {
            cout << "Input was less than 4 characters" << endl;
        }
        else if (strlen(input) > 25) {
            cout << "Input was more than 25 characters" << endl;
        }
        else {
            validated = check_input(input);
        }
    }
}


void select_letters_and_encrypt(char sel[], char input[], int encrypted[]) {
    bool is_even = false;
    int j = 0;
    int selected_letters = 0;

    if (strlen(input) % 2 == 0) {
        is_even = true;
    }
    if (is_even == true) {
        int i = 1;
        while (selected_letters < 4) {
            sel[j] = toupper(input[i]);
            j++;
            i += 2;
            if (i > strlen(input) - 1) {
                i = 1;
            }
            selected_letters++;
        }
    }
    else {
        int i = 0;
        while (selected_letters < 4) {
            sel[j] = tolower(input[i]);
            j++;
            i += 2;
            if (i > strlen(input) - 1) {
                i = 0;
            }
            selected_letters++;
        }
    }
    encrypt(encrypted, sel);
}


void create_pin(int dest[], int source[]) {
    int multi = source[0];
    for (int i = 1; i < 4; i++) {
        multi = multi * source[i];
    }
    char temp_string[26] = "";
    sprintf_s(temp_string, "%d", multi);

    dest[0] = temp_string[0] - '0';
    dest[1] = temp_string[1] - '0';
    dest[2] = temp_string[strlen(temp_string) - 2] - '0';
    dest[3] = temp_string[strlen(temp_string) - 1] - '0';
}


void display_info(char password[], char selected_letters[], int encrypted[], int pin[]) {
    cout << "Initial Password: " << password << endl;
    cout << "Selected Letters: " << selected_letters << endl;
    cout << "ASCII Encrypted Letters: ";
    for (int i = 0; i < 4; i++) {
        cout << encrypted[i];
    }
    cout << endl;
    int multi = encrypted[0];
    for (int i = 1; i < 4; i++) {
        multi = multi * encrypted[i];
    }
    cout << "ASCII Letters Multiplied by Themselves: " << multi << endl;
    cout << "Final Bank Pin: ";
    for (int i = 0; i < 4; i++) {
        cout << pin[i];
    }
    cout << endl;
}


int main() {
    char password[26];
    char selected_letters[5] = "";
    int encrypted[5];
    int pin[4];

    input_validate(password);
    select_letters_and_encrypt(selected_letters, password, encrypted);
    create_pin(pin, encrypted);
    display_info(password, selected_letters, encrypted, pin);

    return 0;
}
