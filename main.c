#include <stdio.h>
#include <stdlib.h>  // Required for rand()

#define MAX_ROOMS 5  // Maximum number of rooms

// Function Prototypes
void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]);
void displayMenu();
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temperature[]);
void checkMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]);

int main() 
{
    int rooms;
    
    printf("Enter number of rooms (Max %d): ", MAX_ROOMS);
    scanf("%d", &rooms);

    if (rooms > MAX_ROOMS || rooms <= 0) {
        printf("Invalid number of rooms! Setting to %d.\n", MAX_ROOMS);
        rooms = MAX_ROOMS;
    }
    
    int lights[MAX_ROOMS], locks[MAX_ROOMS], motion[MAX_ROOMS], temperature[MAX_ROOMS];

    initializeSystem(rooms, lights, locks, motion, temperature);
    
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temperature); break;
            case 3: checkMotion(rooms, motion); break;
            case 4: securitySystem(rooms, locks); break;
            case 5: analyzeHouseStatus(rooms, lights, locks, motion, temperature); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);
    
    return 0;
}

// Function to initialize the system
void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;     // Lights off
        locks[i] = 1;      // Doors locked
        motion[i] = 0;     // No motion detected
        temperature[i] = 22 + (rand() % 10);  // Random temp between 22-31
    }
    printf("System initialized with %d rooms.\n", rooms);
}

// Display menu options
void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// Function to toggle lights
void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

// Function to read temperature of a specific room
void readTemperature(int rooms, int temperature[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

// Function to check motion sensor status
void checkMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        motion[room - 1] = 1;  // Simulate motion detection
        printf("Motion detected in Room %d!\n", room);
    } else {
        printf("Invalid room number!\n");
    }
}

// Function to lock/unlock a room
void securitySystem(int rooms, int locks[]) {
    int room;
    printf("Enter room number to Lock/Unlock (1-%d): ", rooms);
    scanf("%d", &room);
    
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
    } else {
        printf("Invalid room number!\n");
    }
}

// Function to analyze the status of the entire house
void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
               i + 1, 
               lights[i] ? "ON" : "OFF", 
               temperature[i], 
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}
