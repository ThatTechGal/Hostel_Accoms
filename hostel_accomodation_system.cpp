#include <iostream>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    string roomType;
    bool isAvailable;

    Room(int num, string type) {
        roomNumber = num;
        roomType = type;
        isAvailable = true;
    }

    void bookRoom() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Room " << roomNumber << " has been successfully booked!" << endl;
        } else {
            cout << "Sorry, Room " << roomNumber << " is already booked!" << endl;
        }
    }

    void displayRoom() {
        cout << "Room Number: " << roomNumber << ", Type: " << roomType;
        if (isAvailable) {
            cout << ", Status: Available" << endl;
        } else {
            cout << ", Status: Booked" << endl;
        }
    }
};

class Hostel {
private:
    Room* rooms[10];
    int totalRooms;
public:
    Hostel() {
        totalRooms = 0;
    }

    void addRoom(int num, string type) {
        if (totalRooms < 10) {
            rooms[totalRooms] = new Room(num, type);
            totalRooms++;
            cout << "Room " << num << " has been added to the hostel!" << endl;
        } else {
            cout << "Sorry, hostel is full!" << endl;
        }
    }

    void displayAvailableRooms() {
        cout << "Available Rooms: " << endl;
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i]->isAvailable) {
                rooms[i]->displayRoom();
            }
        }
    }

    void bookRoom(int roomNumber) {
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i]->roomNumber == roomNumber) {
                rooms[i]->bookRoom();
                return;
            }
        }
        cout << "Room not found!" << endl;
    }
};

int main() {
    Hostel hostel;
    int choice, roomNumber;
    string roomType;

    while (true) {
        cout << "\nHostel Accommodation System\n";
        cout << "1. Add Room\n";
        cout << "2. Display Available Rooms\n";
        cout << "3. Book Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                cout << "Enter Room Type (Single/Double/Triple): ";
                cin >> roomType;
                hostel.addRoom(roomNumber, roomType);
                break;

            case 2:
                hostel.displayAvailableRooms();
                break;

            case 3:
                cout << "Enter Room Number to Book: ";
                cin >> roomNumber;
                hostel.bookRoom(roomNumber);
                break;

            case 4:
                cout << "Exiting the system... Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
