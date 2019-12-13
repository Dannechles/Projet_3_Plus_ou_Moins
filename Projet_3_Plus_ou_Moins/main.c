#include <stdio.h>
#include <stdlib.h>
#include <time.h> //une fonction de cette bibliothèque permet d'avoir des nombres aléatoires


/* 1- la fonction 'sousMenuNiveau' permet à l'utilisateur de choisir le niveau de jeu.
Elle retourne le choix de l'utilisateur dans la variable 'niveauchoisi'.*/

int sousMenuNiveau()
{
    int niveauchoisi;
    do{
        printf("\n\n     Niveau 1 : 1 - 100 \n");
        printf("     Niveau 2 : 1 - 1000 \n");
        printf("     Niveau 3 : 1 - 10000 \n\n");

        printf("Entrez le Niveau de difficulte que vous desirez: ");
        scanf("%d", &niveauchoisi);
      }while(niveauchoisi < 1 || niveauchoisi > 3); //Tant que l'utilisateur ne suit pas le menu, il reprend.

   return niveauchoisi;
}

/* 2- la fonction 'jeu1Joueur' permettra de gérer tout le processus de jeu d'un joueur.
Comme c'est seulement les bornes qui varient par rapport aux niveaux de difficulté, elle reçoit en entrée
 la borne inférieure et la borne supérieure */

void jeu1Joueur(int min, int max)
{
    int nombreMystere=0, nombreEntre=0, coups=0;

    srand(time(NULL));
    nombreMystere=(rand()%(max - min + 1)) + min;

    //les lignes 31 et 32 permettent à l'ordinateur de faire le choix aléatoire d'un nombre entre le 'min' et le 'max'.

      do
        {
           coups++; //la variable 'coups' est incrémentée pour permettre de savoir en combien d'essai l'utilisateur a trouvé le nombre mystère.

           printf("\n Quel est le nombre Mystere ? ");
           scanf("%d", &nombreEntre);

           if(nombreMystere > nombreEntre)
              printf(" C'est plus !\n\n");

              else if (nombreMystere < nombreEntre)
                  printf(" C'est moins ! \n\n");

                        else
                        {
                            printf("\n\n       **********************************\n");
                            printf("       *****         EUREKA !       *****\n");
                            printf("       **********************************\n\n");
                            printf(" Vous avez trouve le nombre mystere en %d coups\n\n\n", coups);
                        }

        }while(nombreEntre != nombreMystere); //Tant que l'utilisateur trouve pas le nombre mystère les instructions reprennent
}

//3- Une fonction pour commencer une nouvelle partie

int nouvellePartie()
{
    int nouvellePartie;

    printf(" COMMENCER UNE NOUVELLE PARTIE ? \n");
    printf(" 1- OUI \n 2- NON \n\n Votre choix : ");
    scanf("%d", &nouvellePartie);

    return nouvellePartie;
}

/* 4- la fonction 'jeu2Joueurs' permettra de gérer tout le processus de jeu entre deux joueurs.
Le |Joueur 1| entrera un nombre que le |Joueur 2| va deviner. Vu que les bornes qui varient par rapport aux
 niveaux de difficulté, la fonction reçoit en entrée
 la borne inférieure et la borne supérieure du niveau*/

void jeu2joueurs(int min, int max)
{
    int nombreMystereJoueur1, nombreEntre, coups=0;

    printf("\n----- |Joueur 1| ----- \n");
    printf("Entrez un nombre Mystere compris entre %d et %d : ", min, max);
    scanf("%d", &nombreMystereJoueur1);

    system("cls"); //cette ligne permet d'effacer la console pour éviter que le Joueur 2 ne voit le nombre entré par le Joueur 1.

    printf("\n\n----- |Joueur 2| ----- \n");
    do
    {
        coups++;
        printf("\n Quel est le nombre Mystere ? ");
        scanf("%d", &nombreEntre);

        if(nombreMystereJoueur1 > nombreEntre)
            printf(" C'est plus !\n\n");

                else if (nombreMystereJoueur1 < nombreEntre)
                    printf(" C'est moins ! \n\n");

                        else
                        {
                            printf("\n\n       **********************************\n");
                            printf("       *****         EUREKA !       *****\n");
                            printf("       **********************************\n\n");
                            printf("Vous avez trouve le nombre mystere en %d coups\n\n\n", coups);
                        }
    }while(nombreEntre != nombreMystereJoueur1);
}




