#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a show
struct Show {
    string name;
    string schedule;
    int availableSeats;
};

// Structure to represent a ticket
struct Ticket {
    string name;
    string showName;
    string schedule;
    int seatNumber;
    bool reserved;
};

// Vector to store available shows
vector<Show> shows = {
    {"Taylor Swift: Eras Tour", "March 25, 2024 - 7:00 PM", 100},
    {"Mayonnaise 20th Anniversary", "April 5, 2024 - 8:00 PM", 80},
    {"SUD - Live", "April 10, 2024 - 9:00 PM", 80}
};

// Vector to store booked tickets
vector<Ticket> tickets;

// Function to display available shows
void displayShows() {
    cout << "Available Shows:\n";
    for (int i = 0; i < shows.size(); ++i) {
        cout << i + 1 << ". " << shows[i].name << " - " << shows[i].schedule << " (" << shows[i].availableSeats << " seats available)\n";
    }
}

// Function to reserve ticket
void reserveTicket() {
    displayShows();
    int choice;
    cout << "Enter the number of the show you want to book: ";
    cin >> choice;
    if (choice < 1 || choice > shows.size()) {
        cout << "Invalid choice!\n";
        return;
    }
    int seatNumber;
    cout << "Enter preferred seat number: ";
    cin >> seatNumber;
    if (seatNumber < 1 || seatNumber > shows[choice - 1].availableSeats) {
        cout << "Seat not available!\n";
        return;
    }
    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    tickets.push_back({name, shows[choice - 1].name, shows[choice - 1].schedule, seatNumber, true});
    shows[choice - 1].availableSeats--;
    cout << "Ticket reserved successfully!\n";
}

// Function to display ticket status
void displayTicketStatus() {
    if (tickets.empty()) {
        cout << "No tickets booked yet!\n";
        return;
    }
    cout << "Ticket Status:\n";
    for (const auto& ticket : tickets) {
        cout << "Name: " << ticket.name << ", Show: " << ticket.showName << ", Schedule: " << ticket.schedule << ", Seat Number: " << ticket.seatNumber << ", Status: " << (ticket.reserved ? "Booked" : "Cancelled") << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout<<"************************************************************************"<<endl;
        cout<<"*                 Welcome to Tix2Gew                                   *"<<endl;
        cout<<"************************************************************************"<<endl;
        cout << "\nMenu:\n";
        cout << "1. Available Shows\n";
        cout << "2. Ticket Reservation\n";
        cout << "3. Ticket Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayShows();
                break;
            case 2:
                reserveTicket();
                break;
            case 3:
                displayTicketStatus();
                break;
            case 4:
                cout << "Thank you for your patronage!.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
    return 0;
}
