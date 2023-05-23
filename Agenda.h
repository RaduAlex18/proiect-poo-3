#pragma once
#include <vector>
#include <string>
#include <typeinfo>
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Romania.h"
#include "Abonat_Skype_Extern.h"

template<typename T>
class Agenda{
private:
	std::vector <std::shared_ptr<T>> lista;
	static int nr_abonati;

public:
	Agenda()=default;

	template<typename Abonati>
	Agenda& operator+=(const Abonati& other);
	//Agenda& operator+=(const Abonat_Skype_Romania& other);
	//Agenda& operator+=(const Abonat_Skype& other);
	//Agenda& operator+=(const Abonat& other);
	void operator[](const std::string);
	static int get_nr_abonati();
	void agenda();
	~Agenda()=default;

	
	//friend std::ostream& operator<<(std::ostream& os, const Agenda& data);
};

class abonati_factory {
public:
	static Abonat abonat() { return Abonat("07344444444", 01, "Smiley"); }
	static Abonat_Skype abonat_skype() { return Abonat_Skype("123", "071349234", 02, "iM"); }
	static Abonat_Skype_Romania abonat_skype_Romania() { return Abonat_Skype_Romania("blablabla@yahoo.ceva", "999", "079831234", 03, "Jaxi"); }
	static Abonat_Skype_Extern abonat_skype_Extern() { return Abonat_Skype_Extern("SUA", "100", "3190384210", 10, "6ix9ine"); }
};


#include "Agenda1.cpp.h"