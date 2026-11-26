#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 20

struct Ticket {
    int bookingId;
    int seatNumber;
    char passengerName[50];
    int age;
    int booked;
};

struct Ticket seats[TOTAL_SEATS];
int nextBookingId = 1001;

void initializeSeats() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].booked = 0;
        seats[i].seatNumber = i + 1;
    }
}

void bookTicket() {
    int seat, age;

    printf("\nEnter seat number (1-20): ");
    scanf("%d", &seat);

    if (seat < 1 || seat > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (seats[seat - 1].booked) {
        printf("Seat already booked!\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf(" %49[^\n]", seats[seat - 1].passengerName);

    printf("Enter passenger age: ");
    scanf("%d", &age);

    if (age <= 0 || age > 120) {
        printf("Invalid age!\n");
        return;
    }

    seats[seat - 1].age = age;
    seats[seat - 1].bookingId = nextBookingId++;
    seats[seat - 1].booked = 1;

    printf("\nTicket booked successfully!\n");
    printf("Booking ID: %d\n", seats[seat - 1].bookingId);
    printf("Seat Number: %d\n", seat);
}

void displaySeats() {
    printf("\n===== SEAT STATUS =====\n");

    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %2d : %s\n",
               seats[i].seatNumber,
               seats[i].booked ? "Booked" : "Available");
    }
}

void searchBooking() {
    int id, found = 0;

    printf("\nEnter booking ID: ");
    scanf("%d", &id);

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].booked &&
            seats[i].bookingId == id) {

            printf("\nBooking Found!\n");
            printf("Passenger: %s\n",
                   seats[i].passengerName);
            printf("Age: %d\n", seats[i].age);
            printf("Seat: %d\n", seats[i].seatNumber);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Booking not found!\n");
    }
}

void cancelTicket() {
    int id, found = 0;

    printf("\nEnter booking ID to cancel: ");
    scanf("%d", &id);

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].booked &&
            seats[i].bookingId == id) {

            seats[i].booked = 0;
            seats[i].passengerName[0] = '\0';

            printf("Ticket cancelled successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Booking not found!\n");
    }
}

int main() {
    int choice;

    initializeSeats();

    do {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Display Seats\n");
        printf("3. Search Booking\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;

            case 2:
                displaySeats();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cancelTicket();
                break;

            case 5:
                printf("Railway system closed.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
