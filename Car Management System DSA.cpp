#include <iostream>
using namespace std;

#define MAX_SIZE 5  // Maximum parking capacity

class CarQueue {
private:
    int front, rear, count;
    string parking[MAX_SIZE]; // Array to store cars

public:
    CarQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Function to check if parking is full
    bool isFull() {
        return count == MAX_SIZE;
    }

    // Function to check if parking is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to add a car (enqueue)
    void parkCar(string carNumber) {
        if (isFull()) {
            cout << "Parking Full! No space available.\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        parking[rear] = carNumber;
        count++;
        cout << "Car " << carNumber << " parked successfully.\n";
    }

    // Function to remove a car (dequeue)
    void removeCar() {
        if (isEmpty()) {
            cout << "Parking Empty! No car to remove.\n";
            return;
        }
        cout << "Car " << parking[front] << " has left the parking.\n";
        front = (front + 1) % MAX_SIZE;
        count--;
    }

    // Function to display parked cars
    void displayParking() {
        if (isEmpty()) {
            cout << "No cars in the parking lot.\n";
            return;
        }
        cout << "Cars in parking: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << parking[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CarQueue parkingLot;
    int choice;
    string carNumber;

    do {
        cout << "\n--- Car Parking Management System ---\n";
        cout << "1. Park a Car\n";
        cout << "2. Remove a Car\n";
        cout << "3. Display Parked Cars\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Car Number: ";
                cin >> carNumber;
                parkingLot.parkCar(carNumber);
                break;
            case 2:
                parkingLot.removeCar();
                break;
            case 3:
                parkingLot.displayParking();
                break;
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

