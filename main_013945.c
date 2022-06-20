#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

	
	/*variável de escopo global*/
	char player_name[21];
    int pontos;
	
	EscolherLevel(){
		int esc;
		system("cls");
		
		printf("\n ESCOLHA O NIVEL \n");
		printf("\n 1- MEDIUM");
		printf("\n 2- HARD");
		printf("\n 3- IMPOSSIVEL");
		printf("\n 4- VOLTAR AO MENU INICIAL \n");
		scanf("%i",&esc);
		
		switch(esc){
			case 1:levelMedium();
			break;
			
			case 2:levelHard();
			break;
			
			case 3:levelImpossible();
			break;
			
			case 4:main();
			break;
			
			default:printf("Escolha invalida");
			break;
		}
	}
	
	ShowFile(){
	FILE*file;
	file = fopen("Game_pontos.txt", "r"); 
	char file_content[150];
	
	while(!feof(file)){
		fgets(file_content, 150, file);
		puts(file_content);
	} 
	
	fclose(file);
	}
	
	
	
main(){
	int op;
	printf("\n Player_name:");
	gets(player_name);
	
	system("cls");
	system("color 3F");
	
	printf("\n        XPTO          ");
	printf("\n<========================>");
	printf("\n  1- MODO HISTORIA");
	printf("\n  2- MODO VIDA INFINITA");
	printf("\n  3- ESCOLHER NIVEL");
	printf("\n  4- SAIR \n");
	scanf("%i",&op);
	
	switch(op){
		case 1:mainH();
		break;
		case 2:VidaInfinita();
		break;
		case 3:EscolherLevel();
		break;
		case 4:break;
		break;
		
		default:
		printf("\n escolha invalida");
		break;
	}
	
	
}

	/*NIVEIS*/
	
	/*NIVEL MEDIO*/
	levelMedium(){
			system("cls");
	
		/*valores aleatorias p/ linha e coluna (bombas)*/
	long int t;
	int col = time(&t)%5 + 0; /* valores entre 0 e 4 */
	
	
	
	long int u;
	int lin = time(&u)%5 + 0; /* valores entre 0 e 4 */

	

	
	
		/*valores aleatorias p/ linha e coluna (vidas)*/
	int v;
	int colu = time(&v)%5 + 0; /* valores entre 0 e 4 */

	
	
	int w;
	int li = time(&w)%5 + 0; /* valores entre 0 e 4 */
	printf("%i",li);


	
	
	 
	char campo[5][5], play;
	int l,c;
	int vPosicao[2] ={4,0};
	int vLocal[5] ={4,3,2,1,0};
	int life=7;
	
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		campo[l][c]='.';	
	}
	}
	
	
	campo[0][4]='F';
	
	campo[4][0]='J';
	
	/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	/*corpo principal*/
	
     while(life!=-1 || life>0){
    printf("vidas restantes: %d \n ",life);
	printf("informe a sua jogada {W,A,S,D}:");
	scanf("%c",&play);
	
	printf("\n");
	
	
	
	
	/*olha boooombaaaaaa !! mayday mayday !!!*/
	
		if(campo[col][lin]=='J'){
		system("cls");
		printf("\n BOMBA");
		life=0;
		
	}
	
	/*  +50 HP   */
	
		if(campo[colu][li]=='J'){
		printf("\n BAU [+50HP]");
		life=life+8;
		
	}
	
	
	
	
	if( (play=='W') || (play=='w') ){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
	
			
		life-=2;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");	
		
			/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
		if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
			 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		} 
		

			
	}else if((play=='s') || (play=='S')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=2;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");

		
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='d') || (play=='D')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=2;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='a') || (play=='A')){
		
		/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		/*jogadas invalidas*/
		
			if(campo[vPosicao[0]][vPosicao[1]] ==campo[4][0] ){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[3][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[2][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[1][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[0][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}
		
		
		life-=2;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
	
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
			printf("<------------------------PARABENS---------------------------> \n");
			printf("%s \n",player_name);
			ShowFile();
			break;
		}
	
	
 }
 printf("\n VIDA: %i \n",life);
 system("pause");
 system("cls");
 
  if(life==-1 || life<0){
  	printf("MORREU");
  	ShowFile();
  }
	}
	/*<--------->*/
	
	/*NIVEL HARD*/
	
	levelHard(){
	
	
		system("cls");
	
		/*valores aleatorias p/ linha e coluna (bombas)*/
	long int t;
	int col = time(&t)%5 + 0; /* valores entre 0 e 4 */

	
	
	long int u;
	int lin = time(&u)%5 + 0; /* valores entre 0 e 4 */
	
	

	
	
		/*valores aleatorias p/ linha e coluna (vidas)*/
	int v;
	int colu = time(&v)%5 + 0; /* valores entre 0 e 4 */
	
	
	
	int w;
	int li = time(&w)%5 + 0; /* valores entre 0 e 4 */
	


	
	
	 
	char campo[5][5], play;
	int l,c;
	int vPosicao[2] ={4,0};
	int vLocal[5] ={4,3,2,1,0};
	int life=7;
	
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		campo[l][c]='.';	
	}
	}
	
	
	campo[0][4]='F';
	
	campo[4][0]='J';
	
	/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	/*corpo principal*/
	
     while(life!=-1 || life>0){
    printf("vidas restantes: %d \n ",life);
	printf("informe a sua jogada {W,A,S,D}:");
	scanf("%c",&play);
	
	printf("\n");
	
	
	
	
	/*olha boooombaaaaaa !! mayday mayday !!!*/
	
		if(campo[col][lin]=='J'){
		system("cls");
		printf("\n BOMBA");
		life=0;
		
	}
	
	/*  +50 HP   */
	
		if(campo[colu][li]=='J'){
		printf("\n BAU [+50HP]");
		life=life+10;
		
	}
	
	
	
	
	if( (play=='W') || (play=='w') ){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
	
			
		life-=4;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");	
		
			/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
		if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
			 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		} 
		

			
	}else if((play=='s') || (play=='S')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=4;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");

		
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='d') || (play=='D')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=4;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='a') || (play=='A')){
		
		/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		/*jogadas invalidas*/
		
			if(campo[vPosicao[0]][vPosicao[1]] ==campo[4][0] ){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[3][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[2][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[1][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[0][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}
		
		
		life-=4;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
	
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
			printf("<------------------------PARABENS---------------------------> \n");
			printf("%s \n",player_name);
			ShowFile();
			break;
		}
	
	
 }
 printf("\n VIDA: %i \n",life);
 system("pause");
 system("cls");
 
  if(life==-1 || life<0){
  	printf("MORREU");
  	ShowFile();
  }
}
	
	/*<-------->*/
	
	/*NIVEL IMPOSSIBLE*/
	
	levelImpossible(){
		
			system("cls");
	
		/*valores aleatorias p/ linha e coluna (bombas)*/
	long int t;
	int col = time(&t)%5 + 0; /* valores entre 0 e 4 */
	
	
	long int u;
	int lin = time(&u)%5 + 0; /* valores entre 0 e 4 */

	

	
	
		/*valores aleatorias p/ linha e coluna (vidas)*/
	int v;
	int colu = time(&v)%5 + 0; /* valores entre 0 e 4 */
	
	
	
	int w;
	int li = time(&w)%5 + 0; /* valores entre 0 e 4 */
	


	
	
	 
	char campo[5][5], play;
	int l,c;
	int vPosicao[2] ={4,0};
	int vLocal[5] ={4,3,2,1,0};
	int life=7;
	
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		campo[l][c]='.';	
	}
	}
	
	
	campo[0][4]='F';
	
	campo[4][0]='J';
	
	/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	/*corpo principal*/
	
     while(life!=-3 || life>0){
    printf("vidas restantes: %d \n ",life);
	printf("informe a sua jogada {W,A,S,D}:");
	scanf("%c",&play);
	
	printf("\n");
	
	
	
	
	/*olha boooombaaaaaa !! mayday mayday !!!*/
	
		if(campo[col][lin]=='J'){
		system("cls");
		printf("\n BOMBA");
		life=0;
		
	}
	
	/*  +50 HP   */
	
		if(campo[colu][li]=='J'){
		printf("\n BAU [+50HP]");
		life=life+15;
		
	}
	
	
	
	
	if( (play=='W') || (play=='w') ){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
	
			
		life-=5;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");	
		
			/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
		if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
			 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		} 
		

			
	}else if((play=='s') || (play=='S')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=5;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");

		
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='d') || (play=='D')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=5;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='a') || (play=='A')){
		
		/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		/*jogadas invalidas*/
		
			if(campo[vPosicao[0]][vPosicao[1]] ==campo[4][0] ){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[3][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[2][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[1][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[0][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}
		
		
		life-=2;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
	
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
			printf("<------------------------PARABENS---------------------------> \n");
			printf("%s \n",player_name);
			ShowFile();
			break;
		}
	
	
 }
 printf("\n VIDA: %i \n",life);
 system("pause");
 system("cls");
 
  if(life==-3 || life<0){
  	printf("MORREU");
  	ShowFile();
  }
	}
	
	/*<--------------->*/
	/*<-----FIM NIVEIS------>*/
	

/*ficheiro*/

int ficheiro(void){
	int Pontos;
	
	FILE*file;
	file = fopen("Game_pontos.txt", "w"); 

	Pontos =pontos; 

    fprintf(file, "\n Pontos: %i",pontos);	
	fclose(file);	
}
/*MODO VIDA INFINITA*/
VidaInfinita(){
	
	system("cls");
	

char campo[5][5], play;
	int l,c;
	int vPosicao[2] ={4,0};

	int life=1;
	
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		campo[l][c]='.';	
	}
	}
	
	
	campo[0][4]='.';
	
	campo[4][0]='J';
	
	/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	/*corpo principal*/
	
     while(life!=0 || life>0){
    printf("vidas restantes: %d \n ",life);
	printf("informe a sua jogada {W,A,S,D}:");
	scanf("%c",&play);
	
	printf("\n");
	
	
	if( (play=='W') || (play=='w') ){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
	
			
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");	
		
			/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	

		

			
	}else if((play=='s') || (play=='S')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");

		
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	

	
	}else if((play=='d') || (play=='D')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		

		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	}else if((play=='a') || (play=='A')){
		
		/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		/*jogadas invalidas*/
		
			if(campo[vPosicao[0]][vPosicao[1]] ==campo[4][0] ){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[3][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[2][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[1][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[0][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}
		
		

		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
	
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	}
		
 }
 printf("\n VIDA: %i \n",life);
 system("pause");
 system("cls");
 

}
/*MODO HISTÓRIA*/

mainH(){
	
		system("cls");
	
		/*valores aleatorias p/ linha e coluna (bombas)*/
	long int t;
	int col = time(&t)%5 + 0; /* valores entre 0 e 4 */

	
	
	long int u;
	int lin = time(&u)%5 + 0; /* valores entre 0 e 4 */

	

	
	
		/*valores aleatorias p/ linha e coluna (vidas)*/
	int v;
	int colu = time(&v)%5 + 0; /* valores entre 0 e 4 */

	
	
	int w;
	int li = time(&w)%5 + 0; /* valores entre 0 e 4 */



	
	
	 
	char campo[5][5], play;
	int l,c;
	int vPosicao[2] ={4,0};
	int vLocal[5] ={4,3,2,1,0};
	int life=7;
	
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		campo[l][c]='.';	
	}
	}
	
	
	campo[0][4]='F';
	
	campo[4][0]='J';
	
	/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	/*corpo principal*/
	
     while(life!=0 || life>0){
    printf("vidas restantes: %d \n ",life);
	printf("informe a sua jogada {W,A,S,D}:");
	scanf("%c",&play);
	
	printf("\n");
	
	
	
	
	/*olha boooombaaaaaa !! mayday mayday !!!*/
	
		if(campo[col][lin]=='J'){
		system("cls");
		printf("\n BOMBA");
		life=0;
		
	}
	
	/*  +50 HP   */
	
		if(campo[colu][li]=='J'){
		printf("\n BAU [+50HP]");
		life=life+5;
		
	}
	
	
	
	
	if( (play=='W') || (play=='w') ){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
	
			
		life-=1;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");	
		
			/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
		if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
			 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		} 
		

			
	}else if((play=='s') || (play=='S')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=1;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[0]=vPosicao[0]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");

		
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");	
		printf("\t");
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='d') || (play=='D')){
		
			/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		life-=1;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]+1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
		printf("<------------------------PARABENS---------------------------> \n");
		printf("%s \n",player_name);
		ShowFile();
			break;
		}
	
	}else if((play=='a') || (play=='A')){
		
		/*a cada jogada o jogador ganha +1 ponto
		e esse valor[pontos] é mostrado no ficheiro
		'Game_pontos'
		*/
		pontos++;
		ficheiro();
		
		/*jogadas invalidas*/
		
			if(campo[vPosicao[0]][vPosicao[1]] ==campo[4][0] ){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[3][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[2][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[1][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}else if(campo[0][0]=='J'){
			printf("JOGADA INVALIDA");
			break;
		}
		
		
		life-=1;
		campo[vPosicao[0]][vPosicao[1]] ='.';
		vPosicao[1]=vPosicao[1]-1;
		campo[vPosicao[0]][vPosicao[1]] ='J';
		
	
		system("cls");
		
		/*mostrar campo atual*/
	for(l=0;l<5;l++){
	for(c=0;c<5;c++){
		printf("%c",campo[l][c]);
		printf("\t");
		printf("\t");	
	}
	printf("\n \n");
	printf("\n \n");
	}
	}
	
	if(campo[vPosicao[0]][vPosicao[1]] ==campo[0][4]){
		 system("cls");
			printf("<------------------------PARABENS---------------------------> \n");
			printf("%s \n",player_name);
			ShowFile();
			break;
		}
	
	
 }
 printf("\n VIDA: %i \n",life);
 system("pause");
 system("cls");
 
  if(life==0 || life<0){
  	printf("MORREU");
  	ShowFile();
  }
 
}


