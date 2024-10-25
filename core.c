//
// Created by nicol on 22/10/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "core.h"

#include <unistd.h>

#include "database.h"
#include "inventory.h"
#include "save.h"



#define ENDL puts("");




// Function to determine the rarity of the pulled character
int pull()
{
    // Generate a random number between 1 and 1000
    int rar_number = rand() % 1000 + 1;

    // Determine the rarity based on the random number
    if (rar_number >= 392 && rar_number <= 1000) // Normal (40.8%)
    {
        return 1;
    }
    else if (rar_number >= 92 && rar_number <= 391) // Rare (30%)
    {
        return 2;
    }
    else if (rar_number >= 12 && rar_number <= 91) // Super-Rare (8%)
    {
        return 3;
    }
    else if (rar_number >= 2 && rar_number <= 11) // Super-Super-Rare (1%)
    {
        return 4;
    }
    else if (rar_number == 1) // Ultra-Rare (0.1%)
    {
        return 5;
    }

    return 0; // Fallback return
}

// Function to get a random index for a given rarity state
int pullin(int state)
{
    // Calculate sizes of different rarity arrays
    int size_n = sizeof(n) / sizeof(n[0]);
    int size_r = sizeof(r) / sizeof(r[0]);
    int size_sr = sizeof(sr) / sizeof(sr[0]);
    int size_ssr = sizeof(ssr) / sizeof(ssr[0]);
    int size_ur = sizeof(ur) / sizeof(ur[0]);

    // Return a random index based on the rarity state
    if (state == 1)
    {
        return rand() % size_n; // Normal
    }
    else if (state == 2)
    {
        return rand() % size_r; // Rare
    }
    else if (state == 3)
    {
        return rand() % size_sr; // Super-Rare
    }
    else if (state == 4)
    {
        return rand() % size_ssr; // Super-Super-Rare
    }
    else if (state == 5)
    {
        return rand() % size_ur; // Ultra-Rare
    }

    return -1; // Fallback return
}



void inv_print()
{
    printf(BHGRN"NORMAL (*)                      "CRESET);
    printf(BHCYN"RARE (**)                       "CRESET);
    printf(BHMAG"SUPER RARE (***)                "CRESET);
    printf(BHYEL"SUPER SUPER RARE (****)         "CRESET);
    printf(BHRED"ULTRA RARE (****+)\n"CRESET);
    printf(BHWHT"CHR QNT  HP ATK RES DEX SPD     CHR QNT  HP ATK RES DEX SPD     CHR QNT  HP ATK RES DEX SPD     CHR QNT  HP ATK RES DEX SPD     CHR  QNT  HP ATK RES DEX SPD\n"CRESET);
    for(int i=0; i < 38; i++)
    {
        /* Example of how to use stats
        printf("Number: %c, Atk: %d, Res: %d, Dex: %d, Spd: %d\n",
        n_Stats[0].number, n_Stats[0].stats.atk, n_Stats[0].stats.res,
        n_Stats[0].stats.dex, n_Stats[0].stats.spd);*/

        if(i<10){
            //normal
            if(inv_n[i]>0)
            {
                printf("[");
                printf(BHGRN"%c"CRESET, n[i]);
                printf("] x%-2d 000 %3d %3d %3d %3d     ",inv_n[i],n_Stats[i].stats.atk,n_Stats[i].stats.res,n_Stats[i].stats.dex,n_Stats[i].stats.spd);
            }else if (inv_n[i]==0){printf("[ ] x0  --- --- --- --- ---     ");}

        }else{
            printf("                                ");
        }if(i<20)
        {
            //rare
            if(inv_r[i]>0)
            {
                printf("[");
                printf(BHCYN"%c"CRESET, r[i]);
                printf("] x%-2d 000 %3d %3d %3d %3d     ",inv_r[i],r_Stats[i].stats.atk,r_Stats[i].stats.res,r_Stats[i].stats.dex,r_Stats[i].stats.spd);
            }else if (inv_r[i]==0){printf("[ ] x0  --- --- --- --- ---     ");}

        }else{
            printf("                                ");
        }if(i<26){

            //super rare
            if(inv_sr[i]>0)
            {
                printf("[");
                printf(BHMAG"%c"CRESET, sr[i]);
                printf("] x%-2d 000 %3d %3d %3d %3d     ",inv_sr[i],sr_Stats[i].stats.atk,sr_Stats[i].stats.res,sr_Stats[i].stats.dex,sr_Stats[i].stats.spd);
            }else if (inv_sr[i]==0){printf("[ ] x0  --- --- --- --- ---     ");}
        }else{
            printf("                                ");
        }
        if(i<38){

            //ssr
            if(inv_ssr[i]>0)
            {
                printf("[");
                printf(BHYEL"%c"CRESET, ssr[i]);
                printf("] x%-2d 000 %3d %3d %3d %3d     ",inv_ssr[i],ssr_Stats[i].stats.atk,ssr_Stats[i].stats.res,ssr_Stats[i].stats.dex,ssr_Stats[i].stats.spd);
            }else if (inv_ssr[i]==0){printf("[ ] x0  --- --- --- --- ---     ");}
        }else{
            printf("                                ");
        }
        if(i<16){

            //ur
            if(inv_ur[i]>0)
            {
                printf("[");
                printf(BHRED"%s"CRESET, ur[i]);
                printf("] x%-2d 000 %3d %3d %3d %3d     \n",inv_ur[i],ur_Stats[i].stats.atk,ur_Stats[i].stats.res,ur_Stats[i].stats.dex,ur_Stats[i].stats.spd);
            }else if (inv_ur[i]==0){printf("[  ] x0  --- --- --- --- ---     \n");}
        }else{
            puts("");
        }
    }
}

