#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include <Gl/glut.h>
#define pi (2*acos(0.0))
#define GL_SILENCE_DEPRECATION
#include<stdlib.h>
#include<stdio.h>

struct point
{
	double x,y,z;
};

//struct point pos,l,u;
double X=0,Z=0;
//int Y=-1;
int check=0;
struct point arra[100];
float objx=0,objy=20.8,basx=0,basy=-1.95,dropx=0,dropy=20.94;
float ran;
float speed = 0.004;

int score=0,level=1 ,life=1;

float s1x=1.05,s1y=-2.1,s2x=1.84,s2y=-2.1,s2x1= 1.64,s2y1=-1.7 ;
float l1x=-1.95,l1y=-2.1,l2x=-1.55,l2y=-2.1;

float sty=-1,f=0,q=0.00,z=1;

 float lfx1=1.00,lfy1=-1.5,lf2x1=1.79,lf2y1=-1.5;
 int a=1,b = 0,c = 0;

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2.2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}
void drawSphere(double radius,int slices,int stacks)
{
	struct point points[100][100];
	int i,j;
	double h,r;
	//generate points
	for(i=0;i<=stacks;i++)
	{
		h=radius*sin(((double)i/(double)stacks)*(pi/2));
		r=radius*cos(((double)i/(double)stacks)*(pi/2));
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*2*pi);
			points[i][j].y=r*sin(((double)j/(double)slices)*2*pi);
			points[i][j].z=h;
		}
	}
	//draw quads using generated points
	for(i=0;i<stacks;i++)
	{
        glColor3f(a,b,c);
		for(j=0;j<slices;j++)
		{
			glBegin(GL_QUADS);{
			    //upper hemisphere
				glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);
                //lower hemisphere
                glVertex3f(points[i][j].x,points[i][j].y,-points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,-points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,-points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,-points[i+1][j].z);
			}glEnd();
		}
	}
}

void just_line() // create the basket
{
     //BLUE LINE 3f=3



    glLineWidth(6);

    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2d(-0.30,0.5); //d=double
        glVertex2d(-0.30,0.0);
          glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2d(-0.30,0.0);
        glVertex2d(0.30,0.0);
          glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2d(0.30,0.0);
        glVertex2d(0.30,0.5); //d=double


    glEnd();

}







void showscore()
{
    glColor3f(1,1,0); //yellow
    glRasterPos3f(s1x,s1y,0); // poition

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'y');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'c');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'=');

    char str[10];
    sprintf(str, "%d", score);

    glColor3f(1,0,0);
    glRasterPos3f(s2x,s2y,0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[0]);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[1]);



}

 void showlife()
{
    glColor3f(1,1,0); //yellow
    glRasterPos3f(lfx1,lfy1,0);



    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'y');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'f');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'=');


      char str1[10];
       sprintf(str1, "%d",life);

    glColor3f(1,0,1);
    glRasterPos3f(lf2x1,lf2y1,0);
   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[0]);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[1]);


}

void showlevel()
{
    glColor3f(1,1,0);
    glRasterPos3f(l1x,l1y,0);

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'v');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'l');


    char str[10];
    sprintf(str, "%d", level);

    glColor3f(1,0,0);
    glRasterPos3f(l2x,l2y,0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[0]);




}

void restart_msg_show()
{
    char msg4[]="press    r  to restart the game ";
     glColor3f(0,1,0);
    glRasterPos3f(-.9,0.9,0);
    for(int k=0;k<strlen(msg4);k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg4[k]);
    }


}

void all_msg()
{
     char msg1[]="press  s for start the game ";
     glColor3f(0,1,0);
    glRasterPos3f(-.8,0.1,0);
    for(int k=0;k<strlen(msg1);k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[k]);
    }




    char title[]="Catch The Ball";
     glColor3f(1,1,0);
    glRasterPos3f(-0.55,-1.7,0);
    for(int k=0;k<strlen(title);k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title[k]);
    }

    char title1[]="-----------";
     glColor3f(1,1,0);
    glRasterPos3f(-0.55,-1.8,0);
    for(int k=0;k<strlen(title1);k++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title1[k]);
    }


}

void starting_menu()
{
     // create new window

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2.2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);

    // for animation
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();



    all_msg();






    glPushMatrix();
    glTranslatef(0, sty, 0);
    glColor3f(1, 0, 0);
    drawSphere(0.2, 25, 25);  // ball
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, -1.3, 0);
    just_line();

    glPopMatrix();




    glutSwapBuffers();
    glutPostRedisplay();
}



void checked(){
    check=0;


//    objx=0,objy=1.8,basx=0,basy=-1.95,dropx=0,dropy=10.94;
//    ran,speed=0.003;
    ran=((float(rand()) / float(RAND_MAX)) * (1.8 - (-1.8))) + (-1.8);
       objy=10.8;
       objx=ran;
       dropx=10.8;

}

