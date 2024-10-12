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

void Knight(Character* P) {
    // P->class = 1;
    // //P->level;              
    // P->health;
    // P->stamina;             
    // //P->mana;               
    // P->attack;              
    // P->defense;            
    // P->speed;              
    // P->strength;           
    // P->intelligence;
    // Vida: 4
    // Estâmina: 2
    // Ataque: 3
    // Defesa: 5
    // Velocidade: 1
}
void Rogue(Character* P) {

// Vida: 2
// Estâmina: 3
// Ataque: 5
// Defesa: 2
// Velocidade: 4


}
void Archer(Character* P) {
// Vida: 2
// Estâmina: 3
// Ataque: 3
// Defesa: 1
// Velocidade: 5
}
void Wizard(Character* P) {

}
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
    printf("| Digete K para escolher Knight  | Digete R para escolher o Rogue | Digete A para escolher o Archer|\n" );

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
        scanf("%c", &select);

        select = toupper(select);
        switch(select){
            case 'K':
                Knight(&P);
                printf("Voce escolheu Knight\n");
                break;
            case 'R':
                Rogue(&P);
                printf("Voce escolheu Rogue\n");
                break;
            case 'A':
                Archer(&P);
                printf("Voce escolheu Archer\n");
                break;
            default:
                printf("Opcao inválida\n");
                break;
        }

        n = 1;
    }while(n != 1);

    return 0;
}

// --------------------------------------------------------------

// Game menu
void Menu(void) {

}
// 
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    getchar();
    getchar();
}
// 