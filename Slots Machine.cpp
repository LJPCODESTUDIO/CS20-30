// Slots Machine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


int result[3] = { 0,0,0 };
int spins = 0;
int wins = 0;
int last_win = 0;


int wrap(int value, int min, int max) {
    if (value < min) {
        value = max;
    }
    else if (value > max) {
        value = min;
    }
    return value;
}


void update_balance(float &savings, float wager) {
    if (wager == 1) {
        if (wins > 0) {
            cout << "======== = YOU WIN!=========\n" << endl;
            cout << "You won $" << (20 * wins);
        }
        savings += 20 * wins;
        if (last_win >= 5) {
            cout << "\n=====HAVE SOME MONEY!=====\n" << endl;
            cout << "You won $4";
            savings += 4;
            last_win = 0;
        }
    }
    else {
        if (wins > 0) {
            cout << "======== = YOU WIN!=========\n" << endl;
            cout << "You won $" << (10 * wins);
        }
        savings += 10 * wins;
        if (last_win >= 5) {
            cout << "\n=====HAVE SOME MONEY!=====\n" << endl;
            cout << "You won $1";
            savings += 4;
            last_win = 0;
        }
    }
}


void check_calculate_win(int wheel_1[], int wheel_2[], int wheel_3[], float wager, float &savings) {
    last_win++;
    cout << "        ___________" << endl;
    cout << "       /==CASINO!==\\" << endl;
    if (wager == .25) {
        cout << "       | " << char(wheel_1[wrap(result[0] - 1, 0, 4)]) << " | " << char(wheel_2[wrap(result[1] - 1, 0, 4)]) << " | " << char(wheel_3[wrap(result[2] - 1, 0, 4)]) << " |" << endl;
        cout << "       | " << char(wheel_1[result[0]]) << " | " << char(wheel_2[result[1]]) << " | " << char(wheel_3[result[2]]) << " |" << endl;
        cout << "       | " << char(wheel_1[wrap(result[0] + 1, 0, 4)]) << " | " << char(wheel_2[wrap(result[1] + 1, 0, 4)]) << " | " << char(wheel_3[wrap(result[2] + 1, 0, 4)]) << " |" << endl;
        // putting the calculations here so I don't have to check the wager again
        if (wheel_1[wrap(result[0] - 1, 0, 4)] == wheel_2[wrap(result[1] - 1, 0, 4)] && wheel_2[wrap(result[1] - 1, 0, 4)] == wheel_3[wrap(result[2] - 1, 0, 4)]) {
            wins++;
            last_win = 0;
        }
        if (wheel_1[wrap(result[0] + 1, 0, 4)] == wheel_2[wrap(result[1] + 1, 0, 4)] && wheel_2[wrap(result[1] + 1, 0, 4)] == wheel_3[wrap(result[2] + 1, 0, 4)]) {
            wins++;
            last_win = 0;
        }
        if (wheel_1[result[0]] == wheel_2[result[1]] && wheel_2[result[1]] == wheel_3[result[2]]) {
            wins++;
            last_win = 0;
        }
    }
    else {
        cout << "       | " << char(wheel_1[wrap(result[0] - 1, 0, 4)]) << " | " << char(wheel_2[wrap(result[1] - 1, 0, 5)]) << " | " << char(wheel_3[wrap(result[2] - 1, 0, 6)]) << " |" << endl;
        cout << "       | " << char(wheel_1[result[0]]) << " | " << char(wheel_2[result[1]]) << " | " << char(wheel_3[result[2]]) << " |" << endl;
        cout << "       | " << char(wheel_1[wrap(result[0] + 1, 0, 4)]) << " | " << char(wheel_2[wrap(result[1] + 1, 0, 5)]) << " | " << char(wheel_3[wrap(result[2] + 1, 0, 6)]) << " |" << endl;
        // putting the calculations here so I don't have to check the wager again
        if (wheel_1[wrap(result[0] - 1, 0, 4)] == wheel_2[wrap(result[1] - 1, 0, 5)] && wheel_2[wrap(result[1] - 1, 0, 5)] == wheel_3[wrap(result[2] - 1, 0, 6)]) {
            wins++;
            last_win = 0;
        }
        if (wheel_1[wrap(result[0] + 1, 0, 4)] == wheel_2[wrap(result[1] + 1, 0, 5)] && wheel_2[wrap(result[1] + 1, 0, 5)] == wheel_3[wrap(result[2] + 1, 0, 6)]) {
            wins++;
            last_win = 0;
        }
        if (wheel_1[result[0]] == wheel_2[result[1]] && wheel_2[result[1]] == wheel_3[result[2]]) {
            wins++;
            last_win = 0;
        }
    }
    cout << "       |===========|" << endl;
    cout << "       |===========|" << endl;
    cout << "       |===========|" << endl;
    cout << "       |===========|" << endl;
    cout << "       |===========|" << endl;
    update_balance(savings, wager);
}


