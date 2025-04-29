#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
	virtual ~Base();  // Destrutor virtual necessário para RTTI funcionar corretamente
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// Gera um ponteiro para um dos tipos A, B ou C, aleatoriamente
Base* generate(void);

// Identifica o tipo real do objeto usando ponteiro
void identify(Base* p);

// Identifica o tipo real do objeto usando referência
void identify(Base& p);

#endif // IDENTIFY_HPP
