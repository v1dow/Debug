#include "ruleNetwork.h"


ruleNetwork::ruleNetwork()
{
	RuleTrees = new RULETREES();
}

ruleNetwork::~ruleNetwork()
{
	delete RuleTrees;
}

//void ruleNetwork::Init()
//{
//
//}

void ruleNetwork::trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}


RULETREES* ruleNetwork::GetRuleTrees()
{
	return this->RuleTrees;
}

void ruleNetwork::genTrees()
{
	ruleTree* rt;
	vector<string>* acs;

	string AC;
	size_t found = 0;
	int idx = 0;

	string ant = "MAX(S1,4) > 1.46 AND AVG(S1,7) < 1.48 AND AVG(S2,7) < 1.33 AND MAX(S1,4) < 1.66 AND VAR(S1,9) < 1.23";
	string con = "A1 = 1";
	rt = new ruleTree(con);
	acs = new vector<string>();
	while (1)
	{
		if (ant.find("AND") != string::npos)
		{
			idx = 0;
			found = ant.find("AND");
			AC = ant.substr(idx, found - idx);
			trim(AC);
			acs->push_back(AC);
			ant.erase(0, found + 3);
		}
		else {
			idx = 0;
			found = ant.length() - 1;
			AC = ant;
			trim(AC);
			acs->push_back(AC);
			break;
		}
	}
	rt->SetChildren(con, acs);
	//delete acs;

	RuleTrees->push_back(rt);
}

