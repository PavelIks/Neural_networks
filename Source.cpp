// C_Project_Intelec.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Notebook
{
public:
	int Id, SSD;
	float Price, Diagonal, Weight;

	Notebook() {};

	Notebook(int Id, int SSD, float Price, float Diagonal, float Weight)
	{
		this->Id = Id;
		this->SSD = SSD;
		this->Price = Price;
		this->Diagonal = Diagonal;
		this->Weight = Weight;
	}
	~Notebook() {};

};

int Ssd_method(Notebook* arr)
{
	int min_ssd = arr[0].SSD;
	for (int i = 0; i < 4; i++)
	{
		if (min_ssd > arr[i].SSD)
		{
			min_ssd = arr[i].SSD;
		}
	}
	return min_ssd;
}

float Price_method(Notebook* arr)
{
	float min_price = arr[0].Price;
	for (int i = 0; i < 4; i++)
	{
		if (min_price > arr[i].Price)
		{
			min_price = arr[i].Price;
		}
	}
	return min_price;
}

float Diagonal_method(Notebook* arr)
{
	float min_diag = arr[0].Diagonal;
	for (int i = 0; i < 4; i++)
	{
		if (min_diag > arr[i].Diagonal)
		{
			min_diag = arr[i].Diagonal;
		}
	}
	return min_diag;
}

float Weight_method(Notebook* arr)
{
	float min_weight = arr[0].Weight;
	for (int i = 0; i < 4; i++)
	{
		if (min_weight > arr[i].Weight)
		{
			min_weight = arr[i].Weight;
		}
	}
	return min_weight;
}

double* Coeficient(Notebook* arr, int min_ssd, float min_price, float min_diag, float min_weight)
{
	double* coef = new double[4]{ 0,0,0,0 };
	int ssd = arr[0].SSD;
	float price = arr[0].Price;
	float diag = arr[0].Diagonal;
	float weight = arr[0].Weight;

	for (int i = 0; i < 4; i++)
	{
		cout << float(min_ssd) / arr[i].SSD << " % " << arr[i].SSD << " GB" << " ID: " << arr[i].Id << "\n";
		coef[i] += double(min_ssd) / double(arr[i].SSD);
		cout << coef[i];
	}
	for (int i = 0; i < 4; i++)
	{

		cout << min_price / arr[i].Price << " % " << arr[i].Price << " HRN " << " ID: " << arr[i].Id << "\n";
		coef[i] += min_price / arr[i].Price;
		cout << coef[i] << "\n";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << min_diag / arr[i].Diagonal << " % " << arr[i].Diagonal << " INCH " << " ID: " << arr[i].Id << "\n";
		coef[i] += min_diag / arr[i].Diagonal;
		cout << coef[i] << "\n";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << min_weight / arr[i].Weight << " % " << arr[i].Weight << "KG " << " ID: " << arr[i].Id << "\n";
		coef[i] += min_weight / arr[i].Weight;
		cout << coef[i] << "\n";
	}
	for (int i = 0; i < 4; i++)
	{
		coef[i] = coef[i] / 4;
		cout << coef[i] << "\n";
	}

	return coef;
}

void WriteToFile()
{
	Notebook Asus = { Asus.Id = 1,Asus.SSD = 1000,Asus.Price = 28700.50,Asus.Diagonal = 17,Asus.Weight = 3.50 };
	Notebook Accer = { Accer.Id = 2,Accer.SSD = 500,Accer.Price = 16700.50,Accer.Diagonal = 17.5,Accer.Weight = 5.50 };
	Notebook HP = { HP.Id = 3,HP.SSD = 756,HP.Price = 21450.50,HP.Diagonal = 15.7,HP.Weight = 4.50 };
	Notebook Samsung = { Samsung.Id = 4,Samsung.SSD = 1000,Samsung.Price = 29700.50,Samsung.Diagonal = 19.5,Samsung.Weight = 5.50 };
	Notebook* ideal = new Notebook[4]{ Asus,Accer,HP,Samsung };

	ofstream out;	// поток для записи
	out.open("Ideal.txt");	// окрываем файл для записи
	if (out.is_open())
	{
		out << "Ideal SSD : " << Ssd_method(ideal) << "\tIdeal Price : " << Price_method(ideal) << "\tIdeal Diagonal : " << Diagonal_method(ideal) << "\tIdeal Weight : " << Weight_method(ideal) << "\n";
		for (int i = 0; i < 4; i++)
		{
			out << "Ideal coef " << Coeficient(ideal, Ssd_method(ideal), Price_method(ideal), Diagonal_method(ideal), Weight_method(ideal))[i] << "%\n";
		}
	}
}

