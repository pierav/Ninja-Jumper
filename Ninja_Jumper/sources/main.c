
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>


#define MINDEP 1
#include "couleur.h"
#define TRUE 1
#define True 1
#define true 1
#define FALSE 0
#define False 0
#define false 0


#define nombredemobmax 5
#define rafraichissement 10
#define DEVhitbox FALSE
#define DEVsuivi FALSE

	SDL_Surface * SDL_screen;
	SDL_Surface * fusebleu=NULL;
	SDL_Surface * fond;
	SDL_Surface * curseur =NULL;
	SDL_Surface * curseuron =NULL;

	SDL_Surface * persof    =NULL;
	SDL_Surface * persod    =NULL;
	SDL_Surface * persor    =NULL;
	SDL_Surface * persol    =NULL;

	SDL_Surface * surfacenull=NULL;
	SDL_Surface * surfaceterre=NULL;
	SDL_Surface * surfaceherbe=NULL;
	SDL_Surface * surfacesol=NULL;

	SDL_Surface * surfaceblock1=NULL;
	SDL_Surface * surfaceblock3=NULL;
	SDL_Surface * surfaceblock4=NULL;
	SDL_Surface * surfaceblock5=NULL;

	SDL_Surface * spritechu1=NULL;
	SDL_Surface * spritechu2=NULL;
	SDL_Surface * spritefeu1=NULL;

	SDL_Surface * surfacemaison1=NULL;
	SDL_Surface * surfacefondmaison=NULL;

	SDL_Surface * menu=NULL;
	SDL_Surface * niveau=NULL;
	SDL_Surface * win=NULL;


	int SDL_AFFICHE_AUTO = 0;

	typedef struct point {int x,y;} POINT;
	typedef Uint32 COULEUR;
	typedef int BOOL;
	int WIDTH;
	int HEIGHT;


void init_graphics() //Refonte
{

    WIDTH = 900;
    HEIGHT = 600;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF/*|SDL_FULLSCREEN*/);

    SDL_ShowCursor(1);

    SDL_WM_SetCaption("NINJA JUMPER",NULL);

    //fill_screen(noir);
    //affiche_all();
}

void init_fond(int map)
{
    switch (map)
    {
    case 1:
        fond	= SDL_LoadBMP("images/fond.bmp");
        break;
    case 2:
        fond = SDL_LoadBMP("images/fond1.bmp");
        break;
    case 3:
        fond = SDL_LoadBMP("images/fond2.bmp");
        break;
    }
}

void init_img() ///Crée toutes les surfaces à partir des BMP
{
    fusebleu = SDL_LoadBMP("images/test.bmp");

    curseur  = SDL_LoadBMP("images/curseur.bmp");
    curseuron= SDL_LoadBMP("images/curseuron.bmp");
    persof	 = SDL_LoadBMP("images/persof.bmp");
    persod	 = SDL_LoadBMP("images/persod.bmp");
    persor	 = SDL_LoadBMP("images/persor.bmp");
    persol	 = SDL_LoadBMP("images/persol.bmp");

    surfacenull=SDL_LoadBMP("images/surfacenull.bmp");
    surfaceterre=SDL_LoadBMP("images/surfaceterre.bmp");
    surfaceherbe=SDL_LoadBMP("images/surfaceherbe.bmp");
    surfacesol=SDL_LoadBMP("images/surfacesol.bmp");

    surfaceblock1=SDL_LoadBMP("images/surfaceblock1.bmp");
    surfaceblock3=SDL_LoadBMP("images/surfaceblock3.bmp");
    surfaceblock4=SDL_LoadBMP("images/surfaceblock4.bmp");
    surfaceblock5=SDL_LoadBMP("images/surfaceblock5.bmp");
    spritechu1=SDL_LoadBMP("images/spritechu1.bmp");
    spritechu2=SDL_LoadBMP("images/spritechu2.bmp");
    spritefeu1=SDL_LoadBMP("images/spritefeu1.bmp");

    surfacefondmaison=SDL_LoadBMP("images/surfacefondmaison.bmp");
    surfacemaison1=SDL_LoadBMP("images/surfacemaison1.bmp");

    menu=SDL_LoadBMP("images/menu.bmp");
    niveau=SDL_LoadBMP("images/niveau.bmp");
    win=SDL_LoadBMP("images/win.bmp");
}

