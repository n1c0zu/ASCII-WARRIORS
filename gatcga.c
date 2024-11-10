//
// Created by nicol on 21/10/2024.
//

#include <stdbool.h>  // Library for the bool type
#include <stdio.h>    // Standard input/output library
#include <stdlib.h>   // Library for standard functions like malloc, rand and system
#include <conio.h>    // Library for console input/output functions
#include <unistd.h>   // Library for process control functions
#include <windows.h>  // Library for Windows-specific functions
#include <time.h>     // Library for time functions, used for srand
#include "core.h"     // Includes the header file core.h

int main()
{
    system("mode 125,40");   // Set console mode to not exceed buffer size
    SMALL_RECT WinRect = {0, 0, 125, 40};   // New window size in 8x12 pixel characters
    SMALL_RECT* WinSize = &WinRect;  // Pointer to WinRect for SetConsoleWindowInfo
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   // Set the new window size

    /* Alternative console setup
    system("mode con: cols=125 lines=40");
    COORD bufferSize;
    bufferSize.X = 125;
    bufferSize.Y = 40;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    */

    srand(time(NULL));  // Seed for generating random numbers based on current time

    // Variable declaration
    char select;  // Variable for user input
    char *rar[] = {"normal","rare","super-rare","super-super-rare","ultra-rare"};  // Array of rarity levels
    char menu = '1';  // Variable to store menu selection

    /* Example of how to use the stats
    printf("Number: %c, Atk: %d, Res: %d, Dex: %d, Spd: %d\n",
           n_Stats[0].number, n_Stats[0].stats.atk, n_Stats[0].stats.res,
           n_Stats[0].stats.dex, n_Stats[0].stats.spd);
    */

    put_in_fullscreen();  // Put the window in fullscreen mode

    while (true) // Infinite loop for the main menu
    {
        system("cls");  // Clear the console

        menu_print();  // Print the menu
        scanf(" %c", &menu);  // Get user input for menu selection
        system("cls");  // Clear the console again for the next screen

        switch(menu)  // Switch to handle menu selection
        {
            case '1':  // Case to make a single pull
                srand(time(NULL));
                if(money >= 10)  // Check if the user has enough money
                {
                    pull_x_times(1);  // Function to make a single pull
                    money -= 10;  // Decrease money
                }
                else
                {
                    puts("no money");  // Inform the user that they don't have enough money
                }
                printf("\n");
                break;

            case '2':  // Case to make 10 pulls
                srand(time(NULL));
                if(money >= 10 * 10)  // Check if the user has enough money for 10 pulls
                {
                    pull_x_times(10);  // Function to make 10 pulls
                    money -= 10 * 10;  // Decrease money
                }
                else
                {
                    puts("no money");  // Inform the user that they don't have enough money
                }
                printf("\n");
                break;

            case '3':  // Case to make a variable number of pulls
                srand(time(NULL));
                if(money >= pull_times * 10)  // Check if the user has enough money for pulls
                {
                    pull_x_times(pull_times);  // Function to make 'pull_times' pulls
                    money -= pull_times * 10;  // Decrease money
                }
                else
                {
                    puts("no money");  // Inform the user that they don't have enough money
                }
                printf("\n");
                break;

            case 'I':
            case 'i':  // Case to show the inventory
                ascii_inventory();
                inv_print();  // Print the inventory
            puts("");
                break;

            case 'M':
            case 'm':  // Case to add money
                money += 1000;  // Increase money by 1000
                printf("\ntotal money: %d \n\n", money);  // Show total money
                puts("added 1000 money");
                break;

            case 'S':
            case 's':  // Case to save the game
                ascii_save();
                printf("Current save file: %s\n\n", current_save_file);  // Show the current save file
                save_game();  // Save the game
                break;

            case 'L':
            case 'l':  // Case to load the game
                ascii_load();
                printf("Current save file: %s\n\n", current_save_file);  // Show the current save file
                load_game();  // Load the game
                break;

            case 'N':
            case 'n':  // Case to exit the program
                printf("Exiting...\n");
                exit(0);

            case '9':
                first_startup = true;  // Set startup variable
                break;

            case 'p':
            case 'P':  // Case for party creation
                menu_party();
                break;

            case 'c':
            case 'C':  // Case for combat scenario
                combat();
                break;

            default:  // Case of invalid option
                printf("Invalid option. Please try again.\n");
        }

        system("pause");  // Pause for user input before continuing
    }

    return 0;
}