#include "ioCC2530.h"

#define LED5 P0_7
#define LED6 P0_6
#define SW1 P0_5
#define SW2 P0_4
unsigned char Stat_key = 0;   

void Delay(unsigned int t)
{
  while(t--);
}

void InitPort()
{
  P0SEL &= ~0xC0;         
  P0DIR |= 0xC0;         
  P0SEL &= ~0x30;        
  P0DIR &= ~0x30;         

  LED5 = 0;               
  LED6 = 0;               
}

void ScanKeys()
{
  if(SW1 == 1)
  {                       
    Delay(100);          
    if(SW1 == 1)		
    {                      
      while(SW1 == 1);    
	  
      
      if((Stat_key & 0x01) == 0x01)
      {
        Stat_key &= ~0x01;  
        LED5 = 0;
      }
      else{
        Stat_key |= 0x01;
        LED5 = 1;
      } 
    }
  }
  
  
  if(SW2 == 1)
  {                       
    Delay(100);           
    if(SW2 == 1)
    {                     
      while(SW2 == 1);    
      if((Stat_key & 0x02) == 0x02)
      {
        Stat_key &= ~0x02;
        LED6 = 0;
      }
      else{
        Stat_key |= 0x02;
        LED6 = 1;
      } 
    }
  }
  
}

void main()
{
  InitPort();
  while(1)
  {
    ScanKeys();
  }
  
}