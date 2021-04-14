#pragma once

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <process.h> 
#define Form_Weight 50
#define Form_Height 24 //窗口的長度
#define Form_X 10 //窗口的x坐標
#define Form_Y 4 //窗口的y坐標


int EXP,diamond;
static char rarity[6][4]={" ","N","R","SR","SSR","UR"};
int MainMenu,MinorMenu,ClickTabNum[10];
static int HeroRarity[21]={0,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4,5,5};
static int EnemyTowerHP[3]={3000,6000,12000};
int OpenHeroImage[12],CompleteBattle[3],FailBattle[3];

int HeroId[21],HeroBasicAtk[21],HeroBasicHP[21],HeroCoolDownTime[21],CallHeroNeedMoney[21],HeroLV[21],Team[11],BasicTowerLV,BasicGoldProducerLV;
int BattleGoldProducerLV,BattleGold,BombEnergy,godmax;
int CurrentHeroX[21][11],CurrentHeroHP[21][11],IsHeroAlive[21][11],HeroFirstX,HeroBattleNum[21],HeroBattlePastTime[21];
int IsEnemyAlive[4][6],CurrentEnemyX[4][6],CurrentEnemyHP[4][6],TotalEnemyNum,EnemyFirstX;

void callrole1(void *arg);
void callrole2(void *arg);
void callrole3(void *arg);
void callrole4(void *arg);
void callrole5(void *arg);
void callrole6(void *arg);
void callrole7(void *arg);
void callrole8(void *arg);
void callrole9(void *arg);
void callrole10(void *arg);
void callrole11(void *arg);
void callrole12(void *arg);
void callrole13(void *arg);
void callrole14(void *arg);
void callrole15(void *arg);
void callrole16(void *arg);
void callrole17(void *arg);
void callrole18(void *arg);
void callrole19(void *arg);
void callrole20(void *arg);

void callenemy1(void *arg);
void callenemy2(void *arg);
void callenemy3(void *arg);

void bombbomb();
void DrawForm();
void BattleCallRole(int call);
void BattleParallel_2();
void BattleParallel_1();
void gacha();
void run();




