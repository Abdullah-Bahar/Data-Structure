#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/* 
	ABDULLAH BAHAR	
*/

using namespace std;

struct Takim
{
	string Ad;
	int Puan;
};

void SatirAyristirma(string & satir, Takim & team);

// Dosyayi Satir Satir Okuma
void SatirOkumasi(ifstream & Dosya, vector<Takim> & Takimlar)
{
	string satir;
	while (getline(Dosya, satir))
	{
		Takim team;
		SatirAyristirma(satir, team);
		Takimlar.push_back(team);
	}
}

// Okunan Satirlari Ayristirma
void SatirAyristirma(string & satir, Takim & team)
{
	int bosluk;
	bosluk = satir.find(" ");
	team.Ad = satir.substr(0, bosluk);
	team.Puan = stoi(satir.substr(bosluk + 1));
}

void Swap (Takim & a, Takim & b)
{
	Takim temp = a;
	a = b;
	b = temp;
}

// (desc) Siralama --> Ayrica siralanmis bir vectore yeni eleman atamak icin kullanilir
void Insert(vector<Takim> & b, Takim YeniTakim)
{
	int count = b.size() - 1;
	b.push_back(YeniTakim);

	while (count > 0 && b[count-1].Puan > YeniTakim.Puan)
	{
		b[count] = b[count-1];
		count--;
	}
	b[count] = YeniTakim;
}

// Insert fonksiyonunu hic siralanmamis bir vector uygun hale getiriyor
void FixInsert(vector<Takim> & a)
{
	vector <Takim> yeni;
	int sinir = a.size();
	int i = 0;

	yeni.push_back(a[i]);
	for ( i = 0; i < sinir; i++)
		Insert(yeni, a[i]);
	yeni.pop_back();

	for (int i = 0; i < sinir; i++)
		Swap(yeni[i], a[i]);
}

// Struct Yazdirma
void PrintStruct(const vector<Takim> & teams)
{
	int i = 0;
	int size = teams.size();
	while (i < size)
	{
		cout << teams[i].Ad << " " << teams[i].Puan << endl;
		i++;
	}
	cout << endl;
}

// Desc Siralanmis (Insert ile) Vectoru Asc olarak siralama
void AscSiralama(vector <Takim> & Takimlar)
{
	int i = 0;
	int j = Takimlar.size() - 1;
	int k = Takimlar.size()/2;

	while (i < k )
	{
		Swap(Takimlar[i], Takimlar[j]);
		i++;
		j--;
	}
}

// Dosyaya Yazma Fonsksiyonu
void OutputFile(ofstream & Output, vector <Takim> & Takimlar)
{
	int i = 0;
	int had = Takimlar.size();
	while (i < had )
	{
		Output << Takimlar[i].Ad << " " << Takimlar[i].Puan << endl;
		i++;
	}
	cout << "Veriler Dosyaya Basarili Bir Sekilde Kaydedilmistir" << endl;
}

int main()
{
	vector <Takim> Takimlar;

	//	DOSYAYI OKUMA
	ifstream myFile;
	string FileName;
	cout << "Okumak Istediginiz Dosya Adini Giriniz : ";
	cin >> FileName;

	//	DOSYA KONTROLU
	myFile.open(FileName);
	if (myFile.fail())
	{
		cout << "Dosya Bulunamadi. Program Sonlandiriliyor"<< endl;
		system("pause");
		exit(0);
		// return 0;
	}
	else
		cout << "Dosya Basarili Bir Sekilde Acildi"<< endl;
	cout << "\n\n";

	//Dosyayi satir satir okuyoruz ve Vektore kaydediyoruz
	SatirOkumasi(myFile, Takimlar);
	myFile.close();

	cout << "Siralanmamis Vector :" << endl;
	PrintStruct(Takimlar);

	//Vektor Siralama Kucukten Buyuge
	FixInsert(Takimlar);

	cout << "Siralanmis Vector (desc) :" << endl;
	PrintStruct(Takimlar);

	AscSiralama(Takimlar);
	cout << "Siralanmis Vector (asc) :" << endl;
	PrintStruct(Takimlar);

	//	DOSYAYA YAZMA
	ofstream OutFile;
	string FileName1;
	cout << "Yazmak Istediginiz Dosya Adini Giriniz : ";
	cin >> FileName1;

	// DOSYA KONTROLU
	OutFile.open(FileName1);
	if (OutFile.fail())
	{
		/*
			Aslinda bu hatayi hic bir zaman vermeyecek.
			Cunku olmayan bir dosya adi girdigimizde o ada sahip yeni bir dosya olusturuyor.
			Yani Dosyanin bulunamamasi mumkun degil gibi.
		*/
		cout << "Dosya Bulunamadi. Program Sonlandiriliyor"<< endl;
		system("pause");
		exit(0);
	}
	else
	{
		cout << "Dosya Basarili Bir Sekilde Acildi"<< endl;
		OutputFile(OutFile, Takimlar);
	}
	cout << "\n\n";

	
	OutFile.close();

	system("pause");
	return 0;
}