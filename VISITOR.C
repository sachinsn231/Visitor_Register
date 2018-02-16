#include "MYPRO.h"
void main()
{
	int n;
	clrscr();
	start();
	if(GetPassword()==0)
	return;
	while(1)
	{
		clrscr();
		menu();
		gotoxy(23,23);
		textcolor(4);
		cprintf("Enter Appropriate Value");
		textcolor(WHITE);
		gotoxy(50,23);
		cscanf("%d",&n);
		switch(n)
		{
			case 1: clrscr();
				EntryInRegister();
				break;
			case 2: clrscr();
				Title();
				ShowRecord();
				break;
			case 3: clrscr();
				search();
				break;
			case 4:	TimeOut();
				break;
			case 5: clrscr();
				Delete();
				break;
			case 6: clrscr();
				Update();
				break;
			case 7:	exit(0);
				break;
		}
		getch();
	}
}