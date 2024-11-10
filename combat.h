//
// Created by nicol on 25/10/2024.
//

#ifndef COMBAT_H
#define COMBAT_H



void printLayer1(){                // ENEMY STATUS
    printf("                                                      \n");    // fighting window is 54 characters long
    printf("                                                      \n");
    printf("                    -<placeholder>                    \n");    // damage and heal values will be displayed on this row
    printf("                                                      \n");    
};

void printLayer2(){                      // ENEMY GRAPHICS
    printf("                                                      \n");
    printf("                                                      \n");
    printf(BHRED"                P L A C E H O L D E R                 \n"COLOR_RESET);
    printf("                                                      \n");
    printf("                                                      \n");
};

void printLayer3(){                // ACTIVE PARTY STATS
    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity ==1)
        {
            printf("   [");
            printf(BHGRN"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==2)
        {
            printf("   [");
            printf(BHCYN"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==3)
        {
            printf("   [");
            printf(BHMAG"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity ==4)
        {
            printf("   [");
            printf(BHYEL"%s"CRESET, party[i].name);
            printf("]         ");
        }else if(party[i].rarity == 5)
        {
            printf("   [");
            printf(BHRED"%s"CRESET, party[i].name);
            printf("]        ");
        }else
        {
            printf(BHBLU"   <Empty>     "CRESET);
        }
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("HP:   %3d      ",n_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==2)
            printf("HP:   %3d      ",r_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==3)
            printf("HP:   %3d      ",sr_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==4)
            printf("HP:   %3d      ",ssr_Stats[party[i].position].stats.hp);
        else if(party[i].rarity==5)
            printf("HP:   %3d      ",ur_Stats[party[i].position].stats.hp);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("ATK:  %3d      ",n_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==2)
            printf("ATK:  %3d      ",r_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==3)
            printf("ATK:  %3d      ",sr_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==4)
            printf("ATK:  %3d      ",ssr_Stats[party[i].position].stats.atk);
        else if(party[i].rarity==5)
            printf("ATK:  %3d      ",ur_Stats[party[i].position].stats.atk);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("RES:  %3d      ",n_Stats[party[i].position].stats.res);
        else if(party[i].rarity==2)
            printf("RES:  %3d      ",r_Stats[party[i].position].stats.res);
        else if(party[i].rarity==3)
            printf("RES:  %3d      ",sr_Stats[party[i].position].stats.res);
        else if(party[i].rarity==4)
            printf("RES:  %3d      ",ssr_Stats[party[i].position].stats.res);
        else if(party[i].rarity==5)
            printf("RES:  %3d      ",ur_Stats[party[i].position].stats.res);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("DEX:  %3d      ",n_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==2)
            printf("DEX:  %3d      ",r_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==3)
            printf("DEX:  %3d      ",sr_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==4)
            printf("DEX:  %3d      ",ssr_Stats[party[i].position].stats.dex);
        else if(party[i].rarity==5)
            printf("DEX:  %3d      ",ur_Stats[party[i].position].stats.dex);
    }
    puts("");

    for (int i = 0; i < 4; i++)
    {
        if(party[i].rarity==1)
            printf("SPD:  %3d      ",n_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==2)
            printf("SPD:  %3d      ",r_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==3)
            printf("SPD:  %3d      ",sr_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==4)
            printf("SPD:  %3d      ",ssr_Stats[party[i].position].stats.spd);
        else if(party[i].rarity==5)
            printf("SPD:  %3d      ",ur_Stats[party[i].position].stats.spd);
    }
    puts("\n");
};

void printLayer4(){              // STATUS MESSAGES AND INPUTS
    printf("o----------------------------------------------------o\n");
    printf("|  A-ATTACK   S-SKILL   D-DEFEND   E-ESCAPE          |\n");
    printf("|  protoype of status messages max 2 rows supported  |\n");
    printf("o----------------------------------------------------o\n");
};

void combat()
{
    int partyHP[4],partyATK[4],partyRES[4],partyDEX[4],partySPD[4]; // arrays to store modifiable values
    int enemyHP,enemyATK,enemyRES,enemyDEX,enemySPD;
    printf("combat test\n\nPLACEHOLDER\n");
    for (int i = 0; i < 4; i++)   // filling of previous array
    {
        if(party[i].rarity ==1)
        {
            partyHP[i]=n_Stats[party[i].position].stats.hp;
            partyATK[i]=n_Stats[party[i].position].stats.atk;
            partyRES[i]=n_Stats[party[i].position].stats.res;
            partyDEX[i]=n_Stats[party[i].position].stats.dex;
            partySPD[i]=n_Stats[party[i].position].stats.spd;
        }else if(party[i].rarity ==2)
        {
            partyHP[i]=r_Stats[party[i].position].stats.hp;
            partyATK[i]=r_Stats[party[i].position].stats.atk;
            partyRES[i]=r_Stats[party[i].position].stats.res;
            partyDEX[i]=r_Stats[party[i].position].stats.dex;
            partySPD[i]=r_Stats[party[i].position].stats.spd;
        }else if(party[i].rarity ==3)
        {
            partyHP[i]=sr_Stats[party[i].position].stats.hp;
            partyATK[i]=sr_Stats[party[i].position].stats.atk;
            partyRES[i]=sr_Stats[party[i].position].stats.res;
            partyDEX[i]=sr_Stats[party[i].position].stats.dex;
            partySPD[i]=sr_Stats[party[i].position].stats.spd;
        }else if(party[i].rarity ==4)
        {
            partyHP[i]=ssr_Stats[party[i].position].stats.hp;
            partyATK[i]=ssr_Stats[party[i].position].stats.atk;
            partyRES[i]=ssr_Stats[party[i].position].stats.res;
            partyDEX[i]=ssr_Stats[party[i].position].stats.dex;
            partySPD[i]=ssr_Stats[party[i].position].stats.spd;
        }else if(party[i].rarity == 5)
        {
            partyHP[i]=ur_Stats[party[i].position].stats.hp;
            partyATK[i]=ur_Stats[party[i].position].stats.atk;
            partyRES[i]=ur_Stats[party[i].position].stats.res;
            partyDEX[i]=ur_Stats[party[i].position].stats.dex;
            partySPD[i]=ur_Stats[party[i].position].stats.spd;
        }
    }
    printLayer1();
    printLayer2();
    printLayer3();
    printLayer4();
    system("pause");
}



#endif //COMBAT_H
