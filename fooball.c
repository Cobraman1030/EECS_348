#include <stdio.h>

 void math (int points);

int
main ()
{
int points; 
while (1)
	{
printf ("\n Enter 0 or 1 to STOP");		    
printf ("\n Enter the NFL score: ");	  
scanf ("%d", &points); 
if (points <= 1)
		{		  
	break;	
} 
printf ("\nPossible combinations of scoring plays:");	  
math (points);	
} 
return 0;
}
 


void
math (int points)
{ 
for (int td = 0; td <= points / 6; td++)
	{	  
for (int fg = 0; fg <= points / 3; fg++)
		{		  
for (int safety = 0; safety <= points / 2; safety++)
			{			  
int total = td * 6 + fg * 3 + safety * 2;			  
if (total == points)
				{				  
printf ("%d TD + %d FG + %d Safety\n", td, fg, safety);				
}		
}		
}	
}
}