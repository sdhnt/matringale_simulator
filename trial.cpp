
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>  
using namespace std;

	int main()
	{
		int totalbets=0;
		float stbet=1;
		float betamt=stbet;
		int wins=0;
		int currentlosses=0;
		long backup=0;
		
	    long stfund = pow(2,15)/10; 
	    long fund=stfund;
		srand (time(NULL));

		while(fund>0)
		{
		
			int a = rand() %100 +1; //Random no. b/w 1-100
			if(a>54)
				{
					fund=fund + betamt;
					betamt=stbet;wins++;//RESET
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
						float prob=(float(wins)/ float(totalbets));
					printf("Lost all money after %d bets and %d wins. Prob. of winning = %f\n",totalbets,wins,prob); break;
					}
				}		
			totalbets++;
			printf("FUND IS %lu\n", fund );
			
			if(totalbets>100 && betamt==1)
			{
				printf("Terminated\n");break;
			}
		}
		
		return 0;
	}
