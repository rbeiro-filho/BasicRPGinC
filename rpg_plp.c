#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


// CODE STRUCTURES

typedef struct Character{
    char name[20];
    char class[10];             
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
    printf("| Digete 1 para escolher Knight  | Digete 2 para escolher o Rogue | Digete 3 para escolher o Archer|\n" );

}

void TelaDeCombate(struct Character* P) {

    char ataque[10];
    char defesa[10];
    char habilidade[10];

    if(P->class == 1){
        strcpy(ataque, "Espada");
        strcpy(defesa, "Escudo");
        strcpy(habilidade, "Golpe de escudo");
    }else if(P->class == 2){
        strcpy(ataque, "Adaga");
        strcpy(defesa, "Esquiva");
        strcpy(habilidade, "Veneno");
    }else if(P->class == 3){
        strcpy(ataque, "Arco");
        strcpy(defesa, "Flecha");
        strcpy(habilidade, "Tiro rapido");
    }
    printf("|----------------------------------------------------------------|\n" );
    printf("| HP                                          HP                 |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|----------------------------------------------------------------|\n" );
    printf("| Digite 1 para atacar                                           |\n" );
    printf("| Digite 2 para defender                                         |\n" );
    printf("| Digite 3 para usar habilidade                                  |\n" );
    printf("|----------------------------------------------------------------|\n" );

    

    
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
                printf("Voce escolheu Assasino\n");
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

        // Combate
        ClearScreen();
        printf("\t\t\t   Combate\n");
        printf("|                                                         %s|\n", P.class, "Inimigo");
        TelaDeCombate(&P);
        PauseScreen();
        

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
    system("pause");
}
// 