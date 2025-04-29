#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include <string>

typedef unsigned long uintptr_t;

struct Data
{
	int			num;
	std::string	str;
};

class Serialize {
	private:
		Serialize(); // não instanciável
		Serialize(const Serialize&);
		Serialize& operator=(const Serialize&);
		~Serialize();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif