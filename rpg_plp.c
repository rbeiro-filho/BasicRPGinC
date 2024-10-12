#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


// CODE STRUCTURES

typedef struct Character{
    char name[20];
    int class;             
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int speed;    
} Character;
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

void Menu(void);
void ClearScreen(void);
void PauseScreen(void);
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

void Knight(Character* P);
void Assassin(Character* P);
void Archer(Character* P);
// --------------------------------------------------------------

void TelaInicial(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassino            0         | Archer               0         |\n" );
    printf("|                   O/ | \\!      |                    / | \\i      |                    / | \\D      |\n" );
    printf("| Vida                / \\     10 | Vida                / \\      6 | Vida                / \\      6 |\n" );
    printf("| Estamina                     5 | Estamina                     8 | Estamina                     5 |\n" );
    printf("| Ataque                       3 | Ataque                       5 | Ataque                       3 |\n" );
    printf("| Defesa                       5 | Defesa                       2 | Defesa                       1 |\n" );
    printf("| Velocidade                   1 | Velocidade                   4 | Velocidade                   5 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Digete 1 para escolher Knight  | Digete 2 para escolher o Rogue | Digete 3 para escolher o Archer|\n" );

}
    

int main(void) {
    char select;
    int n = 0;
    Character P;

    do{
        ClearScreen();
        printf("\t\t\t\t\tBem vindo ao RPG\n");
        printf("\n");
        TelaInicial();
        printf("\nEscolha seu personagem: ");
        scanf("%c", &select); fflush(stdin);

        select = toupper(select);
        switch(select){
            case '1':
                Knight(&P);
                printf("Voce escolheu Knight\n");
                break;
            case '2':
                Rogue(&P);
                printf("Voce escolheu Rogue\n");
                break;
            case '3':
                Archer(&P);
                printf("Voce escolheu Archer\n");
                break;
            default:
                printf("Opcao invalida\n");
                PauseScreen();

                continue;
                break;
        }

        n = 1;
    }while(n != 1);

    return 0;
}
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

// Game menu
void Menu(void) {

}
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    system("pause");
}
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

// Gives the knight attributes
void Knight(Character* P) {
    P->class = 1;
    P->health = 65;
    P->stamina = 35;
    P->attack = 50;
    P->defense = 80;  
    P->speed = 20;
}
// Gives the assassin attributes
void Assassin(Character* P) {
    P->class = 2;
    P->health = 35;
    P->stamina = 50;
    P->attack = 80;
    P->defense = 35;
    P->speed = 65;
}
// Gives the archer attributes
void Archer(Character* P) {
    P->class = 3;
    P->health = 35;
    P->stamina = 50;
    P->attack = 50;
    P->defense = 20;
    P->speed = 80;
}

void TelaInicial(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassino            0         | Archer               0         |\n" );
    printf("|                   Ü/ | \P      |                   i/ | \i      |                   |/ | \D      |\n" );
    printf("| Vida                / \     10 | Vida                / \      6 | Vida                / \      6 |\n" );
    printf("| Estamina                     5 | Estamina                     8 | Estamina                     5 |\n" );
    printf("| Ataque                       3 | Ataque                       5 | Ataque                       3 |\n" );
    printf("| Defesa                       5 | Defesa                       2 | Defesa                       1 |\n" );
    printf("| Velocidade                   1 | Velocidade                   4 | Velocidade                   5 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Digete K para escolher Knight  | Digete R para escolher o Rogue | Digete A para escolher o Archer|\n" );
}