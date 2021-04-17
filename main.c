#include "little_battle.h"
extern int EXP,diamond;
extern char rarity[6][4];
extern int MainMenu,MinorMenu,ClickTabNum[10],HeroRarity[21];
extern int OpenHeroImage[12],CompleteBattle[3],FailBattle[3];

extern int HeroId[21],HeroBasicAtk[21],HeroBasicHP[21],HeroCoolDownTime[21],CallHeroNeedMoney[21],HeroLV[21],Team[11],BasicTowerLV,BasicGoldProducerLV;
extern int BattleGoldProducerLV,BattleGold,BombEnergy,godmax;
extern int CurrentHeroX[21][11],CurrentHeroHP[21][11],IsHeroAlive[21][11],HeroFirstX,HeroBattleNum[21],HeroBattlePastTime[21];
extern int IsEnemyAlive[4][6],CurrentEnemyX[4][6],CurrentEnemyHP[4][6],TotalEnemyNum,EnemyFirstX,EnemyTowerHP[3];

int main()
{
	FILE *fpr,*fpr2;
	MinorMenu = 0;
	fpr=fopen("./data/roledata.txt","r");
	fscanf(fpr,"%*[^\n]\n");
	for(int i=1;i<=20;i++)
	{
			fscanf(fpr,"%d %d %d %d %d",&HeroId[i],&HeroBasicAtk[i],&HeroBasicHP[i],&HeroCoolDownTime[i],&CallHeroNeedMoney[i]);
	}
	fclose(fpr);
	fpr2=fopen("./data/data.txt","r");
	fscanf(fpr2,"%*[^\n]\n");
	fscanf(fpr2,"%d %d %d %d %d %d %d %d %d %d",&EXP,&diamond,&BasicTowerLV,&BasicGoldProducerLV,&CompleteBattle[0],&CompleteBattle[1],&CompleteBattle[2],&FailBattle[0],&FailBattle[1],&FailBattle[2]);
	fscanf(fpr2,"\n%*[^\n]\n");
	fscanf(fpr2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&HeroLV[1],&HeroLV[2],&HeroLV[3],&HeroLV[4],&HeroLV[5],&HeroLV[6],&HeroLV[7],&HeroLV[8],&HeroLV[9],&HeroLV[10],&HeroLV[11],&HeroLV[12],&HeroLV[13],&HeroLV[14],&HeroLV[15],&HeroLV[16],&HeroLV[17],&HeroLV[18],&HeroLV[19],&HeroLV[20]);
	fscanf(fpr2,"\n%*[^\n]\n");
	fscanf(fpr2,"%d %d %d %d %d %d %d %d %d %d",&Team[1],&Team[2],&Team[3],&Team[4],&Team[5],&Team[6],&Team[7],&Team[8],&Team[9],&Team[10]);
	fclose(fpr2);
	system("mode con cols=120 lines=32");
	for(int i=0;i<=20;i++)
	{
		for(int j=1;j<=10;j++)
		{
			IsHeroAlive[i][j]=0;
			IsEnemyAlive[i][j]=0;
		}
	}
	_beginthread(BattleParallel_2, 0, 0);
	CurrentEnemyHP[0][0]=1;
	CurrentHeroHP[0][0]=1;
	DrawForm();
	DrawForm();
	run();
	return 0;
}