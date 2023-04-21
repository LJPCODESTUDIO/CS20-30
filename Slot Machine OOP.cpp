// Slot Machine OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int last_win = 0;
int wins = 0;
int spins = 0;


class wheel {
private:
    int length = 5;
    int ascii[5] = { 35, 36, 37, 38, 64 };
    int ranval;
    int valid;
    int* wheel_p = new int[1];
    int selected_slot;
public:
    wheel() {
        delete[] wheel_p;
        srand((unsigned)time(0));
        length = 5;

        if (length > 7) {
            length = 7;
        }
        else if (length < 5) {
            length = 5;
        }
        wheel_p = new int[length];

        for (int i = 0; i < length; i++) {
            wheel_p[i] = ascii[rand() % 5];
        }

        while (valid < 5) {
            for (int i = 0; i < 5; i++) {
                if (wheel_p[valid] == wheel_p[i] && valid != i) {
                    ranval = rand() % 5;
                    wheel_p[valid] = ascii[ranval];
                    valid--;
                    break;
                }
            }
            valid++;
        }
    }

    ~wheel() {
        delete[] wheel_p;
    }

    void print_wheel() {
        for (int i = 0; i < length; i++) {
            cout << char(wheel_p[i]) << endl;
        }
    }

    void set_slot_to(int index, int new_val) {
        if (index > length - 1 || index < 0) {
            cout << "That is not a valid slot(0-" << length - 1 << ")\n";
            return;
        }
        wheel_p[index] = new_val;
    }

   int get_slot_at(int index) {
        if (index > length - 1 || index < 0) {
            cout << "That is not a valid slot(0-" << length - 1 << ")\n";
            return 0;
        }
        
        return wheel_p[index];
    }

    int spin_wheel() {
        selected_slot = rand() % length;
        return selected_slot;
    }
    
    void set_size_to(int size) {
        delete[] wheel_p;
        srand((unsigned)time(0));
        length = size;

        if (length > 7) {
            length = 7;
        }
        else if (length < 5) {
            length = 5;
        }
        wheel_p = new int[length];

        for (int i = 0; i < length; i++) {
            wheel_p[i] = ascii[rand() % 5];
        }

        while (valid < 5) {
            for (int i = 0; i < 5; i++) {
                if (wheel_p[valid] == wheel_p[i] && valid != i) {
                    ranval = rand() % 5;
                    wheel_p[valid] = ascii[ranval];
                    valid--;
                    break;
                }
            }
            valid++;
        }
    }
};


void get_validated_user_input(float wager) {
    string input;
    float try_wager;
    bool valid = false;
    while (valid == false) {
        cout << "Please select a wager($1.00, $0.25) ";
        getline(cin, input);
        try
        {
            try_wager = stof(input);
        }
        catch (const exception&)
        {
            cout << "That is not a valid wager." << endl;
            input = "";
            continue;
        }
        if (try_wager == 1 || try_wager == 0.25) {
            wager = try_wager;
            valid = true;
        }
        else {
            cout << "That is not a valid wager." << endl;
            input = "";
            continue;
        }
    }
}


void make_wheels(wheel wheel_1, wheel wheel_2, wheel wheel_3, float wager) {
    int ascii[5] = { 35, 36, 37, 38, 64 };
    int ranval;

    wheel_1.set_size_to(5);

    if (wager == 1) {
        ranval = rand() % 5;
        wheel_2.set_size_to(6);
        wheel_3.set_size_to(7);
        wheel_2.set_slot_to(5, ascii[ranval]);
        wheel_3.set_slot_to(5, ascii[ranval]);
        ranval = rand() % 5;
        wheel_3.set_slot_to(6, ascii[ranval]);
    }
    else {
        wheel_2.set_size_to(5);
        wheel_3.set_size_to(5);
    }
}


void check_calculate_win(int slots[], float wager, float savings, wheel wheel_1, wheel wheel_2, wheel wheel_3) {
    cout << "|" << char(wheel_1.get_slot_at(slots[0])) << "|" << char(wheel_2.get_slot_at(slots[1])) << "|" << char(wheel_3.get_slot_at(slots[2])) << "|";
}


void spin_wheels(wheel wheel_1, wheel wheel_2, wheel wheel_3, float wager, float savings) {
    int slots[3] = { 0,0,0 };
    cout << "Spinning Wheels\n\n";
    spins++;
    slots[0] = wheel_1.spin_wheel();
    slots[1] = wheel_2.spin_wheel();
    slots[2] = wheel_3.spin_wheel();
    for (int i = 0; i < 3; i++) {
        cout << slots[i] << endl;
    }
    //check_calculate_win(slots, wager, savings, wheel_1, wheel_2, wheel_3);
}


int main()
{
    float chosen_wager = 0.25;
    float retirement_savings_balance = 10.0;
    wheel wheel_1;
    wheel wheel_2;
    wheel wheel_3;

    get_validated_user_input(chosen_wager);
    make_wheels(wheel_1, wheel_2, wheel_3, chosen_wager);
    //spin_wheels(wheel_1, wheel_2, wheel_3, chosen_wager, retirement_savings_balance);
    wheel_1.print_wheel();
}