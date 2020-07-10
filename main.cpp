#include "ruleNetwork.h"
#include "preprocessing.h"
#include "statisticalUnion.h"
#include "slidingWindow.h"
#include "func.h"
#include "lct.h"

#include <iostream>
#include <set>

using namespace std;

int main()
{
	// test rule network
	ruleNetwork* rn = new ruleNetwork();
	rn->genTrees();
	RULETREES* rts = rn->GetRuleTrees();
	for (auto it = rts->begin(); it != rts->end(); it++)
	{
		(*it)->tranversal();
	}
	return 0;
}

//int main()
//{
//	//class statistical, statisticalUnion, preprocessing test
//	/*preprocessing* exam = new preprocessing();
//	statisticalUnion* SU1 = new statisticalUnion(1,"MAX",7,1,0,0.0);
//	statisticalUnion* SU2 = new statisticalUnion(1, "MAX", 7, 1, 0, 2.0);
//	bool isEqual = SU1->isEqual(*SU2);
//	cout << isEqual << endl;
//	exam->SUExtraction();
//	exam->SUListProcessing();
//	exam->testSUList();*/
//
//	// class basicWindow, slidingWindow test
//	/*int btu = 1;
//	double freq = 0.1;
//	int BWSize = btu / freq;
//	int capacity = 10;
//	double value = 0.0;
//	basicWindow* curr;
//	set<string>* SS = new set<string>();
//	SS->insert("MAX");
//	SS->insert("AVG");
//	SS->insert("VAR");
//	slidingWindow* SW = new slidingWindow(BWSize,capacity);
//	map<string, double>* tmpMap;
//	
//	int i = 0;
//	while (1)
//	{
//		value = genRandData(0.7, 1.5);
//		SW->updateData(value);
//		if (SW->isFull())
//		{
//			if (i < 20)
//			{
//				curr = SW->GetHead();
//				while (curr != NULL)
//				{
//					curr->testData();
//					curr->updateDigest(SS);
//					curr->testDigest();
//					curr = curr->GetNextWindow();
//				}
//				tmpMap = SW->GetDigest(SS, 4, 6);
//				SW->testDigest(tmpMap);
//				i++;
//			}
//			else {
//				break;
//			}
//		}
//	}*/
//
//	//class lct test
//	/*int BWSize = 10;
//	int capacity = 10;
//	preprocessing* prep = new preprocessing();
//	lct* elct = new lct();
//	slidingWindow* SW = new slidingWindow(BWSize, capacity);
//	prep->SUExtraction();
//	prep->SUListProcessing();
//	prep->testSUList();
//	elct->lctInit(prep);
//	set<string>* SS = new set<string>();
//	set<string>* tmpSS = elct->GetSS();
//	for (auto it = tmpSS->begin(); it != tmpSS->end(); it++)
//	{
//		SS->insert(*it);
//	}
//	for (auto it = SS->begin(); it != SS->end(); it++)
//	{
//		cout << *it << " " << endl;
//	}
//	elct->CreateNDColumns(prep,SW);
//	elct->CreateTSAColumns(prep);
//
//	basicWindow* curr;
//	double value = 0.0;
//	int i = 0;
//	while (1)
//	{
//		value = genRandData(0.7, 1.5);
//		SW->updateData(value);
//		if (SW->isFull())
//		{
//			if (i < 20)
//			{
//				curr = SW->GetHead();
//				while (curr != NULL)
//				{
//					curr->testData();
//					for (auto it = SS->begin(); it != SS->end(); it++)
//					{
//						cout << *it << " " << endl;
//					}
//					curr->updateDigest(SS);
//					curr->testDigest();
//					curr = curr->GetNextWindow();
//				}
//				elct->updateNDColumns(prep, SW);
//				elct->updateTSAColumns(prep);
//				elct->testTSAColumns(prep);
//				i++;
//			}
//			else {
//				break;
//			}
//		}
//	}
//
//	delete SS;*/
//
//	
//}