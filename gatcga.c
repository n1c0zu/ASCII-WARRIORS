//
// Created by nicol on 21/10/2024.
//

#include <stdbool.h>  // Libreria per il tipo bool
#include <stdio.h>    // Libreria standard di input/output
#include <stdlib.h>   // Libreria per funzioni standard come malloc, rand e system
#include <time.h>     // Libreria per funzioni sul tempo, usata per srand
#include <conio.h>    // Libreria per funzioni di input/output su console
#include <unistd.h>   // Libreria per funzioni di controllo dei processi
#include <windows.h>  // Libreria per funzioni specifiche di Windows

#include "core.h"     // Include il file header core.h

int main()
{
    system("mode 125,40");   // Imposta modalità della console per non superare le dimensioni del buffer
    SMALL_RECT WinRect = {0, 0, 125, 40};   // Nuove dimensioni per la finestra in caratteri 8x12 pixel
    SMALL_RECT* WinSize = &WinRect;  // Puntatore a WinRect per SetConsoleWindowInfo
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   // Imposta le nuove dimensioni per la finestra

    /* Impostazione alternativa per la console
    system("mode con: cols=125 lines=40");
    COORD bufferSize;
    bufferSize.X = 125;
    bufferSize.Y = 40;
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    */

    srand(time(NULL));  // Seed per generare numeri casuali basato sull'ora corrente

    // Dichiarazione variabili
    char select;  // Variabile per input dell'utente
    char *rar[] = {"normal","rare","super-rare","super-super-rare","ultra-rare"};  // Array di livelli di rarità
    char menu = '1';  // Variabile per memorizzare la selezione del menu

    /* Esempio di come usare le statistiche
    printf("Number: %c, Atk: %d, Res: %d, Dex: %d, Spd: %d\n",
           n_Stats[0].number, n_Stats[0].stats.atk, n_Stats[0].stats.res,
           n_Stats[0].stats.dex, n_Stats[0].stats.spd);
    */

    put_in_fullscreen();  // Metti la finestra in modalità schermo intero

    while (true) // Loop infinito per il menu principale
    {
        system("cls");  // Pulisci la console

        menu_print();  // Stampa il menu
        scanf(" %c", &menu);  // Ottieni input dell'utente per la selezione del menu
        system("cls");  // Ripulisci la console per la schermata successiva

        switch(menu)  // Switch per gestire la selezione del menu
        {
            case '1':  // Caso per fare una singola estrazione
                if(money >= 10)  // Controlla se l'utente ha abbastanza denaro
                {
                    pull_x_times(1);  // Funzione per fare una singola estrazione
                    money -= 10;  // Diminuisci il denaro
                }
                else
                {
                    puts("no money");  // Informa l'utente che non ha abbastanza denaro
                }
                printf("\n");
                break;

            case '2':  // Caso per fare 10 estrazioni
                if(money >= 10 * 10)  // Controlla se l'utente ha abbastanza denaro per 10 estrazioni
                {
                    pull_x_times(10);  // Funzione per fare 10 estrazioni
                    money -= 10 * 10;  // Diminuisci il denaro
                }
                else
                {
                    puts("no money");  // Informa l'utente che non ha abbastanza denaro
                }
                printf("\n");
                break;

            case '3':  // Caso per fare un numero variabile di estrazioni
                if(money >= pull_times * 10)  // Controlla se l'utente ha abbastanza denaro per estrazioni
                {
                    pull_x_times(pull_times);  // Funzione per fare 'pull_times' estrazioni
                    money -= pull_times * 10;  // Diminuisci il denaro
                }
                else
                {
                    puts("no money");  // Informa l'utente che non ha abbastanza denaro
                }
                printf("\n");
                break;

            case '4':  // Caso per mostrare l'inventario
                inv_print();  // Stampa l'inventario
                break;

            case '5':  // Caso per aggiungere denaro
                money += 1000;  // Aumenta il denaro di 1000
                printf("\ntotal money: %d \n\n", money);  // Mostra il denaro totale
                puts("added 1000 money");
                break;

            case '6':  // Caso per salvare il gioco
                printf("Current save file: %s\n\n", current_save_file);  // Mostra il file di salvataggio attuale
                save_game();  // Salva il gioco
                break;

            case '7':  // Caso per caricare il gioco
                printf("Current save file: %s\n\n", current_save_file);  // Mostra il file di salvataggio attuale
                load_game();  // Carica il gioco
                break;

            case '8':  // Caso per uscire dal programma
                printf("Exiting...\n");
                exit(0);

            case '9':  // Caso per avviare la modalità combattimento
                first_startup = true;  // Imposta variabile di avvio
                combat();  // Avvia la funzione di combattimento
                break;

            default:  // Caso di opzione non valida
                printf("Invalid option. Please try again.\n");
        }

        system("pause");  // Pausa per input utente prima di continuare
    }

    return 0;
}