///=================BLITTE POUR UN FLIP=================================

void blittecurseur(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(curseur, SDL_SRCCOLORKEY, SDL_MapRGB(curseur->format, 255, 0, 0));
    SDL_BlitSurface(curseur, NULL, SDL_screen, &position);
}

void blittecurseuron(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(curseuron, SDL_SRCCOLORKEY, SDL_MapRGB(curseuron->format, 255, 0, 0));
    SDL_BlitSurface(curseuron, NULL, SDL_screen, &position);
}

void blittepersof(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(persof, SDL_SRCCOLORKEY, SDL_MapRGB(persof->format, 255, 0, 0));
    SDL_BlitSurface(persof, NULL, SDL_screen, &position);
}

void blittepersod(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(persod, SDL_SRCCOLORKEY, SDL_MapRGB(persod->format, 255, 0, 0));
    SDL_BlitSurface(persod, NULL, SDL_screen, &position);
}

void blittepersor(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(persor, SDL_SRCCOLORKEY, SDL_MapRGB(persol->format, 255, 0, 0));
    SDL_BlitSurface(persor, NULL, SDL_screen, &position);
}

void blittepersol(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(persol, SDL_SRCCOLORKEY, SDL_MapRGB(persol->format, 255, 0, 0));
    SDL_BlitSurface(persol, NULL, SDL_screen, &position);
}

void blittespritechu1(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(spritechu1, SDL_SRCCOLORKEY, SDL_MapRGB(persol->format, 255, 0, 0));
    SDL_BlitSurface(spritechu1, NULL, SDL_screen, &position);
}

void blittespritechu2(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(spritechu2, SDL_SRCCOLORKEY, SDL_MapRGB(persol->format, 255, 0, 0));
    SDL_BlitSurface(spritechu2, NULL, SDL_screen, &position);
}

void blittespritefeu1(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(spritefeu1, SDL_SRCCOLORKEY, SDL_MapRGB(persol->format, 255, 0, 0));
    SDL_BlitSurface(spritefeu1, NULL, SDL_screen, &position);
}

///=================+CELLE DE LECRAN====================================

void blittemenu()
{

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(menu, NULL, SDL_screen, &position);
}

void blitteniveau()
{

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(niveau, NULL, SDL_screen, &position);
}

void blittewin()
{

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(win, NULL, SDL_screen, &position);
}


///=================BLITTE DANS "FOND"==================================
void blittesurfacenull(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfacenull, NULL, fond, &position);
}

void blittesurfaceterre(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceterre, NULL, fond, &position);
}

void blittesurfaceherbe(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceherbe, NULL, fond, &position);
}

void blittesurfacesol(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfacesol, NULL, fond, &position);
}

void blittesurfaceblock1(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceblock1, NULL, fond, &position);
}

void blittesurfaceblock3(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceblock3, NULL, fond, &position);
}

void blittesurfaceblock4(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceblock4, NULL, fond, &position);
}

void blittesurfaceblock5(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfaceblock5, NULL, fond, &position);
}

void blittesurfacemaison1(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_SetColorKey(surfacemaison1, SDL_SRCCOLORKEY, SDL_MapRGB(surfacemaison1->format, 255, 0, 0));
    SDL_BlitSurface(surfacemaison1, NULL, fond, &position);
}

void blittesurfacefondmaison(int x,int y)
{

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;
    SDL_BlitSurface(surfacefondmaison, NULL, fond, &position);
}

