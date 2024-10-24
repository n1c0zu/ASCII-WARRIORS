//
// Created by nicol on 22/10/2024.
//

#ifndef CORE_H // Include guard to prevent multiple inclusions
#define CORE_H

#include "menu.h"

// Function declarations for pulling characters and managing inventory
int pull(); // Function to determine the rarity of a pulled character
int pullin(int state); // Function to get a random index based on rarity state
void total_pull(char *rar[]); // Function to execute a single pull and display the result  FUNZIONE DEPRECATA
//  void inven(); // OLD Function to display the player's inventory
void inv_print(); // NEW Function to display the player's inventory
void pull_x_times(int n); // Function to pull multiple times and display results
void total_pull_x_times(char *rar[]); // Function to handle pulling and displaying results for multiple pulls
void save_game(); // Function prototype to save the current game state (money and inventory)
void load_game(); // Function prototype to load the game state (money and inventory)

extern char current_save_file[100]; // Global variable to store the name of the current save file

extern int money; // Declaration of the global variable money

extern bool first_startup;

extern int pull_times; // Variable to store how many times you will pull
// Struct to hold character stats
struct Stats {
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

// Extern declarations of the character stats arrays for different rarity levels
extern struct CharStats n_Stats[]; // Array for Normal character stats
extern struct CharStats r_Stats[]; // Array for Rare character stats
extern struct CharStats sr_Stats[]; // Array for Super-Rare character stats
extern struct CharStats ssr_Stats[]; // Array for Super-Super-Rare character stats
extern struct CharStats ur_Stats[]; // Array for Ultra-Rare character stats

#endif //CORE_H // End of include guard
