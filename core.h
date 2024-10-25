//
// Created by nicol on 22/10/2024.
//

#ifndef CORE_H // Include guard to prevent multiple inclusions
#define CORE_H


#include <stdbool.h>

// Function declarations for pulling characters and managing inventory
int pull(); // Function to determine the rarity of a pulled character
int pullin(int state); // Function to get a random index based on rarity state
//  void inven(); // OLD Function to display the player's inventory
void inv_print(); // NEW Function to display the player's inventory
void pull_x_times(int n); // Function to pull multiple times and display results
void total_pull_x_times(char *rar[]); // Function to handle pulling and displaying results for multiple pulls
void save_game(); // Function prototype to save the current game state (money and inventory)
void load_game(); // Function prototype to load the game state (money and inventory)


void menu_print();
void inv_print();
void put_in_fullscreen();


void combat();

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



//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset

#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"




#endif //CORE_H // End of include guard
