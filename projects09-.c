
// Abdessamad Ahmali (2APG1)

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <windows.h>

	void gotoxy(short x, short y)
	
	{	
    	COORD pos = {x, y};
    	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	};
	
	void textcolor(unsigned short color)
	
	{
    	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hcon,color);
	};
	// struct contact
	typedef struct annuaire
	{
		
		int numero;
		char nom[20];
		char prenom[20];
		char adresse[30];
		char profession[20];
		char pays[20];
		char tel[20];
		struct annuaire* nxt;
		struct annuaire* prev;
		
		// initialisation function
	}annuaire;	
	
		annuaire *initialisation()
	{
	annuaire *l=(annuaire*)malloc(sizeof(annuaire));
	l->nxt=l;
	l->prev=l;
	
	return l;
	};
	
	// load function
	
	void Load()
	{
		int r,q;
    	gotoxy(52,10);
    	printf("L O A D I N G...");
    	gotoxy(34,12);
    	
    	for(r=1; r<=49; r++)
    	{
        	for(q=0; q<=30000000; q++); 
        		printf("%c",178);
        		Beep(500, 150);
    	}

    	puts("");
    	gotoxy(45,15);
		puts("Press any key to Continue..");
    	textcolor(8);
		gotoxy(32,20);
		puts("(Realise Par Abdessamad Ahmali & Bader AhlMaatalah )");
    	gotoxy(74,15);
		getch();
		system("cls");	
	};
	
	// Menu function 
	
	void menu()

