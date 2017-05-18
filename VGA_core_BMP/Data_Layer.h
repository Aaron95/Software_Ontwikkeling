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

void TekenBitmap(char *Plaatje)
{
	/*
	 * top to bottom
	 * forward
	 */


	if(Plaatje == "SadSmiley")
	{
		int VerticaleTeller;
		int HorizontaleTeller;

		for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
		{
			for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
			{
				UB_VGA_SetPixel(HorizontaleTeller,VerticaleTeller,BMP_Happy_Smiley[VerticaleTeller][HorizontaleTeller]);
			}
		}
	}
	else if(Plaatje == "Scager")
	{
		int VerticaleTeller;
		int HorizontaleTeller;

		for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
		{
			for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
			{
				UB_VGA_SetPixel(HorizontaleTeller,VerticaleTeller,BMP_Scager[VerticaleTeller][HorizontaleTeller]);
			}
		}
	}

	else if(Plaatje == "Franc")
	{
		int VerticaleTeller;
		int HorizontaleTeller;

		for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
		{
			for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
			{
				UB_VGA_SetPixel(HorizontaleTeller,VerticaleTeller,BMP_Franc[VerticaleTeller][HorizontaleTeller]);
			}
		}
	}
	else if(Plaatje == "Pijl_Omlaag")
		{
			int VerticaleTeller;
			int HorizontaleTeller;

			for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
			{
				for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
				{
					UB_VGA_SetPixel(HorizontaleTeller,VerticaleTeller,BMP_Pijl_Omlaag[VerticaleTeller][HorizontaleTeller]);
				}
			}
		}
	else if(Plaatje == "Smiley_Sad")
			{
				int VerticaleTeller;
				int HorizontaleTeller;

				for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
				{
					for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
					{
						UB_VGA_SetPixel(HorizontaleTeller,VerticaleTeller,BMP_Sad_Smiley[VerticaleTeller][HorizontaleTeller]);
					}
				}
			}

}
