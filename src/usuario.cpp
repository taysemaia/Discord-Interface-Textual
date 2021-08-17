#include "../include/usuario.h"
using namespace std;
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>


int Usuario::getID() const
{
	return id;
}


void Usuario::setID(int id_)
{
	id = id_;
}


std::string Usuario::getNome() const
{
	return nome;
}

void Usuario::setNome(string nome_)
{
	nome = nome_;
}



std::string Usuario::getEmail() const
{
	return email;
}


void Usuario::setEmail(std::string email_)
{
	email = email_;
}


std::string Usuario::getSenha() const
{
	return senha;
}


void Usuario::setSenha(std::string senha_)
{
	senha = senha_;
}
