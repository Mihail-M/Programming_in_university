#include <string>

struct Transformer;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct Expression
{
	virtual ~Expression() { }
	virtual double evaluate() const = 0;
	virtual Expression *transform(Transformer *tr) const = 0;
};

struct Transformer
{
	virtual ~Transformer() { }
	virtual Expression *transformNumber(Number const *) = 0;
	virtual Expression *transformBinaryOperation(BinaryOperation const *) = 0;
	virtual Expression *transformFunctionCall(FunctionCall const *) = 0;
	virtual Expression *transformVariable(Variable const *) = 0;
};

struct Number : Expression
{
	Number(double value);
	double value() const;
	double evaluate() const;
	Expression *transform(Transformer *tr) const;

private:
	double value_;
};

struct BinaryOperation : Expression
{
	enum {
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};
	BinaryOperation(Expression const *left, int op, Expression const *right);
	~BinaryOperation();
	double evaluate() const;
	Expression *transform(Transformer *tr) const;
	Expression const *left() const;
	Expression const *right() const;
	int operation() const;

private:
	Expression const *left_;
	Expression const *right_;
	int op_;
};

struct FunctionCall : Expression
{
	FunctionCall(std::string const &name, Expression const *arg);
	~FunctionCall();
	double evaluate() const;
	Expression *transform(Transformer *tr) const;
	std::string const &name() const;
	Expression const *arg() const;

private:
	std::string const name_;
	Expression const *arg_;
};

struct Variable : Expression
{
	Variable(std::string const name);
	std::string const & name() const;
	double evaluate() const;
	Expression *transform(Transformer *tr) const;

private:
	std::string const name_;
};


/**
 * реализуйте все необходимые методы класса
 * вы можете определять любые вспомогательные
 * методы, если хотите
 */

std::string NameClass(Expression const *e1)
{
	Expression *e = const_cast<Expression *> (e1);
	Number *a = dynamic_cast<Number *> (e);
	if (a)
		return "number";

	FunctionCall *b = dynamic_cast<FunctionCall *>(e);
	if (b)
		return "fcall";

	BinaryOperation *c = dynamic_cast<BinaryOperation *>(e);
	if (c)
		return "operation";

	Variable *d = dynamic_cast<Variable *>(e);
	if (d)
		return "variable";

}


struct FoldConstants : Transformer
{
	Expression *transformNumber(Number const *number)
	{
		Expression *e = new Number(number->value());
		return e;

	}

	Expression *transformBinaryOperation(BinaryOperation const *binop)
	{
		Expression const *left, *right;
		if (NameClass(binop->left()) == "number")
			left = transformNumber(dynamic_cast<Number *>(const_cast<Expression *>(binop->left())));

		if (NameClass(binop->left()) == "operation")
			left = transformBinaryOperation(dynamic_cast<BinaryOperation *>(const_cast<Expression *>(binop->left())));

		if (NameClass(binop->left()) == "variable")
			left = transformVariable(dynamic_cast<Variable *>(const_cast<Expression *>(binop->left())));

		if (NameClass(binop->left()) == "fcall")
			left = transformFunctionCall(dynamic_cast<FunctionCall *>(const_cast<Expression *>(binop->left())));

		if (NameClass(binop->right()) == "number")
			right = transformNumber(dynamic_cast<Number *>(const_cast<Expression *>(binop->right())));

		if (NameClass(binop->right()) == "operation")
			right = transformBinaryOperation(dynamic_cast<BinaryOperation *>(const_cast<Expression *>(binop->right())));
		if (NameClass(binop->right()) == "variable")
			right = transformVariable(dynamic_cast<Variable *>(const_cast<Expression *>(binop->right())));

		if (NameClass(binop->right()) == "fcall")
			right = transformFunctionCall(dynamic_cast<FunctionCall *>(const_cast<Expression *>(binop->right())));

		return new BinaryOperation(left, binop->operation(), right);

	}

	Expression *transformFunctionCall(FunctionCall const *fcall)
	{
		if (NameClass(fcall->arg()) == "number")
			return new FunctionCall(fcall->name(), transformNumber(dynamic_cast<Number *>(const_cast<Expression *>(fcall->arg()))));

		if (NameClass(fcall->arg()) == "operation")
			return new FunctionCall(fcall->name(),
					transformBinaryOperation(dynamic_cast<BinaryOperation *>(const_cast<Expression *>(fcall->arg()))));

		if (NameClass(fcall->arg()) == "variable")
			return new FunctionCall(fcall->name(),
					transformVariable(dynamic_cast<Variable *>(const_cast<Expression *>(fcall->arg()))));

		if (NameClass(fcall->arg()) == "fcall")
			return new FunctionCall(fcall->name(),
					transformFunctionCall(dynamic_cast<FunctionCall *>(const_cast<Expression *>(fcall->arg()))));

	}

	Expression *transformVariable(Variable const *var)
	{
		Variable *a = new Variable(var->name());
		return a;
	}
};

int main() {
	return 0;

}
