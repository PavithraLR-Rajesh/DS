//This C program manages seat reservations using a linked list, allowing users to reserve, cancel, and display available seats dynamically
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a seat
struct Seat {
    int seatNumber;
    bool available;
    struct Seat* next;
};

// Function prototypes
struct Seat* createSeat(int seatNumber, bool available);
struct Seat* initializeSeats(int totalSeats);
void displayAvailableSeats(struct Seat* head);
struct Seat* reserveSeat(struct Seat* head, int seatNumber);
struct Seat* cancelReservation(struct Seat* head, int seatNumber);
void freeSeats(struct Seat* head);

int main() {
    int totalSeats = 10; // Total number of seats
    struct Seat* seats = initializeSeats(totalSeats);
    int choice;
    int seatNumber;

    do {
        printf("\nMenu:\n");
        printf("1. Display available seats\n");
        printf("2. Reserve a seat\n");
        printf("3. Cancel reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats(seats);
                break;
            case 2:
                printf("Enter seat number to reserve: ");
                scanf("%d", &seatNumber);
                seats = reserveSeat(seats, seatNumber);
                break;
            case 3:
                printf("Enter seat number to cancel reservation: ");
                scanf("%d", &seatNumber);
                seats = cancelReservation(seats, seatNumber);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free memory
    freeSeats(seats);

    return 0;
}

// Function to create a new seat node
struct Seat* createSeat(int seatNumber, bool available) {
    struct Seat* newSeat = (struct Seat*)malloc(sizeof(struct Seat));
    if (newSeat != NULL) {
        newSeat->seatNumber = seatNumber;
        newSeat->available = available;
        newSeat->next = NULL;
    }
    return newSeat;
}

// Function to initialize the linked list of seats
struct Seat* initializeSeats(int totalSeats) {
    struct Seat* head = NULL;
    struct Seat* temp = NULL;
    for (int i = 1; i <= totalSeats; i++) {
        struct Seat* newSeat = createSeat(i, true);
        if (newSeat == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        if (head == NULL) {
            head = newSeat;
            temp = head;
        } else {
            temp->next = newSeat;
            temp = temp->next;
        }
    }
    return head;
}

// Function to display the available seats
void displayAvailableSeats(struct Seat* head) {
    printf("Available Seats:\n");
    while (head != NULL) {
        if (head->available) {
            printf("%d ", head->seatNumber);
        }
        head = head->next;
    }
    printf("\n");
}

// Function to reserve a seat (delete operation)
struct Seat* reserveSeat(struct Seat* head, int seatNumber) {
    struct Seat* current = head;
    struct Seat* prev = NULL;

    while (current != NULL) {
        if (current->seatNumber == seatNumber && current->available) {
            // Seat found and available, mark as reserved by making it unavailable
            current->available = false;
            printf("Seat %d reserved successfully!\n", seatNumber);
            return head;
        }
        prev = current;
        current = current->next;
    }

    // Seat not found or already reserved
    printf("Seat %d not available or does not exist!\n", seatNumber);
    return head;
}

// Function to cancel a reservation (restore seat)
struct Seat* cancelReservation(struct Seat* head, int seatNumber) {
    struct Seat* current = head;

    while (current != NULL) {
        if (current->seatNumber == seatNumber && !current->available) {
            // Seat found and reserved, cancel reservation by marking it available
            current->available = true;
            printf("Reservation for seat %d cancelled successfully!\n", seatNumber);
            return head;
        }
        current = current->next;
    }

    // Seat not found or not reserved
    printf("Seat %d not reserved or does not exist!\n", seatNumber);
    return head;
}

// Function to free memory allocated to the linked list
void freeSeats(struct Seat* head) {
    struct Seat* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
