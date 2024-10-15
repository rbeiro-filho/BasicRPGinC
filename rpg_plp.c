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

// Definição de estruturas de dados, utilizadas para armazenar o estado do jogo.
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

// Procedimentos: as funções são definidas aqui para realizar ações específicas no programa.

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

// Funções para modificar o estado dos personagens e inimigos.
void Knight(Character* P);
void Assassin(Character* P);
void Archer(Character* P);


void Looter(Enemy *E);
void Hunter(Enemy *E);
void Murder(Enemy *E);

int Surprise(int Dice, int PlayerDexterity, int EnemyDexterity);
int Initiative(int PlayerDexterity, int EnemyDexterity);
int Attack(int AttackerPoints, int DefensorPoints, int Dice);
void IncreaseDefense(Character *P);
void LowerDefense(Enemy *E);

int D20(int i);

//-----------------------------------------------------------

int main(void) {
    // Mudança de estado: a variável 'control' e 'select' são usadas para controlar o estado do jogo.
    start:
    ClearScreen();
    int control = 0;
    char select = 'Z';
    Character C;
    system("chcp 65001 > nul");


    // Controle de fluxo: a estrutura 'do-while' controla a execução repetitiva até que o jogador confirme.
    do{
        NameScreen();
        scanf(" %19[^\n]", C.name);
        printf("\n\t\t\t\t\t    Are you sure? [Y/N] ");
        select = toupper(getch()); fflush(stdin);
        ClearScreen();
    }while(select != 'Y');

    // Procedimentos: chamada de função para exibir o menu do jogo.
    Menu();
    sleep(5);
    
    // Controle de fluxo: a estrutura 'do-while' controla a execução repetitiva até que o jogador escolha uma classe.
    do{
        ClearScreen();
        MainScreen();
        select = getch(); fflush(stdin);
        ClearScreen();
        // Controle de fluxo: a estrutura 'switch' controla a execução do programa de acordo com a escolha do jogador.
        switch(toupper(select)){
            case 'K':
                Knight(&C); // Mudança de estado: a função 'Knight' é chamada para modificar o estado do personagem.
                KMS();
                printf("\n\t\t\t\t\tYou've choosen Knight\n");
                control = 1; // Mudança de estado: a variável 'control' é alterada para 1 para sair do loop.
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

    // Mudança de estado: inicialização de variáveis para o combate.
    char texto[50];
    Enemy E;
    ClearScreen();
    Looter(&E);
    strcpy(texto, "You've found a Looter");
    BattleLayout(&C, &E, texto);
    sleep(5);

    char action[100] = "1- Attack                                                  2- Defend\n";
    int damage;
        
    // Controle de fluxo: a estrutura 'do-while' controla a execução repetitiva do combate.
    do{
        ClearScreen();
        strcpy(texto, "Choose your action");
        BattleLayout(&C, &E, texto); // Procedimentos: chamada de função para exibir o layout do combate.
        printf("%s\n", action);

        select = getch(); fflush(stdin);
        ClearScreen();
        switch(select){
            case '1':
            // Controle de fluxo: a estrutura 'if-else' controla a execução do combate de acordo com a iniciativa.
                if(Initiative(C.dexterity, E.dexterity)){ 
                    // Mudança de estado: a função 'Attack' é chamada para calcular o dano causado.
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

                break;
            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }
        PauseScreen();
    }while(C.health > 0 && E.health > 0);

    if(C.health <= 0){
        strcpy(texto, "You lost the battle");
        BattleLayout(&C, &E, texto);
        sleep(5);
        goto start;
    }else{
        strcpy(texto, "You won the battle");
        BattleLayout(&C, &E, texto);
        sleep(5);
    }


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
        ClearScreen();
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

                break;

            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }
        PauseScreen();

    }while(C.health > 0 && E.health > 0);

    if(C.health <= 0){
        strcpy(texto, "You lost the battle");
        BattleLayout(&C, &E, texto);
        sleep(5);
        goto start;
    }else{
        strcpy(texto, "You won the battle");
        BattleLayout(&C, &E, texto);
        sleep(5);
    }

    test:
    ClearScreen();
    Murder(&E);
    strcpy(texto, "You've found a Murder");
    BattleLayout(&C, &E, texto);
    sleep(5);
    do{
        ClearScreen();
        strcpy(texto, "Choose your action");
        BattleLayout(&C, &E, texto);
        printf("%s\n", action);
        select = getch(); fflush(stdin);
        ClearScreen();
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
                break;
            default:
                strcpy(texto, "Not a valid option");
                BattleLayout(&C, &E, texto);
                break;
        }
        PauseScreen();
    }while(C.health > 0 && E.health > 0);

    if(C.health <= 0){
        strcpy(texto, "You lost the battle");
        BattleLayout(&C, &E, texto);
        sleep(5);
        goto start;
    }else{
        printf("\n\t\t\t\t\t\tYou've won the game\n");
        sleep(5);
    }




    


    strcpy(texto, "You won the battle");
    BattleLayout(&C, &E, texto);
    sleep(5);



    return 0;
}

void NameScreen(void) {
    printf("\t\t\t\t\t\tYou bastard!!!\n");
    printf("\t\t\tYou must identify yourself before you entering this land\n\n\t\t\t\t\t\t");
}

void Menu(void) {
    printf("\t\t\t\t\tWelcome to Forgotten Land\n\n");
    printf("\t\t\t\t   The fate of this land depends on you\n");
    printf("\t\t\t\t    We wish you lucky! You'll need it!\n");
}

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

void ClearScreen(void) {
    system("cls");
}

void PauseScreen(void) {
    printf("Press any key to continue...");
    getchar();
}

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

int Surprise(int Dice, int PlayerDexterity, int EnemyDexterity) {
    return (Dice >= 15 && PlayerDexterity >= EnemyDexterity);
}

int Initiative(int PlayerDexterity, int EnemyDexterity) {
    return (PlayerDexterity >= EnemyDexterity);
}

int Attack(int AttackerPoints, int DefensorPoints, int Dice) {
    int Damage = (AttackerPoints * (Dice/20.0)) - (AttackerPoints * (DefensorPoints/100.0));

    if(Damage > 0)
        return Damage;
    else
        return 1;
}

void IncreaseDefense(Character *P) {
    P->defense += 10;
}

void LowerDefense(Enemy *E) {
    E->defense -= 10;
}

int D20(int i) {
    int random_number;

    srand(time(NULL)+i);
    random_number = rand() % 21;
    return random_number;
}
