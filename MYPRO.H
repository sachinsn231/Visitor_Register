#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
struct Register
{
	int SrNo;
	char Name[30];
	char ToWhom[30];
	char Mobile[11];
	char TimeIn[10],TimeOut[10],Date[20];
}R;
struct date d;
char day[10],month[10],year[10];
FILE *f,*p;
int SrNo,ExtraSrNo,found;
void EntryInRegister()
{
	printf("\nEnter serial no. = ");
	scanf("%d",&R.SrNo);
	printf("\nEnter name = ");
	scanf("%s",R.Name);
	printf("\nEnter to whom = ");
	scanf("%s",R.ToWhom);
	printf("\nEnter mobile = ");
	scanf("%s",R.Mobile);
	printf("\nEnter Time IN = ");
	scanf("%s",R.TimeIn);
	strcpy(R.TimeOut,"");
	getdate(&d);
	itoa((int)d.da_day,day,10);
	itoa((int)d.da_mon,month,10);
	itoa((int)d.da_year,year,10);
	strcpy(R.Date,day);
	strcat(R.Date,"/");
	strcat(R.Date,month);
	strcat(R.Date,"/");
	strcat(R.Date,year);
	f=fopen("Visitor.txt","a+");
	fwrite(&R,sizeof(R),1,f);
	fclose(f);
	printf("\nRecord has been saved in FILE");
	getch();
}
void Update()
{       int a,pos=0;
	clrscr();
	printf("Enter serial no whose record is to update");
	scanf("%d",&ExtraSrNo);
	f=fopen("visitor.txt","r");
	fseek(f,0,0);
	while(!feof(f))
	{
	fread(&R,sizeof(R),1,f);
	if(R.SrNo==ExtraSrNo)
	{
		printf("Enter 1 for YES & 2 for NO\n");
		printf("\nDo you want to change the name	");
		scanf("%d",&a);
		if(a==1)
		{
		printf("Enter name	");
		scanf("%s",R.Name);
		}
		printf("Do you want to change to whom	    ");
		scanf("%d",&a);
		if(a==1)
		{
		printf("Enter To whom");
		scanf("%s",R.ToWhom);
		}
		printf("Do you want to change the Mobile no");
		scanf("%d",&a);
		if(a==1)
		{
		printf("Enter Mobile No");
		scanf("%s",R.Mobile);
		}
		pos=ftell(f);
		fclose(f);
		break;

	}
	else
	{
	printf("\nrecord not found");
	getch();
	return;
	}
	}
  fopen("visitor.txt","rb+");
  fseek(f,pos-sizeof(R),0);
  fwrite(&R,sizeof(R),1,f);
  fclose(f);
  getch();
  return;
}

void TimeOut()
{
	int pos=0;
	clrscr();
	printf("\nEnter Serial Number for which Time out is SET	");
	scanf("%d",&ExtraSrNo);
	f=fopen("Visitor.txt","r");
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(R.SrNo==ExtraSrNo)
		{
			found=1;
			printf("\nEnter Time out	");
			scanf("%s",R.TimeOut);
			pos=ftell(f);
			break;
		}
	}
	fclose(f);
	if(found==-1)
	{
		printf("\nRecord NOT FOUND");
		getch();
		return;
	}
	f=fopen("Visitor.txt","rb+");
	fseek(f,pos-sizeof(R),0);
	fwrite(&R,sizeof(R),1,f);
	fclose(f);
	printf("\nRecord Saved");
	getch();
	return;
}