void get_validated_user_input(float *wager) {
    bool valid = false;
    float check;
    string input;
    while (valid == false) {
        cout << "How much would you like to wager?($1 or $0.25) ";
        getline(cin, input);
        try {
            check = stof(input);
        }
        catch (exception e) {
            cout << "Please only input numbers" << endl;
            continue;
        }
        if (stof(input) == 1.0 || stof(input) == 0.25) {
            valid = true;
            break;
        }
        cout << "That is not a valid wager." << endl;
    }
    *wager = stof(input);
}


void make_wheels(int wheel_1[], int wheel_2[], int wheel_3[], float wager) {
    int ascii[5] = { 35, 36, 37, 38, 64 };
    int ranval;
    int valid = 0;
    for (int i = 0; i < 5; i++) {
        // First, fill the wheel
        // Then check the wheel for any same characters
        // Change the characters
        ranval = rand() % 5;
        wheel_1[i] = ascii[ranval];
        ranval = rand() % 5;
        wheel_2[i] = ascii[ranval];
        ranval = rand() % 5;
        wheel_3[i] = ascii[ranval];
    }
    while (valid < 5) {
        for (int i = 0; i < 5; i++) {
            if (wheel_1[valid] == wheel_1[i] && valid != i) {
                ranval = rand() % 5;
                wheel_1[valid] = ascii[ranval];
                valid--;
                break;
            }
            if (wheel_2[valid] == wheel_2[i] && valid != i) {
                ranval = rand() % 5;
                wheel_2[valid] = ascii[ranval];
                valid--;
                break;
            }
            if (wheel_3[valid] == wheel_3[i] && valid != i) {
                ranval = rand() % 5;
                wheel_3[valid] = ascii[ranval];
                valid--;
                break;
            }
        }
        valid++;
    }
    if (wager == 1) {
        ranval = rand() % 5;
        wheel_2[5] = ascii[ranval];
        wheel_3[5] = ascii[ranval];
        ranval = rand() % 5;
        while (ascii[ranval] == wheel_2[5]) {
            ranval = rand() % 5;
        }
        wheel_3[6] = ascii[ranval];
    }
}


void spin_wheels(int wheel_1[], int wheel_2[], int wheel_3[], float wager, float &savings) {
    wins = 0;
    cout << "\n=======Spinning Wheels=======\n\n";
    int ranval = rand() % 5;
    result[0] = ranval;
    if (wager == 1) {
        ranval = rand() % 6;
        result[1] = ranval;
        ranval = rand() % 7;
        result[2] = ranval;
    }
    else {
        ranval = rand() % 5;
        result[1] = ranval;
        ranval = rand() % 5;
        result[2] = ranval;
    }
    spins++;
    savings -= wager;
    check_calculate_win(wheel_1, wheel_2, wheel_3, wager, savings);
}


void dis_winnings(float savings, float wager) {
    cout << "\nSavings = " << savings << endl;
    cout << "Spins = " << spins << endl;
    cout << "Wager = " << wager << endl;
}


int main()
{
    srand((unsigned)time(0));
    // =============|=============
    string input;
    float retirement_savings_balance = 100;
    float chosen_wager;
    bool running = true;
    get_validated_user_input(&chosen_wager);
    int* wheel_1 = new int[5];
    int* wheel_2 = new int[7];
    int* wheel_3 = new int[7];
    make_wheels(wheel_1, wheel_2, wheel_3, chosen_wager);
    while (running) {
        spin_wheels(wheel_1, wheel_2, wheel_3, chosen_wager, retirement_savings_balance);
        dis_winnings(retirement_savings_balance, chosen_wager);
        cout << "Would you like to play again(y/n) You can also (c)hange your wager: ";
        getline(cin, input);
        if (input == "n") {
            running = false;
            break;
        }
        else if (input == "y") {
            continue;
        }
        else if (input == "c") {
            get_validated_user_input(&chosen_wager);
        }
    }
    


    return 0;
}