int main()
{
    //le  Titre du projet

    printf("************************************************************************\n");
    printf("*                                                                      *\n");
    printf("*                              PLUS OU MOINS                           *\n");
    printf("*                                                                      *\n");
    printf("************************************************************************\n\n");


    int choix1; // la variable 'choix1' permettra de recevoir le choix de l'utilisateur au niveau du Menu principal


  do{
        //le MENU principal

        printf("---------------------------------| MENU |-------------------------------\n");
        printf("     1 - Jouer\n");
        printf("     2 - Regle du jeu\n");
        printf("     3 - Plus grand score\n");
        printf("     0 - Quitter\n");
        printf("------------------------------------------------------------------------\n\n");


        printf("Votre Choix: ");
        scanf("%d", &choix1);
    }while(choix1 < 0 || choix1 >3);
    //Cette boucle (do...while) est créée pour forcer l'utilisateur a suivre le MENU; au cas contraire il recommence.

        switch(choix1)
        {
          int nombreJoueur, retourjoueur, retourRegles;

           case 1:

            do{
               do{
                  do{
                      //le sous-menu 'NOMBRE DE JOUEUR' pour choisir le nombre de joueur qui sera affecté à la variable 'nombreJoueur'.

                      printf("\n     NOMBRE DE JOUEUR \n\n");
                      printf("          1 joueur\n");
                      printf("          2 joueurs\n");

                      printf("Entrez nombre de Joueur(s): ");
                      scanf("%d", &nombreJoueur);
                    }while(nombreJoueur < 1 || nombreJoueur > 2);

                        switch(nombreJoueur)
                        {
                        //les cas du sous-Menu Nombre de joueur.

                          case 1: //cas d'un seul joueur.
                          {
                              do{
                                   switch(sousMenuNiveau())
                                   {
                                     case 1:
                                       jeu1Joueur(1,100);
                                       break;
                                     case 2:
                                       jeu1Joueur(1,1000);
                                       break;
                                     case 3:
                                       jeu1Joueur(1,10000);
                                       break;
                                   }
                                }while(nouvellePartie()==1);
                          }
                           break;



                           case 2: //Cas de deux joeurs.
                           {
                              do{
                                    switch(sousMenuNiveau())
                                    {
                                        case 1:
                                            jeu2joueurs(1,100);
                                          break;
                                        case 2:
                                            jeu2joueurs(1,1000);
                                          break;
                                        case 3:
                                            jeu2joueurs(1,10000);
                                          break;

                                    }
                             }while(nouvellePartie()==1);
                           }
                           break;
                        }


                    printf(" REPARTIR AU MENU NOMBRE DE JOUEURS ? \n");
                    printf(" 1- OUI \n 2- NON \n\n Votre choix : ");
                    scanf("%d", &retourjoueur);
                 }while(retourjoueur == 1);

                /*On donne avec les lignes 208, 209 et 210, la possibilité à l'utilisateur de repartir au menu 'NOMBRE DE JOUEURS' pour
                recommencer le jeu*/

               break;



                case 2: //les règles de Jeu, et l'utilisateur après la lecture a la possibilité de repartir au menu 'NOMBRE DE JOUEURS'.
                {
                   printf("\n\n   Le but du jeu est de deviner le plus vite possible un nombre mystere\n");
                   printf("   tire au hasard par le jeu ou defini par l'adversaire. Ce nombre est\n");
                   printf("   compris dans un intervalle correspondant au niveau de difficulte\n");
                   printf("   choisi par le(s) joueur(s):\n\n");
                   printf("       * Facile:    1 - 100 \n");
                   printf("       * Moyen:     1 - 1000 \n");
                   printf("       * Difficile: 1 - 10000 \n\n");
                   printf("    A chaque essai on vous notifie si le <<nombre Mystere>> est\n");
                   printf("   superieur au nombre entre par : << C'est Plus ! >> ou s'il est \n");
                   printf("   inferieur au nombre entre par : << C'est moins ! >> \n\n");
                   printf("                        ### Bonne Chance ### \n");


                   printf(" Voulez-vous jouer ? \n");
                   printf(" 1- OUI \n 2- NON \n");
                   printf("Votre choix : ");
                   scanf("%d", &retourRegles);
                }
              }while(retourRegles == 1);
             break;

            case 3: //cas du plus grand score.
               break;

            case 0:
               break;



         }

   return 0;
}