void Game()
{






    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // for animation

    showscore();
    showlevel();
    showlife();

   // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[1]);



    if (objy<-1.8 && (objx<basx-0.3 || objx>basx+0.3))  // check game over
    {
         check=1;
        if(check==1){
            life=life-1;
        }

//        s1x=-.5,s1y=.5,s2x=.28,s2y=.5;
//        l1x=-.3,l1y=.3,l2x=.22,l2y=.3;




        if (life > 0)
        {
            checked();

        }
        else {
            life=0;
        s1x=-.5,s1y=.5,s2x=.28,s2y=.5;
        lfx1 = -.3,lfy1= .3,lf2x1=.29,lf2y1=.3;

         a =1,b=1,c=0;
        restart_msg_show();

        }


    }
//    if(check == 1){
//
//        s1x=-.5,s1y=.5,s2x=.28,s2y=.5;
//        lfx1 = -.3,lfy1= .3,lf2x1=.29,lf2y1=.3;
//
//       restart_msg_show();
//    }
    if (check==0)
    {
      objy-=speed;
    }


    if(objy<-1.85)
    {
       ran=((float(rand()) / float(RAND_MAX)) * (1.8 - (-1.8))) + (-1.8);
       objy=10.8;
       objx=ran;
       dropx=10.8;

       score+=1;
       //printf("score=%d",score);
       if( score == 5 )
       {
         level+=1;
         speed+=0.000001;
         life +=1;

       }
       if( score==10 )
       {
         level+=1;
         speed+=0.0001;
         life +=1;
       }
       if(score==15)
       {
         level+=1;
         life += 1;
         speed+=0.01;
       }
       if(score==20)
       {
         level+=1;
            life +=1;
         speed+=0.02;
       }
       if(score==25)
       {
         level+=1;
         speed+=0.02;
         life += 1;
       }
       if(score==30)
       {
         level+=1;
         speed+=0.000001;
         life +=1;

       }
       if(score==35)
       {
         level+=1;
         life += 1;
         speed+=0.0000001;
       }
    }



    glPushMatrix();
    glTranslatef(objx,objy, 0);
    glColor3f(1, 0, 0);
    drawSphere(0.2, 25, 25);  // main ball
    glPopMatrix();


    glPushMatrix();
    glTranslatef(dropx,dropy, 0);
    glScalef(1.5, 0.4, 1);
    drawSphere(0.2, 25, 25);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(basx, basy, 0);
    just_line();
     glPopMatrix();


    glutSwapBuffers();
    glutPostRedisplay();


}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			break;
		case GLUT_KEY_UP:
		    	//glutDisplayFunc(display);	// up arrow key
			break;

		case GLUT_KEY_RIGHT:
		    if(check!=1)
            {
               if (basx<1.6)
		       basx+=0.3;
            }

		   // printf("%f",basx);
			break;
		case GLUT_KEY_LEFT:
             if(check!=1)
            {
		    if (basx>-1.41)
		    basx-=0.3;
            }

			break;


		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
		     if(check==1)
            {
		   // glutDisplayFunc(starting_menu);
            }


			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}

void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {

    case '1':
        // code animating
        break;
    case 'r':
        check=0;

        objx=0,objy=1.8,basx=0,basy=-1.95,dropx=0,dropy=10.94;
        ran,speed=0.004;

        score=0,level=1;
            a=1,b=0,c=0;

        s1x=1.05,s1y=-2.1,s2x=1.8,s2y=-2.1;
        l1x=-1.95,l1y=-2.1,l2x=-1.55,l2y=-2.1;
        lfx1=1.00,lfy1=-1.5,lf2x1=1.79,lf2y1=-1.5;
        life = 1;

        break;
    case 's':
        check=0;

        objx=0,objy=1.8,basx=0,basy=-1.95,dropx=0,dropy=5.94;
        ran,speed=0.004;

        score=0,level=1;

        s1x=1.05,s1y=-2.1,s2x=1.8,s2y=-2.1;
        l1x=-1.95,l1y=-2.1,l2x=-1.55,l2y=-2.1;
        glutDisplayFunc(Game);

        break;


    default:
        break;
    }
}

 void mouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON)
    {
        if(check!=1)
        {
            if (basx>-1.41)
                basx-=0.2;
        }

    }
    else if(button==GLUT_RIGHT_BUTTON)
    {
        if(check!=1)
        {
            if (basx<1.6)
                basx+=0.2;
        }

    }
    else
    {

    }
}



int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600, 550);
    glutCreateWindow("Catch the ball");
    init();
//    glutDisplayFunc(display);
    glutDisplayFunc(starting_menu);
    glutMouseFunc(mouse);
    glutSpecialFunc(specialKeyListener);
    glutKeyboardFunc(keyboardListener);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
