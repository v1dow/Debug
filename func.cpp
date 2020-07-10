#include "func.h"

double GetMax(deque<double>* d)
{
	double max = -999999999;
	double t = 0;
	for (int i = 0; i < d->size(); i++)
	{
		t = d->at(i);
		if (t > max)max = t;
	}
	//d->clear();
	//delete d;
	return max;
}

double GetMin(deque<double>* d)
{
	double min = 9999999999;
	double t = 0;
	for (int i = 0; i < d->size(); i++)
	{
		t = d->at(i);
		if (t < min)min = t;
	}
	//d->clear();
	//delete d;
	return min;
}

double GetMean(deque<double>* d)
{
	double total = 0;
	double t = 0;
	int count = d->size();
	if (count <= 0)return 0;

	for (int i = 0; i < count; i++)
	{
		t = d->at(i);
		total += t;
	}
	//d->clear();
	//delete d;
	return total / count;
}

double GetVar(deque<double>* d)
{
	double result = 0;
	double tmp = 0;
	double mean = GetMean(d);
	for (int i = 0; i < d->size(); i++)
	{
		tmp = d->at(i);
		result += (tmp - mean) * (tmp - mean);
	}
	return result / (d->size() - 1);
}

double GetStd(deque<double>* d)
{
	return sqrt(GetVar(d));
}

double genRandData(double low, double high)
{
	double value = 0;
	value = low + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (high - low)));
	return value;
}

double digestGenerator(string op,deque<double>* d)
{
	double result = 0.0;

	if (op == "MAX")
		result = GetMax(d);
	if (op == "MIN")
		result = GetMin(d);
	if (op == "AVG")
		result = GetMean(d);
	if (op == "VAR")
		result = GetVar(d);
	if (op == "STD")
		result = GetStd(d);

	return result;
}

int gcd(int a, int b)
{
	int tmp;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int multiGcd(set<int>* s)
{
	if (s->size() == 1)
		return (*(s->begin()));
	int size = s->size();
	int tmp = *(s->end());
	s->erase(size - 1);
	return gcd(tmp, multiGcd(s));
}