/*void search()
{

	f=fopen("visitor.txt","r");
	clrscr();
	gotoxy(20,7);
	printf("\nEnter a serial no.to be searched\t");
	scanf("%d",&ExtraSrNo);
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(R.SrNo==ExtraSrNo)
		{
			found=1;
			break;
		}
	 }
	 if(found==1)
	   {    gotoxy(24,13);
		printf("FOUND");
	   }
	 else
	 {      gotoxy(24,13);
		printf("NOT FOUND");
	 }
	 getch();
	 return;
} */
void search()
{
	int x;
	clrscr();
	gotoxy(35,4);
	textcolor(YELLOW);
	cprintf("SEARCH MENUS");
	gotoxy(25,6);
	for(x=1;x<=35;x++)
	printf("*");
	gotoxy(25,20);
	for(x=1;x<=35;x++)
	 printf("*");
	 for(x=6;x<=20;x++)
	 {
	 gotoxy(25,x);
	 printf("*");
	 }
	 for(x=6;x<=20;x++)
	 {
	 gotoxy(59,x);
	 printf("*");
	 }
	 gotoxy(28,8);
	 textcolor(4);
	 cprintf("1. By SERIAL NO.");
	 gotoxy(28,10);
	 textcolor(3);
	 cprintf("2. By NAME");
	 gotoxy(28,12);
	 textcolor(GREEN);
	 cprintf("3. By MOBILE NO.");
	 gotoxy(28,14);
	 textcolor(5);
	 cprintf("4. By DATE");
	 gotoxy(28,16);
	 textcolor(9);
	 cprintf("5. EXIT");
	 gotoxy(28,18);

	 printf("Enter appropriate VALUE	");
	 scanf("%d",&x);
	 if(x==5)
	 return;
	 searching(x);
	 getch();
 }
 int searching(int x)
 {
	 if(x==1)
	 {
	f=fopen("visitor.txt","r");
	clrscr();
	gotoxy(20,7);
	printf("\nEnter a serial no.to be searched\t");
	scanf("%d",&ExtraSrNo);
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(R.SrNo==ExtraSrNo)
		{
			found=1;
			printf("\n\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",R.SrNo,R.Name,R.ToWhom,R.Mobile,R.TimeIn,R.TimeOut,R.Date);
		}
	 }
	 if(found==-1)
	 {      gotoxy(24,13);
		printf("NOT FOUND");
	 }
	 getch();

	 }
	 else if(x==2)
	 {
	char y[30];
	f=fopen("visitor.txt","r");
	clrscr();
	gotoxy(20,7);
	printf("\nEnter a name to be searched\t");
	scanf("%s",y);
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(strcmp(y,R.Name)==0)
		{
			found=1;
			printf("\n\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",R.SrNo,R.Name,R.ToWhom,R.Mobile,R.TimeIn,R.TimeOut,R.Date);
		}
	 }
	 if(found==-1)
	 {      gotoxy(24,13);
		printf("NOT FOUND");
	 }
	 getch();

	 }
	 else if(x==3)
	 {

	char y[30];
	f=fopen("visitor.txt","r");
	clrscr();
	gotoxy(20,7);
	printf("\nEnter a mobile number to be searched\t");
	scanf("%s",y);
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(strcmp(y,R.Mobile)==0)
		{
			found=1;
			printf("\n\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",R.SrNo,R.Name,R.ToWhom,R.Mobile,R.TimeIn,R.TimeOut,R.Date);
		}
	 }
	 if(found==-1)
	 {      gotoxy(24,13);
		printf("NOT FOUND");
	 }
	 getch();

	 }
	else if(x==4)
	{
	char y[30];
	f=fopen("visitor.txt","r");
	clrscr();
	gotoxy(20,7);
	printf("\nEnter a DATE to be searched in the format dd/mm/yyyy\t");
	scanf("%s",y);
	found=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(strcmp(y,R.Date)==0)
		{
			found=1;
			printf("\n\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n",R.SrNo,R.Name,R.ToWhom,R.Mobile,R.TimeIn,R.TimeOut,R.Date);
		}
	 }
	 if(found==-1)
	 {      gotoxy(24,13);
		printf("NOT FOUND");
	 }
	 getch();

	}
	search();
  return 0;


}

