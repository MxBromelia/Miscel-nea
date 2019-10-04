#include "f_tree.h"

void strallcpy(char* receiver, const char* donator)
{
	receiver = (char*)malloc(sizeof(char)*(strlen(donator)+1));
	strcpy(receiver, donator);
}

Opt newOpt(const char* cnt)
{
	Opt ret;

	strallcpy(ret.cnt, cnt);

	//ret->left = NULL;
	//ret->right = NULL;

	return ret;
}

Fnc newFnc(const char* name, int nVar, char** var)
{
	int i;

	Fnc ret;

	strallcpy(ret.name, name);

	ret.var = (char**)malloc(sizeof(char*)*nVar);
	for(i=0;i<nVar;i++)
	{
		ret.var[i] = (char*)malloc(sizeof(char)*(strlen(var[i])+1));
		strcpy(ret.var[i], var[i]);
	}
	ret.func = NULL;

	return ret;
}

Opt* mOpt(const char* expression, unsigned int len)
{
	Opt* o = (Opt*)malloc(sizeof(Opt));

	*o = newOpt("");

	return o;
}

Fnc* mFnc(const char* assignment, unsigned int len)
{
	Fnc* f = (Fnc*)malloc(sizeof(Fnc));
	char* name = "";
	int nVar = 0;
	char** var = NULL;

	*f = newFnc(name, nVar, var);

	return f;
}

Fnc* mTree(const char* assignment, unsigned int len)
{
	Fnc* f = (Fnc*)malloc(sizeof(Fnc));
	char* equal = strchr(assignment, '=');

	f = mFnc(assignment, equal - assignment);
	f->func = mOpt(equal+1, assignment - equal + len);

	return f;
}