void tableaudansfond(int tableau[18][12]) //on injecte les différentes matières dans le fond
{
    POINT pos;
    int j,i;
    for(j=0; j<12; j++)
    {
        for(i=0; i<18; i++)
        {
            pos.x=(i*50);
            pos.y=((j)*50)+50;
            if (tableau[i][j]==0)
            {
                /*blittesurfaceterre(pos.x,pos.y);*/
            }
            else if (tableau[i][j]==1)
            {
                blittesurfaceherbe(pos.x,pos.y);
            }
            else if (tableau[i][j]==2)
            {
                blittesurfaceblock1(pos.x,pos.y);
            }
            else if (tableau[i][j]==3)
            {
                blittesurfaceblock3(pos.x,pos.y);
            }
            else if (tableau[i][j]==9)
            {
                blittesurfacenull(pos.x,pos.y);
            }
            else if (tableau[i][j]==4)
            {
                blittesurfaceblock4(pos.x,pos.y);
            }
            else if (tableau[i][j]==5)
            {
                blittesurfaceblock5(pos.x,pos.y);
            }


            else {}
        }
    }

}

void blittefond() //avec cette instruction on affiche la surface fond
{

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    SDL_BlitSurface(fond, NULL, SDL_screen, &position);
}


///=================CLIPPER=============================================

void effacezone(int x,int y,int dx,int dy) //affiche la surface fond sur la zone
{

    SDL_Rect positionfond;
    positionfond.x = 0;
    positionfond.y = 0;

    SDL_Rect position;
    position.x = x;
    position.y = HEIGHT-y;

    SDL_Rect clipper;
    clipper.x = position.x;
    clipper.y = position.y;
    clipper.h = dx;//*2 ??? WTF !!//c 1 carre de 50'
    clipper.w = dy;
    SDL_SetClipRect(SDL_screen,&clipper);

    SDL_Rect positionfondblit;
    positionfondblit.x = positionfond.x;
    positionfondblit.y = positionfond.y;


    SDL_BlitSurface(fond, NULL, SDL_screen, &positionfondblit);
    SDL_SetClipRect(SDL_screen,NULL); //Clipper NULL

}

///=================AUTRES==============================================

void affiche_auto_on ()
{
    SDL_AFFICHE_AUTO = 1;
}
void affiche_auto_off()
{
    SDL_AFFICHE_AUTO = 0;
}

void affiche_all()
{
    SDL_Flip(SDL_screen);
}

POINT wait_clic()
{
    int encore = 1;
    POINT P;
    SDL_Event event;
    P.x = 0;
    P.y = 0;
    while (SDL_WaitEvent(&event) && encore)
    {
        if ((event.type == SDL_MOUSEBUTTONDOWN) && (event.button.button == SDL_BUTTON_LEFT))
        {
            encore=0;
            P.x = event.button.x;
            P.y = HEIGHT-event.button.y;
        }
        if (event.type == SDL_MOUSEMOTION)
        {
            fflush(stdout);
        }
        if (event.type == SDL_QUIT) exit(0);

    }
    return P;
}

void fill_screen(COULEUR color)
{
    int i,j;
    for (i=0; i<WIDTH; i++)
        for (j=0; j<HEIGHT; j++) *((COULEUR *)SDL_screen->pixels + (HEIGHT-j-1) * WIDTH + i) = color;
    if (SDL_AFFICHE_AUTO) affiche_all();
}

int dans_ecran(int x, int y)
{
    if (x<0) return 0;
    if (x>=WIDTH) return 0;
    if (y<0) return 0;
    if (y>=HEIGHT) return 0;
    return 1;
}

#define add_pix(x,y,color)  if (dans_ecran((x),(y))) *((COULEUR *)SDL_screen->pixels + (HEIGHT-(y)-1) * WIDTH + (x)) = (color)

void draw_line(POINT p1, POINT p2, COULEUR color)
{
    int xmin, xmax;
    int ymin, ymax;
    int i,j;
    float a,b,ii,jj;

    if (p1.x < p2.x)
    {
        xmin=p1.x;
        xmax=p2.x;
    }
    else
    {
        xmin=p2.x;
        xmax=p1.x;
    }
    if (p1.y < p2.y)
    {
        ymin=p1.y;
        ymax=p2.y;
    }
    else
    {
        ymin=p2.y;
        ymax=p1.y;
    }

    if (xmin==xmax) for (j=ymin; j<=ymax; j++) add_pix(xmin,j,color);
    if (ymin==ymax) for (i=xmin; i<=xmax; i++) add_pix(i,ymin,color);


    // La variation la plus grande est en x
    if ((xmax-xmin >= ymax-ymin) && (ymax-ymin>0))
    {
        a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
        b = p1.y - a*p1.x;
        for (i=xmin; i<=xmax; i++)
        {
            jj = a*i+b;
            j = jj;
            if (((jj-j) > 0.5) && (j < HEIGHT-1)) j++;
            add_pix(i,j,color);
        }
    }

    // La variation la plus grande est en y
    if ((ymax-ymin > xmax-xmin) && (xmax-xmin>0))
    {
        a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
        b = p1.y - a*p1.x;
        for (j=ymin; j<=ymax; j++)
        {
            ii = (j-b)/a;
            i = ii;
            if (((ii-i) > 0.5) && (i < WIDTH-1)) i++;
            add_pix(i,j,color);
        }
    }
    if (SDL_AFFICHE_AUTO) affiche_all();
}