void ReadData()
{
	string line;

	ifstream in("Ideal.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << "\n";
		}
	}
	in.close();	// закрываем файл

}

void ReadFileNotebooks()
{
	ifstream file("Notebooks.txt");
	if (file.is_open())
	{
		cout << "Файл открыт." << "\n";

		string line;

		while (getline(file, line))
		{
			string name;
			float id, ssd, price, diag, weight;

			istringstream iss(line);

			iss >> id >> name >> ssd >> price >> diag >> weight;

			cout << "Данные из строчки:" << endl;
			cout << "\tID: " << id << endl;
			cout << "\tBrand: " << name << endl;
			cout << "\tSSD: " << ssd << endl;
			cout << "\tPrice: " << price << endl;
			cout << "\tDiagonal: " << diag << endl;
			cout << "\tWeight: " << weight << endl;

			/*----------------------------------*/
			Notebook Asus = { Asus.Id = id, Asus.SSD = ssd, Asus.Price = price, Asus.Diagonal = diag, Asus.Weight = weight };
			Notebook Accer = { Accer.Id = id, Accer.SSD = ssd, Accer.Price = price, Accer.Diagonal = diag, Accer.Weight = weight };
			Notebook HP = { HP.Id = id, HP.SSD = ssd, HP.Price = price, HP.Diagonal = diag, HP.Weight = weight };
			Notebook Samsung = { Samsung.Id = id, Samsung.SSD = ssd, Samsung.Price = price, Samsung.Diagonal = diag, Samsung.Weight = weight };
			Notebook* ideal = new Notebook[4] { Asus, Accer, HP, Samsung };

			ofstream out;          // поток для записи
			out.open("Ideal.txt"); // окрываем файл для записи
			if (out.is_open())
			{
				out << "Ideal SSD : " << Ssd_method(ideal) << "\tIdeal Price : " << Price_method(ideal) << "\tIdeal Diagonal : " << Diagonal_method(ideal) << "\tIdeal Weight : " << Weight_method(ideal) << "\n";
				for (int i = 0; i < 4; i++)
				{
					out << "Ideal coef " << Coeficient(ideal, Ssd_method(ideal), Price_method(ideal), Diagonal_method(ideal), Weight_method(ideal))[i] << "%\n";
				}
			}
			/*----------------------------------*/
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Notebook Asus = { Asus.Id = 1,Asus.SSD = 1000,Asus.Price = 28700.50,Asus.Diagonal = 17,Asus.Weight = 3.50 };
	Notebook Accer = { Accer.Id = 2,Accer.SSD = 500,Accer.Price = 16700.50,Accer.Diagonal = 17.5,Accer.Weight = 5.50 };
	Notebook HP = { HP.Id = 3,HP.SSD = 756,HP.Price = 21450.50,HP.Diagonal = 15.7,HP.Weight = 4.50 };
	Notebook Samsung = { Samsung.Id = 4,Samsung.SSD = 1000,Samsung.Price = 29700.50,Samsung.Diagonal = 19.5,Samsung.Weight = 5.50 };
	Notebook* ideal = new Notebook[4]{ Asus,Accer,HP,Samsung };

	cout << "Ideal SSD : " << Ssd_method(ideal) << "\tIdeal Price : " << Price_method(ideal) << "\tIdeal Diagonal : " << Diagonal_method(ideal) << "\tIdeal Weight : " << Weight_method(ideal) << "\n";
	cout << "Ideal coef " << Coeficient(ideal, Ssd_method(ideal), Price_method(ideal), Diagonal_method(ideal), Weight_method(ideal)) << "%\n";


	ReadFileNotebooks();
}