#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
int main() {
    printf("\033[1;31m\n\n\t\tMini-Projet : Systeme de Gestion de Stock dans une Librairie\n");

    // Déclaration des variables
    char titre[100][100];
    char auteur[100][100];
    float prix[100];
    int quantite[100];
    int choix, nmb = 0;
    int valide;

    // Affichage des livres au début (aucun livre ajouté initialement)
    printf("\n\n\t\033[1;34mNoter Bien!!!!!! Aucun livre n'a ete ajoute au stock au debut.\n\n");

    do {
        printf("\n\t\t\033[0mLe programme offre les fonctionnalites suivantes :\n\n");
        printf("\t\033[1;32m1: Ajouter un livre au stock.\n");
        printf("\t\033[1;32m2: Afficher tous les livres disponibles\n");
        printf("\t3: Rechercher un livre par son titre\n");
        printf("\t4: Mettre a jour la quantite d'un livre\n");
        printf("\t5: Supprimer un livre du stock\n");
        printf("\t6: Afficher le nombre total de livres en stock\n");
        printf("\t0: Quitter le programme\n\n");

        //traitement de nombre entrer
        do {
        printf("-->\t\033[0mChoisir un nombre entre 0 et 6 : ");
        valide = scanf("%d", &choix);

        if (valide != 1 || choix < 0 || choix > 6) {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");
            while (getchar() != '\n');  // Vide le buffer en cas d'entrée incorrecte
        }
    } while (valide != 1 || choix < 0 || choix > 6);

    //traiter les cas
        switch(choix) {
            case 1: {
                if (nmb >= 100) {
                    printf("!!!!Erreur : La capacite maximale de livres est atteinte.\n");
                    break;
                }

                printf("\033[1;36m\n\t\tBienvenue sur la phase d'ajout d'un livre au stock\033[0m\n\n");
                int nb_saisir;
                printf("\tEst-ce que vous voulez ajouter un livre ou plusieurs livres?\n");
          g:      printf("\t\t0: Ajouter un livre\n");
                printf("\t\t1: Ajouter plusieurs livres\n\n\n");
                //traiter cas si choix!= 0 ou 1
                 while (1) {
        printf("\tDonnez votre choix (0 ou 1) : ");
        if (scanf("%d", &nb_saisir) != 1 || (nb_saisir != 0 && nb_saisir != 1)) {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer 0 ou 1.\033[0m\n\n");
            while (getchar() != '\n'); // Vider le buffer
        } else {
            break; // Sortir de la boucle si la saisie est valide
        }
    }
//

                 if (nb_saisir == 0) {
        nb_saisir = 1;  // Cas où l'utilisateur ajoute un seul livre
    } else if (nb_saisir == 1) {
        printf("\tCombien de livres voulez-vous ajouter ? ");
        scanf("%d", &nb_saisir);

        if (nb_saisir <= 0) {
            printf("\033[1;31m\nErreur : Le nombre de livres doit être supérieur à 0.\033[0m\n\n");
            goto g;  // Retour à la saisie en cas d'erreur
        }
    } else {
        printf("\033[1;31m\nErreur : Veuillez bien respecter les consignes de choix ci-dessous.\033[0m\n\n");
        goto g;  // Retour à la saisie en cas de mauvais choix
    }

              for (int i = 0; i < nb_saisir; i++) {
        int existe = 0; // Variable pour vérifier l'existence du livre

        printf("\tSaisir les informations du livre %d :\n\n", nmb + 1);
    e:  // Label pour revenir à la saisie du titre
        printf("\t\tTitre : ");
        scanf("%s", titre[nmb]);

        // Vérifier si le titre contient uniquement des alphabets !!! ou pas
        for (int j = 0; titre[nmb][j] != '\0'; j++) {
            if (!isalpha(titre[nmb][j])) { // Si le caractère n'est pas une lettre
            printf("\n\t\033[1;31m!!!!! Erreur : Le titre contient des caracteres non alphabetiques.\033[0m\n");
            printf("\n\n\033[1;35m\t\tResaisir le titre!!!!\033[0m\n");
            goto e; // Retourner à la saisie du titre

            }
        }

        // Vérification si le livre existe déjà
        for (int j = 0; j < nmb; j++) {
            if (strcmp(titre[nmb], titre[j]) == 0) {
                printf("\t\t\033[1;31mLe livre '%s' existe deja dans le stock.\033[0m\n", titre[nmb]);
                existe = 1;
                break;
            }
        }

        // Si le livre n'existe pas, on continue à ajouter les informations
        if (!existe) {
            a:  // Label pour revenir à la saisie de l'auteur
            printf("\t\tAuteur : ");
            scanf("%s", auteur[nmb]);

            // Vérifier si l'auteur contient uniquement des alphabets
            for (int j = 0; auteur[nmb][j] != '\0'; j++) {
                if (!isalpha(auteur[nmb][j])) { // Si le caractère n'est pas une lettre
                    printf("\n\t\033[1;31m!!!!! Erreur : l'auteur contient des caracteres non alphabetiques.\033[0m\n");
                   printf("\n\n\n\t\t\033[1;35mResaisir le nom de l'auteur!!!!\033[0m \n");

                    goto a; // Retourner à la saisie de l'auteur
                }
            }
             //traiter le cas de saisir un nombre pou le prix
             do {
        printf("\t\tPrix : ");
        valide = scanf("%f", &prix[nmb]);
        if (valide != 1) {
            printf("\033[1;31m\n\t\t!!! Erreur : Vous devez entrer un nombre valide pour le prix.\033[0m\n\n");
            while (getchar() != '\n'); // Vide le buffer d'entrée pour éviter une boucle infinie
        }
    } while (valide != 1); // Répète tant qu'une entrée incorrecte est donnée

    // pour la quantite

            do {
        printf("\t\tQuantite : ");
        valide = scanf("%d", &quantite[nmb]);
        if (valide != 1) {
            printf("\033[1;31m\n\t\t!!!! Erreur : Vous devez entrer un nombre valide pour la quantite.\033[0m\n\n");
            while (getchar() != '\n'); // Vide le buffer d'entrée
        }
    } while (valide != 1); // Répète tant qu'une entrée incorrecte est donnée
//
            nmb++; // Incrémente le nombre de livres seulement si le livre est nouveau
            printf("\t\t\033[1;33mLivre ajoute avec succes !\033[0m\n");
        }
    }
                break;
            }

            case 2: {
                if (nmb == 0) {
                    printf("\n\t\t\033[1;31m Ooops!!!!! Aucun livre n'a ete ajoute au stock.\n\n");
                } else {
    printf("\n\n\t***** Affichage de Tous les Livres Disponibles *****\n\n");

    // En-tête du tableau avec alignement des colonnes
    printf("\t%-15s %-15s %-10s %-10s\n", "Titre", "Auteur", "Prix", "Quantite");
    printf("\t-----------------------------------------------------\n");

    // Affichage des livres avec des colonnes bien alignées
    for (int i = 0; i < nmb; i++) {
        printf("\t%-15s %-15s %-10.2f %-10d\n", titre[i], auteur[i], prix[i], quantite[i]);
    }

    printf("\n\t***********************************************\n\n");
                }
                break;
            }

            // Les autres cas restent inchangés
            case 3: {
                char recherche[100];
                printf("Saisir le titre du livre a rechercher : ");
                scanf("%s", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        printf("Livre trouve :\n");
                        printf("\tTitre : %s\n", titre[i]);
                        printf("\tAuteur : %s\n", auteur[i]);
                        printf("\tPrix : %.2f\n", prix[i]);
                        printf("\tQuantite : %d\n", quantite[i]);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\t\033[1;31m !!! Aucun Livre trouve par ce titre \n");
                }
                break;
            }

            // Mettre à jour, supprimer, etc. restent inchangés
            case 4: {
                char recherche[100];
                printf("\t\033[0mSaisir le titre du livre a mettre a jour : ");
                scanf("%s", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        printf("\tLivre trouve :\n");
                        printf("\tTitre : %s\n", titre[i]);
                        printf("\tAuteur : %s\n", auteur[i]);
                        printf("\tPrix : %.2f\n", prix[i]);
                        printf("\tQuantite actuelle : %d\n", quantite[i]);

                        printf("\tSaisir la nouvelle quantite : ");
                        scanf("%d", &quantite[i]);
                        printf("\t\t --> \033[1;33mQuantite mise a jour avec succes !\033[1;0m\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\t\033[1,31m!!! Livre non trouve.\n");
                }
                break;
            }

            case 5: {
                char recherche[100];
                printf("\tSaisir le titre du livre a supprimer : ");
                scanf("%s", recherche);
                int found = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], recherche) == 0) {
                        found = 1;
                        for (int j = i; j < nmb - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        nmb--;
                        printf("\t\t\033[1;33mLivre supprime avec succes !\033[0m\n");

                        break;
                    }
                }

                if (!found) {
                    printf("\t\t!!!\033[1;31mLivre non trouve.\033[0m\n");
                }
                break;
            }

            case 6: {
                printf("\n\n\t\t\033[1;33mNombre total de livres en stock : %d\n", nmb);
                break;
            }

            case 0:
                printf("Fin de programme !!!\n");
                break;

            default:
                printf("Option invalide, veuillez choisir un nombre entre 0 et 6.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}