void draw_fill_circle(POINT centre, int rayon, COULEUR color)
{
    POINT min, max;
    int i,j;
    float dx, dy, rr;

    min.x = centre.x - rayon;
    max.x = centre.x + rayon;
    min.y = centre.y - rayon;
    max.y = centre.y + rayon;

    rr = rayon*rayon;

    for (i=min.x; i<=max.x; i++)
    {
        dx = i - centre.x;
        for (j=min.y; j<=max.y; j++)
        {
            dy = j - centre.y;
            if (dx*dx + dy*dy <= rr) add_pix(i,j,color);
        }
    }
    if (SDL_AFFICHE_AUTO) affiche_all();
}

int min3(int a, int b, int c)
{
    if ( (a<b) && (a<c) ) return a;
    if ( (b<a) && (b<c) ) return b;
    return c;
}

int max3(int a, int b, int c)
{
    if ( (a>b) && (a>c) ) return a;
    if ( (b>a) && (b>c) ) return b;
    return c;
}




typedef enum //le nom de la map
{
    NIVEAUpierre,NIVEAUvincent,NIVEAUjulien
} NIVEAU;

typedef enum //le type de mob
{
    churiken,boule_de_feu
} SKIN;

typedef struct //LE SPRITE entier ! //(posx,posy,posx,posy,0,rayon)
{
    POINT pos;
    POINT posini;
    int tsaut;
    int r;
    int tskin;
    SKIN skin;
} SPRITEOBJ;

typedef struct //Un niveau complet
{
    NIVEAU NIVEAU;//le type de NIVEAU ( merci le CTRL H ...... :) ! ) HA HA HA
    int terrain[18][12];//les blocks du terrain
    POINT pos;//position ini du perso
    int sens;//sens du perso
    int nombremob;//nombre de sprites ennemis sur le terrain
    SPRITEOBJ mob[nombredemobmax];//les enemies
    POINT pwin;//la zone où il faut arriver ( circulaire = + facile)
} TERRAIN;

typedef struct //hitbox a 4 points : HG,HD,BD,BG jeu.sens antitrigo
{
    POINT HG,HD,BD,BG;
} HITBOX;

//==colision :
void calculhitbox(HITBOX * box,POINT POS) //On définit les 4 points de la hitbox
{
    box->HG.x=POS.x+10;
    box->HG.y=POS.y-2;

    box->HD.x=POS.x+50-10;
    box->HD.y=POS.y-2;

    box->BD.x=POS.x+50-10;
    box->BD.y=POS.y-50;

    box->BG.x=POS.x+10;
    box->BG.y=POS.y-50;
}

void drawhitbox(HITBOX * box,int color) //fonction non essentielle, réservée au dévelopeur
{
    draw_line(box->HG,box->HD,color);
    draw_line(box->HD,box->BD,color);
    draw_line(box->BD,box->BG,color);
    draw_line(box->BG,box->HG,color);
}

