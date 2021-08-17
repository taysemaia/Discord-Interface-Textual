#include "../include/servidor.h"
using namespace std;
#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>


bool Servidor::canalExistente(std::string nome){
	for(auto &elem : canaisTexto){
    	if(elem.getNomeCanal() == nome){
    		return true;
    	}
  	}
  	return false;
}

void Servidor::listarCanais(){
	for(auto &elem : canaisTexto){
    	cout << elem.getNomeCanal() << endl; 
  	}
}

bool Servidor::usuarioParticipante(int id){
	for (auto &elem : participantesIDs){
		if (elem == id){

		    return true;
		}
	}
	return false;
}

void Servidor::removeParticipante(int id){
	for(auto itr = participantesIDs.begin(); itr != participantesIDs.end(); itr++){
	    if(*itr == id){
	      participantesIDs.erase(itr);
	      break;
	    }
  	}
}
void Servidor::adicionaCanal(CanalTexto canal){
	canaisTexto.push_back(canal);
}

void Servidor::adicionaID(int id){
	participantesIDs.push_back(id);
}

int Servidor::getUserID() const{
	return usuarioDonoID;
}

	
void Servidor::setUserID(int id_){
	usuarioDonoID = id_;
}

std::string Servidor::getNomeServer() const{
	return nome;
}

void Servidor::setNomeServer(std::string nome_){
	nome = nome_;
}

std::string Servidor::getServerDescricao() const{
	return descricao;
}


void Servidor::setServerDescricao(std::string desc){
	descricao = desc;
}


std::string Servidor::getInviteCode() const{
	return codigoConvite;
}

void Servidor::setInviteCode(std::string code){
	codigoConvite = code;
}