//
// Created by nicol on 21/10/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>


#include "core.h"



int main()
{
    system("mode 125,40");   //Set mode to ensure window does not exceed buffer size
    SMALL_RECT WinRect = {0, 0, 125, 40};   //New dimensions for window in 8x12 pixel chars
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

    /*system("mode con: cols=125 lines=40");
    COORD bufferSize;
    bufferSize.X = 125;
    bufferSize.Y = 40;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);*/

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Variable declarations
    char select; // For user input
    char *rar[] = {"normal","rare","super-rare","super-super-rare","ultra-rare"}; // Array of rarity levels
    char menu = '1'; // Variable to store menu selection



    /* Example of how to use stats
    printf("Number: %c, Atk: %d, Res: %d, Dex: %d, Spd: %d\n",
           n_Stats[0].number, n_Stats[0].stats.atk, n_Stats[0].stats.res,
           n_Stats[0].stats.dex, n_Stats[0].stats.spd);
    */


    put_in_fullscreen();

    while (true) // Infinite loop for the main menu
    {
        // Clear the console
        system("cls");
        
        menu_print();
        // Get user input for menu selection
        scanf(" %c", &menu);
        system("cls"); // Clear the console again for the next display

        // Switch statement to handle menu selection
        switch(menu)
        {
            case '1': // Case for doing a single pull
                if(money >= 10) // Check if user has enough money
                {
                    pull_x_times(1); // Call function to do a single pull
                    money -= 10; // Deduct money
                }
                else
                {
                    puts("no money"); // Inform user they don't have enough money
                }
                printf("\n");
                break;

            case '2': // Case for doing 10 pulls
                if(money >= 10 * 10) // Check if user has enough money for 100 pulls
                {
                    pull_x_times(10); // Call function to pull 10 times
                    money -= 10 * 10; // Deduct money
                }
                else
                {
                    puts("no money"); // Inform user they don't have enough money
                }
                printf("\n");
                break;

            case '3':
                if(money >= pull_times * 10) // Check if user has enough money for 100 pulls
                {
                    pull_x_times(pull_times); // Call function to pull 10 times
                    money -= pull_times * 10; // Deduct money
                }
                else
                {
                    puts("no money"); // Inform user they don't have enough money
                }
                printf("\n");
                break;

            case '4': // Case for showing inventory

                inv_print(); //Print inventory
                break;

            case '5': // Case for adding money
                money += 1000; // Increase money by 1000
                printf("\ntotal money: %d \n\n", money); // Display total money
                puts("added 1000 money");
                break;

            case '6':
                printf("Current save file: %s\n\n", current_save_file);
                save_game(); // Save to file
                break;

            case '7':
                printf("Current save file: %s\n\n", current_save_file);
                load_game(); // Load from file
                break;

            case '8':
                printf("Exiting...\n");
                exit(0);

            case '9':
                first_startup=true;
                combat();
                break;


            default:
                printf("Invalid option. Please try again.\n");

        }

        system("pause"); // Pause for user input before continuing
    }

    return 0;
}
