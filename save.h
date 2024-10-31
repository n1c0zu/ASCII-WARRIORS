//
// Created by nicol on 22/10/2024.
//

#ifndef SAVE_H
#define SAVE_H

#include <dirent.h>
#include <sys/stat.h>


// Global variable to store the name of the current save file
char current_save_file[100] = "No current save";

// Function to check if a file exists
int file_exists(const char* filename) {
    FILE *file = fopen(filename, "r"); // Try to open the file for reading
    if (file) {
        fclose(file); // Close the file if it exists
        return 1; // Return 1 indicating the file exists
    }
    return 0; // Return 0 indicating the file does not exist
}

// Function to list existing save files in the directory
void list_save_files() {
    struct dirent *entry; // Directory entry pointer
    DIR *dp = opendir("savefilesgame"); // Open the savefilesgame directory

    if (dp == NULL) { // Check if the directory was opened successfully
        perror("opendir"); // Print error if unable to open directory
        return;
    }

    printf("Existing save files:\n"); // Output header for listing
    while ((entry = readdir(dp))) { // Read entries in the directory
        // Check if the file has the ".char" extension
        if (strstr(entry->d_name, ".char") != NULL) {
            printf(" - %s\n", entry->d_name); // Print the name of the save file
        }
    }
    closedir(dp); // Close the directory
}

// Function to create the savefilesgame directory if it doesn't exist
void create_save_directory() {
    struct stat st = {0}; // Structure to hold file status

    // Check if the directory already exists
    if (stat("savefilesgame", &st) == -1) {
        mkdir("savefilesgame"); // Create the directory
    }
}

// Function to save money and inventory to a file
void save_game() {
    char filename[100]; // Buffer for the filename

    create_save_directory(); // Ensure the directory exists
    list_save_files(); // List existing save files for the user
    printf("Enter the filename to save your game (without extension): ");
    scanf("%s", filename); // Get the filename from user input
    strcat(filename, ".char"); // Append the .char extension

    // Full path for the save file
    char filepath[150];
    snprintf(filepath, sizeof(filepath), "savefilesgame/%s", filename); // Construct full file path

    // Check if the file already exists
    if (file_exists(filepath)) {
        char confirm; // Variable to store user's confirmation
        printf("File '%s' already exists. Overwrite? (y/n): ", filepath);
        scanf(" %c", &confirm); // Get user confirmation

        // If user chooses not to overwrite, cancel the operation
        if (confirm != 'y' && confirm != 'Y') {
            printf("Save operation canceled.\n");
            return; // Exit the function
        }
    }

    FILE *file = fopen(filepath, "w"); // Open the file for writing
    if (file == NULL) { // Check if the file opened successfully
        perror("Error opening file"); // Print error if unable to open file
        return;
    }

    // Save the money value
    fprintf(file, "%d\n", money);

    // Save the inventory
    for (int i = 0; i < sizeof(inv_n) / sizeof(inv_n[0]); i++) {
        fprintf(file, "%d ", inv_n[i]); // Save inventory items
    }
    fprintf(file, "\n"); // New line after inventory

    for (int i = 0; i < sizeof(inv_r) / sizeof(inv_r[0]); i++) {
        fprintf(file, "%d ", inv_r[i]); // Save inventory items
    }
    fprintf(file, "\n"); // New line after inventory

    for (int i = 0; i < sizeof(inv_sr) / sizeof(inv_sr[0]); i++) {
        fprintf(file, "%d ", inv_sr[i]); // Save inventory items
    }
    fprintf(file, "\n"); // New line after inventory

    for (int i = 0; i < sizeof(inv_ssr) / sizeof(inv_ssr[0]); i++) {
        fprintf(file, "%d ", inv_ssr[i]); // Save inventory items
    }
    fprintf(file, "\n"); // New line after inventory

    for (int i = 0; i < sizeof(inv_ur) / sizeof(inv_ur[0]); i++) {
        fprintf(file, "%d ", inv_ur[i]); // Save inventory items
    }
    fprintf(file, "\n"); // New line after inventory

    for(int i = 0; i < 4; i++)
    {
        fprintf(file,"%s %d %d",party[i].name, party[i].rarity, party[i].position);
        fprintf(file, "\n"); // New line after inventory
    }

    fprintf(file, "NIGGA");

    fclose(file); // Close the file after writing
    printf("Game saved successfully to '%s'.\n", filepath); // Notify user of successful save
    strcpy(current_save_file, filepath); // Update current save file path
}

// Function to load money and inventory from a file
void load_game() {
    char filename[100]; // Buffer for the filename

    create_save_directory(); // Ensure the directory exists
    list_save_files(); // List existing save files for the user
    printf("Enter the filename to load your game (without extension): ");
    scanf("%s", filename); // Get the filename from user input
    strcat(filename, ".char"); // Append the .char extension

    // Full path for the load file
    char filepath[150];
    snprintf(filepath, sizeof(filepath), "savefilesgame/%s", filename); // Construct full file path

    // Check if the file exists before attempting to load
    if (!file_exists(filepath)) {
        printf("File '%s' does not exist.\n", filepath); // Notify user if file is not found
        return; // Exit the function
    }

    FILE *file = fopen(filepath, "r"); // Open the file for reading
    if (file == NULL) { // Check if the file opened successfully
        perror("Error opening file"); // Print error if unable to open file
        return;
    }

    // Load money value from file
    fscanf(file, "%d", &money);

    // Load inventory from file
    for (int i = 0; i < sizeof(inv_n) / sizeof(inv_n[0]); i++) {
        fscanf(file, "%d", &inv_n[i]); // Read inventory items
    }

    for (int i = 0; i < sizeof(inv_r) / sizeof(inv_r[0]); i++) {
        fscanf(file, "%d", &inv_r[i]); // Read inventory items
    }

    for (int i = 0; i < sizeof(inv_sr) / sizeof(inv_sr[0]); i++) {
        fscanf(file, "%d", &inv_sr[i]); // Read inventory items
    }

    for (int i = 0; i < sizeof(inv_ssr) / sizeof(inv_ssr[0]); i++) {
        fscanf(file, "%d", &inv_ssr[i]); // Read inventory items
    }

    for (int i = 0; i < sizeof(inv_ur) / sizeof(inv_ur[0]); i++) {
        fscanf(file, "%d", &inv_ur[i]); // Read inventory items
    }

    for(int i = 0; i < 4; i++)
    {
        fscanf(file,"%s",&party[i].name);
        fscanf(file,"%d", &party[i].rarity);
        fscanf(file,"%d", &party[i].position);
    }

    fclose(file); // Close the file after reading
    printf("Game loaded successfully from '%s'.\n", filepath); // Notify user of successful load
    strcpy(current_save_file, filepath); // Update current save file path
}

#endif //SAVE_H
