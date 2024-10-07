#include <stdio.h>
#include <stdlib.h>

void creerplateau(char plateau[3][3])
{
	for (int i = 0; i<3; i=i+1)
	{
		for (int j = 0; j<3; j=j+1)
		{
			plateau[i][j]=' ';
		}

	}
}
void AffichePlateau(char plateau[3][3])
{
	for (int i =0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%c", plateau[i][j]);
			if (j<2)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i<2)
		{
			printf("------\n");
		}
	}
}

int gagnant(char plateau[3][3], char joueur)
{
	for (int i = 0; i<3; i=i+1)
	{
		if (plateau[i][0] == joueur && plateau[i][1] == joueur && plateau[i][2]==joueur)
		{
			return 1;
		}
	}
	for (int j=0; j<3; j=j+1)
	{
		if (plateau[0][j] == joueur && plateau[1][j] == joueur && plateau[2][j] == joueur)
		{
			return 1;
		}
	}
	if ( plateau[0][0] == joueur && plateau[1][1] == joueur && plateau[2][2] == joueur)
	{
		return 1;
	}
	if (plateau[2][0] == joueur && plateau[1][1] == joueur && plateau[0][2] == joueur)
	{
		return 1;
	}
	return 0;
}

int egalite(char plateau[3][3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (plateau[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	printf("égalité\n");
	return 1;
}

void JoueurHumainTour(char plateau[3][3], char joueur)
{
	int casechoisi;
	printf("Veuillez choisir une case entre 0 et 8 joueur %c\n", joueur);
	scanf("%d", &casechoisi);
	while ( casechoisi<0 || casechoisi>8 || plateau[casechoisi/3][casechoisi%3]!=' ')   //attention ici cela correspond à tant que la case n'est pas valide redemander une case jusqu'à ce qu'elle soit valide
	{
		printf("Case  invalide, choisissez en une autre\n");
		scanf("%d", &casechoisi);
	}
	plateau[casechoisi / 3][casechoisi % 3]=joueur;
}

void JoueurOrdinateurTour(char plateau[3][3], char joueur)
{
	printf("l'ordinateur est en train de jouer\n");
	for (int i= 0; i<3; i=i+1)
	{
		for (int j=0; j<3; j++)
		{
			if (plateau[i][j]==' ')
			{
				plateau[i][j]=joueur;
				return;
			}
		printf("hola\n");
		}
	}
}
int main()
{
	char plateau[3][3];
	char joueurHumain = 'X';
	char joueurOrdinateur = 'O';
	int nbgagnant = 0;
	creerplateau(plateau);
	while (!nbgagnant && !egalite(plateau))
	{
		AffichePlateau(plateau);
		JoueurHumainTour(plateau, joueurHumain);
		if (gagnant(plateau, joueurHumain))
		{
			nbgagnant = 1;
			printf("Le joueur humain a gagné!\n");
			break;
		}
		if (egalite(plateau))
		{
			AffichePlateau(plateau);
			printf("égalité\n");
			break;
		}
		JoueurOrdinateurTour(plateau, joueurOrdinateur);
                if (gagnant(plateau, joueurOrdinateur))
                {
                        nbgagnant = 1;
                        printf("L'ordinateur a gagné!\n");
                        break;
                }
                if (egalite(plateau))
                {
                        AffichePlateau(plateau);
                        printf("égalité\n");
                        break;
                }
	}
	return 0;
}
