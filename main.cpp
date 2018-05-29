#include <iostream>
#include <thread>
#include <chrono>

	typedef std::chrono::high_resolution_clock Clock;

	using namespace std;

	int tempo_espera = 10;

	
	void a(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void b(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void c(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void d(int &x){
		x += 10;
		this_thread::sleep_for (std::chrono::seconds(tempo_espera));
	}

	void normal(){

		int x = 0;

		auto inicio = Clock::now();		

		a(x);
		b(x);
		c(x);
		d(x);

		auto fim = Clock::now();

		double tempo = chrono::duration_cast <chrono::seconds> (fim - inicio).count();

		cout << "Saida: " << x << endl;
		cout << "Tempo: " << tempo << " segundos" << endl;
	}

	void com_thread(){

		int x = 0;

		thread t1(a,ref(x));
		thread t2(b,ref(x));
		thread t3(c,ref(x));
		thread t4(d,ref(x));

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