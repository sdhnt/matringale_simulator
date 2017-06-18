
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>  
using namespace std;

	int main()
	{
		int totalbets=0;
		int betamt=1;
		int wins=0;
		int currentlosses=0;
	    long fund = pow(2,15); 
		srand (time(NULL));

		while(fund>0)
		{
		
			int a = rand() %100 +1; //Random no. b/w 1-100
			if(a>54)
				{
					fund=fund + betamt;
					betamt=1;wins++;//RESET
				}
			else
				{
					if(fund-betamt>0)
					{
						fund = fund - betamt;
						betamt=2*betamt;//DOUBLE
					}
					else
					{
					printf("Lost all money after %d bets and %d wins",totalbets,wins); 	break;
					}
				}		
			totalbets++;
			printf("FUND IS %lu\n", fund );
			
			if(totalbets>100 && betamt==1)
			{
				printf("Terminated");break;
			}
		}
		
		return 0;
	}
