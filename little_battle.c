#include "little_battle.h"
extern int EXP,diamond;
extern char rarity[6][4];
extern int MainMenu,MinorMenu,ClickTabNum[10],HeroRarity[21];
extern int OpenHeroImage[12],CompleteBattle[3],FailBattle[3];

extern int HeroId[21],HeroBasicAtk[21],HeroBasicHP[21],HeroCoolDownTime[21],CallHeroNeedMoney[21],HeroLV[21],Team[11],BasicTowerLV,BasicGoldProducerLV;
extern int BattleGoldProducerLV,BattleGold,BombEnergy,godmax;
extern int CurrentHeroX[21][11],CurrentHeroHP[21][11],IsHeroAlive[21][11],HeroFirstX,HeroBattleNum[21],HeroBattlePastTime[21];
extern int IsEnemyAlive[4][6],CurrentEnemyX[4][6],CurrentEnemyHP[4][6],TotalEnemyNum,EnemyFirstX,EnemyTowerHP[3];
void callrole1(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk1;
	atk1=(int)((float)HeroBasicAtk[1]*(1.+((float)HeroLV[1]/10)));
	CurrentHeroHP[1][i]=(int)((float)HeroBasicHP[1]*(1.+((float)HeroLV[1]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[1][i]=0;
			CurrentHeroX[1][i]=0;
			break;
		}
		if(CurrentHeroHP[1][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[1][i]=0;
			CurrentHeroX[1][i]=0;
			x=0;
			HeroBattleNum[1]--;
			break;
		}
		if(x==Form_X+83){printf("\x1b[%d;%dH↑○",y,x-1);Sleep(300);}
		if(x!=Form_X+83&&x>EnemyFirstX+1){printf("\x1b[%d;%dH↑○ ",y,x-1);Sleep(300);}
		if(x<=EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH↖○ ",y,x-1);
			Sleep(200);
			printf("\x1b[%d;%dH←○",y,x-1);
			Sleep(200);
			printf("\x1b[%d;%dH↑○",y,x-1);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-1)
						CurrentEnemyHP[j][k]-=atk1;
				}
			}
			Sleep(200);
		}
		if(x>EnemyFirstX+1)
		{
			x--;
			CurrentHeroX[1][i]=x;
		}
	}
}
void callrole2(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk2;
	atk2=(int)((float)HeroBasicAtk[2]*(1.+((float)HeroLV[2]/10)));
	CurrentHeroHP[2][i]=(int)((float)HeroBasicHP[2]*(1.+((float)HeroLV[2]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[2][i]=0;
			CurrentHeroX[2][i]=0;
			break;
		}
		if(CurrentHeroHP[2][i]<=0)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[2][i]=0;
			CurrentHeroX[2][i]=0;
			HeroBattleNum[2]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[0;47m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m",y,x);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m\033[0;40m \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m\033[0;40m \033[0m",y,x);
		}
		if(x<=EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;40m  \033[0m",y,x);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m",y-2,x);
			Sleep(400);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m",y,x);
			printf("\x1b[%d;%dH\033[0;47m  \033[0m\033[0;40m \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;40m  \033[0m\033[0;40m \033[0m",y-2,x);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-1)
						CurrentEnemyHP[j][k]-=atk2;
				}
			}
			Sleep(400);
		}
		if(x>EnemyFirstX+1)x--;
		CurrentHeroX[2][i]=x;
	}
}
void callrole3(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk3;
	atk3=(int)((float)HeroBasicAtk[3]*(1.+((float)HeroLV[3]/10))*0.6);
	CurrentHeroHP[3][i]=(int)((float)HeroBasicHP[3]*(1.+((float)HeroLV[3]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			IsHeroAlive[3][i]=0;
			CurrentHeroX[3][i]=0;
			break;
		}
		if(CurrentHeroHP[3][i]<=0)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			IsHeroAlive[3][i]=0;
			CurrentHeroX[3][i]=0;
			HeroBattleNum[3]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH↑○↑",y,x-3);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+16)
		{
			printf("\x1b[%d;%dH↑○↑ ",y,x-3);
			Sleep(300);
		}
		if(x<=EnemyFirstX+16)
		{
			printf("\x1b[%d;%dH  ○↑",y,x-3);
			for(int j=4;j<=14;j++)
			{
				printf("\x1b[%d;%dH← ",y,x-j);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-16&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=atk3;
				}
			}
			printf("\x1b[%d;%dH  ",y,x-14);
			printf("\x1b[%d;%dH○  ",y,x-1);
			for(int j=4;j<=14;j++)
			{
				printf("\x1b[%d;%dH← ",y,x-j);
				Sleep(50);
			}
			printf("\x1b[%d;%dH  ",y,x-14);
			printf("\x1b[%d;%dH↑○↑",y,x-3);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-16&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=(int)atk3;
				}
			}
			Sleep(400);
		}
		if(x>EnemyFirstX+16)x--;
		CurrentHeroX[3][i]=x;
	}
}
void callrole4(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk4;
	atk4=(int)((float)HeroBasicAtk[4]*(1.+((float)HeroLV[4]/10)));
	CurrentHeroHP[4][i]=(int)((float)HeroBasicHP[4]*(1.+((float)HeroLV[4]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[4][i]=0;
			CurrentHeroX[4][i]=0;
			break;
		}
		if(CurrentHeroHP[4][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[4][i]=0;
			CurrentHeroX[4][i]=0;
			HeroBattleNum[4]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[1;33m￥\033[0m○",y,x-1);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+20){printf("\x1b[%d;%dH\033[1;33m￥\033[0m○ ",y,x-1);Sleep(300);}
		if(x<=EnemyFirstX+22)
		{
			printf("\x1b[%d;%dH\033[1;33m￥\033[0m",y-1,x-1);
			printf("\x1b[%d;%dH  ○",y,x-1);
			Sleep(150);
			printf("\x1b[%d;%dH  ",y-1,x-1);
			printf("\x1b[%d;%dH\033[1;33m￥\033[0m○ ",y,x-1);
			printf("\x1b[%d;%dH\033[1;33mwWw\033[0m",y+1,x-21);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-22)
						CurrentEnemyHP[j][k]-=atk4;
				}
			}
			Sleep(700);
			printf("\x1b[%d;%dH───",y+1,x-21);
		}
		if(x>EnemyFirstX+22)x--;
		CurrentHeroX[4][i]=x;
	}
}
void callrole5(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk5;
	atk5=(int)((float)HeroBasicAtk[5]*(1.+((float)HeroLV[5]/10)));
	CurrentHeroHP[5][i]=(int)((float)HeroBasicHP[5]*(1.+((float)HeroLV[5]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH  ",y,x);
			IsHeroAlive[5][i]=0;
			CurrentHeroX[5][i]=0;
			break;
		}
		if(CurrentHeroHP[5][i]<=0)
		{
			printf("\x1b[%d;%dH  ",y,x);
			IsHeroAlive[5][i]=0;
			CurrentHeroX[5][i]=0;
			HeroBattleNum[5]--;
			break;
		}
		if(x==Form_X+83){printf("\x1b[%d;%dH○",y,x);Sleep(300);}
		if(x!=Form_X+83&&x>EnemyFirstX+25){printf("\x1b[%d;%dH○ ",y,x);Sleep(300);}
		if(x<=EnemyFirstX+25)
		{
			printf("\x1b[%d;%dH↑",y-1,x);
			printf("\x1b[%d;%dH○",y,x);
			printf("\x1b[%d;%dH\033[0;31m⊕\033[0m",y,EnemyFirstX);
			Sleep(150);
			for(int j=2;j<=12;j++)
			{
				printf("\x1b[%d;%dH↑",y-j,x);
				printf("\x1b[%d;%dH   ",y+1-j,x-1);
				Sleep(50);
			}
			printf("\x1b[%d;%dH  ",y-12,x);
			Sleep(150);
			for(int j=12;j>=1;j--)
			{
				printf("\x1b[%d;%dH    ",y-1-j,EnemyFirstX-1);
				printf("\x1b[%d;%dH↓",y-j,EnemyFirstX);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-25&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=atk5;
				}
			}
			printf("\x1b[%d;%dH  ",y-1,EnemyFirstX);
			Sleep(250);
			printf("\x1b[%d;%dH  ",y,EnemyFirstX);
			Sleep(250);
		}
		if(x>EnemyFirstX+25)x--;
		CurrentHeroX[5][i]=x;
	}
}
void callrole6(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk6;
	atk6=(int)((float)HeroBasicAtk[6]*(1.+((float)HeroLV[6]/10)));
	CurrentHeroHP[6][i]=(int)((float)HeroBasicHP[6]*(1.+((float)HeroLV[6]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH  ",y,x);
			IsHeroAlive[6][i]=0;
			CurrentHeroX[6][i]=0;
			break;
		}
		if(CurrentHeroHP[6][i]<=0)
		{
			printf("\x1b[%d;%dH  ",y,x);
			IsHeroAlive[6][i]=0;
			CurrentHeroX[6][i]=0;
			HeroBattleNum[6]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH○",y,x);
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(500);
			printf("\x1b[%d;%dH○ ",y,x);
		}
		if(x<=EnemyFirstX+1)
		{
			Sleep(500);
			printf("\x1b[%d;%dH╭──╮",y-2,x-2);
			printf("\x1b[%d;%dH│  │",y-1,x-2);
			printf("\x1b[%d;%dH╰──╯",y,x-2);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-1)
						CurrentEnemyHP[j][k]-=atk6;
				}
			}
			Sleep(350);
			printf("\x1b[%d;%dH    ",y-2,x-2);
			printf("\x1b[%d;%dH    ",y-1,x-2);
			printf("\x1b[%d;%dH    ",y,x-2);
			printf("\x1b[%d;%dH○ ",y,x);
			Sleep(350);
		}
		if(x>EnemyFirstX+1)x--;
		CurrentHeroX[6][i]=x;
	}
}
void callrole7(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk7;
	atk7=(int)((float)HeroBasicAtk[7]*(1.+((float)HeroLV[7]/10)));
	CurrentHeroHP[7][i]=(int)((float)HeroBasicHP[7]*(1.+((float)HeroLV[7]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[7][i]=0;
			CurrentHeroX[7][i]=0;
			break;
		}
		if(CurrentHeroHP[7][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[7][i]=0;
			CurrentHeroX[7][i]=0;
			HeroBattleNum[7]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[1;33m↑○\033[0m",y,x-1);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			printf("\x1b[%d;%dH\033[1;33m↑○ \033[0m",y,x-1);
			Sleep(300);
		}
		if(x<=EnemyFirstX+2)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;33m↖○\033[0m ",y,x-1);
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;33m←○\033[0m",y,x-1);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-2)
						CurrentEnemyHP[j][k]-=atk7;
				}
			}
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;33m↑○\033[0m",y,x-1);
			Sleep(200);
		}
		if(x>EnemyFirstX+2){x--;CurrentHeroX[7][i]=x;}
	}
}
void callrole8(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk8;
	atk8=(int)((float)HeroBasicAtk[8]*(1.+((float)HeroLV[8]/10)));
	CurrentHeroHP[8][i]=(int)((float)HeroBasicHP[8]*(1.+((float)HeroLV[8]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[8][i]=0;
			CurrentHeroX[8][i]=0;
			break;
		}
		if(CurrentHeroHP[8][i]<=0)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[8][i]=0;
			CurrentHeroX[8][i]=0;
			HeroBattleNum[8]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[0;43m  033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m",y,x);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m\033[0;40m \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m\033[0;40m \033[0m",y,x);
		}
		if(x<=EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m",y-2,x);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[1;40m  \033[0m",y,x);
			Sleep(400);
			printf("\x1b[%d;%dH\033[1;40m  \033[0m",y-2,x);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;43m  \033[0m",y,x);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-1)
						CurrentEnemyHP[j][k]-=atk8;
				}
			}
			Sleep(400);
		}
		if(x>EnemyFirstX+1){x--;CurrentHeroX[8][i]=x;}
	}
}
void callrole9(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk9;
	atk9=(int)((float)HeroBasicAtk[9]*(1.+((float)HeroLV[9]/10))*0.7);
	CurrentHeroHP[9][i]=(int)((float)HeroBasicHP[9]*(1.+((float)HeroLV[9]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH      ",y,x-2);
			IsHeroAlive[9][i]=0;
			CurrentHeroX[9][i]=0;
			break;
		}
		if(CurrentHeroHP[9][i]<=0)
		{
			printf("\x1b[%d;%dH      ",y,x-2);
			IsHeroAlive[9][i]=0;
			CurrentHeroX[9][i]=0;
			HeroBattleNum[9]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[1;33m↑○↑\033[0m",y,x-2);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+16)
		{
			printf("\x1b[%d;%dH\033[1;33m↑○↑\033[0m ",y,x-2);
			Sleep(300);
		}
		if(x<=EnemyFirstX+16)
		{
			printf("\x1b[%d;%dH  \033[1;33m○↑\033[0m",y,x-2);
			for(int j=4;j<=14;j++)
			{
				printf("\x1b[%d;%dH\033[1;33m←\033[0m ",y,x-j);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-16&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=(int)atk9;
				}
			}
			printf("\x1b[%d;%dH  ",y,x-14);
			printf("\x1b[%d;%dH\033[1;33m○\033[0m   ",y,x);
			for(int j=4;j<=14;j++)
			{
				printf("\x1b[%d;%dH\033[1;33m←\033[0m ",y,x-j);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-16&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=(int)atk9;
				}
			}
			printf("\x1b[%d;%dH  ",y,x-14);
			printf("\x1b[%d;%dH\033[1;33m↑○↑\033[0m",y,x-2);
			Sleep(400);
		}
		if(x>EnemyFirstX+16){x--;CurrentHeroX[9][i]=x;}
	}
}
void callrole10(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk10;
	atk10=(int)((float)HeroBasicAtk[10]*(1.+((float)HeroLV[10]/10)));
	CurrentHeroHP[10][i]=(int)((float)HeroBasicHP[10]*(1.+((float)HeroLV[10]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[10][i]=0;
			CurrentHeroX[10][i]=0;
			break;
		}
		if(CurrentHeroHP[10][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[10][i]=0;
			CurrentHeroX[10][i]=0;
			HeroBattleNum[10]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[1;36m￥\033[0m\033[1;33m○\033[0m",y,x-1);
		if(x!=Form_X+83&&x>EnemyFirstX+20)
		{
			Sleep(300);
			printf("\x1b[%d;%dH\033[1;36m￥\033[0m\033[1;33m○\033[0m ",y,x-1);
		}
		if(x<=EnemyFirstX+22)
		{
			printf("\x1b[%d;%dH\033[1;36m￥\033[0m",y-1,x-1);
			printf("\x1b[%d;%dH  \033[1;33m○\033[0m ",y,x-1);
			Sleep(150);
			printf("\x1b[%d;%dH  ",y-1,x-1);
			printf("\x1b[%d;%dH\033[1;36m￥\033[0m\033[1;33m○\033[0m ",y,x-1);
			printf("\x1b[%d;%dH\033[1;36mwWw\033[0m",y+1,x-21);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-22)
						CurrentEnemyHP[j][k]-=atk10;
				}
			}
			Sleep(500);
			printf("\x1b[%d;%dH───",y+1,x-21);
		}
		if(x>EnemyFirstX+22){x--;CurrentHeroX[10][i]=x;}
	}
}
void callrole11(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk11;
	atk11=(int)((float)HeroBasicAtk[11]*(1.+((float)HeroLV[11]/10)));
	CurrentHeroHP[11][i]=(int)((float)HeroBasicHP[11]*(1.+((float)HeroLV[11]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH   ",y,x);
			IsHeroAlive[11][i]=0;
			CurrentHeroX[11][i]=0;
			break;
		}
		if(CurrentHeroHP[11][i]<=0)
		{
			printf("\x1b[%d;%dH   ",y,x);
			IsHeroAlive[11][i]=0;
			CurrentHeroX[11][i]=0;
			HeroBattleNum[11]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[1;33m○\033[0m",y,x);
		if(x!=Form_X+83&&x>EnemyFirstX+25)
		{
			Sleep(300);
			printf("\x1b[%d;%dH\033[1;33m○\033[0m ",y,x);
		}
		if(x<=EnemyFirstX+25)
		{
			printf("\x1b[%d;%dH↑",y-1,x);
			printf("\x1b[%d;%dH\033[1;33m○\033[0m",y,x);
			printf("\x1b[%d;%dH\033[0;31m⊕\033[0m",y,EnemyFirstX);
			Sleep(150);
			for(int j=2;j<=12;j++)
			{
				printf("\x1b[%d;%dH\033[1;33m↑\033[0m",y-j,x);
				printf("\x1b[%d;%dH    ",y+1-j,x-1);
				Sleep(50);
			}
			printf("\x1b[%d;%dH  ",y-12,x);
			Sleep(150);
			for(int j=12;j>=1;j--)
			{
				printf("\x1b[%d;%dH    ",y-1-j,EnemyFirstX-1);
				printf("\x1b[%d;%dH\033[1;33m↓\033[0m",y-j,EnemyFirstX);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-25&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=atk11;
				}
			}
			printf("\x1b[%d;%dH  ",y-1,EnemyFirstX);
			Sleep(250);
			printf("\x1b[%d;%dH  ",y,EnemyFirstX);
			Sleep(250);
		}
		if(x>EnemyFirstX+25)x--;
		CurrentHeroX[11][i]=x;
	}
}
void callrole12(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk12;
	atk12=(int)((float)HeroBasicAtk[12]*(1.+((float)HeroLV[12]/10)));
	CurrentHeroHP[12][i]=(int)((float)HeroBasicHP[12]*(1.+((float)HeroLV[12]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[12][i]=0;
			CurrentHeroX[12][i]=0;
			break;
		}
		if(CurrentHeroHP[12][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[12][i]=0;
			CurrentHeroX[12][i]=0;
			HeroBattleNum[12]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[1;36m↑○\033[0m",y,x-1);
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(300);
			printf("\x1b[%d;%dH\033[1;36m↑○ \033[0m",y,x-1);
		}
		if(x<=EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;36m↖○\033[0m ",y,x-1);
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;36m←○\033[0m",y,x-1);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]==x-1)
						CurrentEnemyHP[j][k]-=atk12;
				}
			}
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;36m↑○\033[0m",y,x-1);
			Sleep(200);
		}
		if(x>EnemyFirstX+1)x--;
		CurrentHeroX[12][i]=x;
	}
}
void callrole13(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk13;
	atk13=(int)((float)HeroBasicAtk[13]*(1.+((float)HeroLV[13]/10)));
	CurrentHeroHP[13][i]=(int)((float)HeroBasicHP[13]*(1.+((float)HeroLV[13]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[13][i]=0;
			CurrentHeroX[13][i]=0;
			break;
		}
		if(CurrentHeroHP[13][i]<=0)
		{
			printf("\x1b[%d;%dH  ",y,x);
			printf("\x1b[%d;%dH  ",y-1,x);
			printf("\x1b[%d;%dH  ",y-2,x);
			IsHeroAlive[13][i]=0;
			CurrentHeroX[13][i]=0;
			HeroBattleNum[13]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y,x);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m\033[0;40m \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m\033[0;40m \033[0m",y,x);
		}
		if(x<=EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[1;40m  \033[0m",y,x);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y-2,x);
			Sleep(400);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y,x);
			printf("\x1b[%d;%dH\033[0;46m  \033[0m",y-1,x);
			printf("\x1b[%d;%dH\033[1;40m  \033[0m",y-2,x);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]==x-1)
						CurrentEnemyHP[j][k]-=atk13;
				}
			}
			Sleep(400);
		}
		if(x>EnemyFirstX+1)x--;
		CurrentHeroX[13][i]=x;
	}
}
void callrole14(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk14;
	atk14=(int)((float)HeroBasicAtk[14]*(1.+((float)HeroLV[14]/10)));
	CurrentHeroHP[14][i]=(int)((float)HeroBasicHP[14]*(1.+((float)HeroLV[14]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-2);
			IsHeroAlive[14][i]=0;
			CurrentHeroX[14][i]=0;
			break;
		}
		if(CurrentHeroHP[14][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-2);
			IsHeroAlive[14][i]=0;
			CurrentHeroX[14][i]=0;
			HeroBattleNum[14]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[1;30m×○\033[0m",y,x-2);
		if(x!=Form_X+83&&x>EnemyFirstX+16)
		{
			Sleep(300);
			printf("\x1b[%d;%dH\033[1;30m×○\033[0m ",y,x-2);
		}
		if(x<=EnemyFirstX+16)
		{
			printf("\x1b[%d;%dH\033[1;30m×○\033[0m",y,x-2);
			for(int j=4;j<=14;j+=2)
			{
				printf("\x1b[%d;%dH\033[1;30m× \033[0m ",y,x-j);
				Sleep(50);
				printf("\x1b[%d;%dH\033[1;30m+ \033[0m ",y,x-j-1);
				Sleep(50);
			}
			printf("\x1b[%d;%dH  ",y,x-15);
			printf("\x1b[%d;%dH\033[1;30m×○\033[0m  ",y,x-2);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-16&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=atk14;
				}
			}
			Sleep(400);
		}
		if(x>EnemyFirstX+16)x--;
		CurrentHeroX[14][i]=x;
	}
}
void callrole15(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk15;
	atk15=(int)((float)HeroBasicAtk[15]*(1.+((float)HeroLV[15]/10)));
	CurrentHeroHP[15][i]=(int)((float)HeroBasicHP[15]*(1.+((float)HeroLV[15]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[15][i]=0;
			CurrentHeroX[15][i]=0;
			break;
		}
		if(CurrentHeroHP[15][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[15][i]=0;
			CurrentHeroX[15][i]=0;
			HeroBattleNum[15]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[1;35m￥\033[0m\033[1;36m○\033[0m",y,x-1);
		if(x!=Form_X+83&&x>EnemyFirstX+20)
		{
			Sleep(300);
			printf("\x1b[%d;%dH\033[1;35m￥\033[0m\033[1;36m○\033[0m ",y,x-1);
		}
		if(x<=EnemyFirstX+22)
		{
			printf("\x1b[%d;%dH\033[1;35m￥\033[0m",y-1,x-1);
			printf("\x1b[%d;%dH  \033[1;36m○\033[0m ",y,x-1);
			Sleep(150);
			printf("\x1b[%d;%dH  ",y-1,x-1);
			printf("\x1b[%d;%dH\033[1;35m￥\033[0m\033[1;36m○\033[0m ",y,x-1);
			printf("\x1b[%d;%dH\033[1;35mwWw\033[0m",y+1,x-21);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-22)
						CurrentEnemyHP[j][k]-=atk15;
				}
			}
			Sleep(500);
			printf("\x1b[%d;%dH───",y+1,x-21);
		}
		if(x>EnemyFirstX+22)x--;
		CurrentHeroX[15][i]=x;
	}
}
void callrole16(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	CurrentHeroHP[1][i]=(int)((float)HeroBasicHP[1]*(1.+((float)HeroLV[1]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH   ",y,x);
			IsHeroAlive[16][i]=0;
			CurrentHeroX[16][i]=0;
			break;
		}
		if(CurrentHeroHP[16][i]<=0)
		{
			printf("\x1b[%d;%dH   ",y,x);
			IsHeroAlive[16][i]=0;
			CurrentHeroX[16][i]=0;
			HeroBattleNum[16]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH\033[0;44m  \033[0m",y,x);
		if(x!=Form_X+83&&x>EnemyFirstX+1)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;44m  \033[0m\033[0;40m \033[0m",y,x);
		}
		if(x>EnemyFirstX+1)x--;
		CurrentHeroX[16][i]=x;
	}
}
void callrole17(void *arg)
{
	int y=Form_Y+18,x=Form_X+83;
	int i=*(int *)arg;
	int atk17;
	atk17=(int)((float)HeroBasicAtk[17]*(1.+((float)HeroLV[17]/10))*(((float)HeroBasicHP[17]*(1.+((float)HeroLV[17]/10)))/(float)CurrentHeroHP[17][i]));
	CurrentHeroHP[17][i]=(int)((float)HeroBasicHP[17]*(1.+((float)HeroLV[17]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[17][i]=0;
			CurrentHeroX[17][i]=0;
			break;
		}
		if(CurrentHeroHP[17][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsHeroAlive[17][i]=0;
			CurrentHeroX[17][i]=0;
			HeroBattleNum[17]--;
			break;
		}
		if(x==Form_X+83)printf("\x1b[%d;%dH●",y,x);
		if(x!=Form_X+83&&x>EnemyFirstX)
		{
			Sleep(500);
			printf("\x1b[%d;%dH● ",y,x);
		}
		if(x<=EnemyFirstX)
		{
			Sleep(1500);
			printf("\x1b[%d;%dH● ",y,x);
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;33m●\033[0m",y,x);
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;31m●\033[0m",y,x);
			Sleep(500);
			printf("\x1b[%d;%dH\033[0;31m※※※\033[0m",y-2,x-2);
			printf("\x1b[%d;%dH\033[0;31m※※※\033[0m",y-1,x-2);
			printf("\x1b[%d;%dH\033[0;31m※※※\033[0m",y,x-2);
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]<=x&&CurrentEnemyX[j][k]>=x-5)
						CurrentEnemyHP[j][k]-=atk17;
				}
			}
			Sleep(350);
			printf("\x1b[%d;%dH      ",y-2,x-2);
			printf("\x1b[%d;%dH      ",y-1,x-2);
			printf("\x1b[%d;%dH      ",y,x-2);
			HeroBattleNum[17]--;
			CurrentHeroX[17][i]=0;
			IsHeroAlive[17][i]=0;
			break;
		}
		if(x>EnemyFirstX)x--;
		CurrentHeroX[17][i]=x;
	}
}
void callrole18(void *arg)
{
	int y=Form_Y+13,x=Form_X+83;
	int i=*(int *)arg;
	int atk18;
	atk18=(int)((float)HeroBasicAtk[18]*(1.+((float)HeroLV[18]/10)));
	CurrentHeroHP[18][i]=(int)((float)HeroBasicHP[18]*(1.+((float)HeroLV[18]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			printf("\x1b[%d;%dH      ",y+1,x-3);
			IsHeroAlive[18][i]=0;
			CurrentHeroX[18][i]=0;
			break;
		}
		if(CurrentHeroHP[18][i]<=0)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			printf("\x1b[%d;%dH      ",y+1,x-3);
			IsHeroAlive[18][i]=0;
			CurrentHeroX[18][i]=0;
			HeroBattleNum[18]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH  €○",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌",y+1,x-3);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX+20)
		{
			printf("\x1b[%d;%dH  €○ ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌ ",y+1,x-3);
			Sleep(300);
		}
		if(x<=EnemyFirstX+20)
		{
			printf("\x1b[%d;%dH  €○ ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌ ",y+1,x-3);
			Sleep(300);
			printf("\x1b[%d;%dH←€○",y,x-3);
			for(int j=3;j<=16;j++)
			{
				printf("\x1b[%d;%dH← ",y,x-j);
				Sleep(50);
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]>=x-20&&CurrentEnemyX[j][k]==EnemyFirstX)
						CurrentEnemyHP[j][k]-=atk18;
				}
			}
			printf("\x1b[%d;%dH  ",y,x-16);
			Sleep(400);
		}
		if(x>EnemyFirstX+20)x--;
		CurrentHeroX[18][i]=x;
	}
}
void callrole19(void *arg)
{
	int y=Form_Y+18,x=Form_X+52;
	int i=*(int *)arg;
	int atk19;
	int x19;
	atk19=(int)((float)HeroBasicAtk[19]*(1.+((float)HeroLV[19]/10)));
	CurrentHeroHP[19][i]=(int)((float)HeroBasicHP[19]*(1.+((float)HeroLV[19]/10)));
	while(1)
	{
		if(MainMenu==0||MainMenu==1||MainMenu==2||MainMenu==3||MainMenu==4||MainMenu==5||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH          ",y-2,x+7);
			printf("\x1b[%d;%dH               ",y-1,x+5);
			printf("\x1b[%d;%dH                         ",y,x+5);
			printf("\x1b[%d;%dH                                 ",y+1,x);
			IsHeroAlive[19][i]=0;
			CurrentHeroX[19][i]=0;
			break;
		}
		if(CurrentHeroHP[19][i]<=0)
		{
			printf("\x1b[%d;%dH          ",y-2,x+7);
			printf("\x1b[%d;%dH               ",y-1,x+5);
			printf("\x1b[%d;%dH                         ",y,x+5);
			printf("\x1b[%d;%dH                                 ",y+1,x);
			IsHeroAlive[19][i]=0;
			CurrentHeroX[19][i]=0;
			HeroBattleNum[19]--;
			break;
		}
		if(x==Form_X+52)
		{
			printf("\x1b[%d;%dH\033[0;46m          \033[0m      Z",y-2,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m z",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;30;46m     ─          \033[0m    \033[0;36m◣◢ \033[0m",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m",y+1,x);
		}
		if(x<=EnemyFirstX+20)
		{
			printf("\x1b[%d;%dH\033[0;46m          \033[0m      Z ",y-2,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m z ",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;30;46m     ─          \033[0m    \033[0;36m◣◢ \033[0m ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m─",y+1,x);
			Sleep(2000);
			printf("\x1b[%d;%dH\033[0;46m          \033[0m        ",y-2,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m    ",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;30;46m     Θ         \033[0m    \033[0;36m◣◢ \033[0m ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH                ",y-2,x+7);
			printf("\x1b[%d;%dH  \033[0;46m          \033[0m    ",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m          ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;30;46m     Θ         \033[0m\033[0;34m～～\033[0m\033[0;36m◣◢\033[0m\033[0;34m～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH                      ",y-1,x+5);
			printf("\x1b[%d;%dH  \033[0;46m          \033[0m          ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;46m               \033[0m\033[0m\033[0;34m～～～～～～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH               ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;46m          \033[0m\033[0m\033[0;34m～～～～～～～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH\033[0;34m～～～～～～～～～～～～～～～～\033[0m─",y+1,x);
			Sleep(700);
			for(int i=1;i<=12;i++)
			{
				printf("\x1b[%d;%dH\033[0;34m～～～～～～～～～～～～～～～～\033[0m─",y+1,x);
				printf("\x1b[%d;%dH\033[0;36m↑\033[0m",y-i,x+11);
				if(MainMenu==0||MainMenu==1||MainMenu==2||MainMenu==3||MainMenu==4||MainMenu==5||MinorMenu==5||MinorMenu==6)break;
				Sleep(150);
				printf("\x1b[%d;%dH  ",y-i,x+11);
			}
			printf("\x1b[%d;%dH  ",y-12,x+11);
			Sleep(550);
			x19=EnemyFirstX-4;
			for(int j=12;j>=4;j--)
			{
				if(MainMenu==0||MainMenu==1||MainMenu==2||MainMenu==3||MainMenu==4||MainMenu==5||MinorMenu==5||MinorMenu==6)break;
				printf("\x1b[%d;%dH  \033[0;46m      \033[0m  ",y-j,x19);
				printf("\x1b[%d;%dH\033[0;46m          \033[0m",y-j+1,x19);
				printf("\x1b[%d;%dH\033[0;46m          \033[0m",y-j+2,x19);
				printf("\x1b[%d;%dH\033[0;46m          \033[0m",y-j+3,x19);
				printf("\x1b[%d;%dH  \033[0;46m      \033[0m  ",y-j+4,x19);
				for(int j=0;j<=3;j++)
				{
					for(int k=0;k<=5;k++)
					{
						if(CurrentEnemyX[j][k]<=x19+4&&CurrentEnemyX[j][k]>=x19-2)
							CurrentEnemyHP[j][k]-=(int)((float)atk19*0.01);
					}
				}
				Sleep(250);
				printf("\x1b[%d;%dH          ",y-j,x19);
			}
			x19=EnemyFirstX-4;
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]<=x19+4&&CurrentEnemyX[j][k]>=x19-2)
						CurrentEnemyHP[j][k]-=atk19;
				}
			}
			printf("\x1b[%d;%dH          ",y-3,x19);
			printf("\x1b[%d;%dH          ",y-2,x19);
			printf("\x1b[%d;%dH          ",y-1,x19);
			printf("\x1b[%d;%dH          ",y,x19);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;46m          \033[0m\033[0m\033[0;34m～～～～～～～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH\033[0;46m          \033[0m",y,x+7);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;46m               \033[0m\033[0m\033[0;34m～～～～～～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH\033[0;46m          \033[0m",y-1,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～ \033[0;30;46m     Θ         \033[0m\033[0;34m～～\033[0m\033[0;36m◣◢\033[0m\033[0;34m～～\033[0m─",y+1,x);
			Sleep(300);
			printf("\x1b[%d;%dH\033[0;46m          \033[0m",y-2,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;30;46m     Θ         \033[0m    \033[0;36m◣◢ \033[0m",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m─",y+1,x);
			Sleep(300);
		}
		else
		{
			Sleep(800);
			printf("\x1b[%d;%dH\033[0;46m          \033[0m      Z ",y-2,x+7);
			printf("\x1b[%d;%dH\033[0;46m               \033[0m z ",y-1,x+5);
			printf("\x1b[%d;%dH\033[0;30;46m     ─          \033[0m    \033[0;36m◣◢ \033[0m ",y,x+5);
			printf("\x1b[%d;%dH\033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m─",y+1,x);
		}
		if(x>EnemyFirstX+20)x--;
		CurrentHeroX[19][i]=x;
	}
}
void callrole20(void *arg)
{
	int y=Form_Y+9,x=Form_X+83;
	int i=*(int *)arg;
	int atk20;
	atk20=(int)((float)HeroBasicAtk[20]*(1.+((float)HeroLV[20]/10)));
	CurrentHeroHP[20][i]=(int)((float)HeroBasicHP[20]*(1.+((float)HeroLV[20]/10)));
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			printf("\x1b[%d;%dH      ",y+1,x-3);
			IsHeroAlive[20][i]=0;
			CurrentHeroX[20][i]=0;
			break;
		}
		if(CurrentHeroHP[20][i]<=0)
		{
			printf("\x1b[%d;%dH      ",y,x-3);
			printf("\x1b[%d;%dH      ",y+1,x-3);
			IsHeroAlive[20][i]=0;
			CurrentHeroX[20][i]=0;
			HeroBattleNum[20]--;
			break;
		}
		if(x==Form_X+83)
		{
			printf("\x1b[%d;%dH \033[1;33mㄣ\033[0m\033[0;33m○\033[0m",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌",y+1,x-3);
			Sleep(300);
		}
		if(x!=Form_X+83&&x>EnemyFirstX)
		{
			printf("\x1b[%d;%dH \033[1;33mㄣ\033[0m\033[0;33m○\033[0m ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌ ",y+1,x-3);
			Sleep(300);
		}
		if(x<=EnemyFirstX+2)
		{
			printf("\x1b[%d;%dH \033[1;33mㄣ\033[0m\033[0;33m○\033[0m ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌ ",y+1,x-3);
			Sleep(300);
			printf("\x1b[%d;%dH \033[0;33mㄣ\033[0m",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌",y+1,x-3);
			Sleep(300);
			printf("\x1b[%d;%dH \033[0;31mㄣ\033[0m\033[0;33m○\033[0m ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌",y+1,x-3);
			Sleep(300);
			printf("\x1b[%d;%dH \033[0;35mㄣ\033[0m\033[0;33m○\033[0m ",y,x-3);
			printf("\x1b[%d;%dH﹌﹌﹌",y+1,x-3);
			Sleep(300);
			for(int j=2;j<=10;j++)
			{
				printf("\x1b[%d;%dH\033[1;33mㄣㄣㄣ\033[0m",y+j,x-3);
				Sleep(50);
				printf("\x1b[%d;%dH      ",y+j,x-3);
				for(int j=0;j<=3;j++)
				{
					for(int k=0;k<=5;k++)
					{
						if(CurrentEnemyX[j][k]<=x&&CurrentEnemyX[j][k]>=x-6)
							CurrentEnemyHP[j][k]-=(int)((float)atk20*0.01);
					}
				}
			}
			for(int j=0;j<=3;j++)
			{
				for(int k=0;k<=5;k++)
				{
					if(CurrentEnemyX[j][k]<=x&&CurrentEnemyX[j][k]>=x-6)
						CurrentEnemyHP[j][k]-=atk20;
				}
			}
			printf("\x1b[%d;%dH──────",y+10,x-3);
			Sleep(400);
		}
		if(x>EnemyFirstX+2)
		{
			x--;
			CurrentHeroX[20][i]=x;
		}
	}
}
void callenemy1(void *arg)
{
	int y=Form_Y+18,x=27;
	int i=*(int *)arg;
	int atk1;
	IsEnemyAlive[1][i]=1;
	if(MainMenu==6){atk1=150;CurrentEnemyHP[1][i]=250;}
	if(MainMenu==7){atk1=300;CurrentEnemyHP[1][i]=500;}
	if(MainMenu==8){atk1=450;CurrentEnemyHP[1][i]=1000;}
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH      ",y,x-2);
			IsEnemyAlive[1][i]=0;
			CurrentEnemyX[1][i]=0;
			break;
		}
		if(CurrentEnemyHP[1][i]<=0)
		{
			printf("\x1b[%d;%dH      ",y,x-2);
			IsEnemyAlive[1][i]=0;
			CurrentEnemyX[1][i]=0;
			x=0;
			TotalEnemyNum--;
			break;
		}
		if(x==27){printf("\x1b[%d;%dH\033[0;31m○↑\033[0m",y,x-1);Sleep(300);}
		if(x!=27&&x<HeroFirstX){printf("\x1b[%d;%dH\033[0;31m ○↑\033[0m",y,x-2);Sleep(300);}
		if(x>=HeroFirstX-3)
		{
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;31m ○↑\033[0m",y,x-2);
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;31m○↗\033[0m",y,x-1);
			Sleep(200);
			printf("\x1b[%d;%dH\033[0;31m○→\033[0m",y,x-1);
			for(int j=0;j<=20;j++)
			{
				for(int k=0;k<=10;k++)
				{
					if(CurrentHeroX[j][k]<=x+3)
						CurrentHeroHP[j][k]-=atk1;
				}
			}
			Sleep(200);
		}
		if(x<HeroFirstX-3)
		{
			x++;
			CurrentEnemyX[1][i]=x;
		}
	}
}
void callenemy2(void *arg)
{
	int y=Form_Y+18,x=27;
	int i=*(int *)arg;
	IsEnemyAlive[2][i]=1;
	int atk2;
	if(MainMenu==6){atk2=150;CurrentEnemyHP[2][i]=250;}
	if(MainMenu==7){atk2=300;CurrentEnemyHP[2][i]=500;}
	if(MainMenu==8){atk2=450;CurrentEnemyHP[2][i]=1000;}
	while(1)
	{
		if(MainMenu==0||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsEnemyAlive[2][i]=0;
			CurrentEnemyX[2][i]=0;
			break;
		}
		if(CurrentEnemyHP[2][i]<=0)
		{
			printf("\x1b[%d;%dH    ",y,x-1);
			IsEnemyAlive[2][i]=0;
			CurrentEnemyX[2][i]=0;
			x=0;
			TotalEnemyNum--;
			break;
		}
		if(x==27)
		{
			printf("\x1b[%d;%dH\033[0;31m○￥\033[0m",y,x-1);
			Sleep(300);
		}
		if(x!=27&&x<HeroFirstX)
		{
			printf("\x1b[%d;%dH \033[0;31m○￥\033[0m",y,x-2);Sleep(300);
		}
		if(x>=HeroFirstX-23)
		{
			printf("\x1b[%d;%dH\033[0;31m￥\033[0m",y-1,x+1);
			printf("\x1b[%d;%dH \033[0;31m○\033[0m  ",y,x-2);
			Sleep(150);
			printf("\x1b[%d;%dH  ",y-1,x+1);
			printf("\x1b[%d;%dH\033[0;31m○￥\033[0m",y,x-1);
			printf("\x1b[%d;%dH\033[1;31mwWw\033[0m",y+1,x+20);
			for(int j=0;j<=20;j++)
			{
				for(int k=0;k<=10;k++)
				{
					if(CurrentHeroX[j][k]<=x+23)
						CurrentHeroHP[j][k]-=atk2;
				}
			}
			Sleep(700);
			printf("\x1b[%d;%dH───",y+1,x+20);
		}
		if(x<HeroFirstX-23)
		{
			x++;
			CurrentEnemyX[2][i]=x;
		}
	}
}
void callenemy3(void *arg)
{
	int y=Form_Y+18,x=21;
	int i=*(int *)arg;
	IsEnemyAlive[3][i]=1;
	int atk3;
	if(MainMenu==6){atk3=600;CurrentEnemyHP[3][i]=500;}
	if(MainMenu==7){atk3=1200;CurrentEnemyHP[3][i]=1000;}
	if(MainMenu==8){atk3=2400;CurrentEnemyHP[3][i]=2000;}
	while(1)
	{
		if(MainMenu==0||MainMenu==1||MainMenu==2||MainMenu==3||MainMenu==4||MainMenu==5||MinorMenu==5||MinorMenu==6)
		{
			printf("\x1b[%d;%dH        ",y-4,x+4);
			printf("\x1b[%d;%dH        ",y-3,x+4);
			printf("\x1b[%d;%dH            ",y-2,x+4);
			printf("\x1b[%d;%dH      ",y-1,x+1+4);
			printf("\x1b[%d;%dH      ",y,x+1+4);
			printf("\x1b[%d;%dH          ",y+1,x-1+4);
			IsEnemyAlive[3][i]=0;
			CurrentEnemyX[3][i]=0;
			break;
		}
		if(CurrentEnemyHP[3][i]<=0)
		{
			printf("\x1b[%d;%dH        ",y-4,x+4);
			printf("\x1b[%d;%dH        ",y-3,x+4);
			printf("\x1b[%d;%dH            ",y-2,x+4);
			printf("\x1b[%d;%dH      ",y-1,x+1+4);
			printf("\x1b[%d;%dH      ",y,x+5);
			printf("\x1b[%d;%dH          ",y+1,x-1+4);
			IsEnemyAlive[3][i]=0;
			CurrentEnemyX[3][i]=0;
			x=0;
			TotalEnemyNum--;
			break;
		}
		if(x==21)
		{
			printf("\x1b[%d;%dH\033[0;31m◣▲◢\033[0m",y-4,x+6);
			printf("\x1b[%d;%dH\033[0;30;41m   Θ \033[0m",y-3,x+6);
			printf("\x1b[%d;%dH\033[0;41m      \033[0m",y-2,x+6);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y-1,x+7);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y,x+7);
			printf("\x1b[%d;%dH\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+5);
			Sleep(300);
		}
		if(x!=21&&x<HeroFirstX)
		{
			printf("\x1b[%d;%dH \033[0;31m◣▲◢\033[0m",y-4,x+5);
			printf("\x1b[%d;%dH \033[0;30;41m   Θ \033[0m",y-3,x+5);
			printf("\x1b[%d;%dH \033[0;41m      \033[0m",y-2,x+5);
			printf("\x1b[%d;%dH \033[0;41m    \033[0m",y-1,x+6);
			printf("\x1b[%d;%dH \033[0;41m    \033[0m",y,x+6);
			printf("\x1b[%d;%dH─\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+4);
			Sleep(300);
		}
		if(x>=HeroFirstX-43)
		{
			Sleep(1500);
			printf("\x1b[%d;%dH \033[0;31m◣▲◢\033[0m",y-4,x+5);
			printf("\x1b[%d;%dH \033[0;30;41m   Θ \033[0m",y-3,x+5);
			printf("\x1b[%d;%dH \033[0;41m      \033[0m",y-2,x+5);
			printf("\x1b[%d;%dH \033[0;41m    \033[0m",y-1,x+6);
			printf("\x1b[%d;%dH \033[0;41m    \033[0m",y,x+6);
			printf("\x1b[%d;%dH─\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+4);
			Sleep(400);
			printf("\x1b[%d;%dH\033[0;31m◣▲◢\033[0m",y-4,x+6);
			printf("\x1b[%d;%dH\033[0;30;41m   Θ \033[0m",y-3,x+6);
			printf("\x1b[%d;%dH\033[0;41m      \033[0m   \033[0;31m○\033[0m",y-2,x+6);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y-1,x+7);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y,x+7);
			printf("\x1b[%d;%dH\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+5);
			Sleep(400);
			printf("\x1b[%d;%dH\033[0;31m◣▲◢\033[0m",y-4,x+6);
			printf("\x1b[%d;%dH\033[0;30;41m   Θ \033[0m",y-3,x+6);
			printf("\x1b[%d;%dH\033[0;41m      \033[0m   \033[0;31m●\033[0m",y-2,x+6);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y-1,x+7);
			printf("\x1b[%d;%dH\033[0;41m    \033[0m",y,x+7);
			printf("\x1b[%d;%dH\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+5);
			Sleep(500);
			for(int i=0;HeroFirstX>=x+22+i;i++)
			{
				printf("\x1b[%d;%dH\033[0;31m◣▲◢\033[0m",y-4,x+6);
				printf("\x1b[%d;%dH\033[0;30;41m   Θ \033[0m",y-3,x+6);
				printf("\x1b[%d;%dH\033[0;41m      \033[0m",y-2,x+6);
				printf("\x1b[%d;%dH\033[0;41m    \033[0m",y-1,x+7);
				printf("\x1b[%d;%dH\033[0;41m    \033[0m",y,x+7);
				printf("\x1b[%d;%dH\033[0;31m～\033[0m\033[0;41m    \033[0m\033[0;31m～\033[0m",y+1,x+5);
				printf("\x1b[%d;%dH   \033[0;41m      \033[0m  ",y-4,x+12+i);
				printf("\x1b[%d;%dH \033[0;41m          \033[0m",y-3,x+12+i);
				printf("\x1b[%d;%dH \033[0;41m          \033[0m",y-2,x+12+i);
				printf("\x1b[%d;%dH \033[0;41m          \033[0m",y-1,x+12+i);
				printf("\x1b[%d;%dH   \033[0;41m      \033[0m  ",y,x+12+i);
				if(MainMenu==0||MainMenu==1||MainMenu==2||MainMenu==3||MainMenu==4||MainMenu==5||MinorMenu==5||MinorMenu==6)break;
				Sleep(200);
			}
			for(int j=0;j<=20;j++)
			{
				for(int k=0;k<=10;k++)
				{
					if(CurrentHeroX[j][k]<=x+43)
						CurrentHeroHP[j][k]-=atk3;
				}
			}
			Sleep(250);
			printf("\x1b[%d;%dH           ",y-4,HeroFirstX-10);
			printf("\x1b[%d;%dH           ",y-3,HeroFirstX-10);
			printf("\x1b[%d;%dH           ",y-2,HeroFirstX-10);
			printf("\x1b[%d;%dH           ",y-1,HeroFirstX-10);
			printf("\x1b[%d;%dH           ",y,HeroFirstX-10);
			Sleep(200);
		}
		if(x<HeroFirstX-43)
		{
			x++;
			CurrentEnemyX[3][i]=x+8;
		}
	}
}
void bombbomb()
{
	int y=Form_Y+18;
	for(int j=12;j>=1;j--)
	{
		printf("\x1b[%d;%dH↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓",y-j,26);
		Sleep(50);
		printf("\x1b[%d;%dH                                                                    ",y-1-j,26);
	}
	Sleep(150);
	printf("\x1b[%d;%dH                                                                    ",y-1,26);
	for(int j=1;j<=3;j++)
	{
		for(int k=1;k<=5;k++)
		{
			CurrentEnemyHP[j][k]-=BasicTowerLV*100+100;
		}
	}
}
void DrawForm()
{
	system("cls");
	for (int row = 1; row < Form_Weight * 2 - 2; row += 2)
	{
		printf("\x1b[%d;%dH\033[1;34m──\033[0m",Form_Y+1,Form_X+row);
		printf("\x1b[%d;%dH\033[1;34m──\033[0m",Form_Y+Form_Height+1,Form_X+row);
	}
	for (int col = 1; col < Form_Height; col++)
	{
//		printf("\x1b[%d;%dH\033[1;34m│\033[0m",Form_Y + col+1,Form_X+1);
//		printf("\x1b[%d;%dH\033[1;34m│\033[0m",Form_Y + col+1,Form_X + Form_Weight * 2 -1);
		printf("\x1b[%d;%dH│",Form_Y + col+1,Form_X+1);
		printf("\x1b[%d;%dH│",Form_Y + col+1,Form_X + Form_Weight * 2 -1);
	}
	printf("\x1b[%d;%dH\033[1;34m┌\033[0m",Form_Y+1,Form_X+1);
	printf("\x1b[%d;%dH┐\033[0m",Form_Y+1,Form_X+Form_Weight*2-1);
	printf("\x1b[%d;%dH\033[1;34m└\033[0m",Form_Y+Form_Height+1,Form_X+1);
	printf("\x1b[%d;%dH┘\033[0m",Form_Y+Form_Height+1,Form_X+Form_Weight*2-1);
	if(MainMenu!=1&&MainMenu!=4&&MainMenu!=6&&MainMenu!=7&&MainMenu!=8)
	{
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+2,Form_X+56);
		printf("\x1b[%d;%dH│   EXP %9d │",Form_Y+3,Form_X+56,EXP);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+4,Form_X+56);
	}
	if((MainMenu==1&&Team[1]!=0)||(MainMenu==2&&MinorMenu==0)||(MainMenu==3)||(MainMenu==4)||(MainMenu==5)||(MainMenu==6)||(MainMenu==7)||(MainMenu==8))
	{
		printf("\x1b[%d;%dH\033[0m┌────────────┐",Form_Y + 2,Form_X + 5);
		printf("\x1b[%d;%dH\033[0m│ 0. 主選單  │",Form_Y + 3,Form_X + 5);
		printf("\x1b[%d;%dH\033[0m└────────────┘",Form_Y + 4,Form_X + 5);
	}
	printf("\x1b[%d;%dH┌─────────────────┐",Form_Y + 2,Form_X + 78);
	printf("\x1b[%d;%dH│ 星石☆  %7d │",Form_Y + 3,Form_X + 78,diamond);
	printf("\x1b[%d;%dH└─────────────────┘",Form_Y + 4,Form_X + 78);
	if(MainMenu==0)
	{
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+7,Form_X+11);
		printf("\x1b[%d;%dH│   \033[1;33m1.\033[0m 戰    鬥   │",Form_Y+8,Form_X+11);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+9,Form_X+11);
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+10,Form_X+11);
		printf("\x1b[%d;%dH│   \033[1;33m2.\033[0m 抽    卡   │",Form_Y+11,Form_X+11);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+12,Form_X+11);
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+13,Form_X+11);
		printf("\x1b[%d;%dH│   \033[1;33m3.\033[0m 角色升級   │",Form_Y+14,Form_X+11);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+15,Form_X+11);
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+16,Form_X+11);
		printf("\x1b[%d;%dH│   \033[1;33m4.\033[0m 隊伍編成   │",Form_Y+17,Form_X+11);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+18,Form_X+11);
		printf("\x1b[%d;%dH┌─────────────────┐",Form_Y+19,Form_X+11);
		printf("\x1b[%d;%dH│   \033[1;33m5.\033[0m 選    單   │",Form_Y+20,Form_X+11);
		printf("\x1b[%d;%dH└─────────────────┘",Form_Y+21,Form_X+11);
		printf("\x1b[%d;%dH┌────────────┐",Form_Y+2,Form_X+5);
		printf("\x1b[%d;%dH│ Z. 退  出  │",Form_Y+3,Form_X+5);
		printf("\x1b[%d;%dH└────────────┘",Form_Y+4,Form_X+5);
		printf("\x1b[%d;%dH┌────────────────────────────────────┐",Form_Y+9,Form_X+50);
		printf("\x1b[%d;%dH│                                    │",Form_Y+12,Form_X+50);
		printf("\x1b[%d;%dH│                                    │",Form_Y+18,Form_X+50);
		printf("\x1b[%d;%dH│              ☆現在10連抽就送1抽☆ │",Form_Y+19,Form_X+50);
		printf("\x1b[%d;%dH└────────────────────────────────────┘",Form_Y+20,Form_X+50);
		printf("\x1b[%d;%dH〈",Form_Y+14,Form_X+45);
		printf("\x1b[%d;%dH〉",Form_Y+14,Form_X+92);
		if(ClickTabNum[0]%2==0)
		{
			printf("\x1b[%d;%dH│   UR角色：\033[1;36mㄎ鯨\033[0m登場       Id : 19   │",Form_Y+10,Form_X+50);
			printf("\x1b[%d;%dH│   按U可觀看大圖                    │",Form_Y+11,Form_X+50);
			printf("\x1b[%d;%dH│                                    │",Form_Y+13,Form_X+50);
			printf("\x1b[%d;%dH│        \033[0;46m          \033[0m      Z           │",Form_Y+14,Form_X+50);
			printf("\x1b[%d;%dH│      \033[0;46m               \033[0m z             │",Form_Y+15,Form_X+50);
			printf("\x1b[%d;%dH│      \033[0;30;46m     ─          \033[0m    \033[0;36m◣◢ \033[0m     │",Form_Y+16,Form_X+50);
			printf("\x1b[%d;%dH│ \033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m  │",Form_Y+17,Form_X+50);
		}
		if(ClickTabNum[0]%2==1)
		{
			printf("\x1b[%d;%dH│   UR角色：\033[1;33m雷神\033[0m登場       Id : 20   │",Form_Y+10,Form_X+50);
			printf("\x1b[%d;%dH│   按U可觀看大圖                    │",Form_Y+11,Form_X+50);
			printf("\x1b[%d;%dH│               \033[0;31mㄣ\033[0m\033[0;33m○\033[0m                 │",Form_Y+13,Form_X+50);
			printf("\x1b[%d;%dH│              ﹌﹌﹌                │",Form_Y+14,Form_X+50);
			printf("\x1b[%d;%dH│                                    │",Form_Y+15,Form_X+50);
			printf("\x1b[%d;%dH│                                    │",Form_Y+16,Form_X+50);
			printf("\x1b[%d;%dH│              \033[1;33mㄣㄣㄣ\033[0m                │",Form_Y+17,Form_X+50);
		}
	}
	if(MainMenu==1&&Team[1]==0)
	{
		printf("\x1b[%d;%dH┌────────────────────────────────────────────────────────────┐",Form_Y+6,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+7,Form_X+19);
		printf("\x1b[%d;%dH│                      \033[0;31mE R R O R ! !\033[0m                         │",Form_Y+8,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+9,Form_X+19);
		printf("\x1b[%d;%dH│                      請先編輯隊伍                          │",Form_Y+10,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+11,Form_X+19);
		printf("\x1b[%d;%dH│                      \033[0;31mE R R O R ! !\033[0m                         │",Form_Y+12,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+13,Form_X+19);
		printf("\x1b[%d;%dH│                      請先編輯隊伍                          │",Form_Y+14,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+15,Form_X+19);
		printf("\x1b[%d;%dH│                      \033[0;31mE R R O R ! !\033[0m                         │",Form_Y+16,Form_X+19);
		printf("\x1b[%d;%dH│                                                            │",Form_Y+17,Form_X+19);
		printf("\x1b[%d;%dH└────────────────────────────────────────────────────────────┘",Form_Y+18,Form_X+19); 
	}
	if(MainMenu==1&&Team[1]!=0)
	{
		printf("\x1b[%d;%dH┌─────────────────┐   ┌─────────────────┐   ┌─────────────────┐",Form_Y+8,Form_X+19);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+9,Form_X+19);
		printf("\x1b[%d;%dH│    A. \033[1;36m簡  單\033[0m    │   │    B. \033[1;32m普  通\033[0m    │   │    C. \033[0;31m困  難\033[0m    │",Form_Y+10,Form_X+19);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+11,Form_X+19);
		printf("\x1b[%d;%dH│  敵人攻擊力\033[1;36m減半\033[0m │   │  敵人攻擊力\033[1;32m正常\033[0m │   │  敵人攻擊力\033[0;31m加倍\033[0m │",Form_Y+12,Form_X+19);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+13,Form_X+19);
		printf("\x1b[%d;%dH│   敵方塔HP\033[1;36m減半\033[0m  │   │   敵方塔HP\033[1;32m正常\033[0m  │   │   敵方塔HP\033[0;31m加倍\033[0m  │",Form_Y+14,Form_X+19);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+15,Form_X+19);
		printf("\x1b[%d;%dH│  敵方角色HP\033[1;36m減半\033[0m │   │  敵方角色HP\033[1;32m正常\033[0m │   │  敵方角色HP\033[0;31m加倍\033[0m │",Form_Y+16,Form_X+19);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+17,Form_X+19);
		printf("\x1b[%d;%dH│   已通關%3d 次  │   │   已通關%3d 次  │   │   已通關%3d 次  │",Form_Y+18,Form_X+19,CompleteBattle[0],CompleteBattle[1],CompleteBattle[2]);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+19,Form_X+19);
		printf("\x1b[%d;%dH│   失敗數%3d 次  │   │   失敗數%3d 次  │   │   失敗數%3d 次  │",Form_Y+20,Form_X+19,FailBattle[0],FailBattle[1],FailBattle[2]);
		printf("\x1b[%d;%dH│                 │   │                 │   │                 │",Form_Y+21,Form_X+19);
		printf("\x1b[%d;%dH└─────────────────┘   └─────────────────┘   └─────────────────┘",Form_Y+22,Form_X+19);
	}
	if(MainMenu==2)
	{
		if(MinorMenu==0)
		{
			printf("\x1b[%d;%dH╭────────╮",Form_Y+2,Form_X+45);
			printf("\x1b[%d;%dH│ O.機率 │",Form_Y+3,Form_X+45);
			printf("\x1b[%d;%dH╰────────╯",Form_Y+4,Form_X+45);
			printf("\x1b[%d;%dH┌────────────────────────────────────────────────────────────┐",Form_Y+6,Form_X+19);
			printf("\x1b[%d;%dH│                                                            │",Form_Y+8,Form_X+19);
			printf("\x1b[%d;%dH│                                                            │",Form_Y+9,Form_X+19);
			printf("\x1b[%d;%dH│                                                            │",Form_Y+14,Form_X+19);
			printf("\x1b[%d;%dH│                                                            │",Form_Y+16,Form_X+19);
			printf("\x1b[%d;%dH└────────────────────────────────────────────────────────────┘",Form_Y+18,Form_X+19);
			if(ClickTabNum[2]%2==0)
			{
				printf("\x1b[%d;%dH│   UR角色：\033[1;36mㄎ鯨\033[0m登場                       Id:19             │",Form_Y+7,Form_X+19);
				printf("\x1b[%d;%dH│                        \033[0;46m          \033[0m      Z                   │",Form_Y+10,Form_X+19);
				printf("\x1b[%d;%dH│                      \033[0;46m               \033[0m z                     │",Form_Y+11,Form_X+19);
				printf("\x1b[%d;%dH│                      \033[0;30;46m     ─          \033[0m    \033[0;36m◣◢ \033[0m             │",Form_Y+12,Form_X+19);
				printf("\x1b[%d;%dH│                 \033[0;34m～～\033[0;46m                       \033[0m\033[0;34m\033[0;36m◤\033[0m\033[0;34m～～\033[0m          │",Form_Y+13,Form_X+19);
				printf("\x1b[%d;%dH│                                                            │",Form_Y+15,Form_X+19);
				printf("\x1b[%d;%dH│  (UR角色\033[1;33m雷神\033[0m不出現(Id:20))                  按U可觀看大圖  │",Form_Y+17,Form_X+19);
			}
			if(ClickTabNum[2]%2==1)
			{
				printf("\x1b[%d;%dH│   UR角色：\033[1;33m雷神\033[0m登場                       Id:20             │",Form_Y+7,Form_X+19);
				printf("\x1b[%d;%dH│                             \033[0;31mㄣ\033[0m\033[0;33m○\033[0m                           │",Form_Y+10,Form_X+19);
				printf("\x1b[%d;%dH│                            ﹌﹌﹌                          │",Form_Y+11,Form_X+19);
				printf("\x1b[%d;%dH│                                                            │",Form_Y+12,Form_X+19);
				printf("\x1b[%d;%dH│                                                            │",Form_Y+13,Form_X+19);
				printf("\x1b[%d;%dH│                            \033[1;33mㄣㄣㄣ\033[0m                          │",Form_Y+15,Form_X+19);
				printf("\x1b[%d;%dH│  (UR角色\033[1;36mㄎ鯨\033[0m不出現(Id:19))                  按U可觀看大圖  │",Form_Y+17,Form_X+19);
			}
			printf("\x1b[%d;%dH┌─────────────────┐                        ┌─────────────────┐",Form_Y+19,Form_X+19);
			printf("\x1b[%d;%dH│   H. 單    抽   │                        │   L. 10  +1 抽  │",Form_Y+20,Form_X+19);
			printf("\x1b[%d;%dH│     星石   20   │                        │     星石   200  │",Form_Y+21,Form_X+19);
			printf("\x1b[%d;%dH└─────────────────┘                        └─────────────────┘",Form_Y+22,Form_X+19);
		}
		if(MinorMenu==3)
		{
			printf("\x1b[%d;%dH┌────────────────────────┐",Form_Y+7,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+8,Form_X+37);
			printf("\x1b[%d;%dH│   N(6隻):       42%%    │",Form_Y+9,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+10,Form_X+37);
			printf("\x1b[%d;%dH│   R(5隻):       30%%    │",Form_Y+11,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+12,Form_X+37);
			printf("\x1b[%d;%dH│   SR(4隻):      16%%    │",Form_Y+13,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+14,Form_X+37);
			printf("\x1b[%d;%dH│   SSR(3隻):      9%%    │",Form_Y+15,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+16,Form_X+37);
			printf("\x1b[%d;%dH│   UR(1隻):       3%%    │",Form_Y+17,Form_X+37);
			printf("\x1b[%d;%dH│                        │",Form_Y+18,Form_X+37);
			printf("\x1b[%d;%dH└────────────────────────┘",Form_Y+19,Form_X+37);
		}
		printf("\x1b[%d;%dH〈",Form_Y+12,Form_X+5);
		printf("\x1b[%d;%dH〉",Form_Y+12,Form_X+96);
		if(MinorMenu==1)
		{
			printf("\x1b[%d;%dH┌───────────────────────────────────────┐",Form_Y+5,Form_X+30);
			printf("\x1b[%d;%dH│                                       │",Form_Y+6,Form_X+30);
			printf("\x1b[%d;%dH│      ┌────────────────────────┐       │",Form_Y+7,Form_X+30);
			printf("\x1b[%d;%dH│      │  %-3s         Id:%-2d     │       │",Form_Y+8,Form_X+30,rarity[HeroRarity[OpenHeroImage[1]]],OpenHeroImage[1]);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+9,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+10,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+11,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+12,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+13,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+14,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+15,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+16,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+17,Form_X+30);
			printf("\x1b[%d;%dH│      └────────────────────────┘       │",Form_Y+18,Form_X+30);
			printf("\x1b[%d;%dH│                                       │",Form_Y+19,Form_X+30);
			printf("\x1b[%d;%dH└───────────────────────────────────────┘",Form_Y+20,Form_X+30);
		}
		if(MinorMenu==11)
		{
			printf("\x1b[%d;%dH┌──────────────────────────────────────────────────────────────────────┐",Form_Y+5,Form_X+15);
			printf("\x1b[%d;%dH│                                                                      │",Form_Y+6,Form_X+15);
			printf("\x1b[%d;%dH│  ┌────────────┬────────────┬────────────┬────────────┬────────────┐  │",Form_Y+7,Form_X+15);
			printf("\x1b[%d;%dH│  │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │  │",Form_Y+8,Form_X+15,rarity[HeroRarity[OpenHeroImage[1]]],OpenHeroImage[1],rarity[HeroRarity[OpenHeroImage[2]]],OpenHeroImage[2],rarity[HeroRarity[OpenHeroImage[3]]],OpenHeroImage[3],rarity[HeroRarity[OpenHeroImage[4]]],OpenHeroImage[4],rarity[HeroRarity[OpenHeroImage[5]]],OpenHeroImage[5]);
			printf("\x1b[%d;%dH│  │            │            │            │            │            │  │",Form_Y+9,Form_X+15);
			printf("\x1b[%d;%dH│  │            │            │            │            │            │  │",Form_Y+10,Form_X+15);
			printf("\x1b[%d;%dH│  └────────────┴────────────┴────────────┴────────────┴────────────┘  │",Form_Y+11,Form_X+15);
			printf("\x1b[%d;%dH│  ┌────────────┬────────────┬────────────┬────────────┬────────────┐  │",Form_Y+12,Form_X+15);
			printf("\x1b[%d;%dH│  │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │ %-3s  Id:%-2d │  │",Form_Y+13,Form_X+15,rarity[HeroRarity[OpenHeroImage[6]]],OpenHeroImage[6],rarity[HeroRarity[OpenHeroImage[7]]],OpenHeroImage[7],rarity[HeroRarity[OpenHeroImage[8]]],OpenHeroImage[8],rarity[HeroRarity[OpenHeroImage[9]]],OpenHeroImage[9],rarity[HeroRarity[OpenHeroImage[10]]],OpenHeroImage[10]);
			printf("\x1b[%d;%dH│  │            │            │            │            │            │  │",Form_Y+14,Form_X+15);
			printf("\x1b[%d;%dH│  │            │            │            │            │            │  │",Form_Y+15,Form_X+15);
			printf("\x1b[%d;%dH│  └────────────┴────────────┴────────────┴────────────┴────────────┘  │",Form_Y+16,Form_X+15);
			printf("\x1b[%d;%dH│                          ┌────────────────┐                          │",Form_Y+17,Form_X+15);
			printf("\x1b[%d;%dH│                          │    %-3s  Id:%-2d  │                          │",Form_Y+18,Form_X+15,rarity[HeroRarity[OpenHeroImage[11]]],OpenHeroImage[11]);
			printf("\x1b[%d;%dH│                          │                │                          │",Form_Y+19,Form_X+15);
			printf("\x1b[%d;%dH│                          │                │                          │",Form_Y+20,Form_X+15);
			printf("\x1b[%d;%dH│                          └────────────────┘                          │",Form_Y+21,Form_X+15);
			printf("\x1b[%d;%dH│                                                                      │",Form_Y+22,Form_X+15);
			printf("\x1b[%d;%dH└──────────────────────────────────────────────────────────────────────┘",Form_Y+23,Form_X+15); 
		}
	}
	if(MainMenu==3)
	{
		printf("\x1b[%d;%dH┌───────────────────────────────────┐",Form_Y+6,Form_X+31);
		printf("\x1b[%d;%dH│  Id:%2d             按U可觀看大圖  │",Form_Y+7,Form_X+31,ClickTabNum[3]%20+1);
		printf("\x1b[%d;%dH│                                   │",Form_Y+8,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+9,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+10,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+11,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+12,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+13,Form_X+31);
		printf("\x1b[%d;%dH│                                   │",Form_Y+14,Form_X+31);
		printf("\x1b[%d;%dH│             ╭──────────────────╮  │",Form_Y+15,Form_X+31);
		printf("\x1b[%d;%dH│             ╰──────────────────╯  │",Form_Y+17,Form_X+31);
		printf("\x1b[%d;%dH└───────────────────────────────────┘",Form_Y+18,Form_X+31);
		if(HeroLV[ClickTabNum[3]%20+1]==30)
		{
			printf("\x1b[%d;%dH│  等級:%2d    │     無法升級     │  │",Form_Y+16,Form_X+31,HeroLV[ClickTabNum[3]%20+1]);
		}
		else
		{
			printf("\x1b[%d;%dH│  等級:%2d    │ W.升級經驗:%6d│  │",Form_Y+16,Form_X+31,HeroLV[ClickTabNum[3]%20+1],HeroLV[ClickTabNum[3]%20+1]*1000*HeroRarity[ClickTabNum[3]%20+1]);
		}
		printf("\x1b[%d;%dH┌───────────┬───────────┬───────────┬───────────┬───────────┐",Form_Y+20,Form_X+19);
		printf("\x1b[%d;%dH│\033[1;30m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │\033[1;33m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │",Form_Y+21,Form_X+19,rarity[HeroRarity[(ClickTabNum[3]-2)%20+1]],rarity[HeroRarity[(ClickTabNum[3]-1)%20+1]],rarity[HeroRarity[ClickTabNum[3]%20+1]],rarity[HeroRarity[(ClickTabNum[3]+1)%20+1]],rarity[HeroRarity[(ClickTabNum[3]+2)%20+1]]);
		printf("\x1b[%d;%dH│     \033[1;30m%2d\033[0m    │     \033[1;30m%2d\033[0m    │     \033[1;33m%2d\033[0m    │     \033[1;30m%2d\033[0m    │     \033[1;30m%2d\033[0m    │",Form_Y+22,Form_X+19,(ClickTabNum[3]-2)%20+1,(ClickTabNum[3]-1)%20+1,ClickTabNum[3]%20+1,(ClickTabNum[3]+1)%20+1,(ClickTabNum[3]+2)%20+1);
		printf("\x1b[%d;%dH│\033[1;30mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │\033[1;33mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │",Form_Y+23,Form_X+19,HeroLV[(ClickTabNum[3]-2)%20+1],HeroLV[(ClickTabNum[3]-1)%20+1],HeroLV[ClickTabNum[3]%20+1],HeroLV[(ClickTabNum[3]+1)%20+1],HeroLV[(ClickTabNum[3]+2)%20+1]);
		printf("\x1b[%d;%dH└───────────┴───────────┴───────────┴───────────┴───────────┘",Form_Y+24,Form_X+19);
		printf("\x1b[%d;%dH〈",Form_Y+12,Form_X+5);
		printf("\x1b[%d;%dH〉",Form_Y+12,Form_X+96);
	}
	if(MainMenu==4)
	{
		printf("\x1b[%d;%dH┌───────────┬───────────┬───────────┬───────────┬───────────┐",Form_Y+6,Form_X+19);
		printf("\x1b[%d;%dH│           │           │           │           │           │",Form_Y+7,Form_X+19);
		printf("\x1b[%d;%dH│     %2d    │     %2d    │     %2d    │     %2d    │     %2d    │",Form_Y+8,Form_X+19,Team[1],Team[2],Team[3],Team[4],Team[5]);
		printf("\x1b[%d;%dH│           │           │           │           │           │",Form_Y+9,Form_X+19);
		printf("\x1b[%d;%dH├───────────┼───────────┼───────────┼───────────┼───────────┤",Form_Y+10,Form_X+19);
		printf("\x1b[%d;%dH│           │           │           │           │           │",Form_Y+11,Form_X+19);
		printf("\x1b[%d;%dH│     %2d    │     %2d    │     %2d    │     %2d    │     %2d    │",Form_Y+12,Form_X+19,Team[6],Team[7],Team[8],Team[9],Team[10]);
		printf("\x1b[%d;%dH│           │           │           │           │           │",Form_Y+13,Form_X+19);
		printf("\x1b[%d;%dH└───────────┴───────────┴───────────┴───────────┴───────────┘",Form_Y+14,Form_X+19);
		printf("\x1b[%d;%dH┌───────────────┐",Form_Y+6,Form_X+81);
		printf("\x1b[%d;%dH│  R. 隊伍重製  │",Form_Y+7,Form_X+81);
		printf("\x1b[%d;%dH├───────────────┤",Form_Y+8,Form_X+81);
		printf("\x1b[%d;%dH│  U. 觀看大圖  │",Form_Y+9,Form_X+81);
		printf("\x1b[%d;%dH├───────────────┤",Form_Y+10,Form_X+81);
		printf("\x1b[%d;%dH│  Enter. 選擇  │",Form_Y+11,Form_X+81);
		printf("\x1b[%d;%dH└───────────────┘",Form_Y+12,Form_X+81);
		printf("\x1b[%d;%dH┌───────────┬───────────┬───────────┬───────────┬───────────┐",Form_Y+17,Form_X+19);
		printf("\x1b[%d;%dH│\033[1;30m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │\033[1;33m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │\033[1;30m%-3s\033[0m        │",Form_Y+18,Form_X+19,rarity[HeroRarity[(ClickTabNum[4]-2)%20+1]],rarity[HeroRarity[(ClickTabNum[4]-1)%20+1]],rarity[HeroRarity[ClickTabNum[4]%20+1]],rarity[HeroRarity[(ClickTabNum[4]+1)%20+1]],rarity[HeroRarity[(ClickTabNum[4]+2)%20+1]]);
		printf("\x1b[%d;%dH│     \033[1;30m%2d\033[0m    │     \033[1;30m%2d\033[0m    │     \033[1;33m%2d\033[0m    │     \033[1;30m%2d\033[0m    │     \033[1;30m%2d\033[0m    │",Form_Y+19,Form_X+19,(ClickTabNum[4]-2)%20+1,(ClickTabNum[4]-1)%20+1,ClickTabNum[4]%20+1,(ClickTabNum[4]+1)%20+1,(ClickTabNum[4]+2)%20+1);
		printf("\x1b[%d;%dH│\033[1;30mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │\033[1;33mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │\033[1;30mLV:%2d\033[0m      │",Form_Y+20,Form_X+19,HeroLV[(ClickTabNum[4]-2)%20+1],HeroLV[(ClickTabNum[4]-1)%20+1],HeroLV[ClickTabNum[4]%20+1],HeroLV[(ClickTabNum[4]+1)%20+1],HeroLV[(ClickTabNum[4]+2)%20+1]);
		printf("\x1b[%d;%dH└───────────┴───────────┴───────────┴───────────┴───────────┘",Form_Y+21,Form_X+19);
		printf("\x1b[%d;%dH〈",Form_Y+19,Form_X+5);
		printf("\x1b[%d;%dH〉",Form_Y+19,Form_X+96);
	}
	if(MainMenu==5)
	{
		printf("\x1b[%d;%dH┌─────────────────┐                   ┌─────────────────┐",Form_Y+8,Form_X+21);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+9,Form_X+21);
		printf("\x1b[%d;%dH│   A. 砲塔升級   │                   │   B. 金庫升級   │",Form_Y+10,Form_X+21);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+11,Form_X+21);
		printf("\x1b[%d;%dH│  砲塔等級:%2d/10 │                   │  金庫等級:%2d/10 │",Form_Y+12,Form_X+21,BasicTowerLV,BasicGoldProducerLV);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+13,Form_X+21);
		printf("\x1b[%d;%dH│  炮塔攻擊=%5d │                   │  金庫容量:%5d │",Form_Y+14,Form_X+21,BasicTowerLV*100+100,BasicGoldProducerLV*500+500);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+15,Form_X+21);
		printf("\x1b[%d;%dH│   炮塔HP=%5d  │                   │  挖礦速度:%3d/s │",Form_Y+16,Form_X+21,BasicTowerLV*1000+1000,BasicGoldProducerLV*30+30);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+17,Form_X+21);
		printf("\x1b[%d;%dH│                 │                   │                 │",Form_Y+19,Form_X+21);
		printf("\x1b[%d;%dH└─────────────────┘                   └─────────────────┘",Form_Y+20,Form_X+21);
		if(BasicTowerLV<=9)
		{
		printf("\x1b[%d;%dH│   消耗星石:%3d  │",Form_Y+18,Form_X+21,BasicTowerLV*10+10);
		}
		if(BasicTowerLV>=10)
		{
		printf("\x1b[%d;%dH│     無法升等    │",Form_Y+18,Form_X+21);
		}
		if(BasicGoldProducerLV<=9)
		{
			printf("\x1b[%d;%dH│   消耗星石:%3d  │",Form_Y+18,Form_X+59,BasicGoldProducerLV*10+10);
		}
		if(BasicGoldProducerLV>=10)
		{
			printf("\x1b[%d;%dH│     無法升等    │",Form_Y+18,Form_X+59);
		}
	}
	if((MainMenu==6||MainMenu==7||MainMenu==8)&&CurrentEnemyHP[0][0]>0)
	{
		printf("\x1b[%d;%dH┌───────────┐   ╭─────────────╮  ┌─────────────────┐",Form_Y+2,Form_X+22);
		printf("\x1b[%d;%dH│ 失敗數:%3d│   │ O.神 ☆-100 │  │        /%5d元 │",Form_Y+3,Form_X+22,FailBattle[MainMenu-6],(BasicGoldProducerLV+BattleGoldProducerLV+1)*1000);
		printf("\x1b[%d;%dH└───────────┘   ╰─────────────╯  └─────────────────┘",Form_Y+4,Form_X+22);
		printf("\x1b[%d;%dH  ↑失敗數 +1",Form_Y+5,Form_X+5);
		if(MainMenu==6)
		{
			printf("\x1b[%d;%dH\033[1;36m簡  單\033[0m",Form_Y+7,Form_X+47);
		}
		if(MainMenu==7)
		{
			printf("\x1b[%d;%dH\033[1;32m普  通\033[0m",Form_Y+7,Form_X+47);
		}
		if(MainMenu==8)
		{
			printf("\x1b[%d;%dH\033[0;31m困  難\033[0m",Form_Y+7,Form_X+47);
		}
		printf("\x1b[%d;%dHtotal Num:  /10",Form_Y+6,Form_X+83);
		printf("\x1b[%d;%dH■■",Form_Y+10,Form_X+7);
		printf("\x1b[%d;%dH■■■■",Form_Y+11,Form_X+5);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+12,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+13,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+14,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+15,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+16,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+17,Form_X+3);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+18,Form_X+3);
		printf("\x1b[%d;%dH■■",Form_Y+10,Form_X+91);
		printf("\x1b[%d;%dH■■■■",Form_Y+11,Form_X+89);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+12,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+13,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+14,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+15,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+16,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+17,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■",Form_Y+18,Form_X+87);
		printf("\x1b[%d;%dH■■■■■■────────────────────────────────────────────────────────────────────────■■■■■■",Form_Y+19,Form_X+3);
		printf("\x1b[%d;%dH─────────────┐",Form_Y+21,Form_X+2);
		if(BattleGoldProducerLV==8)
		{
			printf("\x1b[%d;%dH   金幣等級: │",Form_Y+22,Form_X+2);
			printf("\x1b[%d;%dH      MAX    │",Form_Y+23,Form_X+2);
			printf("\x1b[%d;%dH             │",Form_Y+24,Form_X+2);
		}
		else
		{
			printf("\x1b[%d;%dH  金幣等級:%1d │",Form_Y+22,Form_X+2,BattleGoldProducerLV);
			printf("\x1b[%d;%dH  W.金幣LV↑ │",Form_Y+23,Form_X+2);
			printf("\x1b[%d;%dH    $%3d     │",Form_Y+24,Form_X+2,(BattleGoldProducerLV*80+80+BasicGoldProducerLV*40));
		}
		printf("\x1b[%d;%dH小寫召喚角色    ┌───────────┬───────────┬───────────┬───────────┬───────────┐       大寫可看大圖",Form_Y+20,Form_X+3);
		if(ClickTabNum[MainMenu]%2==0)printf("\x1b[%d;%dH│a.   Id:%2d │b.   Id:%2d │c.   Id:%2d │d.   Id:%2d │e.   Id:%2d │",Form_Y+21,Form_X+19,Team[ClickTabNum[MainMenu]%2*5+1],Team[ClickTabNum[MainMenu]%2*5+2],Team[ClickTabNum[MainMenu]%2*5+3],Team[ClickTabNum[MainMenu]%2*5+4],Team[ClickTabNum[MainMenu]%2*5+5]);
		if(ClickTabNum[MainMenu]%2==1)printf("\x1b[%d;%dH│f.   Id:%2d │g.   Id:%2d │h.   Id:%2d │i.   Id:%2d │j.   Id:%2d │",Form_Y+21,Form_X+19,Team[ClickTabNum[MainMenu]%2*5+1],Team[ClickTabNum[MainMenu]%2*5+2],Team[ClickTabNum[MainMenu]%2*5+3],Team[ClickTabNum[MainMenu]%2*5+4],Team[ClickTabNum[MainMenu]%2*5+5]);
		printf("\x1b[%d;%dH│ %-3s       │ %-3s       │ %-3s       │ %-3s       │ %-3s       │ Tab←",Form_Y+22,Form_X+19,rarity[HeroRarity[Team[ClickTabNum[MainMenu]%2*5+1]]],rarity[HeroRarity[Team[ClickTabNum[MainMenu]%2*5+2]]],rarity[HeroRarity[Team[ClickTabNum[MainMenu]%2*5+3]]],rarity[HeroRarity[Team[ClickTabNum[MainMenu]%2*5+4]]],rarity[HeroRarity[Team[ClickTabNum[MainMenu]%2*5+5]]]);
		printf("\x1b[%d;%dH│ Num:      │ Num:      │ Num:      │ Num:      │ Num:      │    →",Form_Y+23,Form_X+19,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+1]],HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+2]],HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+3]],HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+4]],HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+5]]);
		printf("\x1b[%d;%dH│      $%4d│      $%4d│      $%4d│      $%4d│      $%4d│",Form_Y+24,Form_X+19,CallHeroNeedMoney[Team[ClickTabNum[MainMenu]%2*5+1]],CallHeroNeedMoney[Team[ClickTabNum[MainMenu]%2*5+2]],CallHeroNeedMoney[Team[ClickTabNum[MainMenu]%2*5+3]],CallHeroNeedMoney[Team[ClickTabNum[MainMenu]%2*5+4]],CallHeroNeedMoney[Team[ClickTabNum[MainMenu]%2*5+5]]);
		printf("\x1b[%d;%dH┌─────────",Form_Y+21,Form_X+89);
		printf("\x1b[%d;%dH│    N ",Form_Y+22,Form_X+89);
		printf("\x1b[%d;%dH│   轟炸",Form_Y+23,Form_X+89);
		printf("\x1b[%d;%dH│      %% ",Form_Y+24,Form_X+89);
	}
	if(MinorMenu==5||MinorMenu==6)
	{
			printf("\x1b[%d;%dH┌───────────────────────────────────────┐",Form_Y+5,Form_X+30);
			printf("\x1b[%d;%dH│                                       │",Form_Y+6,Form_X+30);
			printf("\x1b[%d;%dH│      ┌────────────────────────┐       │",Form_Y+7,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+8,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+10,Form_X+30);
			if(MainMenu==6)
			{
			printf("\x1b[%d;%dH│      │        \033[1;36m簡單模式\033[0m        │       │", Form_Y+11, Form_X + 30);
			}
			if(MainMenu==7)
			{
			printf("\x1b[%d;%dH│      │        \033[1;32m普通模式\033[0m        │       │", Form_Y+11, Form_X+30);
			}
			if(MainMenu==8)
			{
			printf("\x1b[%d;%dH│      │        \033[0;31m困難模式\033[0m        │       │", Form_Y+11, Form_X+30);
			}
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+12,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+14,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+16,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+18,Form_X+30);
			printf("\x1b[%d;%dH│      │                        │       │",Form_Y+19,Form_X+30);
			printf("\x1b[%d;%dH│      └────────────────────────┘       │",Form_Y+20,Form_X+30);
			printf("\x1b[%d;%dH│                                       │",Form_Y+21,Form_X+30);
			printf("\x1b[%d;%dH└───────────────────────────────────────┘",Form_Y+22,Form_X+30);
	}
	if(MinorMenu==5)
	{
			printf("\x1b[%d;%dH│      │         已通關         │       │",Form_Y+9,Form_X+30);
			printf("\x1b[%d;%dH│      │      通關次數:%3d      │       │",Form_Y+13,Form_X+30,CompleteBattle[MainMenu-6]);
			printf("\x1b[%d;%dH│      │       EXP +%6d      │       │",Form_Y+15,Form_X+30,50000*MainMenu);
			printf("\x1b[%d;%dH│      │        星石 +%3d       │       │",Form_Y+17,Form_X+30,100*(MainMenu-3));
	}
	if(MinorMenu==6)
	{
			printf("\x1b[%d;%dH│      │         失  敗         │       │",Form_Y+9,Form_X+30);
			printf("\x1b[%d;%dH│      │      失敗次數:%3d      │       │",Form_Y+13,Form_X+30,FailBattle[MainMenu-6]);
			printf("\x1b[%d;%dH│      │       EXP +000000      │       │",Form_Y+15,Form_X+30);
			printf("\x1b[%d;%dH│      │        星石 +000       │       │",Form_Y+17,Form_X+30);
	}
	printf("\x1b[%d;%dH ",Form_Y+26,Form_X+1);
}
void BattleCallRole(int call)
{
	int aaa[11],total=0;
	for(int i=1;i<=10;i++)aaa[i]=i;
	for(int i=1;i<=10;i++)
	{
		if(Team[i]==0)HeroBattleNum[Team[i]]=0;
		total+=HeroBattleNum[Team[i]];
	}
	if(HeroBattlePastTime[Team[call]]>=HeroCoolDownTime[Team[call]]&&BattleGold>=CallHeroNeedMoney[Team[call]]&&Team[call]!=0&&total<10)
	{
		for(int abc=1;abc<=10;abc++)
		{
			if(IsHeroAlive[Team[call]][abc]==0)
			{
				HeroBattlePastTime[Team[call]]=0;
				HeroBattleNum[Team[call]]++;
				BattleGold-=CallHeroNeedMoney[Team[call]];
				IsHeroAlive[Team[call]][abc]=1;
				int *arg=&aaa[abc];
				switch(Team[call])
				{
					case 1:
						_beginthread(callrole1, 0,(void *)arg);
						break;
					case 2:
						_beginthread(callrole2, 0,(void *)arg);
						break;
					case 3:
						_beginthread(callrole3, 0,(void *)arg);
						break;
					case 4:
						_beginthread(callrole4, 0,(void *)arg);
						break;
					case 5:
						_beginthread(callrole5, 0,(void *)arg);
						break;
					case 6:
						_beginthread(callrole6, 0,(void *)arg);
						break;
					case 7:
						_beginthread(callrole7, 0,(void *)arg);
						break;
					case 8:
						_beginthread(callrole8, 0,(void *)arg);
						break;
					case 9:
						_beginthread(callrole9, 0,(void *)arg);
						break;
					case 10:
						_beginthread(callrole10, 0,(void *)arg);
						break;
					case 11:
						_beginthread(callrole11, 0,(void *)arg);
						break;
					case 12:
						_beginthread(callrole12, 0,(void *)arg);
						break;
					case 13:
						_beginthread(callrole13, 0,(void *)arg);
						break;
					case 14:
						_beginthread(callrole14, 0,(void *)arg);
						break;
					case 15:
						_beginthread(callrole15, 0,(void *)arg);
						break;
					case 16:
						_beginthread(callrole16, 0,(void *)arg);
						break;
					case 17:
						_beginthread(callrole17, 0,(void *)arg);
						break;
					case 18:
						_beginthread(callrole18, 0,(void *)arg);
						break;
					case 19:
						_beginthread(callrole19, 0,(void *)arg);
						break;
					case 20:
						_beginthread(callrole20, 0,(void *)arg);
						break;
				}
				break;
			}
		}
	}
}
void BattleParallel_2()
{
	int bbb[6];
	int r,g=1,k,e;
	for(int i=1;i<=5;i++)bbb[i]=i;
	while(1)
	{
		if((MainMenu==6||MainMenu==7||MainMenu==8)&&MinorMenu!=5&&MinorMenu!=6)
		{
			r=1;
			if(BattleGold==0&&BattleGoldProducerLV==0&&BombEnergy==0)
				for(int i=1;i<=20;i++)HeroBattlePastTime[Team[i]]=30;
			CurrentEnemyHP[0][0]=EnemyTowerHP[MainMenu-6];
		}
		else r=0;
		while (r)
		{
			if(MainMenu==0||MinorMenu==5||MinorMenu==6)
			{
				g=0;
				k=0;
				e=0;
				break;
			}
			if((MainMenu==6||MainMenu==7||MainMenu==8)&&(CurrentEnemyHP[0][0]<=0||CurrentHeroHP[0][0]<=0))
			{
				g=0;
				k=0;
				e=0;
				TotalEnemyNum=0;
				if(CurrentEnemyHP[0][0]<=0)
				{
					MinorMenu=5;
					CompleteBattle[MainMenu-6]++;
					EXP+=50000*MainMenu;
					diamond+=100*(MainMenu-3);
				}
				else 
				{
					MinorMenu=6;
					FailBattle[MainMenu-6]++;
				}
				BattleGold=0;
				BombEnergy=0;
				BattleGoldProducerLV=0;
				ClickTabNum[MainMenu]=0;
				for(int i=0;i<=20;i++)HeroBattleNum[i]=0;
				CurrentHeroHP[0][0]=BasicTowerLV*1000+1000,CurrentEnemyHP[0][0]=EnemyTowerHP[MainMenu-6];
				system("cls");
				Sleep(150);
				DrawForm();
				break;
			}
			if(BattleGold<(BasicGoldProducerLV+BattleGoldProducerLV+1)*1000)
			{
				BattleGold+=(BasicGoldProducerLV+BattleGoldProducerLV+1)*3;
			}
			else if(BattleGold>(BasicGoldProducerLV+BattleGoldProducerLV+1)*1000)
			{
				BattleGold=(BasicGoldProducerLV+BattleGoldProducerLV+1)*1000;
			}
			if(g%5==0&&BombEnergy<100)
			{
				BombEnergy++;
				g=0;
			}
			else if(BombEnergy>=100)
			{
				BombEnergy=100;
				g=0;
			}
			printf("\x1b[%d;%dHHP %5d/%5d",Form_Y+8,Form_X+3,CurrentEnemyHP[0][0],EnemyTowerHP[MainMenu-6]);
			printf("\x1b[%d;%dHHP %5d/%5d",Form_Y+8,Form_X+85,CurrentHeroHP[0][0],BasicTowerLV*1000+1000);
			printf("\x1b[%d;%dH%5d",Form_Y+3,Form_X+59,BattleGold);
			printf("\x1b[%d;%dH%3d",Form_Y+24,Form_X+92,BombEnergy);
			Sleep(99);
			if(((e%280)+1==60||(e%280)+1==120||(e%280)+1==180)&&TotalEnemyNum<5)
			{
				for(int abc=1;abc<=5;abc++)
				{
					if(IsEnemyAlive[1][abc]==0&&TotalEnemyNum<5)
					{
						int *arg=&bbb[abc];
						IsEnemyAlive[1][abc]=1;
						TotalEnemyNum++;
						_beginthread(callenemy1, 0,(void *)arg);
						break;
					}
				}
			}
			else if((e%280)+1==280&&TotalEnemyNum<5)
			{
				for(int abc=1;abc<=5;abc++)
				{
					if(IsEnemyAlive[2][abc]==0&&TotalEnemyNum<5)
					{
						int *arg=&bbb[abc];
						IsEnemyAlive[2][abc]=1;
						TotalEnemyNum++;
						_beginthread(callenemy2, 0,(void *)arg);
						break;
					}
				}
			}
			else if(((e%450)+1==450)&&TotalEnemyNum<5)
			{
				for(int abc=1;abc<=5;abc++)
				{
					if(IsEnemyAlive[3][abc]==0&&TotalEnemyNum<5)
					{
						int *arg=&bbb[abc];
						IsEnemyAlive[3][abc]=1;
						TotalEnemyNum++;
						_beginthread(callenemy3, 0,(void *)arg);
						break;
					}
				}
			}
			if(k%10==0)for(int i=1;i<=20;i++)HeroBattlePastTime[Team[i]]++;
			g++,k++;
			if(TotalEnemyNum<5)e++;
		}
	}
}

void BattleParallel_1()
{
	int r,eex,ccx,timemax,time888;
	CurrentEnemyHP[0][0]=EnemyTowerHP[MainMenu-6];
	CurrentHeroHP[0][0]=BasicTowerLV*1000+1000;
	system("cls");
	int ttt[21];
	CurrentHeroX[0][0]=94;
	CurrentEnemyX[0][0]=26;
	IsHeroAlive[0][0]=1;
	IsEnemyAlive[0][0]=1;
	TotalEnemyNum=0;
	while(1)
	{
		if(MinorMenu==5||MinorMenu==6||MainMenu==0)
		{
			time888=0;
			godmax=0;
			break;
		}
		ccx=CurrentHeroX[0][0];
		eex=CurrentEnemyX[0][0];
		printf("\x1b[%d;%dH%2d",Form_Y+6,Form_X+93,(HeroBattleNum[Team[1]]+HeroBattleNum[Team[2]]+HeroBattleNum[Team[3]]+HeroBattleNum[Team[4]]+HeroBattleNum[Team[5]]+HeroBattleNum[Team[6]]+HeroBattleNum[Team[7]]+HeroBattleNum[Team[8]]+HeroBattleNum[Team[9]]+HeroBattleNum[Team[10]]));
		printf("\x1b[%d;%dH%2d",Form_Y+23,Form_X+25,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+1]]);
		printf("\x1b[%d;%dH%2d",Form_Y+23,Form_X+37,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+2]]);
		printf("\x1b[%d;%dH%2d",Form_Y+23,Form_X+49,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+3]]);
		printf("\x1b[%d;%dH%2d",Form_Y+23,Form_X+61,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+4]]);
		printf("\x1b[%d;%dH%2d",Form_Y+23,Form_X+73,HeroBattleNum[Team[ClickTabNum[MainMenu]%2*5+5]]);
		for(int o=1;o<=20;o++)
		{
			for(int p=1;p<=10;p++)
			{
				if(IsHeroAlive[o][p]==1&&CurrentHeroX[o][p]<=ccx&&CurrentHeroX[o][p]!=0)
				{
					ccx=CurrentHeroX[o][p];
				}
				if(o<=3&&p<=5&&CurrentEnemyX[o][p]>=eex&&CurrentEnemyX[o][p]!=0&&IsEnemyAlive[o][p]==1)
				{
					eex=CurrentEnemyX[o][p];
				}
			}
		}
		HeroFirstX=ccx,EnemyFirstX=eex;
		if(godmax!=0)
		{
			time888++;
			if(HeroCoolDownTime[1]!=0)
				for(int i=1;i<=20;i++)
				{
					ttt[i]=HeroCoolDownTime[i];
					HeroCoolDownTime[i]=0;
				}
			printf("\x1b[%d;%dH剩餘:%3.1fsec",9,53,((float)(godmax*600-time888)/(float)10));
			if(time888>=godmax*600)
			{
				for(int i=1;i<=20;i++)
				{
					HeroCoolDownTime[i]=ttt[i];
				}
				printf("\x1b[%d;%dH              ",9,53);
				time888=0;
				godmax=0;
			}
		}
		Sleep(100);
	}
}


void gacha()
{
	int g;
	char Image[7];
	if(MinorMenu==11)
	{
		for(int i=1;i<=11;i++)
		{
			OpenHeroImage[i]=0;
		}
	}
	for(int i=0;i<MinorMenu;i++)
	{
		g = (int)rand()%100+1;
		if(g<=42)OpenHeroImage[i+1]=(g-1)/7+1;
		else if(g>=43&&g<=72)OpenHeroImage[i+1]=(g-43)/6+7;
		else if(g>=73&&g<=88)OpenHeroImage[i+1]=(g-73)/4+12;
		else if(g>=89&&g<=97)OpenHeroImage[i+1]=(g-89)/3+18;
		else if(g>=98&&g<=100&&ClickTabNum[2]%2==0)OpenHeroImage[i+1]=19;
		else if(g>=98&&g<=100&&ClickTabNum[2]%2==1)OpenHeroImage[i+1]=20;
		
		if(HeroLV[OpenHeroImage[i+1]]!=30)HeroLV[OpenHeroImage[i+1]]++;
		else EXP+=(30*HeroRarity[OpenHeroImage[i+1]]*1000);
		
		if(HeroLV[OpenHeroImage[i+1]]==1||OpenHeroImage[i+1]>18||MinorMenu==1)
		{
			sprintf(Image,"%d.png",OpenHeroImage[i+1]);
			system(Image);
		}
		DrawForm();
		if(MinorMenu==11)Sleep(300);
	}
}

void run()
{
	char input,YN,inputh,Image[7];
	int ll;
	ClickTabNum[3]=20,ClickTabNum[4]=20;
	while(1)
	{
		if(MainMenu==0)
		{
			MinorMenu=0;
			input = getch();
			switch (input)
			{
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
					MainMenu=input-48;
					break;
				case 75 :
				case 77 :
					ClickTabNum[0]++;
					break;
				case 'z':
				case 'Z':
					system("cls");
					printf("\x1b[%d;%dH是否存檔",15,55);
					printf("\x1b[%d;%dHY=YES",17,55);
					printf("\x1b[%d;%dHN=NO",18,55);
					YN=getch();
					switch (YN)
					{
						case 'Y':
						case 'y':
							{
								FILE *fpw;
								fpw=fopen("./data/data.txt","w");
								fprintf(fpw,"EXP      星石     塔LV  金庫LV 簡單通關數 普通通關數 困難通關數 簡單失敗數 普通失敗數 困難失敗數\n");
								fprintf(fpw,"%-8d %-5d    %-2d    %-2d     %-3d        %-3d        %-3d        %-3d        %-3d        %-3d\n",EXP,diamond,BasicTowerLV,BasicGoldProducerLV,CompleteBattle[0],CompleteBattle[1],CompleteBattle[2],FailBattle[0],FailBattle[1],FailBattle[2]);
								fprintf(fpw,"Id 1~20角色等級\n");
								fprintf(fpw,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",HeroLV[1],HeroLV[2],HeroLV[3],HeroLV[4],HeroLV[5],HeroLV[6],HeroLV[7],HeroLV[8],HeroLV[9],HeroLV[10],HeroLV[11],HeroLV[12],HeroLV[13],HeroLV[14],HeroLV[15],HeroLV[16],HeroLV[17],HeroLV[18],HeroLV[19],HeroLV[20]);
								fprintf(fpw,"目前隊伍id\n");
								fprintf(fpw,"%d %d %d %d %d %d %d %d %d %d\n",Team[1],Team[2],Team[3],Team[4],Team[5],Team[6],Team[7],Team[8],Team[9],Team[10]);
								fclose(fpw);
							}
							system("cls");
							printf("\x1b[%d;%dH已存檔",15,55);
							return ;
						case 'N':
						case 'n':
							system("cls");
							printf("\x1b[%d;%dH無存檔",15,55);
							return ;
					}
					YN=0;
					input=90;
					break;
				case 'u':
				case 'U':
					if(ClickTabNum[0]%2==0)system("19.png");
					if(ClickTabNum[0]%2==1)system("20.png");
					break;
			}
		}
		else if(MainMenu==1&&Team[1]!=0)
		{
			input = getch();
			switch (input)
			{
				case '0':
					MainMenu=0;
					system("cls");
					break;
				case 'A':
				case 'B':
				case 'C':
					MainMenu=input-59;
					_beginthread(BattleParallel_1, 0, 0);
					break;
				case 'a':
				case 'b':
				case 'c':
					MainMenu=input-91;
					_beginthread(BattleParallel_1, 0, 0);
					break;
			}
		}
		else if(MainMenu==1&&Team[1]==0)
		{
			DrawForm();
			input = getch();
			MainMenu=0;
		}
		else if(MainMenu==2)
		{
			input = getch();
			switch (input)
			{
				case '0':
					MainMenu=0;
					ClickTabNum[2]=0;
					break;
				case 'O':
				case 'o':
					MinorMenu=3;
					DrawForm();
					inputh = getch();
					MinorMenu=0;
					break;
				case 'H':
				case 'h':
					if(diamond>=20)
					{
						diamond-=20;
						MinorMenu=1;
						gacha();
						MinorMenu=0;
						inputh = getch();
					}
					break;
				case 'L':
				case 'l':
					if(diamond>=200)
					{
						MinorMenu=11;
						diamond-=200;
						gacha();
						MinorMenu=0;
						inputh = getch();
					}
					break;
				case 'U':
				case 'u':
					if(ClickTabNum[2]%2==0)system("19.png");
					if(ClickTabNum[2]%2==1)system("20.png");
					break;
				case '\t' :
				case 75 :
				case 77 :
					ClickTabNum[2]++;
					break;
			}
		}
		else if(MainMenu==3)
		{
			input = getch();
			switch (input)
			{
				case '0':
					MainMenu=0;
					ClickTabNum[3]=20;
					break;
				case 'W':
				case 'w':
					if(HeroLV[ClickTabNum[3]%20+1]!=0&&HeroLV[ClickTabNum[3]%20+1]!=30&&EXP>=HeroLV[ClickTabNum[3]%20+1]*1000*HeroRarity[ClickTabNum[3]%20+1])
					{
						EXP-=HeroLV[ClickTabNum[3]%20+1]*1000*HeroRarity[ClickTabNum[3]%20+1];
						HeroLV[ClickTabNum[3]%20+1]++;
					}
					break;
				case 'U':
				case 'u':
					sprintf(Image,"%d.png",ClickTabNum[3]%20+1);
					system(Image);
					break;
				case 75 :
					if(ClickTabNum[3]<=20)ClickTabNum[3]+=19;
					else ClickTabNum[3]--;
					break;
				case 77 :
				case '\t' :
					ClickTabNum[3]++;
					break;
			}
		}
		else if(MainMenu==4)
		{
			input = getch();
			switch (input)
			{
				case '0':
					MainMenu=0;
					ClickTabNum[4]=20;
					break;
				case 'U':
				case 'u':
					sprintf(Image,"%d.png",ClickTabNum[4]%20+1);
					system(Image);
					break;
				case 75 :
					if(ClickTabNum[4]<=20)ClickTabNum[4]+=19;
					else ClickTabNum[4]--;
					break;
				case 77 :
				case '\t' :
					ClickTabNum[4]++;
					break;
				case '\r' :
					if(((ClickTabNum[4]%20+1)!=Team[1])&&((ClickTabNum[4]%20+1)!=Team[2])&&((ClickTabNum[4]%20+1)!=Team[3])&&((ClickTabNum[4]%20+1)!=Team[4])&&((ClickTabNum[4]%20+1)!=Team[5])&&((ClickTabNum[4]%20+1)!=Team[6])&&((ClickTabNum[4]%20+1)!=Team[7])&&((ClickTabNum[4]%20+1)!=Team[8])&&((ClickTabNum[4]%20+1)!=Team[9])&&((ClickTabNum[4]%20+1)!=Team[10]))
					{
						if(HeroLV[(ClickTabNum[4]%20+1)]!=0)
						{
							if(ll<=9)
							{
								ll++;
								Team[ll]=ClickTabNum[4]%20+1;
							}
						}
					}
					break;
				case 'R' :
				case 'r' :
					for(int l=1;l<=10;l++)
						Team[l]=0;
					ClickTabNum[4]=20;
					ll=0;
					break;
			}
		}
		else if(MainMenu==5)
		{
			input = getch();
			switch (input)
			{
				case '0':
					MainMenu=0;
					break;
				case 'A':
				case 'a':
					if(BasicTowerLV<=9)
					{
						BasicTowerLV++;
						diamond-=BasicTowerLV*10;
					}
					break;
				case 'b' :
				case 'B' :
					if(BasicGoldProducerLV<=9)
					{
						BasicGoldProducerLV++;
						diamond-=BasicGoldProducerLV*10;
					}
					break;
			}
		}
		else if((MainMenu==6||MainMenu==7||MainMenu==8)&&MinorMenu!=5&&MinorMenu!=6)
		{
			for(int i=1;i<=10;i++)if(Team[i]==0)HeroBattleNum[Team[i]]=0;
			DrawForm();
			input = getch();
			switch (input)
			{
				case '0':
					if(MinorMenu!=5&&MinorMenu!=6)FailBattle[MainMenu-6]++;
					BattleGold=0;
					BombEnergy=0;
					BattleGoldProducerLV=0;
					ClickTabNum[MainMenu]=0;
					for(int i=0;i<=20;i++)HeroBattleNum[i]=0;
					CurrentHeroHP[0][0]=BasicTowerLV*1000+1000,CurrentEnemyHP[0][0]=EnemyTowerHP[MainMenu-6];
					for(int i=0;i<=20;i++)
					{
						for(int j=1;j<=10;j++)
						{
							IsHeroAlive[i][j]=0;
							IsEnemyAlive[i][j]=0;
						}
					}
					MinorMenu=0;
					MainMenu=0;
					break;
				case '\t' :
					ClickTabNum[MainMenu]++;
					break;
				case 'o':
				case 'O':
					if(diamond-100>=0)
					{
						diamond-=100;
						godmax++;
						BattleGoldProducerLV=8;
						BattleGold=(BasicGoldProducerLV+BattleGoldProducerLV+1)*1000;
						BombEnergy=100;
					}
					break;
				case 'N':
				case 'n':
					if(BombEnergy==100)
					{
						_beginthread(bombbomb, 0,0);
						BombEnergy-=100;
					}
					break;
				case 'W':
				case 'w':
					if(BattleGoldProducerLV<8&&(BattleGold-(BattleGoldProducerLV*80+80+BasicGoldProducerLV*40)>=0))
					{
						BattleGoldProducerLV++;
						BattleGold-=(BattleGoldProducerLV*80+BasicGoldProducerLV*40);
					}
					break;
				case 'a':
				case 'b':
				case 'c':
				case 'd':
				case 'e':
				case 'f':
				case 'g':
				case 'h':
				case 'i':
				case 'j':
					BattleCallRole(input-96);
					break;
				case 'A':
				case 'B':
				case 'C':
				case 'D':
				case 'E':
				case 'F':
				case 'G':
				case 'H':
				case 'I':
				case 'J':
					sprintf(Image,"%d.png",Team[input-64]);
					system(Image);
					break;
			}
			input=0;
		}
		if(MinorMenu==5||MinorMenu==6)
		{
			DrawForm();
			system("Pause>NUL");
			MinorMenu=0;
			MainMenu=0;
		}
		DrawForm();
	}
}
