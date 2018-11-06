/* 	ROY Adrien  -  THEBAULT Alexandre */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

typedef struct coordonnees coordonnees;
struct coordonnees {
	int x[64];
	int y[64];
	int larg[64];
	int longu[64];
	int larg1[64];
	int longu1[64];
};



int main(void){
	coordonnees point;				/* Declaration de toutes les variables requisent */
	srand(time(NULL));
	int tab[15][15];
	int tab1[15][15];	
	int i=0, j=0, a=0, b=0, c=1, temp, col=0, lig=0, d,fin=0, z=0, e=0, f=0, alea=0,t=20;
	int x=0,y=100,larg=0,longu=0;
	int rep, coup=0, vide=0, img=0, tailleimgx=0,tailleimgy=0, imag=0;
	int droite=0, gauche=0, bas=0, haut=0, var;
	char compteur [10];

	couleur c1 = CouleurParComposante(170,9,74);
	couleur c2 = CouleurParComposante(255,255,255);
 	InitialiserGraphique();
	CreerFenetre(50,30,900,700);

	while(1){		/* Début de la boucle principale */ 
	img=0;			/* Initialisation de toutes les variables */
	imag=0;
	coup=0;
	col=0;
	lig=0;
	larg=0;
	longu=0;
	x=0;
	y=100;
	alea=5;
	droite=0;
	gauche=0;
	haut=0;
	bas=0;
	var=0;

	ChargerImageFond("./image/Menu-principal.bmp");
	while(a==0){						/* Programmation des bouton jouer et quitter du menu principal */
		if (SourisCliquee()){		
			if (286<=_X && _X<=603 && 310<=_Y && _Y<=391){
				EffacerEcran(c2);
				a=a+1;
			}
			if (286<=_X && _X<=603 && 467<=_Y && _Y<=549){
				FermerGraphique();
				exit(0);
			}
		}
	}
	ChargerImageFond("./image/Menu-colonne.bmp");
	while(col==0){ 				 		/* Choix du nombre de colonne */
		if (SourisCliquee()){
			if (332<=_X && _X<=396 && 174<=_Y && _Y<=238){
				col=3;
			}
			if (332<=_X && _X<=396 && 344<=_Y && _Y<=409){
				col=4;
			}
			if (332<=_X && _X<=396 && 514<=_Y && _Y<=578){
				col=5;
			}
			if (501<=_X && _X<=567 && 174<=_Y && _Y<=238){
				col=6;
			}
			if (501<=_X && _X<=567 && 344<=_Y && _Y<=409){
				col=7;
			}
			if (501<=_X && _X<=567 && 514<=_Y && _Y<=578){
				col=8;
			}
		}
	}
	EffacerEcran(c2);
	ChargerImageFond("./image/Menu-ligne.bmp");
	while(lig==0){ 						/* Choix du nombre de ligne */
		if (SourisCliquee()){
			if (217<=_X && _X<=282 && 229<=_Y && _Y<=293){
				lig=3;
			}
			if (416<=_X && _X<=482 && 229<=_Y && _Y<=293){
				lig=4;
			}
			if (615<=_X && _X<=678 && 229<=_Y && _Y<=293){
				lig=5;
			}
			if (217<=_X && _X<=282 && 403<=_Y && _Y<=466){
				lig=6;
			}
			if (416<=_X && _X<=482 && 403<=_Y && _Y<=466){
				lig=7;
			}
			if (615<=_X && _X<=678 && 403<=_Y && _Y<=466){
				lig=8;
			}
		}
	}
	EffacerEcran(c2);
	ChargerImageFond("./image/Menu-image.bmp");
	while(img==0){ 							/* Choix de l'image de jeu et initialisation de ses caractéritiques */
		if (SourisCliquee()){
			if (47<=_X && _X<=369 && 161<=_Y && _Y<=604){
			img=1;
			imag=1;
			tailleimgx=400;
			tailleimgy=546;
			}
			if (461<=_X && _X<=853 && 161<=_Y && _Y<=368){
			img=2;
			imag=2;
			tailleimgx=600;
			tailleimgy=313;
			}
			if (461<=_X && _X<=853 && 386<=_Y && _Y<=604){
			img=3;
			imag=3;
			tailleimgx=580;
			tailleimgy=320;
			}
		}
	}
	EffacerEcran(c2);

	a=0;
	for (i=0;i<lig;i++){   /* Boucle for permettant de remplir le tableau de jeu */
		if(img==1){
			x=50;
		} else {
			x=100;
		}
		for (j=a;b<col;j++){

			point.larg[j]=larg;
			point.larg1[j]=larg;
			
			larg=larg+(tailleimgx/col);
			point.x[j]=x;
			x=x+(tailleimgx/col)+5;
			point.longu[j]=longu;	
			point.longu1[j]=longu;	
			point.y[j]=y;
			a=j+1;
			b++;
		}
		longu=longu+(tailleimgy/lig);
		y=y+(tailleimgy/lig)+5;
		larg=0;
		b=0;

	}
	a=0;
	j=0;
	i=0;
	z=0;	

	for(f=0;f<1000;f++){   /* Boucle for permettant de melanger le tableau de jeu */

		alea=(rand()%4);
		
		for(i=0;c!=0; i++) { 
				for(j=a;b<col && c!=0 ;j++) {
					
					if (point.larg[j] == 0 && point.longu[j]==0){
						c=0;
					}
					a=j+1;					
					b++;
					d=b;
				}
				b=0;
		}
		c=1;
		a=0;
		if(alea==0 && d<col){			
			temp=point.larg[j-1];
			point.larg[j-1]=point.larg[j];
			point.larg[j]=temp;
			temp=0;
			temp=point.longu[j-1];
			point.longu[j-1]=point.longu[j];
			point.longu[j]=temp;
			temp=0;

		} else if(alea==1 && d>1) {
			temp=point.larg[j-1];
			point.larg[j-1]=point.larg[j-2];
			point.larg[j-2]=temp;
			temp=0;
			temp=point.longu[j-1];
			point.longu[j-1]=point.longu[j-2];
			point.longu[j-2]=temp;
			temp=0;
		} else if (alea==2 && i<lig) {
			temp=point.larg[j-1];
			point.larg[j-1]=point.larg[j+col-1];
			point.larg[j+col-1]=temp;
			temp=0;
			temp=point.longu[j-1];
			point.longu[j-1]=point.longu[j+col-1];
			point.longu[j+col-1]=temp;
			temp=0;
		} else if (alea==3 && i>1){
			temp=point.larg[j-1];
			point.larg[j-1]=point.larg[j-col-1];
			point.larg[j-col-1]=temp;
			temp=0;
			temp=point.longu[j-1];
			point.longu[j-1]=point.longu[j-col-1];
			point.longu[j-col-1]=temp;
			temp=0;
		}	
	}
	d=0;
	a=0;
	j=0;
	b=0;
	


	while(z!=1){		  /*  Boucle while permettant d'afficher les images et de trouver la position de la case vide */

		if(imag==1){
			ChargerImageFond("./image/Menu-jeu-img1.bmp");
			imag=4;
		}
		if(img==1){
			sprintf(compteur,"%d",coup);  
			ChoisirCouleurDessin(c2);
			RemplirRectangle(560,575,270,65);
			ChoisirCouleurDessin(c1);
			EcrireTexte(670,620,compteur,2);
		for(i=0;i<lig; i++) {		 
			for(j=a;b<col;j++) {
				if(point.larg[j]!=0 || point.longu[j]!=0){
					if (var==0){
						ChargerImage("./image/img1.jpg",point.x[j],point.y[j],point.larg[j],point.longu[j],(tailleimgx/col),(tailleimgy/lig));
					}
				}
				if(point.larg[j]==0 && point.longu[j]==0){
					vide = j;
					d=b;
					e=i;
					if(droite==1){
						ChargerImage("./image/img1.jpg", point.x[j-1], point.y[j-1], point.larg[vide-1],point.longu[vide-1],(tailleimgx/col),(tailleimgy/lig));
					} else if (gauche==1) {
						ChargerImage("./image/img1.jpg", point.x[j+1], point.y[j+1], point.larg[vide+1],point.longu[vide+1],(tailleimgx/col),(tailleimgy/lig));
					} else if (haut==1){
						ChargerImage("./image/img1.jpg", point.x[j+col], point.y[j+col], point.larg[vide+col],point.longu[vide+col],(tailleimgx/col),(tailleimgy/lig));
					} else if (bas==1){
						ChargerImage("./image/img1.jpg", point.x[j-col], point.y[j-col], point.larg[vide-col],point.longu[vide-col],(tailleimgx/col),(tailleimgy/lig));
					}
					ChargerImage("./image/Blanc.jpg", point.x[j], point.y[j], point.larg[j], point.longu[j],(tailleimgx/col),(tailleimgy/lig));


				}

				a=j+1;			
				b++;
			}
			b=0;
	
		}
		}

		if(imag==2){
			ChargerImageFond("./image/Menu-jeu-img2.bmp");
			imag=4;
		}
		if(img==2){
			sprintf(compteur,"%d",coup);  
			ChoisirCouleurDessin(c2);
			RemplirRectangle(538,602,250,72);
			ChoisirCouleurDessin(c1);
			EcrireTexte(650,650,compteur,2);
		for(i=0;i<lig; i++) {		  
			for(j=a;b<col;j++) {
				if(point.larg[j]!=0 || point.longu[j]!=0){
					if (var==0){
						ChargerImage("./image/img2.png",point.x[j],point.y[j],point.larg[j],point.longu[j],(tailleimgx/col),(tailleimgy/lig));
					}
				}
				if(point.larg[j]==0 && point.longu[j]==0){
					vide = j;
					d=b;
					e=i;
					if(droite==1){
						ChargerImage("./image/img2.png", point.x[j-1], point.y[j-1], point.larg[vide-1],point.longu[vide-1],(tailleimgx/col),(tailleimgy/lig));
					} else if (gauche==1) {
						ChargerImage("./image/img2.png", point.x[j+1], point.y[j+1], point.larg[vide+1],point.longu[vide+1],(tailleimgx/col),(tailleimgy/lig));
					} else if (haut==1){
						ChargerImage("./image/img2.png", point.x[j+col], point.y[j+col], point.larg[vide+col],point.longu[vide+col],(tailleimgx/col),(tailleimgy/lig));
					} else if (bas==1){
						ChargerImage("./image/img2.png", point.x[j-col], point.y[j-col], point.larg[vide-col],point.longu[vide-col],(tailleimgx/col),(tailleimgy/lig));
					}
					ChargerImage("./image/Blanc.jpg", point.x[j], point.y[j], point.larg[j], point.longu[j],(tailleimgx/col),(tailleimgy/lig));


				}
			
				a=j+1;			
				b++;
			}
			b=0;
	
		}
		}
		
		if(imag==3){
			ChargerImageFond("./image/Menu-jeu-img3.bmp");
			imag=4;
		}
		if(img==3){
			sprintf(compteur,"%d",coup);  
			ChoisirCouleurDessin(c2);
			RemplirRectangle(538,602,250,72);
			ChoisirCouleurDessin(c1);
			EcrireTexte(650,650,compteur,2);
		for(i=0;i<lig; i++) {		 
			for(j=a;b<col;j++) {
				if(point.larg[j]!=0 || point.longu[j]!=0){
					if (var==0){
						ChargerImage("./image/img3.jpg",point.x[j],point.y[j],point.larg[j],point.longu[j],(tailleimgx/col),(tailleimgy/lig));
					}
				}
				if(point.larg[j]==0 && point.longu[j]==0){
					vide = j;
					d=b;
					e=i;
					if(droite==1){
						ChargerImage("./image/img3.jpg", point.x[j-1], point.y[j-1], point.larg[vide-1],point.longu[vide-1],(tailleimgx/col),(tailleimgy/lig));
					} else if (gauche==1) {
						ChargerImage("./image/img3.jpg", point.x[j+1], point.y[j+1], point.larg[vide+1],point.longu[vide+1],(tailleimgx/col),(tailleimgy/lig));
					} else if (haut==1){
						ChargerImage("./image/img3.jpg", point.x[j+col], point.y[j+col], point.larg[vide+col],point.longu[vide+col],(tailleimgx/col),(tailleimgy/lig));
					} else if (bas==1){
						ChargerImage("./image/img3.jpg", point.x[j-col], point.y[j-col], point.larg[vide-col],point.longu[vide-col],(tailleimgx/col),(tailleimgy/lig));
					}
					ChargerImage("./image/Blanc.jpg", point.x[j], point.y[j], point.larg[j], point.longu[j],(tailleimgx/col),(tailleimgy/lig));


				}

				a=j+1;			
				b++;
			}
			b=0;
	
		}
		}
		droite=0;
		gauche=0;
		bas=0;
		haut=0;
		


		rep=Touche();  					/* Stockage du mouvement choisit */

		while (rep!=65361 && rep!= 65362 && rep!= 65363 && rep!= 65364 && rep!= 65307){  /* Verification de la validité du mouvement */
				rep=Touche();		 /* Si non valide, on rappel la fonction pour avoir un mouvement valide */
			}

		if(rep==65307){   /* Boucle if permettant le mouvement */
			exit(0);
		} else if(rep == 65361 && d<col-1){  		
			temp=point.larg[vide];
			point.larg[vide]=point.larg[vide+1];
			point.larg[vide+1]=temp;
			temp=0;
			temp=point.longu[vide];
			point.longu[vide]=point.longu[vide+1];
			point.longu[vide+1]=temp;
			temp=0;
			droite=1;
			coup++;

		} else if(rep == 65363 && d>0) { 
			temp=point.larg[vide];
			point.larg[vide]=point.larg[vide-1];
			point.larg[vide-1]=temp;
			temp=0;
			temp=point.longu[vide];
			point.longu[vide]=point.longu[vide-1];
			point.longu[vide-1]=temp;
			temp=0;
			gauche=1;
			coup++;

		} else if (rep == 65362 && e<lig-1) {  
			temp=point.larg[vide];
			point.larg[vide]=point.larg[vide+col];
			point.larg[vide+col]=temp;
			temp=0;
			temp=point.longu[vide];
			point.longu[vide]=point.longu[vide+col];
			point.longu[vide+col]=temp;
			temp=0;
			bas=1;
			coup++;
		
		} else if (rep== 65364 && e>=1){ 
			temp=point.larg[vide];
			point.larg[vide]=point.larg[vide-col];
			point.larg[vide-col]=temp;
			temp=0;
			temp=point.longu[vide];
			point.longu[vide]=point.longu[vide-col];
			point.longu[vide-col]=temp;
			temp=0;
			haut=1;
			coup++;

		}
		var=1;
		a=0;
		alea=5;
		vide=0;
		e=0;

		for(j=0;j<col*lig;j++){    /* Verification de victoire */
			if(point.larg[j]==point.larg1[j] && point.longu[j]==point.longu1[j]){
					b++;
				}
			}

		if(b==(col*lig)){ 		/* Affichage de l'écran de fin */
			EffacerEcran(c2);
			if(img==1){
				ChargerImageFond("./image/Ecran-fin-img1.bmp");
				sprintf(compteur,"%d",coup);  
				ChoisirCouleurDessin(c1);
				EcrireTexte(671,240,compteur,2);
			}
			if(img==2){
				ChargerImageFond("./image/Ecran-fin-img2.bmp");
			}
			if(img==3){
				ChargerImageFond("./image/Ecran-fin-img3.bmp");
			}
			while(a==0){  /* Boucle while permettant de programmer les zones de clique pour les boutons rejouer et quitter */
				if (img==1){
					if (SourisCliquee()){
						if (546<=_X && _X<=840 && 360<=_Y && _Y<=438){
							a++;
						}
						if (546<=_X && _X<=840 && 591<=_Y && _Y<=672){
							FermerGraphique();
							exit(0);
						}
					}	
				}
				else {
					sprintf(compteur,"%d",coup);  
					ChoisirCouleurDessin(c1);
					EcrireTexte(590,530,compteur,2);
					if (SourisCliquee()){
						if (146<=_X && _X<=441 && 595<=_Y && _Y<=675){
							a++;
						}
						if (456<=_X && _X<=750 && 595<=_Y && _Y<=675){
							FermerGraphique();
							exit(0);
						}	
				}
			}
			}
			z=1;
		}			
		a=0;
		b=0;
		j=0;
		temp=0;
		i=0;
		c=1;
	}
	}
}
