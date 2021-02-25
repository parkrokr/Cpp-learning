//�ڷ��� �߷� (Type Inference)  auto �� decltype

#include <iostream>
#include <vector>
#include <algorithm>	//std::min

//Referecne : http://thbecker.net/articles/auto_and_decltype/section_01.html

using namespace std;

class Examples
{
public:

	void ex1()
	{
		std::vector<int> vect;
		for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
			cout << *itr;

		for (auto itr = vect.begin(); itr != vect.end(); itr++)
			cout << *itr;

		for (auto itr : vect)	//for (const auto & itr : vect)
			cout << itr;
	}

	void ex2()
	{
		int x = int();

		auto auto_x = x;	//int �� ����


		const int& crx = x;

		auto auto_crx1 = crx;	//crx �� const int & ������ auto �� const, reference �� ��� int �� ����

		const auto& auto_crx2 = crx;	//const int & �� ���� ������ auto ��ü�� const, reference �� ����


		volatile int vx = 1024;		//volatile �� ���� ���� ���ϴ� ����ȭ �Ҷ� ���޶� ��� �ǹ�
		//multi threading �� �Ҷ� ����� �� ���� 

		auto avx = vx;	//volatile �������� int �� ����

		volatile auto vavx = vx;	//volatile ���� ����ϰ� ������ voliatile auto ���


		//auto �� ���� �⺻���� �ڷ���(ex int) �� �߷����ְ� ������ ���ľ�(const, reference, volitile ) �� ������
		//����ڰ� �߰��ϰ� ������ �߰������ ��
	}


	template<class T>
	void func_ex3(T arg)
	{}

	/*template<class T>
	void func_ex3(const T& arg)
	{}*/

	void ex3()
	{
		const int& crx = 123;

		func_ex3(crx);	//const �� & �� ���� int �� ����

		//const int reference �� �ְ� ������  void func_ex3(const T& arg) ���
	}


	void ex4()
	{
		const int c = 0;
		auto& rc = c;		//rc �� const int reference

		//rc = 123; �� �õ��ϸ� compile error �� �߻�

		//reference �� �޾ƿ��µ� c �� const �̱� ������ �޴� rc �� const ������, auto �� �� �߷��� ����
	}


	void ex5() //amendament(����, ����)
	{
		int i = 42;
		auto&& ri_1 = i;	// l value (amendament(����, ����))
		auto&& ri_2 = 42;	// r value

		//auto&&�� r vlaue reference �� �����ϰ� �ʹٴ� �ǵ�, l value �� ������ & �� �ٲ�
		//r value �� ������ &&(r value reference) �� ����
	}


	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;		//p2 �� const int * �� �� ����

		//auto �� �����͵� �������� const �� ������, auto �� �ݵ�� �ʿ��� ��� (������ ������� ��)
		//*p2 = 43; const �� error
	}



	template<typename T, typename S>
	void func_ex7(T lhs, S rhs)	//���� �� ���ڸ� ���ϴ� �Լ�
	{
		auto prod1 = lhs * rhs;

		//lhs �� rhs �� data type �� �ٸ� �� ���� 
		//prod1 �� data type �� ���� ���� �˱� �����(��Ȯ ���� ����)


		//lhs* rhs�� � type ���� data type �� return �ϴ� �Լ�
		//typedef typeof(lhs* rhs) product_type;	//c++11 ���� '�Ϻ�' �����Ϸ����� ����
		typedef decltype(lhs* rhs) product_type;	//���������� ���

		//decltype �ȿ��� lhs* rhs �� ������ ����(���)���� �ʰ� �߷и� ��

		product_type prod2 = lhs * rhs;


		decltype(lhs * rhs) prod3 = lhs * rhs;	//datatype �� �������� �ʾƵ� �ٷ� �� �� ����
	}


	//�Լ��� return type ���� decltype �� ����� �� ����
	template<typename T, typename S>
	auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)	//trailing
	{
		return lhs * rhs;
	}

	//decltype(lhs* rhs) func_ex8(T lhs, S rhs)		//decltype �� �ٷ� return type �ڸ����� �� �� ����
	//�����Ϸ��� �ڵ带 �д� ������ decltype(lhs* rhs)�� ���� �����µ� lhs* rhs�� ���� ���� �ȳ���


	void ex7_8()
	{
		func_ex7(1.0, 345);		//double
		func_ex8(1.2, 345);		//double
	}



	struct S
	{
		int m_x;

		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();


		auto a = x;			//int
		auto b = cx;		//int
		auto c = crx;		//int		, const & �� ������
		auto d = p;			//const S*	, �����Ͷ� const �����
		auto e = p->m_x;	//int		, p �� const �� m_x �� ������ �� ������
							//e�� const �� �ƴϾ e �� m_x �� ���� �� �� ����


		typedef decltype(x)		x_type;		//int
		typedef decltype(cx)	cx_type;	//const int			auto �� �ٸ�
		typedef decltype(crx)	crx_type;	//const int &		const, & �״�� �� ������ ��
		typedef decltype(p->m_x)m_x_type;	//int				m_x �� int �� ����Ǿ declared type �״�� ������

		typedef decltype((x))	x_with_parens_type;		//int &			,add reference to l values
		typedef decltype((cx))	cx_with_parens_type;	//const int &
		typedef decltype((crx))	crw_with_parens_type;	//const int &	,& �� �ϳ� �� ���� ����, ������
		typedef decltype((p->m_x)) m_x_with_parens_type;//const int &	,const �� ���� ����!
	}



	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10()
	{
		std::vector<int> vect = { 42,43 };

		auto a = foo();		//S
		typedef decltype(foo()) foo_type;	//const S		const �� ������

		auto b = foobar();	//int		,const �� & ������
		typedef decltype(foobar()) foobar_type;	//const int &		,const �� & �Ѵ� ������


		auto itr = vect.begin();						//std::vector itreator
		typedef decltype(vect.begin())	iterator_type;	//std::vector itreator

		auto first_element = vect[0];					//int
		decltype(vect[1]) second_element = vect[1];		//int &

		//std::vector �� overloading �Ǿ��ִ� [] �����ڰ� return �Ҷ� & �� return ��
		//decltype ���� ������ �� reference �� ������
	}



	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y) prod_xy_type;		//int
		auto a = x * y;								//int

		typedef decltype(cx* cy) prod_cxcy_type;	//int		result is prvalue(pure r value)
		auto b = cx * cy;							//int


		typedef decltype(d1 < d2 ? d1 : d2)	cond_type;	//result is lvalue. & is added	d1 �� d2 �� ���� type
		auto c = d1 < d2 ? d1 : d2;						//double

		typedef decltype(x < d2 ? x : d2)	cond_type_mixed;	//double	promotion of x to double
		auto d = x < d2 ? x : d2;								//double


		//std::min �� �ԷµǴ� �� ������ ���� type �϶��� �۵���, �ٸ��� error
		//auto d = std::min(x,d1);	//error
	}


	//data type �� ������� �۵��ϴ� min
	//floating point min(boost lib)

	//�߸��� ���
	template<typename T, typename S>
	auto fpmin_wrong(T x, S y)->decltype(x < y ? x : y)			
	{
		return x < y ? x : y;
	}


	//T �� S �� data type �� ���� ��� return type �� & �� ����
	//remove_reference	: &�� ���ŵ� data type �� ���	(�տ� typename �پ�����)
	template<typename T, typename S>
	auto fpmin(T x, S y)->
		typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}


	void ex12()
	{
		int i = 42;
		double d = 45.1;
		//auto a = std::min(i,d);	//error : 'std::min' : no mathching overloaded function found
		auto a = std::min(static_cast<double>(i), d);	//std::min �� ����ϱ� ���ؼ��� casting �� ����ߵ�

		int& j = i;


		typedef decltype(fpmin_wrong(d, d)) fpmin_return_type;		//double &
		typedef decltype(fpmin_wrong(i, d)) fpmin_return_type1;		//double		,&�� �����
		typedef decltype(fpmin_wrong(j, d)) fpmin_return_type2;		//double		,&�� �����

		//�׶��׶� �޶����°͵� ������, reference �� return �ϸ� ������ ���� �� ����
		//��κ��� ��� �������� ����


		//std::remove_reference ���	:	&�� ������ type �� ����ϰڴ�
		typedef decltype(fpmin(d, d)) fpmin_return_type3;		//double 
		typedef decltype(fpmin(i, d)) fpmin_return_type4;		//double		
		typedef decltype(fpmin(j, d)) fpmin_return_type5;		//double		
	}


	void ex13()
	{
		std::vector<int> vect; //cect is empty

		typedef decltype(vect[0]) integer;

		//vect �� ����ֱ� ������ [] �����ڸ� �̿��Ͽ� vect[0] �� �ϸ� ��Ÿ�ӿ����� �߻�������
		//decltype �� ������ �������� �ʱ� ������(compile time �� üũ��) ������
	}


	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor(){}

		//result_type �� return �ϴ� functor, ��ü�� �Լ�ó�� ����� �� ����
		result_type operator() ()
		{
			return R();
		}
	};


	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type inteager;		//nested type
		//decltype(func) �� ���� SomeFunctor<int> �� �������� �ű⼭ result_type ( int ) �� ������
		//class �ȿ� �ִ� nested type�� decltype �� ���� �����ϰ� ������ �� ����
	}


	//lambda �� decltype �� ���� data type �� ã�Ƴ� �� ����
	void ex15()
	{
		auto lambda = []() {return 42; };		//auto �� lambda class �� data type �� ����
		decltype(lambda) lambda2(lambda);		//lambda �� ���� ����� �ϴ� lambda2 �� ����
		decltype((lambda)) lambda3(lambda);		//lambda3 �� reference

		cout << "Lambda functions" << endl;
		cout << &lambda << " " << &lambda2 << endl;		//�ּҰ� �ٸ�
		cout << &lambda << " " << &lambda3 << endl;		//�ּҰ� ����
	}


	//generic lambda
	void ex16()
	{
		//�Լ����� parameter �� auto �� ���� �������� lambda ���� �� �� ����

		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.4, 2.2) << endl;
		//	double		int		double
	}


};

int main()
{
	Examples examples;
	
	examples.ex1();
	examples.ex2();
	examples.ex3();
	examples.ex4();
	examples.ex5();
	examples.ex6();
	examples.ex7_8();
	examples.ex9();
	examples.ex10();
	examples.ex11();
	examples.ex12();
	examples.ex13();
	examples.ex14();
	examples.ex15();
	examples.ex16();


	return 0;
}