BOOL calculcolision(HITBOX * box, TERRAIN * zone) //Puis on vérifie si cette hitbox rentre en collision avec les blocks du tableau ( Pour les depl )
{

    HITBOX boxtableau;
    boxtableau.HG.x=box->HG.x/50;
    boxtableau.HG.y=box->HG.y/50;
    boxtableau.HD.x=box->HD.x/50;
    boxtableau.HD.y=box->HD.y/50;
    boxtableau.BD.x=box->BD.x/50;
    boxtableau.BD.y=box->BD.y/50;
    boxtableau.BG.x=box->BG.x/50;
    boxtableau.BG.y=box->BG.y/50;

    BOOL colision;
    if ((zone->terrain[boxtableau.HG.x][boxtableau.HG.y]>0)||(zone->terrain[boxtableau.HD.x][boxtableau.HD.y]>0)||
            (zone->terrain[boxtableau.BD.x][boxtableau.BD.y]>0)||(zone->terrain[boxtableau.BG.x][boxtableau.BG.y]>0))
    {
        colision=TRUE;
        if(DEVhitbox)drawhitbox(box,orange);
    }
    else
    {
        colision=FALSE;
        if(DEVhitbox)drawhitbox(box,green);
    }
    return colision;
}

//===affichage personnage :
void blitteperso(int i,POINT POS) //1 F // 2 <-- // 3 ^ // 4 -->
{
    switch(i)
    {
    case 1:
        blittepersof(POS.x,POS.y);
        break;
    case 2:
        blittepersol(POS.x,POS.y);
        break;
    case 3:
        blittepersod(POS.x,POS.y);
        break;
    case 4:
        blittepersor(POS.x,POS.y);
        break;
    }
}

//===terrain :

NIVEAU choixniveau()
{
    /*fill_screen(white);
    POINT p1,p2;
    p1.x=450;p2.x=450;
    p1.y=0;p2.y=600;
    draw_line(p1,p2,black);
    p1.x=150;p1.y=300;
    aff_pol("NV 1",50,p1,black);
    p1.x+=450;
    aff_pol("NV 2",50,p1,black);
    */
    blitteniveau();
    affiche_all();
    POINT p=wait_clic();
    if((p.x>600)&&(p.y<100))
    {
        exit(666);   //Propre ?
    }
    if(p.y>360)
    {
        return NIVEAUpierre;
    }
    if((p.y<360)&&(p.y>200))
    {
        return NIVEAUvincent;
    }
    if((p.x<600)&&(p.y<200))
    {
        return NIVEAUjulien;
    }
    return 0;

}

