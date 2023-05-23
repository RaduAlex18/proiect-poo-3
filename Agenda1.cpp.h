#include "Agenda.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

/*
template<typename T>
Agenda<T>::Agenda()
{

}
*/

template<typename T>
template<typename Abonati>
Agenda<T>& Agenda<T>::operator+=(const Abonati& other)
{
	lista.push_back(std::make_shared<Abonati>(other));
	nr_abonati++;
	return *this;
}


/*
Agenda& Agenda::operator+=(const Abonat_Skype_Extern& other)
{
	lista.push_back(new Abonat_Skype_Extern(other));
	nr_abonati++;
	return *this;
}

Agenda& Agenda::operator+=(const Abonat_Skype_Romania& other)
{
	lista.push_back(new Abonat_Skype_Romania(other));
	nr_abonati++;
	return *this;
}

Agenda& Agenda::operator+=(const Abonat_Skype& other)
{
	lista.push_back(new Abonat_Skype(other));
	nr_abonati++;
	return *this;
}

Agenda& Agenda::operator+=(const Abonat& other)
{
	lista.push_back(new Abonat(other));
	nr_abonati++;
	return *this;
}
*/

template<typename T>
void Agenda<T>::operator[](const std::string nume)
{

	for (auto x : lista)
	{
		try
		{
			if (typeid(*x) == typeid(Abonat_Skype) && (std::dynamic_pointer_cast<Abonat_Skype>(x)->get_Nume() == nume))
			{
				std::shared_ptr<T> temp;
				temp = std::dynamic_pointer_cast<Abonat_Skype>(x);
				temp->Afis();
				throw nume;
			}

			if (typeid(*x) == typeid(Abonat_Skype_Romania) && (std::dynamic_pointer_cast<Abonat_Skype_Extern>(x)->get_Nume() == nume))
			{
				std::shared_ptr<T> temp;
				temp = std::dynamic_pointer_cast<Abonat_Skype_Extern>(x);
				temp->Afis();
				throw nume;
			}

			if (typeid(*x) == typeid(Abonat_Skype_Extern) && (std::dynamic_pointer_cast<Abonat_Skype_Extern>(x)->get_Nume() == nume))
			{
				std::shared_ptr<T> temp;
				temp = std::dynamic_pointer_cast<Abonat_Skype_Extern>(x);
				temp->Afis();
				throw nume;
			}

			if (typeid(*x) == typeid(Abonat) && (std::dynamic_pointer_cast<Abonat>(x)->get_Nume() == nume))
			{
				std::shared_ptr<T> temp;
				temp = std::dynamic_pointer_cast<Abonat>(x);
				temp->Afis();
				throw nume;
			}

		}
		catch (const std::string nume)
		{
			std::cout << "\n";
			std::cout << "Abonatul cu numele " << nume << " se afla in agenda noastra.\n";
			std::cout << "\n";
		}
	}

}

/*
template<typename T>
Agenda<T>::~Agenda()
{
}
*/

template<typename T>
int Agenda<T>::get_nr_abonati()
{
	return nr_abonati;
}

template<typename T>
void Agenda<T>::agenda()
{
	std::cout << " [ ";
	for (auto x : lista)
	{
		if (typeid(*x) == typeid(Abonat_Skype))
		{
			std::shared_ptr<T> temp;
			temp = std::dynamic_pointer_cast<Abonat_Skype>(x);
			temp->Afis();

		}

		if (typeid(*x) == typeid(Abonat_Skype_Romania))
		{
			std::shared_ptr<T> temp;
			temp = std::dynamic_pointer_cast<Abonat_Skype_Romania>(x);
			temp->Afis();
		}

		if (typeid(*x) == typeid(Abonat_Skype_Extern))
		{
			std::shared_ptr<T> temp;
			temp = std::dynamic_pointer_cast<Abonat_Skype_Extern>(x);
			temp->Afis();
		}

		if (typeid(*x) == typeid(Abonat))
		{
			std::shared_ptr<T> temp;
			temp = std::dynamic_pointer_cast<Abonat>(x);
			temp->Afis();
			//std::unique_ptr<Abonat> p(temp);
			//(p)->Afis();
		}

		std::cout << " | ";

	}

	std::cout << "]";
}
/*
std::ostream& operator<<(std::ostream& os, const Agenda& data)
{
	os << " [ ";
	for (auto x : data.lista)
	{
		if (typeid(*x) == typeid(Abonat_Skype))
		{
			Abonat* temp;
			temp = dynamic_cast<Abonat_Skype*>(x);
			temp->Afis();

		}

		if (typeid(*x) == typeid(Abonat_Skype_Romania))
		{
			Abonat* temp;
			temp = dynamic_cast<Abonat_Skype_Romania*>(x);
			temp->Afis();
		}

		if (typeid(*x) == typeid(Abonat_Skype_Extern))
		{
			Abonat* temp;
			temp = dynamic_cast<Abonat_Skype_Extern*>(x);
			temp->Afis();
		}

		if (typeid(*x) == typeid(Abonat))
		{
			Abonat* temp;
			temp = dynamic_cast<Abonat*>(x);
			temp->Afis();
			//std::unique_ptr<Abonat> p(temp);
			//(p)->Afis();
		}

		os << " | ";

	}

	os << "]";
	return os;
}
*/