#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include "mensagem.h"

class CanalTexto{
	private:
		std::string nome; //<! nome do canal de texto
		std::vector<Mensagem> mensagem; //<! vetor com as mensagens
	public:

		/*! Adiciona um objeto mensagem no vetor de Mensagens 
			@param mensagem, mensagem a ser armazenada
		*/
		void adicionaMensagem(Mensagem mensagem);

		/*! Recuperar o nome do canal de texto
			@return uma string com o nome do canal
		*/
		std::string getNomeCanal();

		/*! Adicionar o nome do canal ao objeto
			@param nome com o nome que deseja dar ao canal
		*/
		void setNomeCanal(std::string nome);

};

#endif
