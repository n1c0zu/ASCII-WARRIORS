//
// Created by nicol on 22/10/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "core.h"

#include "database.h"
#include "inventory.h"

const static int size[] = {sizeof(n) / sizeof(n[0]), sizeof(r) / sizeof(r[0]), sizeof(sr) / sizeof(sr[0]), sizeof(ssr) / sizeof(ssr[0]), sizeof(ur) / sizeof(ur[0])};


#include "menu.h"
#include "save.h"
#include "party.h"
#include "combat.h"


#define ENDL puts("");



// Function to determine the rarity of the pulled character
int pull()
{
    // Generate a random number between 1 and 1000
    int rar_number = rand() % 1000 + 1;

    // Determine the rarity based on the random number
    if (rar_number >= 407 && rar_number <= 1000) // Normal (40.8%)
    {
        return 1;
    }
    else if (rar_number >= 107 && rar_number <= 406) // Rare (30%)
    {
        return 2;
    }
    else if (rar_number >= 27 && rar_number <= 106) // Super-Rare (8%)
    {
        return 3;
    }
    else if (rar_number >= 2 && rar_number <= 26) // Super-Super-Rare (2.5%)
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
    //returning a random number for every rarity, using a lookup table
    return rand() % size[state-1];
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
                printf("] x%-2d %3d %3d %3d %3d %3d     ",inv_n[i],n_Stats[i].stats.hp,n_Stats[i].stats.atk,n_Stats[i].stats.res,n_Stats[i].stats.dex,n_Stats[i].stats.spd);
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
                printf("] x%-2d %3d %3d %3d %3d %3d     ",inv_r[i],r_Stats[i].stats.hp,r_Stats[i].stats.atk,r_Stats[i].stats.res,r_Stats[i].stats.dex,r_Stats[i].stats.spd);
            }else if (inv_r[i]==0){printf("[ ] x0  --- --- --- --- ---     ");}

        }else{
            printf("                                ");
        }if(i<26){

            //super rare
            if(inv_sr[i]>0)
            {
                printf("[");
                printf(BHMAG"%c"CRESET, sr[i]);
                printf("] x%-2d %3d %3d %3d %3d %3d     ",inv_sr[i],sr_Stats[i].stats.hp,sr_Stats[i].stats.atk,sr_Stats[i].stats.res,sr_Stats[i].stats.dex,sr_Stats[i].stats.spd);
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
                printf("] x%-2d %3d %3d %3d %3d %3d     ",inv_ssr[i],ssr_Stats[i].stats.hp,ssr_Stats[i].stats.atk,ssr_Stats[i].stats.res,ssr_Stats[i].stats.dex,ssr_Stats[i].stats.spd);
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
                printf("] x%-2d %3d %3d %3d %3d %3d     \n",inv_ur[i],ur_Stats[i].stats.hp,ur_Stats[i].stats.atk,ur_Stats[i].stats.res,ur_Stats[i].stats.dex,ur_Stats[i].stats.spd);
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
        printf(BHRED"%s"CRESET, ur[pull_save]); // Print character name
        printf("]");

        //Check if new
        if(inv_ur[pull_save]==0)
        {
            printf(BHRED"NEW"CRESET);
        }else{printf("   ");}

        if(inv_ur[pull_save]<5)
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
            printf(BHGRN"NEW"CRESET);
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
            printf(BHCYN"NEW"CRESET);
        }else{printf("   ");}


        if(inv_r[pull_save]<75)
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
            printf(BHMAG"NEW"CRESET);
        }else{printf("   ");}


        if(inv_sr[pull_save]<30)
        {
            inv_sr[pull_save] ++; // Mark as obtained
        }
    }
    else if (state == 4) // Super-Super-Rare
    {
        printf("   [");
        printf(BYEL"%c"CRESET, ssr[pull_save]);
        printf("] ");

        //Check if new
        if(inv_ssr[pull_save]==0)
        {
            printf(BYEL"NEW"CRESET);
        }else{printf("   ");}


        if(inv_ssr[pull_save]<15)
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

void color_test(){
    printf(COLOR_RESET BLK"BLK  ");
    printf(COLOR_RESET RED"RED  ");
    printf(COLOR_RESET GRN"GRN  ");
    printf(COLOR_RESET YEL"YEL  ");
    printf(COLOR_RESET BLU"BLU  ");
    printf(COLOR_RESET MAG"MAG  ");
    printf(COLOR_RESET CYN"CYN  ");
    printf(COLOR_RESET WHT"WHT  ");
    puts("");
    printf(COLOR_RESET BBLK"BBLK ");
    printf(COLOR_RESET BRED"BRED ");
    printf(COLOR_RESET BGRN"BGRN ");
    printf(COLOR_RESET BYEL"BYEL ");
    printf(COLOR_RESET BBLU"BBLU ");
    printf(COLOR_RESET BMAG"BMAG ");
    printf(COLOR_RESET BCYN"BCYN ");
    printf(COLOR_RESET BWHT"BWHT ");
    puts("");
    printf(COLOR_RESET UBLK"UBLK ");
    printf(COLOR_RESET URED"URED ");
    printf(COLOR_RESET UGRN"UGRN ");
    printf(COLOR_RESET UYEL"UYEL ");
    printf(COLOR_RESET UBLU"UBLU ");
    printf(COLOR_RESET UMAG"UMAG ");
    printf(COLOR_RESET UCYN"UCYN ");
    printf(COLOR_RESET UWHT"UWHT ");
    puts("");
    printf(COLOR_RESET BLKB"BLKB ");
    printf(COLOR_RESET REDB"REDB ");
    printf(COLOR_RESET GRNB"GRNB ");
    printf(COLOR_RESET YELB"YELB ");
    printf(COLOR_RESET BLUB"BLUB ");
    printf(COLOR_RESET MAGB"MAGB ");
    printf(COLOR_RESET CYNB"CYNB ");
    printf(COLOR_RESET WHTB"WHTB ");
    puts("");
    printf(COLOR_RESET BLKHB"BLKHB");
    printf(COLOR_RESET REDHB"REDHB");
    printf(COLOR_RESET GRNHB"GRNHB");
    printf(COLOR_RESET YELHB"YELHB");
    printf(COLOR_RESET BLUHB"BLUHB");
    printf(COLOR_RESET MAGHB"MAGHB");
    printf(COLOR_RESET CYNHB"CYNHB");
    printf(COLOR_RESET WHTHB"WHTHB");
    puts("");
    printf(COLOR_RESET HBLK"HBLK ");
    printf(COLOR_RESET HRED"HRED ");
    printf(COLOR_RESET HGRN"HGRN ");
    printf(COLOR_RESET HYEL"HYEL ");
    printf(COLOR_RESET HBLU"HBLU ");
    printf(COLOR_RESET HMAG"HMAG ");
    printf(COLOR_RESET HCYN"HCYN ");
    printf(COLOR_RESET HWHT"HWHT ");
    puts("");
    printf(COLOR_RESET BHBLK"BHBLK");
    printf(COLOR_RESET BHRED"BHRED");
    printf(COLOR_RESET BHGRN"BHGRN");
    printf(COLOR_RESET BHYEL"BHYEL");
    printf(COLOR_RESET BHBLU"BHBLU");
    printf(COLOR_RESET BHMAG"BHMAG");
    printf(COLOR_RESET BHCYN"BHCYN");
    printf(COLOR_RESET BHWHT"BHWHT");
    puts("");
    printf(COLOR_RESET"");
}