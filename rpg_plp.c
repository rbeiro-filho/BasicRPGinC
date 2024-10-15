/*
O Paradigma Imperativo Procedural é um paradigma de programação que se 
baseia na execução de comandos sequenciais, que são executados
um após o outro. O programa é composto por funções que são chamadas
em sequência, e cada função é composta por comandos que são executados
em sequência. 

As principais características do paradigma imperativo procedural são:

Procedimentos: o programa é composto por funções que são chamadas em sequência.
Controla o fluxo de execução: o programador controla o fluxo de execução do programa.
Mudança de estado: o programa altera o estado dos dados conforme as instruções são executadas.

Neste codigo, com o meio de comentarios, iremos monstrar onde cada uma das caracteristicas
do paradigma imperativo procedural se encontra no codigo.

*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

// CODE STRUCTURES

typedef struct Character{
    char name[20];
    char body1[20];
    char body2[20];
    char body3[20];
    char class[10];
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int dexterity; 
} Character;

typedef struct Enemy {
    char type[10];
    char body1[20];
    char body2[20];
    char body3[20];
    int health;
    int stamina;           
    int attack;              
    int defense;            
    int dexterity;
} Enemy;
// --------------------------------------------------------------
// VISUAL FUNCTIONS

void NameScreen(void);
void Menu(void);
void MainScreen(void);
void KMS(void);
void SMS(void);
void AMS(void);
void BattleLayout(Character* P, Enemy* E, char *texto);
void BattleLayout (Character* P, Enemy* E, char *texto);
void ClearScreen(void);
void PauseScreen(void);
// --------------------------------------------------------------
// CHARACTER FUNCTIONS

void Knight(Character* P);
void Assassin(Character* P);
void Archer(Character* P);
// --------------------------------------------------------------
// ENEMY FUNCTIONS

void Looter(Enemy *E);
void Hunter(Enemy *E);
void Murder(Enemy *E);
// --------------------------------------------------------------
// COMBAT FUNCTIONS

int Surprise(int Dice, int PlayerDexterity, int EnemyDexterity);
int Initiative(int PlayerDexterity, int EnemyDexterity);
int Attack(int AttackerPoints, int DefensorPoints, int Dice);
void IncreaseDefense(Character *P);
void LowerDefense(Enemy *E);
// --------------------------------------------------------------
// AUXILIAR FUNCTIONS

int D20(int i);


// --------------------------------------------------------------

int main(void) {
    ClearScreen();
    int control = 0;
    char select = 'Z';
    Character C;
    system("chcp 65001 > nul");

    

    // Choose the player name
    do{
        NameScreen();
        scanf(" %19[^\n]", C.name);
        printf("\n\t\t\t\t\t    Are you sure? [Y/N] ");
        select = toupper(getch()); fflush(stdin);
        ClearScreen();
    }while(select != 'Y');
    // Entering Forgotten Land
    Menu();
    sleep(5);
    // Class selection
    do{
        ClearScreen();
        MainScreen();
        select = getch(); fflush(stdin);
        ClearScreen();
        switch(toupper(select)){
            case 'K':
                Knight(&C);
                KMS();
                printf("\n\t\t\t\t\tYou've choosen Knight\n");
                control = 1;
                break;
            case 'S':
                Assassin(&C);
                SMS();
                printf("\n\t\t\t\t\tYou've choosen Assassin\n");
                control = 1;
                break;
            case 'A':
                Archer(&C);
                AMS();
                printf("\n\t\t\t\t\tYou've choosen Archer\n");
                control = 1;
                break;
            default:
                printf("\n\t\t\t\t\tNot a valid option\n");
                break;
        }
        PauseScreen();
    }while(control != 1);

    // Battle Looters
    char texto[50];
    Enemy E;

    ClearScreen();
    Looter(&E);
    strcpy(texto, "You've found a Looter");
    BattleLayout(&C, &E, texto);
    sleep(5);

    char action[100] = "1- Attack                                                  2- Defend\n";
    int damage;
        
    
    do{
        ClearScreen();
        strcpy(texto, "Choose your action");
        BattleLayout(&C, &E, texto);
        printf("%s\n", action);

        select = getch(); fflush(stdin);

        switch(select){
            case '1':
                if(Initiative(C.dexterity, E.dexterity)){
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(E.health <= 0)
                        break;
                    
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }else{
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(C.health <= 0)
                        break;
                    
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }
                
                break;
            case '2':
                IncreaseDefense(&C);
                sprintf (texto, "Your defense has increased");
                BattleLayout(&C, &E, texto);
                sleep(3);
                ClearScreen();

                damage = Attack(E.attack, C.defense, D20(2));
                C.health -= damage;
                sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                BattleLayout(&C, &E, texto);
                sleep(3);
                ClearScreen();
                break;
            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }

    }while(C.health > 0 && E.health > 0);

    strcpy(texto, "You won the battle");
    BattleLayout(&C, &E, texto);
    sleep(5);

    // Battle Hunter
    ClearScreen();
    Hunter(&E);
    strcpy(texto, "You've found a Hunter");
    BattleLayout(&C, &E, texto);
    sleep(5);

    do{
        ClearScreen();
        strcpy(texto, "Choose your action");
        BattleLayout(&C, &E, texto);
        printf("%s\n", action);
        select = getch(); fflush(stdin);
        switch(select){
            case '1':
                if(Initiative(C.dexterity, E.dexterity)){
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(E.health <= 0)
                        break;
                    
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }else{
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(C.health <= 0)
                        break;
                    
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }
                break;
            case '2':
                IncreaseDefense(&C);
                sprintf (texto, "Your defense has increased");
                BattleLayout(&C, &E, texto);
                sleep(3);
                ClearScreen();

                damage = Attack(E.attack, C.defense, D20(2));
                C.health -= damage;
                sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                BattleLayout(&C, &E, texto);
                sleep(3);
                ClearScreen();
                break;

            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }
        PauseScreen();

    }while(C.health > 0 && E.health > 0);

    strcpy(texto, "You won the battle");
    BattleLayout(&C, &E, texto);
    sleep(5);

    // Battle Murder
    ClearScreen();
    Murder(&E);
    strcpy(texto, "You've found a Hunter");
    BattleLayout(&C, &E, texto);
    sleep(5);

    do{
        ClearScreen();
        strcpy(texto, "Choose your action");
        BattleLayout(&C, &E, texto);
        printf("%s\n", action);
        select = getch(); fflush(stdin);
        switch(select){
            case '1':
                if(Initiative(C.dexterity, E.dexterity)){
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(E.health <= 0)
                        break;
                    
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }else{
                    damage = Attack(E.attack, C.defense, D20(2));
                    C.health -= damage;
                    sprintf (texto, "The %s attacked you, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                    ClearScreen();
                    if(C.health <= 0)
                        break;
                    
                    damage = Attack(C.attack, E.defense, D20(1));
                    E.health -= damage;
                    sprintf (texto, "You've attacked the %s, %d damage caused", E.type, damage);
                    BattleLayout(&C, &E, texto);
                    sleep(3);
                }
                break;
            case '2':
                IncreaseDefense(&C);
                sprintf (texto, "Your defense has increased");
                BattleLayout(&C, &E, texto);
                sleep(3);
                ClearScreen();
                break;
            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }
        PauseScreen();
    }while(C.health > 0 && E.health > 0);

    strcpy(texto, "You won the battle");
    BattleLayout(&C, &E, texto);
    sleep(5);


    return 0;
}
// --------------------------------------------------------------
// VISUAL FUNCTIONS PREVIEW

// Name screen
void NameScreen(void) {
    printf("\t\t\t\t\t\tYou bastard!!!\n");
    printf("\t\t\tYou must identify yourself before you entering this land\n\n\t\t\t\t\t\t");
}
// Game menu
void Menu(void) {
    printf("\t\t\t\t\tWelcome to Forgotten Land\n\n");
    printf("\t\t\t\t   The fate of this land depends on you\n");
    printf("\t\t\t\t    We wish you lucky! You'll need it!\n");
}
// Prints the home screen
void MainScreen(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0         | Archer               0         |\n" );
    printf("|                   U/ | \\P      |                   i/ | \\i      |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Dexterity                   20 | Dexterity                   65 | Dexterity                   80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Knight choosen home screen 
void KMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0 /P      | Assassin             0         | Archer               0         |\n" );
    printf("|                   U/ |         |                   i/ | \\i      |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Dexterity                   20 | Dexterity                   65 | Dexterity                   80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Assassin choosen home screen
void SMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0 /i      | Archer               0         |\n" );
    printf("|                   U/ | \\P      |                   i/ |         |                   |/ | \\D      |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Dexterity                   20 | Dexterity                   65 | Dexterity                   80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
// Prints the Archer choosen home screen
void AMS(void) {
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Knight               0         | Assassin             0         | Archer               0 /D      |\n" );
    printf("|                   U/ | \\P      |                   i/ | \\i      |                   |/ |         |\n" );
    printf("| Health              / \\     65 | Health              / \\     35 | Health              / \\     35 |\n" );
    printf("| Stamina                     35 | Stamina                     50 | Stamina                     50 |\n" );
    printf("| Attack                      50 | Attack                      80 | Attack                      50 |\n" );
    printf("| Defense                     80 | Defense                     35 | Defense                     20 |\n" );
    printf("| Dexterity                   20 | Dexterity                   65 | Dexterity                   80 |\n" );
    printf("|--------------------------------|--------------------------------|--------------------------------|\n" );
    printf("| Type K to choose Knight        | Type S to choose Assassin      | Type A to choose Archer        |\n" );
}
//Battle Layout
void BattleLayout (Character* P, Enemy* E, char *texto) {
    printf("                                Combat                                \n");
    printf("| %-8s                        VS                       %8s |\n", P->class, E->type);
    printf("|-------------------------------------------------------------------|\n" );
    printf("| Health: %3d                                           Health: %3d |\n", P->health, E->health);
    printf("|                                                                   |\n");
    printf("|          %s                              %s             |\n", P->body1, E->body1);
    printf("|          %s                              %s             |\n", P->body2, E->body2);
    printf("|          %s                              %s             |\n", P->body3, E->body3); 
    printf("|                                                                   |\n");
    printf("| Stamina: %3d                                         Stamina: %3d |\n", P->stamina, E->stamina);
    printf("|-------------------------------------------------------------------|\n" );
    printf("|                                                                   |\n");
    printf("|%-67s|\n", texto);
    printf("|                                                                   |\n");
    printf("|-------------------------------------------------------------------|\n" );
}
// Clear terminal
void ClearScreen(void) {
    system("cls");
}
// Pause terminal
void PauseScreen(void) {
    printf("Press any key to continue...");
    getchar();
}
// --------------------------------------------------------------
// CHARACTER FUNCTIONS PREVIEW

// Gives the knight attributes
void Knight(Character *P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "U/ | \\P");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Knight");
    P->health = 100;
    P->stamina = 35;
    P->attack = 50;
    P->defense = 80;  
    P->dexterity = 20;
}
// Gives the assassin attributes
void Assassin(Character *P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "i/ | \\i");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Assassin");
    P->health = 100;
    P->stamina = 50;
    P->attack = 80;
    P->defense = 35;
    P->dexterity = 65;
}
// Gives the archer attributes
void Archer(Character *P) {
    strcpy(P->body1, "   O   ");
    strcpy(P->body2, "|/ | \\D");
    strcpy(P->body3, "  / \\  ");
    strcpy(P->class, "Archer");
    P->health = 100;
    P->stamina = 50;
    P->attack = 50;
    P->defense = 20;
    P->dexterity = 80;
}

// --------------------------------------------------------------
// ENEMY FUNCTIONS PREVIEW

// Gives the Looter attributes
void Looter(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, " / | \\i");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Looter");
    E->health = 100;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 18;
    E->dexterity = 72;
}
// Gives the Hunter attributes
void Hunter(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, " / | \\D");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Hunter");
    E->health = 100;
    E->stamina = 60;
    E->attack = 45;
    E->defense = 33;
    E->dexterity = 60;
}
// Gives the Murder attributes
void Murder(Enemy *E) {
    strcpy(E->body1, "   O   ");
    strcpy(E->body2, "l/ | \\l");
    strcpy(E->body3, "  / \\  ");
    strcpy(E->type,"Murder");
    E->health = 100;
    E->stamina = 33;
    E->attack = 60;
    E->defense = 45;
    E->dexterity = 45;
}
// --------------------------------------------------------------
// COMBAT FUNCTIONS PREVIEW

// Returns if enemy was caught by surprise (0/1)
// First attack before battle
int Surprise(int Dice, int PlayerDexterity, int EnemyDexterity) {
    return (Dice >= 15 && PlayerDexterity >= EnemyDexterity);
}
// Returns if player attacks first
// Determines the order of turns during combat
int Initiative(int PlayerDexterity, int EnemyDexterity) {
    return (PlayerDexterity >= EnemyDexterity);
}
// Returns the damage caused by the attack
int Attack(int AttackerPoints, int DefensorPoints, int Dice) {
    int Damage = (AttackerPoints * (Dice/20.0)) - (AttackerPoints * (DefensorPoints/100.0));

    if(Damage > 0)
        return Damage;
    else
        return 0;
}
// Increase the defense of the attacker
void IncreaseDefense(Character *P) {
    P->defense += 10;
}
// Decrease the defense of the enemy 
void LowerDefense(Enemy *E) {
    E->defense -= 10;
}
// --------------------------------------------------------------
// AUXILIAR FUNCTIONS PREVIEW

// Returns a value positive for the amount of results of the dice
int D20(int i) {
    int random_number;
    // Starts the seed using the clock
    srand(time(NULL)+i);
    random_number = rand() % 21;
    return random_number;
}
