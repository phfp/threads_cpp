#include <iostream>
#include <thread>
#include <chrono>

	typedef std::chrono::high_resolution_clock Clock;

	using namespace std;

	int tempo_espera = 10;

	
	void func(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void normal(){

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

	void com_thread(){

		int x = 0;

		thread t1(func,ref(x));
		thread t2(func,ref(x));
		thread t3(func,ref(x));
		thread t4(func,ref(x));

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

		cout << "\nExecutando programa sem utilização de threads..." << endl;
		normal();

		cout << "\nExecutando programa com utilização de threads..." << endl;
		com_thread();

		return 0;
	}
