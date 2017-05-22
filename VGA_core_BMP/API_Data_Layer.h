void Vul_Rechthoek(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	/** \fn
	 *  Action: Deze functie tekent een rechthoek op basis van de gegeven coördinaten en vult deze in
	 *  Input: uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur
	 *  Subject: Pixels
	*/
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
	/** \fn
	 *  Action: Deze functie tekent een rechthoek op basis van de gegeven coördinaten
	 *  Input: uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur
	 *  Subject: Pixels
	*/
	Teken_Lijn(xp0, yp0, xp1, yp0, Kleur);
	Teken_Lijn(xp1, yp0, xp1, yp1, Kleur);
	Teken_Lijn(xp1, yp1, xp0, yp1, Kleur);
	Teken_Lijn(xp0, yp1, xp0, yp0, Kleur);
}

void Teken_Driehoek(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	/** \fn
	 *  Action: Deze functie tekent een driehoek op basis van de gegeven coördinaten
	 *  Input: uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur
	 *  Subject: Pixels
	*/
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

void Teken_Lijn(uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur)
{
	/** \fn
	 *  Action: Deze functie tekent een lijn op basis van de gegeven coördinaten
	 *  Input: uint16_t xp0, uint16_t yp0, uint16_t xp1, uint16_t yp1, uint8_t Kleur
	 *  Subject: Pixels
	*/

  int dx,dy,sdx,sdy,px,py,dxabs,dyabs,i;
  float helling;

  dx=xp1-xp0;      /* the horizontal distance of the line */
  dy=yp1-yp0;      /* the vertical distance of the line */
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx = dxabs / dx;	//was  sdx=sgn(dx);
  sdy = dyabs / dy; //was  sdy=sgn(dy);

  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
  {
    helling=(float)dy / (float)dx;
    for(i=0;i!=dx;i+=sdx)
    {
      px=i+xp1;
      py=helling*i+yp0;
      UB_VGA_SetPixel(px,py,Kleur);
    }
  }
  else /* the line is more vertical than horizontal */
  {
    helling=(float)dx / (float)dy;
    for(i=0;i!=dy;i+=sdy)
    {
      px=helling*i+xp0;
      py=i+yp0;
      UB_VGA_SetPixel(px,py,Kleur);
    }
  }
}

void Teken_Bitmap(uint16_t xp0, uint16_t yp0, char *Plaatje)
{
	/** \fn
	 *  Action: Deze functie haalt een bitmap op in de file bitmap.h uit het flashgeheugen en projecteert deze op de gewenste plaats op het scherm
	 *  Input: uint16_t xp0, uint16_t yp0, char *Plaatje
	 *  Subject: Pixels
	*/

	if(Plaatje == "SadSmiley")
	{
		int VerticaleTeller;
		int HorizontaleTeller;

		for (VerticaleTeller = 0; VerticaleTeller < 80; VerticaleTeller++)
		{
			for (HorizontaleTeller = 0; HorizontaleTeller < 80; HorizontaleTeller++)
			{
				UB_VGA_SetPixel(HorizontaleTeller + xp0,VerticaleTeller + yp0,BMP_Happy_Smiley[VerticaleTeller][HorizontaleTeller]);
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
				UB_VGA_SetPixel(HorizontaleTeller +xp0,VerticaleTeller + yp0,BMP_Scager[VerticaleTeller][HorizontaleTeller]);
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
				UB_VGA_SetPixel(HorizontaleTeller + xp0,VerticaleTeller + yp0,BMP_Franc[VerticaleTeller][HorizontaleTeller]);
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
					UB_VGA_SetPixel(HorizontaleTeller + xp0,VerticaleTeller + yp0,BMP_Pijl_Omlaag[VerticaleTeller][HorizontaleTeller]);
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
						UB_VGA_SetPixel(HorizontaleTeller + xp0,VerticaleTeller + yp0,BMP_Sad_Smiley[VerticaleTeller][HorizontaleTeller]);
					}
				}
			}

}

void Ellipse(uint16_t xmp, uint16_t ymp, uint16_t Radius_X, uint16_t Radius_Y, uint8_t Kleur)
{
	/** \fn
	 *  Action: Deze functie tekent een ellipse op het scherm op basis van de gegeven startpunten en radii
	 *  Input: uint16_t xmp, uint16_t ymp, uint16_t Radius_X, uint16_t Radius_Y, uint8_t Kleur
	 *  Subject: Pixels
	*/
	int pixel;

	for( pixel=0;  pixel < 800;  pixel++)
	     { float x = xmp + Radius_X*cos(pixel);
	       float y = ymp - 0.5* Radius_Y*sin(pixel);    //note 2.
	       UB_VGA_SetPixel(x,y, Kleur);
	     }
}
