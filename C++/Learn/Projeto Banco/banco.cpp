#include<ctime>
#include<iostream>
#include<vector>

using namespace std;

enum {op_saque,op_deposito,op_transfer} op;

class Operacao {
private:
	struct tm tempo;
	int tipo;
	float valor;

public:
	Operacao(int tipo, float valor): tipo(tipo), valor(valor)
	{
		time_t t = time(NULL);
		struct tm *tt = localtime(&t);
		tempo = *tt;
	}

	void print()
	{
		char buffer[80];

		strftime(buffer,80,"%c: Operation.\n",&tempo);

		cout << "-->" << buffer;
	}
};


class Conta
{
private:
	float saldo;
	vector<Operacao> hist;

	friend class CaixaEletronico;
public:
	Conta()
	{
		saldo = 0;
	}

	Conta(int saldo_inicial)
	{
		saldo = saldo_inicial;
	}
};

class CaixaEletronico
{
private:
	bool nova_op(Conta &conta, int id, float valor)
	{
		Operacao op(id, valor);
		conta.hist.push_back(op);
		return true;
	}

	bool pode_sacar(Conta conta, float valor)
	{
		return conta.saldo >= valor;
	}

	bool saque_unsafe(Conta &conta, float valor)
	{
		conta.saldo -= valor;
		nova_op(conta,op_saque,valor);
		return true;
	}
public:
	bool deposito(Conta &conta, float valor)
	{
		conta.saldo += valor;
		nova_op(conta,op_deposito,valor);
		return true;
	}

	bool saque(Conta &conta, float valor)
	{
		return pode_sacar(conta,valor)
			&& saque_unsafe(conta,valor);
	}

	bool transfer(Conta &conta1, Conta &conta2, float valor)
	{
		return pode_sacar(conta1,valor)
			&& nova_op(conta1, op_transfer,-valor)
			&& nova_op(conta2, op_transfer,valor)
			&& saque_unsafe(conta1,valor)
			&& deposito(conta2,valor);
	}

	void printHist(Conta c)
	{
		cout << c.hist.size() << endl;
		for(int i=0;i<c.hist.size();i++)
			c.hist[i].print();
	}
};


int main()
{
	Conta c1, c2;
	CaixaEletronico ce;

	ce.deposito(c1,20);
	ce.saque(c1,10);
	ce.transfer(c1,c2,5);

	ce.printHist(c1);


	return 0;
}