#include <iostream>
using namespace std;

struct Time {
    int hour;  
    int minute;    
};

// Converting to GMT
int toGMT(int gmt_minutes, int offset) {
    gmt_minutes -= offset * 60;
    gmt_minutes = (gmt_minutes + 1440) % 1440;
    return gmt_minutes;
}

// Converting GMT back to local
int toLocal(int gmtMinutes, int offset) {
    gmtMinutes += offset * 60;
    gmtMinutes = (gmtMinutes + 1440) % 1440;
    return gmtMinutes;
}

// Printing time 
void printTime(int minutes) {
    int h = minutes / 60;
    int m = minutes % 60;
    if (h < 10) cout << "0";
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m;
}

int main() {
    int offset1, offset2;
    int slot1, slot2, duration;

    Time slots1[100], slots2[100];

    // Inputs
    cout << "Enter offset of Person 1 [in hours]: ";
    cin >> offset1;

    cout << "Enter number of slots for Person 1: ";
    cin >> slot1;

    cout << "Enter time slot for person 1: \n";
    for (int counter = 0; counter < slot1; counter++) {
        int starting_hour, starting_minute, end_hour, end_minute;
        cin >> starting_hour >> starting_minute >> end_hour >> end_minute;
        slots1[counter].hour = toGMT(starting_hour * 60 + starting_minute, offset1);
        slots1[counter].minute = toGMT(end_hour * 60 + end_minute, offset1);
    }

    cout << "Enter  offset of Person 2 [in hours]: ";
    cin >> offset2;

    cout << "Enter number of slots for Person 2: ";
    cin >> slot2;

    cout << "Enter time slot for person 2: \n";
    for (int counter2 = 0; counter2 < slot2; counter2++) {
        int starting_hour, starting_minute, end_hour, end_minute;
        cin >> starting_hour >> starting_minute >> end_hour >> end_minute;
        slots2[counter2].hour = toGMT(starting_hour * 60 + starting_minute, offset2);
        slots2[counter2].minute = toGMT(end_hour * 60 + end_minute, offset2);
    }

    cout << "Enter the duration (in minutes): ";
    cin >> duration;

    bool found = false;
    cout << "\n available slots: \n";

    for (int counter = 0; counter < slot1; counter++) {
        for (int counter2 = 0; counter2 < slot2; counter2++) {
            int start = max(slots1[counter].hour, slots2[counter2].hour);
            int end = min(slots1[counter].minute, slots2[counter2].minute);

            if (end - start >= duration) {
                found = true;

                //printing the available time for person 1 
                cout << "Person 1: ";
                printTime(toLocal(start, offset1));
                cout << " - ";
                printTime(toLocal(start + duration, offset1));
                cout << endl;

                // printing the available time for person 2 
                cout << "Person 2: ";
                printTime(toLocal(start, offset2));
                cout << " - ";
                printTime(toLocal(start + duration, offset2)); 
                cout << endl;
                //printing with their local time zone. 
            }
        }
    }

    if (!found) {
        cout << "\n No common slot found.\n";
    }

    return 0;
}
