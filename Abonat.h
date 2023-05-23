#pragma once
#include <string>
#include "Persoana.h"

class Abonat : public Persoana {
protected:
	std::string nr_telefon;

	friend class abonat_builder;

public:
	Abonat();
	Abonat(const std::string& other_nr_telefon,const int other_id, const std::string& other_nume);
	Abonat(const std::string& other_nr_telefon, const Persoana& data);
	Abonat(const Abonat& other);
	Abonat(Abonat&& other);
	Abonat& operator=(const Abonat& other);
	virtual void Afis() override;
	virtual std::string get_Nume();
	virtual ~Abonat();

	friend std::ostream& operator<<(std::ostream& os, const Abonat& data);
	friend std::istream& operator>>(std::istream& is, Abonat& data);
};

class abonat_builder {
protected:
	Abonat a;
public:
	abonat_builder() = default;

	abonat_builder& nr_telefon(const std::string& val1) {
		a.nr_telefon = val1;
		return *this;
	}

	abonat_builder& id(int id) {
		a.id = id;
		return *this;
	}

	abonat_builder& nume(const std::string& val2) {
		a.nume = val2;
		return *this;
	}

	Abonat build() {
		return a;
	}
};