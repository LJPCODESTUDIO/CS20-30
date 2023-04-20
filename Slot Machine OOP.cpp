// Slot Machine OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class wheel {
private:
    int length = 5;
    int ascii[5] = { 35, 36, 37, 38, 64 };
    int ranval;
    int valid;
    int* wheel_p;
    int selected_slot;
public:
    wheel() {
        srand((unsigned)time(0));
        wheel_p = new int[length];
        for (int i = 0; i < length; i++) {
            wheel_p[i] = ascii[rand() % 5];
        }
        while (valid < length) {
            for (int i = 0; i < length; i++) {
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

    wheel(int len) {
        srand((unsigned)time(0));
        length = len;
        wheel_p = new int[length];

        if (length > 7) {
            length = 7;
        }
        else if (length < 5) {
            length = 5;
        }

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
        delete wheel_p;
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
            return;
        }
        return wheel_p[index];
    }

    void spin_wheel() {
        selected_slot = rand() % length;
    }
};


int main()
{
    wheel wheel_1(7);
    wheel_1.spin_wheel();
}