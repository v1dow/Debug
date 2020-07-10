#ifndef FUNC_H
#define FUNC_H

#include <deque>
#include <string>
#include <set>

#define RAND_M 32767

using namespace std;

double GetMax(deque<double>* d);
double GetMin(deque<double>* d);
double GetMean(deque<double>* d);
double GetVar(deque<double>* d);
double GetStd(deque<double>* d);

double genRandData(double low, double high);
double digestGenerator(string op, deque<double>* d);
int gcd(int a, int b);
int multiGcd(set<int>* s);
#endif // !FUNC_H

