/* ==============  Program Description  ============= */
/*   program name : SNAKE'S RUN game                  */
/*                                                    */
/* ================================================== */

#include	<iostream.h>
#include	<conio.h>
#include	<graphics.h>
#include	<conio.h>
#include	<stdlib.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<time.h>

#define Finish	100

	/*	Global Declearation	*/
int BaseX=195,BaseY=370,PlayerNo,CurrentPossision[10],PlayersValue[10];
int BoardCaution[100],PlayerRank[10],tag[100],Rank=1,RunStart[10];
char PlayerName[10][15];

	/*	function for forward or backward	*/
void Board_Caution(){

	for(int i=0;i<=100;i++)
		BoardCaution[i]=0;

	/*	Advance Forward from Current Possition	*/
	BoardCaution[4]=5;
	BoardCaution[21]=3;
	BoardCaution[29]=2;
	BoardCaution[34]=11;
	BoardCaution[47]=5;
	BoardCaution[61]=4;
	BoardCaution[74]=10;
	BoardCaution[88]=3;
	BoardCaution[94]=2;

	/*	Advance Backward from Current Possition	*/
	BoardCaution[6]=-5;
	BoardCaution[11]=-8;
	BoardCaution[16]=-6;
	BoardCaution[24]=-6;
	BoardCaution[36]=-16;
	BoardCaution[49]=-10;
	BoardCaution[57]=-5;
	BoardCaution[64]=-25;
	BoardCaution[77]=-15;
	BoardCaution[84]=-8;
	BoardCaution[91]=-6;
	BoardCaution[95]=-35;


}

	/*	Draw the game board	*/
void DrawBoard(){

	int i,j,k;
	int x,y,x1,y1,x2,y2;

	char str[4],ch[4];

	outtextxy(150,15,"LET\'S SOME FUN, FRIENDS!!");
	outtextxy(330,45,"\"SNAKES RUN\"");
	outtextxy(10,55,"Total Player No# is: ");
	outtextxy(170,55,itoa(PlayerNo,str,10)); //show the player no.

		/* Show the player name in the board	*/
	outtextxy(10,87,"Player\'s Position:");

	//x=5;y=110;	// for outtextxy
	x=10;y=100;// for gotoxy
	for(i=1;i<=PlayerNo;i++){  //	show players name
		outtextxy(x,y,PlayerName[i]);
		/*outtextxy(120,y,": ");
		outtextxy(140,y,itoa(CurrentPossision[i],ch,10));
		y=y+25;   */
		y=y+16;
	}
	x=1; y=7;
	for(i=1;i<=PlayerNo;i++){  //	show players possision
		gotoxy(x,y);
		//cout<<PlayerName[i]);
		gotoxy(x+10,y);
		cout<<": "<<CurrentPossision[i];
		y=y+1;
		}

		   /*	Draw the Horizantel line Change 'Y' Coordinate	*/
	x1=195;x2=635;y1=y2=60;
	for(i=0;i<=10;i++){
		line(x1,y1,x2,y2);
		y1=y2+=31;
	}
	   /*	Draw the Vartical line Change 'X' Coordinate	*/
	x1=x2=195;y1=60;y2=370;
	for(j=0;j<=10;j++){
		line(x1,y1,x2,y2);
		x1=x2+=44;
	}

	Board_Caution(); /* Advance forward backword set.*/

	/*	Printing values in the block	*/
	int l=100;
	char cau[3];
	x=605;y=80;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			outtextxy(x,y,itoa(l,str,10));
			if(BoardCaution[l]!=0)
				outtextxy(x,(y-12),itoa(BoardCaution[l],cau,10));
			l--;
			x-=44;
		}
		x=610;
		y+=31;
	}

	/*	Rules of Game show below the board	*/
	outtextxy(60,380,"Rules of \"SNACK\'S RUN\" Game.");
	outtextxy(30,390,"=> Players have only one chance to draw DIE & Never be RETURNED.");
	outtextxy(30,400,"=> Player must start RUN from gain of \'1\'.");
	outtextxy(30,410,"=> After ACivED the FINAL point, Player must loss his\/her drawing chance.");
	outtextxy(30,420,"=> Enter \'7\' for Exit ANY time from the game.");
}

	/*	For first page of game	*/