void initterrain2(TERRAIN * zone, NIVEAU NIVEAU_du_terrain)
{
    zone->NIVEAU=NIVEAU_du_terrain;
    int i,j;
    switch(zone->NIVEAU)
    {
    case NIVEAUpierre:
        zone->pos.x=0;
        zone->pos.y=100;
        zone->sens=1;
        zone->pwin.x=25;
        zone->pwin.y=475;
        init_fond(1);
        zone->nombremob=4;
        initspriteobj(&zone->mob[0],200,150,70,churiken);//Humm humm
        initspriteobj(&zone->mob[1],200,350,90,churiken);
        initspriteobj(&zone->mob[2],600,380,110,boule_de_feu);
        //initspriteobj(&zone->mob[3],650,280,110,boule_de_feu);//HARDDDD



        int terrainpierre[18][12]= //Mon terrain test
        {
            {2,0,0,0,0,0,0,0,2,0,0,0},//0
            {2,0,0,0,0,0,0,0,2,0,0,0},
            {2,0,0,0,0,0,2,2,2,0,0,0},
            {2,0,0,0,0,0,0,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,0,0,0,0},//5
            {2,0,0,0,0,2,2,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,2,0,0,0},
            {2,0,0,0,0,0,0,0,2,0,0,0},//00
            {2,2,0,0,0,0,0,0,2,0,0,0},
            {0,2,2,0,0,0,0,0,2,0,0,0},
            {0,0,2,2,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,2,2,0,0,0,2,2,0,0,0},//50
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,2,2,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}
        };//[y][x]
        for(i=0; i<18; i++)
        {
            for(j=0; j<12; j++)
            {
                zone->terrain[i][j]=terrainpierre[i][j];
            }
        }
        break;
    case NIVEAUvincent:
        init_fond(2);
        zone->pos.x=50;
        zone->pos.y=100;
        zone->sens=1;
        zone->pwin.x=825;
        zone->pwin.y=525;

        zone->nombremob=0;
        int terrainvincent[18][12]=
        {
            {4,0,4,4,0,0,0,0,0,0,0,0},//0
            {4,0,4,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,0,0,0,0,0,0},
            {4,0,0,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,0,0,0,0,0,0},//5
            {4,0,4,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,0,0,0,0,0,0},
            {4,0,0,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,0,0,0,0,0,0},
            {4,0,4,0,0,0,0,0,0,0,0,0},//00
            {4,0,4,0,0,0,0,0,0,0,0,0},
            {4,0,0,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,0,0,0,0,0,0},
            {4,0,0,0,0,0,0,0,0,0,0,0},
            {4,0,4,4,4,4,4,0,0,0,0,0},//50
            {4,0,4,0,4,0,4,0,0,0,0,0},
            {4,0,4,0,0,0,4,0,0,0,0,0},
            {4,0,0,0,0,0,0,0,0,0,0,0}
        };//[y][x]
        for(i=0; i<18; i++)
        {
            for(j=0; j<12; j++)
            {
                zone->terrain[i][j]=terrainvincent[i][j];
            }
        }
        break;
    case NIVEAUjulien:
        init_fond(3);
        zone->pos.x=50;
        zone->pos.y=100;
        zone->sens=1;
        zone->pwin.x=825;
        zone->pwin.y=470;
        zone->nombremob=0;
        int terrainjulien[18][12]= //Mon terrain test
        {
            {3,0,0,5,0,0,0,5,0,0,0,0},//0
            {3,0,0,5,0,0,0,5,0,0,0,0},
            {3,0,0,5,0,0,0,0,0,0,0,0},
            {3,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0},//5
            {0,0,0,0,0,5,0,0,0,5,0,0},
            {0,0,0,0,0,5,0,0,0,5,0,0},
            {3,0,0,0,0,0,0,0,0,5,0,0},
            {0,3,0,0,0,0,0,0,0,5,0,0},
            {0,0,3,0,0,5,5,0,0,0,0,0},//00
            {0,0,3,0,0,0,0,0,0,0,0,0},
            {0,3,0,0,0,0,0,0,0,5,0,0},
            {0,3,0,0,0,5,0,0,0,5,0,0},
            {3,0,0,0,0,5,0,0,0,0,0,0},
            {3,0,0,0,0,0,0,0,0,0,0,0},//50
            {3,0,0,0,0,0,0,0,5,0,0,0},
            {0,0,0,5,0,0,0,0,5,0,0,0},
            {0,0,0,5,0,0,0,0,5,0,0,0}
        };//[y][x]
        for(i=0; i<18; i++)
        {
            for(j=0; j<12; j++)
            {
                zone->terrain[i][j]=terrainjulien[i][j];
            }
        }
        break;
    }
}

void afficheterrain2(TERRAIN * zone) //la surface NIVEAU possède le NIVEAU et il est affiché SUR SDLScreen
{

    tableaudansfond(zone->terrain);//on injecte les différentes matières dans le "NIVEAU" // Surface pour les clippers
    blittefond();//Puis on blitte le NIVEAU
    affiche_all();
}


//===Ennemis :

void initspriteobj(SPRITEOBJ * test,int posx, int posy,int r,SKIN skin)
{
    test->pos.x=posx;
    test->pos.y=posy;
    test->posini.x=posx;
    test->posini.y=posy;
    test->tsaut=0;
    test->r=r;
    test->tskin=0;
    test->skin=skin;
}

void actualisepositionspriteobj(SPRITEOBJ * test) //POS modifié de façon circulaire !
{
    test->tsaut++;
    if (test->tsaut<=2*test->r)
    {
        test->pos.y=test->posini.y-sqrt((test->r*test->r)-(test->tsaut-test->r)*(test->tsaut-test->r));    //équation d' un cetest->rcle : test->racine(test->r²-x²)
        test->pos.x++;
    }
    else if(test->tsaut<=4*test->r)
    {
        test->pos.y=test->posini.y+sqrt((test->r*test->r)-(test->tsaut-3*test->r)*(test->tsaut-3*test->r));    //+ -2test->r catest->r tsaut = 2test->r a l' instant
        test->pos.x--;
    }
    else
    {
        test->tsaut=0;
        test->pos.x=test->posini.x;
    }
}

