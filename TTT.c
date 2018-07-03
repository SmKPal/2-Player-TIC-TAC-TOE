#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<GL/glut.h>
int arr[3][3];
int screen=0;
int box,bx,by,player=1,moves=0;
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,800.0,600.0,0.0);
}
void draw1()
{
	glBegin(GL_LINES);
	glVertex2i(250,450);
	glVertex2i(250,150);
	glVertex2i(550,450);
	glVertex2i(550,150);
	glVertex2i(250,450);
	glVertex2i(550,450);
	glVertex2i(250,150);
	glVertex2i(550,150);
	glVertex2i(350,450);
	glVertex2i(350,150);
	glVertex2i(450,450);
	glVertex2i(450,150);
	glVertex2i(250,250);
	glVertex2i(550,250);
	glVertex2i(250,350);
	glVertex2i(550,350);
	glEnd();
	glFlush();
}
void display()
{
    if(screen==0)
    {
	   glClear(GL_COLOR_BUFFER_BIT);
	   glFlush();
	   screen++;
    }
	if(screen==1)
	draw1();
}
int getrow(int b)
{
    switch(b)
    {
       case 0:
       case 1:
       case 2:return 0;
              break;
       case 3:
       case 4:
       case 5:return 1;
              break;
       case 6:
       case 7:
       case 8:return 2;
              break;
    }
}
int getcol(int b)
{
    switch(b)
    {
       case 0:
       case 3:
       case 6:return 0;
              break;
       case 1:
       case 4:
       case 7:return 1;
              break;
       case 2:
       case 5:
       case 8:return 2;
              break;
    }
}
int drawx(int b)
{
    int row=getrow(b);
    int col=getcol(b);
    int flag=0;
    printf("%d\t%d\n",row,col);
    if(arr[row][col]==-1)
    {
        glBegin(GL_LINES);
        glVertex2i(bx-25,by-25);
        glVertex2i(bx+25,by+25);
        glVertex2i(bx-25,by+25);
        glVertex2i(bx+25,by-25);
        glEnd();
        glFlush();
        arr[row][col]=1;
    }
    else
    flag=1;
    return flag;
}    
int drawo(int b)
{
    int row=getrow(b);
    int col=getcol(b);
    int flag=0;
    if(arr[row][col]==-1)
    {
        GLint x,y,r;
        r=30;
        x=0,y=30;
        GLint p=1-r;
        while(x<=y)
        {
            glBegin(GL_POINTS);
            glVertex2i(x+bx,y+by);
            glVertex2i(y+bx,x+by);
            glVertex2i(x+bx,-y+by);
            glVertex2i(y+bx,-x+by);
            glVertex2i(-x+bx,-y+by);
            glVertex2i(-y+bx,-x+by);
            glVertex2i(-x+bx,y+by);
            glVertex2i(-y+bx,x+by);
            glEnd();
            x++;
            if(p<0)
            {
                p=p+2*x+3;
            }                
            else
            {
                p=p+2*x-2*y+5;
                y--;
            }
        }
        glFlush();
        arr[row][col]=2;
    }
    else
    flag=1;
    return flag;
} 
int rowcheck(int r,int p)
{
    int i,count=0;
    for(i=0;i<3;i++)
    {
        if(arr[r][i]==p)
        count++;
    }
    if(count==3)
    return 1;
    else
    return 0;
}
int colcheck(int c,int p)
{
    int i,count=0;
    for(i=0;i<3;i++)
    {
        if(arr[i][c]==p)
        count++;
    }
    if(count==3)
    return 1;
    else
    return 0;
}
int ldiagcheck(int p)
{
    int i,count=0;
    for(i=0;i<3;i++)
    {
        if(arr[i][i]==p)
        count++;
    }
    if(count==3)
    return 1;
    else
    return 0;
}
int rdiagcheck(int p)
{
    int i,count=0;
    for(i=0;i<3;i++)
    {
        if(arr[i][2-i]==p)
        count++;
    }
    if(count==3)
    return 1;
    else
    return 0;
}
void checkwin(int p)
{
     int i;
     for(i=0;i<3;i++)
     {
         if(rowcheck(i,p)==1)
         {
            glBegin(GL_LINES);
            glVertex2i(260,200+i*100);
            glVertex2i(540,200+i*100);
            glEnd();
            glFlush();
            Sleep(2500);
            exit(0);
         }
     }
     for(i=0;i<3;i++)
     {
         if(colcheck(i,p)==1)
         {
            glBegin(GL_LINES);
            glVertex2i(300+i*100,160);
            glVertex2i(300+i*100,440);
            glEnd();
            glFlush();
            Sleep(2500);
            exit(0);
         }
     }
     if(ldiagcheck(p)==1)
     {
         glBegin(GL_LINES);
         glVertex2i(260,160);
         glVertex2i(540,440);
         glEnd();
         glFlush();
         Sleep(2500);
         exit(0);
     }
     if(rdiagcheck(p)==1)
     {
         glBegin(GL_LINES);
         glVertex2i(540,160);
         glVertex2i(260,440);
         glEnd();
         glFlush();
         Sleep(2500);
         exit(0);
     }
     if(moves==9)
     {
         Sleep(2500);
         exit(0);
     }
}
void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		int status;
        if(x>250&&x<350&&y>150&&y<250)
		{
           box=0;
           bx=300;
           by=200;
        }
		if(x>350&&x<450&&y>150&&y<250)
		{
           box=1;
           bx=400;
           by=200;
        }
		if(x>450&&x<550&&y>150&&y<250)
		{
           box=2;
           bx=500;
           by=200;
        }
		if(x>250&&x<350&&y>250&&y<350)
		{
           box=3;
           bx=300;
           by=300;
        }
		if(x>350&&x<450&&y>250&&y<350)
		{
           box=4;
           bx=400;
           by=300;
        }
		if(x>450&&x<550&&y>250&&y<350)
		{
           box=5;
           bx=500;
           by=300;
        }
		if(x>250&&x<350&&y>350&&y<450)
		{
           box=6;
           bx=300;
           by=400;
        }
		if(x>350&&x<450&&y>350&&y<450)
		{
           box=7;
           bx=400;
           by=400;
        }
		if(x>450&&x<550&&y>350&&y<450)
		{
           box=8;
           bx=500;
           by=400;
        }
		printf("box=%d\n",box);
		if(player==1)
		{
            status=drawx(box);
            if(status==0)
            {
            moves++;
            checkwin(player);
            player=2;
            }
            else
            player=1;
        }
        else
        {
            status=drawo(box);
            if(status==0)
            {
            moves++;
            checkwin(player);
            player=1;
            }
            else
            player=2;
            
        }
	}
}
int main(int argc,char **argv)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
               arr[i][j]=-1;
        }
    }
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("TIC-TAC-TOE");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
		