{
	int j=36;
	int i=38;
	textcolor(8);
	gotoxy(j,4); 	printf("şşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşş");
	gotoxy(j,5); 	printf("Û                                                                       Û");
	gotoxy(j,6);	printf("Û  ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÎ          ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÎ        Û");
	gotoxy(j,7); 	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,8); 	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,9); 	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,10);	printf("Û  ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÎ          Î                 º                Î        Û");
	gotoxy(j,11);	printf("Û                           Î                 º                Î        Û");
	gotoxy(j,12);	printf("Û                           ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÎ        Û");
	gotoxy(j,13);	printf("Û                           Î                 º                Î        Û");
	gotoxy(j,14);	printf("Û  ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÎ          Î                 º                Î        Û");
	gotoxy(j,15);	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,16);	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,17);	printf("Û  Î             Î          Î                 º                Î        Û");
	gotoxy(j,18);	printf("Û  ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÎ          ÎÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÎ        Û");
	gotoxy(j,19);	printf("Û                                                                       Û");
	gotoxy(j,20);	printf("şşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşşş");
	textcolor(6);	gotoxy(42,8);printf("1-Ajouter");
	gotoxy(42,16);	printf("2-Afficher");
	gotoxy(67,8);	printf("3-Initialiser");
	gotoxy(68,10);	printf("4-Cree");
	gotoxy(85,8);	printf("5-Rechercher");
	gotoxy(85,10);	printf("6-Compter");
	gotoxy(69,15);	printf("7-Supprimer"); 
	gotoxy(86,15);	printf("8-Quitter");
	textcolor(8);	gotoxy(12,4);printf("MENU");
	textcolor(6);	gotoxy(11,5);printf("ÄÄÄÄÄÄÄ");
	textcolor(2);	gotoxy(9,8);printf("1-Ajouter");
	gotoxy(9,9);	printf("2-Afficher");
	gotoxy(9,10);	printf("3-Initialiser");
	gotoxy(9,11);	printf("4-Cree");
	gotoxy(9,12);	printf("5-Rechercher");
	gotoxy(9,13);	printf("6-Compter");
	gotoxy(9,14);	printf("7-Supprimer");
	gotoxy(9,15);	printf("8-Quitter");
	textcolor(8);	gotoxy(30,24);printf("èèèèè______MENU DICTIONNAIRE ELECTRONIQUE ______ èèèè");
	gotoxy(30,25);	printf("ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	gotoxy(12,16);


}

	// add First Function
	annuaire* AjoutDebut(annuaire *l,char* nom,char *prenom,char* adresse,char* profession,char* pays, char* tel,int n)
	{
		annuaire *nv=(annuaire*)malloc(sizeof(annuaire));
		nv->numero=n;
		strcpy(nv->nom,nom);
		strcpy(nv->prenom,prenom);
		strcpy(nv->adresse,adresse);
		strcpy(nv->profession,profession);
		strcpy(nv->pays,pays);
		strcpy(nv->tel,tel);
		nv->nxt=l->nxt;
		nv->prev=l;
		l->nxt->prev=nv;
		l->nxt=nv;
		
		return l;
	};

	// display total contacts 

	void AffichageSimple(annuaire *l)
{
	annuaire *p=l->nxt;
	
	while(p!=l)
	{
		
		textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero,p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
		puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
		p=p->nxt;
	}	
		
};
	annuaire* rechercherNom(annuaire *l,char noun[20])
{
	annuaire *p=l->nxt;
	system("cls");
	gotoxy(40,10);printf(" Donner Le nom : ");
	gotoxy(63,10);fflush(stdin);gets(noun);
	while(p!=l)
	{
		if(strcmp(p->nom,noun)==0)
		{
		textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero,p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
		puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
		p=p->nxt;
		}
	}
	return l;	
		
};
	annuaire* rechercherTel(annuaire *l,char phone[20])
{
	annuaire *p=l->nxt;
	system("cls");
	gotoxy(40,10);printf(" Donner Le phone : ");
	gotoxy(63,10);fflush(stdin);gets(phone);
	while(p!=l)
	{
		if(strcmp(p->tel,phone)==0)
		{
		textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero, p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
		puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
		p=p->nxt;
		}
	}
	return l;	
		
};
	void AffichageVill(annuaire *l,char vill[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner La ville : ");
	gotoxy(63,10);fflush(stdin);gets(vill);
	annuaire *p=l->nxt;
	while(p!=l)
	{
		if(strcmp(p->pays,vill)==0)	
		{
				textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero, p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
					puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
				p=p->nxt;
		}

	}	
		
};
	void AffichageVillProf(annuaire *l,char vill[20],char prof[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner La ville : ");
	gotoxy(63,10);fflush(stdin);gets(vill);
	gotoxy(40,12);printf(" Donner La profession : ");
	gotoxy(63,12);fflush(stdin);gets(prof);
	annuaire *p=l->nxt;
	while(p!=l)
	{
		if(strcmp(p->pays,vill)==0 && strcmp(p->profession,prof)==0)	
		{
				textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero, p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
					puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
				p=p->nxt;
		}
	}	
		
};
	void affichageLettre(annuaire *l,char lettre[10])
{
	system("cls");
	gotoxy(40,10);printf(" Donner La lettre: ");
	gotoxy(60,10);scanf("%s",lettre);
	annuaire *p=l->nxt;
	while(p!=l)
	{
		if(p->nom[0]==lettre[0])	
		{
				textcolor(1);printf("\n  Num:%d \t Nom: %s \t Prenom:%s  \t Adresse :%s \t Profession:%s \t  Pays:%s \t Tel:%s \n\n",p->numero, p->nom,p->prenom,p->adresse,p->profession,p->pays,p->tel);
				puts("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
				p=p->nxt;
		}
		
	}	
		
};
annuaire *CreeVille(annuaire *l,char vill[15])
{
	system("cls");
	gotoxy(40,10);printf(" Donner Le Pays: ");
	gotoxy(60,10);fflush(stdin);	gets(vill);
	annuaire *p=l->nxt;
	annuaire *ze=initialisation();
	while(p!=l)
	{
		if(strcmp(p->pays,vill)==0)	
		{
				ze->numero=p->numero;
				strcpy(ze->nom,p->nom);
				strcpy(ze->prenom,p->prenom);
				strcpy(ze->adresse,p->adresse);
				strcpy(ze->pays,p->pays);
				strcpy(ze->profession,p->profession);
				strcpy(ze->tel,p->tel);
				p=p->nxt;
		}
		
	}	
		return l;
};

annuaire* CreeVilleNom(annuaire *l,char city[20],char nom[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner Le Pays: ");
	gotoxy(60,10);fflush(stdin);	gets(city);
	gotoxy(40,12);printf(" Donner Le Nom : ");
	gotoxy(60,12);fflush(stdin);	gets(nom);
	annuaire *p=l->nxt;
	annuaire *ze=initialisation();
	
	while(p!=l)
	{
		if(strcmp(p->pays,city)==0 && strcmp(p->nom,nom)==0)	
		{
				ze->numero=p->numero;
				strcpy(ze->nom,p->nom);
				strcpy(ze->prenom,p->prenom);
				strcpy(ze->adresse,p->adresse);
				strcpy(ze->pays,p->pays);
				strcpy(ze->profession,p->profession);
				strcpy(ze->tel,p->tel);
				p=p->nxt;
		}
		
	}
	return l;	
		
}


annuaire *ajoutfin(annuaire *l,char* nom,char *prenom,char* adresse,char* profession,char* pays, char* tel,int n)
{
	annuaire *nv=(annuaire*)malloc(sizeof(annuaire));
	nv->numero=n;
	strcpy(nv->nom,nom);
	strcpy(nv->prenom,prenom);
	strcpy(nv->adresse,adresse);
	strcpy(nv->profession,profession);
	strcpy(nv->pays,pays);
	strcpy(nv->tel,tel);
	
	nv->nxt=l;
	nv->prev=l->prev;
	l->prev->nxt=nv;
	l->prev=nv;
	return l;
}
annuaire *ajoutposition(annuaire *l,char* nom,char *prenom,char* adresse,char* profession,char* pays, char* tel,int P,int n)
{
	int s=1;
	annuaire *p=l->nxt;
	annuaire *nv;

	nv=(annuaire*)malloc(sizeof(annuaire));
	nv->numero=n;
	strcpy(nv->nom,nom);
	strcpy(nv->prenom,prenom);
	strcpy(nv->adresse,adresse);
	strcpy(nv->profession,profession);
	strcpy(nv->pays,pays);
	strcpy(nv->tel,tel);
	while(p!=l)
	{
		if(s==P-1)
		{
			nv->nxt=p->nxt;
			nv->prev=p;
			p->nxt->prev=nv;
			p->nxt=nv;
			return l;
		}
	p=p->nxt;
	s=s+1;
	
	}
}

	annuaire *SuppressionDebut(annuaire *l)
{
	annuaire *p=l->nxt;
	if(p==l)
	{
		return l;	
	} 
		p->nxt->prev=l;
		l->nxt=p->nxt;
		free(p);
	return l;
};
annuaire *SuppressionPosition(annuaire *l, int pos)
{
	int c=1;
	annuaire *p=l->nxt;
	if(p==l) 
	{
		return l;
	}
	while(p!=l)
	{
		if(c==pos)
		{
			p->nxt->prev=p->prev;
			p->prev->nxt=p->nxt;
			free(p);
			return l;
		}
		c++;
		p=p->nxt;
	}
};
annuaire *SuppressionNom(annuaire *l, char noun[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner Le Nom : ");
	gotoxy(60,10);fflush(stdin);gets(noun);
	annuaire *p=l->nxt;
	if(p==l) 
	{
		return l;
	}
	while(p!=l)
	{
		if(strcmp(p->nom,noun)==0)
		{
			p->nxt->prev=p->prev;
			p->prev->nxt=p->nxt;
			free(p);
			return l;
			p=p->nxt;
		}
		
	}
};
annuaire *SuppressionPhone(annuaire *l, char phone[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner Le phone : ");
	gotoxy(60,10);fflush(stdin);gets(phone);
	annuaire *p=l->nxt;
	if(p==l) 
	{
		return l;
	}
	while(p!=l)
	{
		if(strcmp(p->tel,phone)==0)
		{
			p->nxt->prev=p->prev;
			p->prev->nxt=p->nxt;
			free(p);
			return l;
			p=p->nxt;
		}

		
	}
};
annuaire *SuppressionPay(annuaire *l, char city[20])
{
	system("cls");
	gotoxy(40,10);printf(" Donner Le Pays : ");
	gotoxy(60,10);fflush(stdin);gets(city);
	annuaire *p=l->nxt;
	if(p==l) 
	{
		return l;
	}
	while(p!=l)
	{
		if(strcmp(p->pays,city)==0)
		{
			p->nxt->prev=p->prev;
			p->prev->nxt=p->nxt;
			free(p);
			return l;
			p=p->nxt;
		}
		
	}
};
annuaire *SuppressionFin(annuaire *l)
{
	annuaire *p=l->prev;
	if(p==l) 
	{
		return l;	
	}
		p->prev->nxt=l;
		l->prev=p->prev;
		free(p);
		return l;
}

int longueurlistePays(annuaire *l)
{
	char city[20];
	system("cls");
	gotoxy(40,10);printf(" Donner Le Pays : ");
	gotoxy(60,10);fflush(stdin);gets(city);
	annuaire *p=l->nxt;
	int counter=0;
	while(p!=l)
	{
		if(strcmp(p->pays,city)==0)
		{
					counter++;		p=p->nxt;
		}
		system("cls");
		gotoxy(40,10);printf("%d Contacts Disponible dans %s ",counter,city);
	}
	return counter;
}
int longueurlisteProfession(annuaire *l)
{
	char profes[20];
	system("cls");
	gotoxy(40,10);printf(" Donner La profession : ");
	gotoxy(65,10);fflush(stdin);gets(profes);
	annuaire *p=l->nxt;
	int counter=0;
	while(p!=l)
	{
		if(strcmp(p->profession,profes)==0)
		{
			counter++;		p=p->nxt;
		}
		system("cls");
		gotoxy(40,10);printf("%d Contacts Disponible exercant profession %s ",counter,profes);
	}
	return counter;
}
int longueurlisteT(annuaire *l)
{
	annuaire *p=l->nxt;
	int counter=0;
	while(p!=l)
	{
		
			counter++;		p=p->nxt;

		system("cls");
		gotoxy(40,10);printf("%d Contacts Disponible en Total ! ",counter);
	}
	return counter;
}

main()


{
	
	 

	int choix = -1;
	int j,i,x,counter=0,m;
	int choice ,choice2,P,choice4,choice3,choice7,choice6;
	char lettre[10];
	char noun[20];
	char phone[20];
	annuaire *l = NULL ;
	l=initialisation();
	char nom[15], prenom[15], adresse[20], profession[15], pays[20], tel[20];
	char vill[15],prof[15];

	Load();
	menu();
	do
	{
	 	switch( choix )

	{
		
		case 1:
			
		{
			do{
				system("cls");
				system("color 60");
//				textcolor(7);
				gotoxy(25,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(25,8);printf("³");
				gotoxy(29,8);printf(" 1_Ajout Debut:              ==> Taper 1");
				gotoxy(25,9);printf("³");
				gotoxy(25,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(86,8);printf("³");
				gotoxy(86,9);printf("Ù");
				gotoxy(86,7);printf("¿");
//				textcolor(7);
				gotoxy(25,13);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(25,14);printf("³");
				gotoxy(29,14);printf(" 2_Ajout Milieu :           ==> Taper 2");
				gotoxy(25,15);printf("³");
				gotoxy(25,15);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(86,14);printf("³");
				gotoxy(86,15);printf("Ù");
				gotoxy(86,13);printf("¿");
//				textcolor(7);
				gotoxy(25,19);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(25,20);printf("³");
				gotoxy(29,20);printf(" 3_Ajout Fin :              ==> Taper 3");
				gotoxy(25,21);printf("³");
				gotoxy(25,21);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(86,20);printf("³");
				gotoxy(86,21);printf("Ù");
				gotoxy(86,19);printf("¿");
				
				textcolor(3);gotoxy(40,22);scanf("%d",&choice);
				
				}while(choice<0 || choice>3);
			if (choice==1)
			{
				system("cls");
				
				gotoxy(30,7); 	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,8); 	printf("³       Nom         ³                            ³");
				gotoxy(30,9); 	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,10);	printf("³     Prenom        ³                            ³");
				gotoxy(30,11);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,12);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,13);	printf("³     Adresse       ³                            ³");
				gotoxy(30,14);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,15);	printf("³     Profession    ³                            ³");
				gotoxy(30,16);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,17);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,18);	printf("³       Pays        ³                            ³");
				gotoxy(30,19);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,20);	printf("³        Tel	  ³                            ³");
				gotoxy(30,21);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,22);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,23);	printf("³       Numero      ³                            ³");
				gotoxy(30,24);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				
				textcolor(6);
				gotoxy(58,8);	fflush(stdin); gets(nom);
				printf("\a");
				gotoxy(58,10);	fflush(stdin); gets(prenom);
				printf("\a");
				gotoxy(58,13);	fflush(stdin); gets(adresse);
				printf("\a");
				gotoxy(58,15);	fflush(stdin); gets(profession);
				printf("\a");
				gotoxy(58,18);	fflush(stdin); gets(pays);
				printf("\a");
				gotoxy(58,20);	fflush(stdin); gets(tel);
				printf("\a");
				gotoxy(58,23);	scanf("%d",&m);
				printf("\a");
				
				textcolor(6);gotoxy(40,26);puts("[ Contact  Ajoute avec Success ] ");
				getch();
				l=AjoutDebut(l,nom,prenom,adresse,profession,pays,tel,m);
				system("cls");
				menu();
				break;
			}
			if (choice==2)
			{
				system("cls");
				gotoxy(40,10);printf(" Donner Pos Ajout : ");
				gotoxy(63,10);scanf("%d",&P);
				system("cls");
				textcolor(5);
				system("cls");
				gotoxy(30,7); 	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,8); 	printf("³       Nom         ³                            ³");
				gotoxy(30,9); 	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,10);	printf("³     Prenom        ³                            ³");
				gotoxy(30,11);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,12);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,13);	printf("³     Adresse       ³                            ³");
				gotoxy(30,14);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,15);	printf("³     Profession    ³                            ³");
				gotoxy(30,16);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,17);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,18);	printf("³       Pays        ³                            ³");
				gotoxy(30,19);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,20);	printf("³        Tel	  ³                            ³");
				gotoxy(30,21);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,22);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,23);	printf("³       Numero      ³                            ³");
				gotoxy(30,24);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(60,8);	fflush(stdin); gets(nom);
				gotoxy(60,10);	fflush(stdin); gets(prenom);
				gotoxy(60,13);	fflush(stdin); gets(adresse);
				gotoxy(60,15);	fflush(stdin); gets(profession);
				gotoxy(60,18);	fflush(stdin); gets(pays);
				gotoxy(60,20);	fflush(stdin); gets(tel);
				gotoxy(58,23);	scanf("%d",&m);
				
				l=ajoutposition(l,nom,prenom,adresse,profession,pays,tel,P,m);
				system("cls");
				menu();
				break;
			}
			if (choice==3)
			{
				textcolor(4);
				system("cls");
				gotoxy(30,7); 	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,8); 	printf("³       Nom         ³                            ³");
				gotoxy(30,9); 	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,10);	printf("³     Prenom        ³                            ³");
				gotoxy(30,11);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,12);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,13);	printf("³     Adresse       ³                            ³");
				gotoxy(30,14);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,15);	printf("³     Profession    ³                            ³");
				gotoxy(30,16);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,17);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,18);	printf("³       Pays        ³                            ³");
				gotoxy(30,19);	printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
				gotoxy(30,20);	printf("³        Tel	  ³                            ³");
				gotoxy(30,21);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(30,22);	printf("ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÂÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿");
				gotoxy(30,23);	printf("³       Numero      ³                            ³");
				gotoxy(30,24);	printf("ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÁÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÙ");
				
				gotoxy(60,8);	fflush(stdin); gets(nom);
				gotoxy(60,10);	fflush(stdin); gets(prenom);
				gotoxy(60,13);	fflush(stdin); gets(adresse);
				gotoxy(60,15);	fflush(stdin); gets(profession);
				gotoxy(60,18);	fflush(stdin); gets(pays);
				gotoxy(60,20);	fflush(stdin); gets(tel);
				gotoxy(58,23);	scanf("%d",&m);
				
				l=ajoutfin(l,nom,prenom,adresse,profession,pays,tel,m);
				system("cls");
				menu();
				break;
			}
	}
		case 2:
		{
				
				system("cls");
				gotoxy(21,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,8);printf("³");
				gotoxy(25,8);printf(" 1_Afficher Tous Les contacts :                                ==> Taper 1            ");
				gotoxy(21,9);printf("³");
				gotoxy(21,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,8);printf("³");
				gotoxy(109,9);printf("Ù");
				gotoxy(109,7);printf("¿");
				
				gotoxy(21,10);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,11);printf("³");
				gotoxy(25,11);printf(" 2_Afficher Les contacts d'une ville :                        ==> Taper 2                 ");
				gotoxy(21,12);printf("³");
				gotoxy(21,12);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,11);printf("³");
				gotoxy(109,12);printf("Ù");
				gotoxy(109,10);printf("¿");
				
				gotoxy(16,13);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(16,14);printf("³");
				gotoxy(20,14);printf(" 3_Afficher Les contacts d'une ville ayant une Profession :         ==> Taper 3  ");
				gotoxy(16,15);printf("³");
				gotoxy(16,15);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,14);printf("³");
				gotoxy(109,15);printf("Ù");
				gotoxy(109,13);printf("¿");
				
				gotoxy(16,16);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(16,17);printf("³");
				gotoxy(20,17);printf(" 4_Afficher Les contacts  commencant avec une lettre :            ==> Taper 4    ");
				gotoxy(16,18);printf("³");
				gotoxy(16,18);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,17);printf("³");
				gotoxy(109,18);printf("Ù");
				gotoxy(109,16);printf("¿");
				
				textcolor(3);gotoxy(40,19);scanf("%d",&choice2);
			if(choice2==1)
			{
				system("cls");
				AffichageSimple(l);
				getch();
				system("cls");
				menu();
			
			break;
			}
			if(choice2==2)
			{
				
				AffichageVill(l,vill);
				getch();
				system("cls");
				menu();
				break;
			}
			if(choice2==3)
			{
				AffichageVillProf(l,vill,prof);
				getch();
				system("cls");
				menu();
				break;
			}
			if(choice2==4)
			{
				affichageLettre(l,lettre);
				getch();
				system("cls");
				menu();
				break;
			}
			
		}
		
		
		
		case 3:
			{
				system("cls");
				gotoxy(40,10);puts("[ Votre chaine est bien Initialisee : ] ");
				getch();
				menu();
				break;
			}
		case 4:
			{
				system("cls");
				textcolor(5);
				gotoxy(21,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,8);printf("³");
				gotoxy(25,8);printf(" 1_Cree Nouvelle Liste Contenant les Cantacts ayant un pays                     ");
				gotoxy(21,9);printf("³");
				gotoxy(21,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,8);printf("³");
				gotoxy(109,9);printf("Ù");
				gotoxy(109,7);printf("¿");
				
				gotoxy(21,10);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,11);printf("³");
				gotoxy(25,11);printf(" 2_Cree Nouvelle Liste Contenant les Contacts ayant une Profession            ");
				gotoxy(21,12);printf("³");
				gotoxy(21,12);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,11);printf("³");
				gotoxy(109,12);printf("Ù");
				gotoxy(109,10);printf("¿");
				
				gotoxy(21,13);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,14);printf("³");
				gotoxy(25,14);printf(" 3_Cree Nouvelle Liste Contenant les Contacts ayant un Nom et un Pays           ");
				gotoxy(21,15);printf("³");
				gotoxy(21,15);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,14);printf("³");
				gotoxy(109,15);printf("Ù");
				gotoxy(109,13);printf("¿");
			
				textcolor(3);gotoxy(40,17);scanf("%d",&choice4);
				if(choice4==1)
				{
					system("cls");
					l=CreeVille(l,vill);
					system("cls");
					menu();
					break;
				}
				if(choice4==3)
				{
					system("cls");
					l=CreeVilleNom(l,vill,noun);
					system("cls");
					menu();
					break;
				}
				system("cls");
				
				
				
				getch();
				menu();
				break;
			}
		case 5:
			{
				system("cls");
				
				gotoxy(25,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(25,8);printf("³");
				gotoxy(29,8);printf(" 1_Rechercher par Nom:                  ==> Taper 1");
				gotoxy(25,9);printf("³");
				gotoxy(25,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(86,8);printf("³");
				gotoxy(86,9);printf("Ù");
				gotoxy(86,7);printf("¿");
				
				gotoxy(25,10);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(25,11);printf("³");
				gotoxy(29,11);printf(" 2_Rechercher par Telephone :           ==> Taper 2");
				gotoxy(25,12);printf("³");
				gotoxy(25,12);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(86,11);printf("³");
				gotoxy(86,12);printf("Ù");
				gotoxy(86,10);printf("¿");
				textcolor(3);gotoxy(40,15);scanf("%d",&choice3);
				if(choice3==1)
				{
					system("cls");
					l=rechercherNom(l,noun);
					getch();
					system("cls");
					menu();
					break;
				}
				if(choice3==2)
				{
					system("cls");
					l=rechercherTel(l,phone);
					getch();
					system("cls");
					menu();
					break;
				}
			}
			case 6:
				{
				system("cls");
				textcolor(5);
				gotoxy(21,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,8);printf("³");
				gotoxy(25,8);printf(" 1_Compter  Les contacts d'un Pays:                                ==> Taper 1            ");
				gotoxy(21,9);printf("³");
				gotoxy(21,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,8);printf("³");
				gotoxy(109,9);printf("Ù");
				gotoxy(109,7);printf("¿");
				
				gotoxy(21,10);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,11);printf("³");
				gotoxy(25,11);printf(" 2_Compter  Les contacts exercant une Profession :                ==> Taper 2                 ");
				gotoxy(21,12);printf("³");
				gotoxy(21,12);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,11);printf("³");
				gotoxy(109,12);printf("Ù");
				gotoxy(109,10);printf("¿");
				
				gotoxy(21,13);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(21,14);printf("³");
				gotoxy(25,14);printf(" 3_Compter  Le nombre Total des Contacts     :                    ==> Taper 3                 ");
				gotoxy(21,15);printf("³");
				gotoxy(21,15);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				gotoxy(109,14);printf("³");
				gotoxy(109,15);printf("Ù");
				gotoxy(109,13);printf("¿");
			
				textcolor(3);gotoxy(40,17);scanf("%d",&choice6);
				if(choice6==1)
					{
						system("cls");
						counter=longueurlistePays(l);
						getch();
						system("cls");
						menu();
						break;
					}
				if(choice6==2)
				{
						system("cls");
						counter=longueurlisteProfession(l);
						getch();
						system("cls");
						menu();
						break;
				}
				if(choice6==3)
				{
					system("cls");
					counter=longueurlisteT(l);
					getch();
					system("cls");
					menu();
					break;
				}
				
				}
			case 7:
				{
					system("cls");
					textcolor(9);
					gotoxy(25,7);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,8);printf("³");
					gotoxy(29,8);printf(" Supprimer Debut:                   ==> Taper 1");
					gotoxy(25,9);printf("³");
					gotoxy(25,9);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,8);printf("³");
					gotoxy(86,9);printf("Ù");
					gotoxy(86,7);printf("¿");
				
					gotoxy(25,10);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,11);printf("³");
					gotoxy(29,11);printf(" 2_Supprimer Milieu :               ==> Taper 2");
					gotoxy(25,12);printf("³");
					gotoxy(25,12);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,11);printf("³");
					gotoxy(86,12);printf("Ù");
					gotoxy(86,10);printf("¿");
				
					gotoxy(25,13);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,14);printf("³");
					gotoxy(29,14);printf(" 3_Supprimer Fin :                  ==> Taper 3");
					gotoxy(25,15);printf("³");
					gotoxy(25,15);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,14);printf("³");
					gotoxy(86,15);printf("Ù");
					gotoxy(86,13);printf("¿");
					
					gotoxy(25,16);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,17);printf("³");
					gotoxy(29,17);printf(" 4_Supprimer par Nom :              ==> Taper 4  ");
					gotoxy(25,18);printf("³");
					gotoxy(25,18);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,17);printf("³");
					gotoxy(86,18);printf("Ù");
					gotoxy(86,16);printf("¿");
					
					gotoxy(25,19);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,20);printf("³");
					gotoxy(29,20);printf(" 5_Supprimer par telephone :        ==> Taper 5        ");
					gotoxy(25,21);printf("³");
					gotoxy(25,21);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,20);printf("³");
					gotoxy(86,21);printf("Ù");
					gotoxy(86,19);printf("¿");
					
					gotoxy(25,22);printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(25,23);printf("³");
					gotoxy(29,23);printf(" 6_Supprimer par pays :             ==> Taper 6       ");
					gotoxy(25,24);printf("³");
					gotoxy(25,24);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
					gotoxy(86,23);printf("³");
					gotoxy(86,24);printf("Ù");
					gotoxy(86,22);printf("¿");
					textcolor(7);gotoxy(40,25);scanf("%d",&choice7);
					if(choice7==1)
					{
						// Suppression Debut
						system("cls");
						l=SuppressionDebut(l);
						getch();
						system("cls");
						menu();
						break;
					}
					if(choice7==2)
					{
						// Suppression Pos
						system("cls");
						gotoxy(40,10);printf(" Donner Pos Supression : ");
						gotoxy(65,10);scanf("%d",&P);
						system("cls");
						l=SuppressionPosition(l,P);
						getch();
						system("cls");
						menu();
						break;
					}
					
					if(choice7==3)
					{
						// Suppression Fin
						system("cls");
						l=SuppressionFin(l);
						getch();
						menu();
						system("cls");
						break;
					}
					if(choice7==4)
					{
						// Suppression par nom
						system("cls");
						l=SuppressionNom(l,noun);
						menu();
						break;
					}
					if(choice7==5)
					{
						// Suppression par telephone
						system("cls");
						l=SuppressionPhone(l,phone);
						menu();
						break;
					}
					if(choice7==6)
					{
							// Suppression par pays
						system("cls");
						l=SuppressionPay(l,vill);
						menu();
						break;
					}
				}
			case 8:
			{
				system("cls");
				exit(0);
			}
	}	
		textcolor(3);scanf("%d",&choix);
	}while( choix != 25 );
	 
}