void affichespriteobj(SPRITEOBJ *test) // afficher le sprite à ses coordonnées
{
    switch(test->skin)
    {
    case churiken:
        if (test->tsaut%100==1)
        {
            test->tskin=1-test->tskin;
        }
        if (test->tskin)blittespritechu1(test->pos.x-25,test->pos.y+25);
        else blittespritechu2(test->pos.x-25,test->pos.y+25);//+/- 25 pour le centre de l'image de 50*50
        break;
    case boule_de_feu:
        blittespritefeu1(test->pos.x-25,test->pos.y+25);
        break;
    }
}


int main(int argc, char* argv[])
{

    init_graphics();
    init_img();
    fill_screen(red);
    blittemenu();
    affiche_all();
    wait_clic();

    NIVEAU niveau=choixniveau();
    SDL_ShowCursor(0);

    ///variables initiales :

    int saut=0;
    int tsaut=0;
    int valtempsaut;
    int sauttemp;// variables pour le saut + variables temporaires (intermédiaires)
    int droite=0;
    int gauche=0;// variables pour le depl perso
    POINT suivi;// Point pour le suivi rouge ( Indicateur à commenter à l'avenir )
    int numeromob;
    int continuer=1;
    BOOL mort = FALSE;
    POINT mid;//le milieu du perso;
    int lags;//pour for

    ///création du terrain ========

    TERRAIN jeu;
    initterrain2(&jeu,niveau);
    afficheterrain2(&jeu);

    ///création de la hitbox =====

    HITBOX box;

    ///============================


    while (continuer) // Le prog continue tant que non croix ou echap //SDL_Delay(1);//intervalle entre chaque NIVEAU à def ? Automatique ne marche pas ? PLZ ! dslay(1) = 1 millisegond : MDR !!
    {

        SDL_Delay(1);
        ///Affichage
        for (numeromob=0; numeromob<jeu.nombremob; numeromob++)
        {
            affichespriteobj(&jeu.mob[numeromob]);
        }
        blitteperso(jeu.sens,jeu.pos);
        affiche_all();
        effacezone(jeu.pos.x,jeu.pos.y,50,50);
        for (numeromob=0; numeromob<jeu.nombremob; numeromob++)
        {
            effacezone(jeu.mob[numeromob].pos.x-25,jeu.mob[numeromob].pos.y+25,50,50);
        }

        /*fc dev suivi perso*/if (DEVsuivi)
        {
            suivi.x = jeu.pos.x;
            suivi.y = jeu.pos.y-100;
            draw_fill_circle(suivi,2,red);
        }

        ///Détection des événements du clavier : ) ========================================
        SDL_Event event;
        SDL_PollEvent(&event);
        //droite=0;gauche=0;
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_UP:
                jeu.pos.y--;
                calculhitbox(&box,jeu.pos);
                if (calculcolision(&box,&jeu))
                {
                    saut=1;
                }
                jeu.pos.y++;/*jeu.sens=3 conservation du jeu.sens*/;
                break;
            case SDLK_DOWN:/*if(jeu.pos.y-50>0){jeu.pos.y--;}jeu.sens=1*/
                ;
                break;
            case SDLK_RIGHT:
                droite=1;
                gauche=0;
                jeu.sens=4;
                break;
            case SDLK_LEFT:
                gauche=1;
                droite=0;
                jeu.sens=2;
                break;
            //+test :
            case SDLK_ESCAPE:
                continuer=0;
                break;
            case SDLK_F1:
                initterrain2(&jeu,niveau);
                afficheterrain2(&jeu);
                break;
            }
            break;//le break qui ma fait perdre 2 H !!!
        case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                droite=0;
                gauche=0;
                break;//Wtffffffff ??? Essentiel pour le bug d'appui simultané ?
            case SDLK_LEFT:
                gauche=0;
                droite=0;
                break;
            }
            break;
        }
        ///On calcule la nouvelle jeu.position du personnage (collision) =============================
        /**
         * Code calculant les jeu.position des objest a chaque images (Saut, jeu.pos perso , sprites &nemi)
         * le code suicant est coder avec les PIEDS ! :*
         * Pour savoir si collision on déplace l' OBJET VIRTUELLEMENT, puis on regarde si collision, si collision le mv est conserver, sinon annuler. (pas trè propre, mais bon .. ca marche .. xD)
         */
        if (droite&&(jeu.pos.x+51<900))
        {
            jeu.pos.x++;    //on annule le depl si collision
            calculhitbox(&box,jeu.pos);
            if (calculcolision(&box,&jeu))
            {
                jeu.pos.x--;
            }
        }
        if (gauche&&(jeu.pos.x>0))
        {
            jeu.pos.x--;
            calculhitbox(&box,jeu.pos);
            if (calculcolision(&box,&jeu))
            {
                jeu.pos.x++;
            }
        }
        ///Pour savoir si collision, on déplace UNE AUTRES HITBOX VIRTUELLEMENT, puis on regarde si collision, si collision rien ne se produit, sinon le mv est accepter
        if (saut==1) //si saut est ON alors on entame une procédure de montée en hauteur
        {
            tsaut++;
            valtempsaut=sauttemp+sin(tsaut/(300/3.1415))*175;//la jeu.pos n'est pas défini par récurence car accélération n'est pas entière 250 = L 150 = H ! 2l=h ! BIEN !! ATTENTION aux accroissements d'accéleration !
            if((jeu.pos.y<600))jeu.pos.y=valtempsaut;//Pour la hauteur ne pas deplacer + LES BLOCKs A AJOUER ( MUR ) !!!!
            jeu.pos.y--;
            calculhitbox(&box,jeu.pos);
            jeu.pos.y++;//on def la hitbox VIRTUELLE à une jeu.pos d'équart
            if ((tsaut==300)||calculcolision(&box,&jeu)||(jeu.pos.y>=600))
            {
                tsaut=0;    // tsaut == L  MAX !!!!!! SIN PI ! SI tsault < L On arrte le saut plus TOt
                saut=0;
                jeu.pos.y++;
            }
            jeu.pos.y++;
            calculhitbox(&box,jeu.pos);
            jeu.pos.y--;//on def la hitbox VEIRTUELLE à une jeu.pos d'équart
            if (calculcolision(&box,&jeu))
            {
                tsaut=0;
                saut=0;
                jeu.pos.y--;
            }
        }
        else if(saut==0)
        {
            sauttemp=jeu.pos.y;//complément car saut à définir à la pos ini

            jeu.pos.y--;
            calculhitbox(&box,jeu.pos);
            if (calculcolision(&box,&jeu))
            {
                jeu.pos.y++;
            };

        }
        for (numeromob=0; numeromob<jeu.nombremob; numeromob++)
        {
            actualisepositionspriteobj(&jeu.mob[numeromob]);   //calcule la nouvelle position des ennemis
        }

        //Pt du milieu : (utile pour les tests de mort et win)
        mid.x=jeu.pos.x+25;
        mid.y=jeu.pos.y-25;
        ///test de mort :
        for (numeromob=0; numeromob<jeu.nombremob; numeromob++)
        {
            if (sqrt((jeu.mob[numeromob].pos.x-mid.x)*(jeu.mob[numeromob].pos.x-mid.x)+(jeu.mob[numeromob].pos.y-mid.y)*(jeu.mob[numeromob].pos.y-mid.y))<=40) //D entre moi et ennemi x4 Pythagore
            {
                mort=TRUE;
            }
        }
        if (jeu.pos.y<=-10)
        {
            mort=TRUE;
        }
        if(mort)
        {
            initterrain2(&jeu,niveau);
            afficheterrain2(&jeu);
            mort=FALSE;
            tsaut=0;
            saut=0;
        }
        /// test de win :
        if (sqrt((mid.x-jeu.pwin.x)*(mid.x-jeu.pwin.x)+(mid.y-jeu.pwin.y)*(mid.y-jeu.pwin.y))<25)
        {
            blittewin();
            affiche_all();
            SDL_ShowCursor(1);
            wait_clic();
            niveau=choixniveau();
            initterrain2(&jeu,niveau);
            afficheterrain2(&jeu);
        }
        ///======================================================
    }//fin du while

    exit(0);
}

