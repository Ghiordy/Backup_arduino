//Programa : Teste Display LCD 128x64 em modo 8 bits
//Autor : Arduino e Cia

#include "U8glib.h"  

//Utilize a linha abaixo para utilizar a comunicacao serial
//(Enable, RW, RS, RESET)
//U8GLIB_ST7920_128X64_1X u8g(2, 3, 4 ,5); 

//Utilize a linha abaixo para utilizar a comunicacao paralela (8 bits)
//(d0, d1, d2, d3, d4, d5, d6, d7, en, di, rw, reset)
U8GLIB_ST7920_128X64_1X u8g(6, 7, 8, 9, 10, 11, 12, 13, 2, 4, 3, 5);

int display = 1;  
   
void u8g_prepare() 
{  
  u8g.setFont(u8g_font_6x10);  
  u8g.setFontRefHeightExtendedText();  
  u8g.setDefaultForegroundColor();  
  u8g.setFontPosTop();  
}  
   
void u8g_Tela1()  //Tela 1 - Arduino e Cia - Retangulos  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawStr( 11, 35, "Arduino e Cia");  
  u8g.drawStr( 12, 35, "Arduino e Cia");  
  u8g.drawFrame(0,0,128,64);  
  u8g.drawFrame(2,2,124,60);   
}  
   
void u8g_Tela2() //Tela 2 - Linhas horizontais e verticais
{
  for (int i = 0; i<127 ; i=i+2)
  {
    u8g.drawLine(i,0,i,64); 
  }
  for (int c = 0; c<64 ; c=c+2)
  {
    u8g.drawLine(0,c,128,c); 
  }
}  

void u8g_Tela3() //Tela 3 - Arduino e Cia - Retangulo preenchido  
{
  u8g.setFont(u8g_font_unifont);  
  u8g.drawBox(0,0,128,64);  
  u8g.drawBox(2,2,124,60);   
  u8g.setColorIndex(0);  
  u8g.drawStr( 11, 35, "Arduino e Cia");  
  u8g.drawStr( 12, 35, "Arduino e Cia");  
  u8g.drawFrame(2,2,124,60);  
}   
   
void draw() //Rotina Desenho  
{
  u8g_prepare();  
  switch(display) //Carrega a tela correspondente  
  {
   case 1:  
    u8g_Tela1();  
    break;  
   case 2:  
    u8g_Tela2();  
    break;  
   case 3:  
    u8g_Tela3();  
    break;  
  }  
}  
   
void setup() 
{  
  // assign default color value  
  if ( u8g.getMode() == U8G_MODE_R3G3B2 )   
   u8g.setColorIndex(255);   // white  
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )  
   u8g.setColorIndex(1);     // max intensity  
  else if ( u8g.getMode() == U8G_MODE_BW )  
   u8g.setColorIndex(1);     // pixel on  
}  
   
void loop() 
{  
  //Loop carregamento telas
  for (display =1; display < 4; display++) //Carrega as telas de 1 a 7  
  {  
    u8g.firstPage();   
    do 
    {  
    draw();  
    } 
    while( u8g.nextPage() );  
    delay(3000);  //Pausa de 3 segundos e reinicia o processo  
  }  
}     
