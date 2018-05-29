#include <iostream>
#include <thread>
#include <chrono>

	typedef std::chrono::high_resolution_clock Clock;

	using namespace std;

	class Minha_Thread
	{

	private:

		int tempo_espera = 1;

	public:

		Minha_Thread(){};
		~Minha_Thread(){};

		void func(int &x);
		void normal();
		void com_thread();		
	};

	
	void Minha_Thread::func(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void Minha_Thread::normal(){

		int x = 0;

		auto inicio = Clock::now();		

		func(x);
		func(x);
		func(x);
		func(x);

		auto fim = Clock::now();

		double tempo = chrono::duration_cast <chrono::seconds> (fim - inicio).count();

		cout << "Saida: " << x << endl;
		cout << "Tempo: " << tempo << " segundos" << endl;


	}

	void Minha_Thread::com_thread(){

		int x = 0;

		Minha_Thread *mt = new Minha_Thread();

		thread t1(&Minha_Thread::func, mt, ref(x));
		thread t2(&Minha_Thread::func, mt, ref(x));
		thread t3(&Minha_Thread::func, mt, ref(x));
		thread t4(&Minha_Thread::func, mt, ref(x));
		

		auto inicio = Clock::now();

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		auto fim = Clock::now();

		double tempo = chrono::duration_cast <chrono::seconds> (fim - inicio).count();

		cout << "Saida: " << x << endl;
		cout << "Tempo: " << tempo << " segundos" << endl;


	}

	int main(){

		Minha_Thread t;

		t.normal();
		t.com_thread();

		return 0;
	}