void Title()
{
       //	printf("\nSrNo\t   Name\t   ToWhom\t Mobile\tTime in  \tTime out\tDate");
	printf("\n%s%11s%11s%13s%10s%12s%11s","SrNo","Name","ToWhom","Mobile","Time In","Time Out","Date");
	printf("\n================================================================================\n");
}
void ShowRecord()
{       int y;
	f=fopen("Visitor.txt","r");
	fseek(f,0,0);
	SrNo=-1; y=4;
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		gotoxy(18,y);
		if(R.SrNo!=SrNo)
		{
			printf("\n%d%12s%12s%15s%10s%10s\t%11s",R.SrNo,R.Name,R.ToWhom,R.Mobile,R.TimeIn,R.TimeOut,R.Date);
		}
		SrNo=R.SrNo;
		y++;
	}
	fclose(f);
	getch();
}
void start()
{
	int a,b,n;
	a=DETECT;
	clrscr();
	initgraph(&a,&b,"");
	setbkcolor(BLUE);
	setcolor(GREEN);
	rectangle(10,10,630,470);
	setcolor(YELLOW);
	rectangle(15,15,625,465);
	setcolor(11);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,8);
	outtextxy(50,50,"Visitor Register");
	setcolor(RED);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(520,130,"1.0");
	setcolor(14);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	outtextxy(50,300,"Designed and Developed by Us");
	outtextxy(50,320,"C-BATCH, CIT Computer Education");
	outtextxy(50,340,"Copyright and Release Version 1.0 ");
	for(n=1;n<=24;n++)
	{
		setcolor(GREEN);
		setfillstyle(XHATCH_FILL,YELLOW);
		bar3d(25*n,400,70,420,1,1);
		delay(100);
	}
	cleardevice();	// to clear the graphics loaded screen
	closegraph();	// to close the graphics that has been initialised first.
}
void Delete()
{
	f=fopen("Visitor.txt","r");
	p=fopen("Extra.txt","a+");
	printf("\nEnter Serial Number to be deleted	");
	scanf("%d",&ExtraSrNo);
	found=-1;
	SrNo=-1;
	fseek(f,0,0);
	while(!feof(f))
	{
		fread(&R,sizeof(R),1,f);
		if(R.SrNo!=ExtraSrNo)
		{
			if(R.SrNo!=SrNo)
				fwrite(&R,sizeof(R),1,p);
			SrNo=R.SrNo;
		}
	}
	fclose(f);
	fclose(p);
/*	if(found==-1)
	{
		printf("\nNUMBER not FOUND to delete");
		getch();
		return;
	}*/
	remove("Visitor.txt");
	rename("Extra.txt","Visitor.txt");
	printf("\nRecord Deleted");
	getch();
	return;
}
int GetPassword()
{
	char str[20];
	int x=1;
	while(x<=3)
	{
		clrscr();
		gotoxy(24,12);
		if(strcmp(strcpy(str,getpass("Enter Password : ")),"123")!=0)
		{
			gotoxy(24,13);
			printf("WRONG CREDENTIAL");
			gotoxy(24,14);
			printf("TRY AGAIN");
			getch();
		}
		else
			return x;
		x++;
	}
	if(x==4)
		return 0;
	else
		return x;
}
void menu()
{
	int x;
	clrscr();
	gotoxy(37,3);
	textcolor(YELLOW);
	cprintf("MENUS");
	gotoxy(20,5);
	textcolor(WHITE);
	for(x=1;x<=40;x++)
		printf("è");
	gotoxy(20,25);
	textcolor(WHITE);
	for(x=1;x<=40;x++)
		printf("è");
	for(x=6;x<=24;x++)
	{
		gotoxy(20,x);
		printf("è");
	}
	for(x=6;x<=24;x++)
	{
		gotoxy(59,x);
		printf("è");
	}

	gotoxy(28,7);
	textcolor(2);
	cprintf("1. ENTRY in Register");
	gotoxy(28,9);
	textcolor(3);
	cprintf("2. VIEW Register");
	gotoxy(28,11);
	textcolor(4);
	cprintf("3. SEARCH in Register");
	gotoxy(28,13);
	textcolor(5);
	cprintf("4. TIMEOUT");
	gotoxy(28,15);
	textcolor(6);
	cprintf("5. DELETE from Register");
	gotoxy(28,17);
	textcolor(7);
	cprintf("6. UPDATE from Register");
	gotoxy(28,19);
	textcolor(9);
	cprintf("7. Exit");
}