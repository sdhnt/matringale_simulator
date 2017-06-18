
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>  
using namespace std;

	int main()
	{
			srand (time(NULL));
		int losingt=0;
		int wint=0;
		long totalmutualfund= pow(2,15); //100 Times the individual game run
		long remfund=0;
		
		int i=1;
		
		while(i<=1)//i<=x where x is the number of tables played on simultaneously
		{
		int totalbets=0;
		float stbet=1;
		float betamt=stbet;
		int wins=0;
		int currentlosses=0;
		long backup=0;
	    long stfund = totalmutualfund/1;//totalmutualfund/x
	    long fund=stfund;
	    


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
						
					printf("Lost all money after %d bets and %d wins. Prob. of winning = %f\n",totalbets,wins,prob); losingt++;break;
					}
				}		
			totalbets++;
			//printf("FUND IS %lu\n", fund );

			if(totalbets>1000 && betamt==1)//Number of total bets per table
			{
				remfund=remfund+fund; printf("Terminated\n");wint++;break;
			}
		}
		
		i++;
		
	    }
		printf("LOSING:%d WIN:%d",losingt,wint);
	    
	    
	    if(remfund>totalmutualfund)
	    {	   
			long netprofit=remfund-totalmutualfund;
	    	printf("NET PROFIT: %lu\n",netprofit);
	   		float ratereturn=( float(netprofit)/float(totalmutualfund) ) * 100;
	   		printf("RATE OF RETURN FOR 100 bets * 100 tables = %f\n",ratereturn  );
		}
		else
		{
			long netloss=-remfund+totalmutualfund;
	    	printf("NET LOSS: %lu\n",netloss);
	   		float ratereturn=( float(netloss)/float(totalmutualfund) ) * 100;
	   		printf("RATE OF LOSS FOR 100 bets * 100 tables = %f\n",ratereturn  );
		}
		
		return 0;
	}
