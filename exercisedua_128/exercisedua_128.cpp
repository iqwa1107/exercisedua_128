#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class buku;
class penerbit
{
public:
	string nama;
	vector<pengarang*>daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit\"" << nama << "\"\n";
	}
	~penerbit() {
		cout << "penerbit\"" << nama << "\"\n";
	}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};


class pengarang
{
public:
	string nama;
	vector<penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\"\n";

	}

	~pengarang() {
		cout << "pengarang \"" << nama << "\"\n";
	}

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();

};


void penerbit::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakpengarang() {
	cout << "Daftar pengarang pada penerbit \"" <<this->nama << "\":\n";
	for (auto& a : daftar_pengarang)
	{
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahpenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahpengarang(this);
}

void pengarang::cetakpenerbit() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit)
	{
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varpengarang1 = new pengarang("Joko,Lia,Giga");
	pengarang* varpengarang2 = new pengarang("Asroni,Giga");
	penerbit* varpenerbit1 = new penerbit("Gama Press");
	penerbit* varpenerbit2 = new penerbit("Intan Pariwara");

	varpengarang1->tambahpenerbit(varpenerbit1);
	varpengarang2->tambahpenerbit(varpenerbit2);
	varpengarang1->tambahpenerbit(varpenerbit1);

	varpengarang1->cetakpenerbit();
	varpengarang2->cetakpenerbit();
	varpenerbit1->cetakpengarang();
	varpenerbit2->cetakpengarang();

	delete varpenerbit1;
	delete varpenerbit2;
	delete varpengarang1;
	delete varpengarang2;

	return 0;
}