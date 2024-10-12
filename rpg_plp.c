#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


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

void Knight(Character* P);
void Assassin(Character* P);
void Archer(Character* P);
// --------------------------------------------------------------

void TelaInicial(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassino            0         | Archer               0         |\n" );
    printf("|                   O/ | \\!      |                   i/ | \\i      |                    / | \\D      |\n" );
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
    char habilidade[20];
    char boneco[10];

    if(strcmp(P->class, "Knight") == 0){
        strcpy(ataque, "Espada");
        strcpy(defesa, "Escudo");
        strcpy(habilidade, "Golpe de escudo");
        strcpy(boneco, "O/ | \\!");
    }else if(strcmp(P->class, "Assassino") == 0){
        strcpy(ataque, "Adaga");
        strcpy(defesa, "Esquiva");
        strcpy(habilidade, "Veneno");
        strcpy(boneco, "i/ | \\i");
    }else if(strcmp(P->class, "Archer") == 0){
        strcpy(ataque, "Arco");
        strcpy(defesa, "Flecha");
        strcpy(habilidade, "Tiro rapido");
        strcpy(boneco, " / | \\D");
    }
    printf("|----------------------------------------------------------------|\n" );
    printf("| HP %3d                                      HP %3d             |\n", P->health, 100);
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|                                                                |\n" );
    printf("|     0                                                          |\n" );
    printf("|  %s                                                       |\n", boneco);
    printf("|    / \\                                                         |\n" );
    printf("|                                                                |\n" );
    printf("|----------------------------------------------------------------|\n" );
    printf("| Digite 1 para %-15s                                  |\n", ataque);
    printf("| Digite 2 para %-15s                                  |\n", defesa);
    printf("| Digite 3 para %-15s                                  |\n", habilidade);
    printf("|----------------------------------------------------------------|\n" );


    
}
    

int main(void) {
    char select;
    int n = 0;
    Character P;
    int acao;
    char modo[20] = "TelaInicial";

    do{
        ClearScreen();
        if(strcmp(modo, "TelaInicial") == 0){
            printf("\t\t\t\t\tBem vindo ao RPG\n");
            printf("\n");
            TelaInicial();
            printf("\nEscolha seu personagem: ");
            scanf("%c", &select); fflush(stdin);

            

            switch(select){
                case '1':
                    Knight(&P);
                    printf("Voce escolheu Knight\n");
                    break;
                case '2':
                    Assassin(&P);
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
        }else if(strcmp(modo, "Combate") == 0){
            ClearScreen();
            printf("\t\t\t   Combate\n");
            printf("|%-10s                                               %s|\n", P.class, "Inimigo");
            TelaDeCombate(&P);
            printf("Escolha sua acao: ");
            scanf("%d", &acao ); fflush(stdin);
            PauseScreen();
        }
             




    }while(n != 1);

    return 0;
}
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

// Limpa a tela
void ClearScreen(void) {
    system("cls");
}
// Pausa a tela
void PauseScreen(void) {
    system("pause");
}
// --------------------------------------------------------------
// USUAL FUNCTIONS PREVIEW

// Gives the knight attributes
void Knight(Character* P) {
    strcpy(P->class, "Knight");
    P->health = 65;
    P->stamina = 35;
    P->attack = 50;
    P->defense = 80;  
    P->speed = 20;
}
// Gives the assassin attributes
void Assassin(Character* P) {
    strcpy(P->class, "Assassino");
    P->health = 35;
    P->stamina = 50;
    P->attack = 80;
    P->defense = 35;
    P->speed = 65;
}
// Gives the archer attributes
void Archer(Character* P) {
    strcpy(P->class, "Archer");
    P->health = 35;
    P->stamina = 50;
    P->attack = 50;
    P->defense = 20;
    P->speed = 80;
}