InitPlay(){
	int n;
	char ch,y_n;

	cout<<"\n\n\n\t\t\tLET\'S SOME FUN, FRIENDS!!";
	cout<<"\n\n\t\tWELCOME to the \"SNAKES RUN\" games world.";
	cout<<"\n\n\n\n\tEnter the Number of Player(2-7) : ";
	gotoxy(23,23);
	cout<<"Press ENTER to Exit.";

	ch=getche();
	if(ch=='\r'){
		gotoxy(5,23);
		cout<<"Press ANY key to Exit.";
		exit(1);
		}
	else if(!isdigit(ch)){
		gotoxy(10,13);
		cout<<"You Have to press any NUMBER with in 2-7.";
		cout<<"\n\n\t\t Do you want to Exit(y/n):";
		cin>>y_n;
		if(y_n=='y')
			exit(1);
		else{
			cout<<"\n\t\tEnter a Number with in 2-7 : ";
			cin>>ch;
			if(isdigit(ch))
				PlayerNo=ch-48;
			else
				exit(1);
			}


		}
	else 		/* The player is in right way. */
		PlayerNo=ch-48;



	if(PlayerNo>7||PlayerNo<2){
		cout<<"\n\n\t You have to ENTER within 2-7. ";
		cout<<"\n\t Enter any key to exit.";
		getch();
		exit(1);
		}
	else{          /*	Entry for Player Name	*/
		clearviewport();
		gotoxy(1,1);
		cout<<"\n\t\t\tLET\'S SOME FUN, FRIENDS!!";
		cout<<"\n\t\tWELCOME to the \"SNAKES RUN\" games world.";
		cout<<"\n\n\t\t\tTotal Player Number is : "<<PlayerNo;

		gotoxy(30,8);
		cout<<"Enter the Player\'s Name :\n";
		cout<<"\t\t\tName must be UNDER 5 letters.\n";
		for(int i=1;i<=PlayerNo;i++){
			cout<<"\n\t\t Name of the Player No# "<<i<<" : ";
			cin>>PlayerName[i];
			if(i==PlayerNo){       // if the entry is last player
				gotoxy(23,25);
				cout<<"Press any key to continue......";
				getch();
				}
			}

	}

	clearviewport();
	return 0;
}
	/* 	Draw pool within 1-6	*/

int DrawPool(){
	int m;
	char ch;
	//cout<<"Press Enter to Pool.";
	ch=getche();
	while(1){
	if(ch=='7'){
		clearviewport();
		gotoxy(20,10);
		cout<<"Thanks to used SNAK\'S RUN game...";
		gotoxy(30,23);
		cout<<"Enter ANY KEY to exit.";
		getch();
		exit(1);
		}
	else{
		m=rand()%7;
		if(m==0){
			while(1){
				m=rand()%7;
				if(m==0)
					continue;
				else
					break;
			}
		}

		else
			break;
		}

	}
	/*gotoxy(1,21);
	cout<<"You Gain : "<<m;
	*/
	return m;

}
	/*	The ending sms of the play	*/
GameEnd(){
	clearviewport();
	int x,y;
	x=30; y=2;
	gotoxy(x,y);
	cout<<"SNAKE\'S RUN!!!";
	x-=5;y+=2;
	gotoxy(x,y+=2);
	cout<<"The total player no was : "<<PlayerNo<<".";
	gotoxy(x,y+=2);
	cout<<"The player Ranking is:";
	for(int i=1;i<=PlayerNo;i++){
		gotoxy(x,y);
		cout<<PlayerName[i];
		gotoxy(x+8,y+=2);
		cout<<"  :"<<PlayerRank[i]+1;
	}
	gotoxy(20,24);
	cout<<"Thanks to Play Snake\'s Run game.";
	gotoxy(20,25);
	cout<<"Press any key to Exit.";
	getch();
	exit(1);
	return 0;
}

	/* 	Players Possision count	*/
PlayersPossision(){
	int Add,Total,x=13,y=7;//x=140,y=110;
	//int Count=0;
	char ch[4];
	while(1){
		DrawBoard();
		for(int i=1;i<=PlayerNo;i++){
			gotoxy(1,20);
			cout<<"Term of Player : "<<"      ";
			gotoxy(1,20);
			cout<<"Term of Player : "<<PlayerName[i];

			if(CurrentPossision[i]<Finish){
				Add=DrawPool();
				gotoxy(1,21);
				cout<<"====================";
				gotoxy(1,22);
				cout<<"        ";
				gotoxy(1,22);
				cout<<PlayerName[i];
				gotoxy(10,22);
				cout<<"GAIN : "<<Add;

				if(Add==1&&RunStart[i]==0)
					RunStart[i]=1; //Start to Play from 1
				if(CurrentPossision[i]+Add<=Finish&&RunStart[i]==1){
					CurrentPossision[i]+=Add;
					CurrentPossision[i]+=BoardCaution[CurrentPossision[i]];
					}
				if(CurrentPossision[i]==Finish)
					PlayerRank[i]=Rank++;

				}


			gotoxy(x,y);
			cout<<"   ";
			gotoxy(x,y);
			cout<<CurrentPossision[i];
			y+=1;

			if((y-7)==PlayerNo)
				y=7;
			if(Rank>=PlayerNo-1){
				getch();
				for(i=1;i<=PlayerNo;i++)
					if(CurrentPossision[i]!=Finish)
						PlayerRank[i]=Rank++; // For last players ranking
				GameEnd();
				}
		}



	}
}

	/* main function	*/

void main()
{
	   /* request auto detection */
	int     driver = DETECT,mode,errorcode;
	int     i;

		/* initialize graphics and local variables */
	initgraph(&driver,&mode,"c:\\tc\\bgi");

		/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		cout<<"Graphics error: %s\n", grapherrormsg(errorcode);
		cout<<"Press any key to halt:";
		getch();
		exit(1); /* terminate with an error code */
	}
		/*	Set Players init Possision	*/
	for(i=0;i<=100;i++){
		CurrentPossision[i]=0;
		tag[i]=0;
		}
	for(i=0;i<=10;i++)
		RunStart[i]=0;
	InitPlay();
	DrawBoard();
	//DrawPool();
	PlayersPossision();

	getch();
	closegraph();
}
