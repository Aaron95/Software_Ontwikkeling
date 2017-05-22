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

/**
   @file ledmatrix.cpp
   @author  Ronald Boon <ronald.boon@moba.nl>
   @version 1.5

   for more information, see readme.
*/
#include "main.h"
#include "stm32_ub_vga_screen.h"
#include "bitmap.h"
#include "API_Data_Layer.h"
#include <math.h>




//const tImage sadsmileycolor = { image_data_sadsmileycolor, 80, 80,
//   8 };


int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz
	UART_init();
	//UART_INT_init();

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);
/*
  Vul_Rechthoek(20, 20, 100, 100, VGA_COL_RED);
  Teken_Rechthoek(120, 20, 200, 100, VGA_COL_BLUE);

  Teken_Rechthoek(0, 0, 319, 239, VGA_COL_WHITE);

  Teken_Driehoek(20, 120, 100, 200, VGA_COL_GREEN);
<<<<<<< HEAD
*/
  Teken_Lijn(10, 120, 100, 120, 5,  VGA_COL_CYAN);
  Teken_Lijn(10, 10, 100, 200, 10,  VGA_COL_YELLOW);

//  Teken_Bitmap(0, 0, "Smiley_Sad");
//  Teken_Bitmap(80, 0, "Smiley_Happy");
//  Teken_Bitmap(160, 0, "Pijl_Omlaag");
//  Teken_Bitmap(120, 80, "Scager");
//  Ellipse(159, 119, 160, 50, VGA_COL_WHITE);
=======

  Teken_Lijn(319, 239, 0, 0, VGA_COL_CYAN);
  */
 // Teken_Bitmap("Scager");
  //Ellipse(100, 100, 70, 50, VGA_COL_WHITE);
  //UB_VGA_ReadPixel(2,5);
  //UART_puts("DOE HET");

>>>>>>> cf934ccad18143bce17458fecb3be15f77e89b20
  while(1)
  {
	  int buf =0;
	  UART_gets(buf, 1);
	  switch(buf)
	  {
	  case "lijn":
		  Teken_Lijn(319, 239, 0, 0, VGA_COL_CYAN);

	  }
  }
}



