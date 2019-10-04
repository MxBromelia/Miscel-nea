class Operacao
{
private:
	struct tm tempo;

public:
	Operacao()
	{
		const time_t t = time(NULL);
	}


};

class CriarConta: public Operacao
{

}

class FecharConta: public Operacao
{

}

class OperacaoCaixa: public Operacao
{
	private:
		float valor;
}

class Saque: public OperacaoCaixa
{
	public:
		Saque(float valor)
		{
			this->valor = valor;
		}
}

class Deposito: public OperacaoCaixa
{
	public:
		Deposito(float valor)
		{
			this->valor = valor;
		}
}

class Transfer: public OperacaoCaixa
{
	private:
		int id_conta;

	public:
		Transfer(float value, int id_conta)
		{
			this->value;
			this->id_conta;
		}
}