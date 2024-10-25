//
// Created by nicol on 22/10/2024.
//

#ifndef CORE_H // Include guard to prevent multiple inclusions
#define CORE_H


#include <stdbool.h>




// Function declarations for pulling characters and managing inventory
int pull(); // Function to determine the rarity of a pulled character
int pullin(int state); // Function to get a random index based on rarity state
void pull_x_times(int n); // Function to pull multiple times and display results
void total_pull_x_times(char *rar[]); // Function to handle pulling and displaying results for multiple pulls
void save_game(); // Function prototype to save the current game state (money and inventory)
void load_game(); // Function prototype to load the game state (money and inventory)


void menu_print(); // Function prototype to print the menu
void inv_print(); // Function prototype to print the inventory
void put_in_fullscreen();
void ascii_save();
void ascii_load();
void ascii_inventory();

void combat();

extern char current_save_file[100]; // Global variable to store the name of the current save file


struct Stats {
    int hp;  // Health points
    int atk; // Attack stat
    int res; // Resistance stat
    int dex; // Dexterity stat
    int spd; // Speed stat
};

// Struct to hold a character along with its stats
struct CharStats {
    char character; // Character identifier
    struct Stats stats; // Character stats
};

extern int money;

extern bool first_startup;

extern int pull_times; // Variable to store how many times you will pull
// Struct to hold character stats

#endif //CORE_H // End of include guard