// Function to pull multiple times and display the results
void total_pull_x_times(char *rar[])
{
    // Determine the rarity state of the pulled character
    int state = pull();

    // Get a random character index based on the rarity state
    int pull_save = pullin(state);



    // Handle the output for each rarity state
    if (state == 5) // Ultra-Rare
    {
        printf("   [");
        printf(REDHB BHWHT"%s"CRESET, ur[pull_save]); // Print character name
        printf("]");

        //Check if new
        if(inv_ur[pull_save]==0)
        {
            printf("NEW");
        }else{printf("   ");}

        if(inv_ur[pull_save]<99)
        {
            inv_ur[pull_save] ++; // Mark as obtained
        }

    }
    else if (state == 1) // Normal
    {
        printf("   [");
        printf(BHGRN"%c"CRESET, n[pull_save]);
        printf("] ");

        //Check if new
        if(inv_n[pull_save]==0)
        {
            printf("NEW");
        }else{printf("   ");}


        if(inv_n[pull_save]<99)
        {
            inv_n[pull_save] ++; // Mark as obtained
        }
    }
    else if (state == 2) // Rare
    {
        printf("   [");
        printf(BHCYN"%c"CRESET, r[pull_save]);
        printf("] ");

        //Check if new
        if(inv_r[pull_save]==0)
        {
            printf("NEW");
        }else{printf("   ");}


        if(inv_r[pull_save]<99)
        {
            inv_r[pull_save] ++; // Mark as obtained
        }
    }
    else if (state == 3) // Super-Rare
    {
        printf("   [");
        printf(BHMAG"%c"CRESET, sr[pull_save]);
        printf("] ");

        //Check if new
        if(inv_sr[pull_save]==0)
        {
            printf("NEW");
        }else{printf("   ");}


        if(inv_sr[pull_save]<99)
        {
            inv_sr[pull_save] ++; // Mark as obtained
        }
    }
    else if (state == 4) // Super-Super-Rare
    {
        printf("   [");
        printf(BHYEL"%c"CRESET, ssr[pull_save]);
        printf("] ");

        //Check if new
        if(inv_ssr[pull_save]==0)
        {
            printf("NEW");
        }else{printf("   ");}


        if(inv_ssr[pull_save]<99)
        {
            inv_ssr[pull_save] ++; // Mark as obtained
        }
    }
}

// Function to pull a specified number of times and display results
void pull_x_times(int n)
{
    char *rar[] = {"normal","rare","super-rare","super-super-rare","ultra-rare"}; // Array of rarity names
    printf("\n\n\n\n          -=<|0)> PULL RESULTS <(0|>=-\n");

    for (int i = 0; i < n; i++)
    {


        if(i%5==0)
        {
            ENDL
            ENDL
        }
        total_pull_x_times(rar); // Call the function to pull once
    }
    puts("");
}




bool first_startup=true;

int pull_times = 1000;

int secondsToMicroseconds(double seconds) {
        return seconds * 1000000.0;  // 1 second = 1,000,000 microseconds
}



