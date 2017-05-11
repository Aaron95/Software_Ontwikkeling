//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>

void Vul_Rechthoek(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	int i;
	int j;

	for(i = xp0; i <= xp1; i++)
	{
		for(j = yp0; j <= yp1; j++)
		{
			UB_VGA_SetPixel(i,j,Kleur);
		}
	}
}

void Teken_Rechthoek(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	Teken_Lijn(xp0, yp0, xp1, yp0, Kleur);
	Teken_Lijn(xp1, yp0, xp1, yp1, Kleur);
	Teken_Lijn(xp1, yp1, xp0, yp1, Kleur);
	Teken_Lijn(xp0, yp1, xp0, yp0, Kleur);
}

void Teken_Driehoek(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	int x0, x1, x2, y0, y1, y2 = 0;
	x0 = xp0;
	y0 = yp0;

	x1 = xp1;
	y1 = (yp1 - yp0)/2 + yp0;

	x2 = xp0;
	y2 = yp1;

	Teken_Lijn(x0, y0, x1, y1, Kleur);
	Teken_Lijn(x1, y1, x2, y2, Kleur);
	Teken_Lijn(x2, y2, x0, y0, Kleur);
}

void Teken_Lijn(int x1, int y1, int x2, int y2, uint8_t color)
{
  int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
  float helling;

  dx=x2-x1;      /* the horizontal distance of the line */
  dy=y2-y1;      /* the vertical distance of the line */
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx = dxabs / dx;	//was  sdx=sgn(dx);
  sdy = dyabs / dy; //was  sdy=sgn(dy);

  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
  {
    helling=(float)dy / (float)dx;
    for(i=0;i!=dx;i+=sdx)
    {
      px=i+x1;
      py=helling*i+y1;
      UB_VGA_SetPixel(px,py,color);
    }
  }
  else /* the line is more vertical than horizontal */
  {
    helling=(float)dx / (float)dy;
    for(i=0;i!=dy;i+=sdy)
    {
      px=helling*i+x1;
      py=i+y1;
      UB_VGA_SetPixel(px,py,color);
    }
  }
}

int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);

  Vul_Rechthoek(20, 20, 100, 100, VGA_COL_RED);
  Teken_Rechthoek(120, 20, 200, 100, VGA_COL_BLUE);

  Teken_Rechthoek(0, 0, 319, 239, VGA_COL_WHITE);

  Teken_Driehoek(20, 120, 100, 200, VGA_COL_GREEN);

  Teken_Lijn(319, 239, 0, 0, VGA_COL_CYAN);
  while(1)
  {

  }
}



