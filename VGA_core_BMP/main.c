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
#include "bitmap.h"
#include "Data_Layer.h"
#include <math.h>




//const tImage sadsmileycolor = { image_data_sadsmileycolor, 80, 80,
//   8 };


int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);
/*
  Vul_Rechthoek(20, 20, 100, 100, VGA_COL_RED);
  Teken_Rechthoek(120, 20, 200, 100, VGA_COL_BLUE);

  Teken_Rechthoek(0, 0, 319, 239, VGA_COL_WHITE);

  Teken_Driehoek(20, 120, 100, 200, VGA_COL_GREEN);

  Teken_Lijn(319, 239, 0, 0, VGA_COL_CYAN);
  */
  TekenBitmap("Scager");
  while(1)
  {

  }
}