void menu_print()
{

        // Display the menu
        if (first_startup == true)
        {
        printf(BHCYN"\n\n\n\n                                                          WELCOME TO\n\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.5));
                printf(BRED"       d8888  .d8888b.   .d8888b. 8888888 8888888      888       888                          d8b\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"      d88888 d88P  Y88b d88P  Y88b  888     888        888   o   888                          Y8P\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"     d88P888 Y88b.      888    888  888     888        888  d8b  888\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BWHT"    d88P 888  \"Y888b.   888         888     888        888 d888b 888  8888b.  888d888 888d888 888  .d88b.  888d888 .d8888b\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BWHT"   d88P  888     \"Y88b. 888         888     888        888d88888b888     \"88b 888P\"   888P\"   888 d88\"\"88b 888P\"   88K\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL"  d88P   888       \"888 888    888  888     888        88888P Y88888 .d888888 888     888     888 888  888 888     \"Y8888b.\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BYEL" d8888888888 Y88b  d88P Y88b  d88P  888     888        8888P   Y8888 888  888 888     888     888 Y88..88P 888          X88 \n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.06));
                printf(BRED"d88P     888  \"Y8888P\"   \"Y8888P\" 8888888 8888888      888P     Y888 \"Y888888 888     888     888  \"Y88P\"  888      88888P'\n"COLOR_RESET);
                usleep(secondsToMicroseconds(0.5));
                printf(BHCYN"\n                                              Copyright (c) 2024. All rights reserved.\n"COLOR_RESET);

                first_startup=false;
        }else
        {
                printf(BHCYN"\n\n\n\n                                                          WELCOME TO\n\n"COLOR_RESET);
                printf(BRED"       d8888  .d8888b.   .d8888b. 8888888 8888888      888       888                          d8b\n"COLOR_RESET);
                printf(BYEL"      d88888 d88P  Y88b d88P  Y88b  888     888        888   o   888                          Y8P\n"COLOR_RESET);
                printf(BYEL"     d88P888 Y88b.      888    888  888     888        888  d8b  888\n"COLOR_RESET);
                printf(BWHT"    d88P 888  \"Y888b.   888         888     888        888 d888b 888  8888b.  888d888 888d888 888  .d88b.  888d888 .d8888b\n"COLOR_RESET);
                printf(BWHT"   d88P  888     \"Y88b. 888         888     888        888d88888b888     \"88b 888P\"   888P\"   888 d88\"\"88b 888P\"   88K\n"COLOR_RESET);
                printf(BYEL"  d88P   888       \"888 888    888  888     888        88888P Y88888 .d888888 888     888     888 888  888 888     \"Y8888b.\n"COLOR_RESET);
                printf(BYEL" d8888888888 Y88b  d88P Y88b  d88P  888     888        8888P   Y8888 888  888 888     888     888 Y88..88P 888          X88 \n"COLOR_RESET);
                printf(BRED"d88P     888  \"Y8888P\"   \"Y8888P\" 8888888 8888888      888P     Y888 \"Y888888 888     888     888  \"Y88P\"  888      88888P'\n"COLOR_RESET);
                printf(BHCYN"\n                                              Copyright (c) 2024. All rights reserved.\n"COLOR_RESET);
        }
        printf("\n\n\nCurrent save file: %s\n", current_save_file);
        printf("Balance: %d \n\n\n", money); // Display total money
        printf("MAKE YOUR SELECTION\n\n");
        printf("1: PULL         5: GIVE MONEY\n");
        printf("2: PULL x10     6: SAVE GAME\n");
        printf("3: PULL x%0-4d   7: LOAD GAME\n",pull_times);
        printf("4: INVENTORY    8: QUIT\n");

}


void put_in_fullscreen() {



        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        puts("");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        puts("");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        puts("");
        puts("");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        puts(BHRED"");
        printf(" |  __ \\| |  | |__   __|  |_   _| \\ | |                                 \n");
        printf(" | |__) | |  | |  | |       | | |  \\| |                                 \n");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);

        usleep(secondsToMicroseconds(0.1));
        system("cls");

        printf(BHRED"  _____  _    _ _______    _____ _   _                                  \n");
        printf(" |  __ \\| |  | |__   __|  |_   _| \\ | |                                 \n");
        printf(" | |__) | |  | |  | |       | | |  \\| |                                 \n");
        printf(" |  ___/| |  | |  | |       | | | . ` |                                 \n");
        printf(" | |    | |__| |  | |      _| |_| |\\  |                                 \n");
        printf(" |_|____ \\____/ _ |_|  _  |_____|_|_\\_|____ _____  ______ ______ _   _  \n");
        printf(" |  ____| |  | | |    | |     / ____|/ ____|  __ \\|  ____|  ____| \\ | | \n");
        printf(" | |__  | |  | | |    | |    | (___ | |    | |__) | |__  | |__  |  \\| | \n");
        printf(" |  __| | |  | | |    | |     \\___ \\| |    |  _  /|  __| |  __| | . ` | \n");
        printf(" | |    | |__| | |____| |____ ____) | |____| | \\ \\| |____| |____| |\\  | \n");
        printf(" |_|     \\____/|______|______|_____/ \\_____|_|  \\_\\______|______|_| \\_| \n"COLOR_RESET);


        usleep(secondsToMicroseconds(1.5));
        system("cls");
}



void combat()
{
    printf("combat\n");
}