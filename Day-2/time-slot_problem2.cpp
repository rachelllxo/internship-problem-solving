#include <iostream>
using namespace std;

int main() {
    int slot_size1, slot_size2;
    int timeSlot1[100][2], timeSlot2[100][2];
    int duration;

    // Input for person 1
    cout << "Enter number of slots for person : ";
    cin >> slot_size1;
    cout << "Enter the slots as start and end time :\n";
    for (int start_counter1 = 0; start_counter1 < slot_size1; start_counter1++) {
        cin >> timeSlot1[start_counter1][0] >> timeSlot1[start_counter1][1];
    }

    // Input for person 2
    cout << "Enter number of slots for person : ";
    cin >> slot_size2;
    cout << "Enter the slots as start and end time :\n";
    for (int start_counter2 = 0; start_counter2 < slot_size2; start_counter2++) {
        cin >> timeSlot2[start_counter2][0] >> timeSlot2[start_counter2][1];
    }

    // Input duration
    cout << "Enter the duration: ";
    cin >> duration;

    // Two pointer approach using naming convention
    int start_counter1 = 0, start_counter2 = 0;
    bool found = false;

    while (start_counter1 < slot_size1 && start_counter2 < slot_size2) {
        int start_time = max(timeSlot1[start_counter1][0], timeSlot2[start_counter2][0]);
        int end_time = min(timeSlot1[start_counter1][1], timeSlot2[start_counter2][1]);

        if (end_time - start_time >= duration) {
            cout << "Earliest common available slot: [" << start_time << ", " << start_time + duration << "]\n";
            found = true;
            break;
        }

        // Move the pointer of the slot that ends earlier
        if (timeSlot1[start_counter1][1] < timeSlot2[start_counter2][1])
            start_counter1++;
        else
            start_counter2++;
    }

    if (!found) {
        cout << "No common slot available for the required duration.\n";
    }

    return 0;
}
