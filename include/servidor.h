#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "canaltexto.h"
#include <string>
#include <vector>


class Servidor
{
	private: 
		
		int usuarioDonoID; //<! id do usuario 
		std::string nome, codigoConvite, descricao; //<! nome do servidor, codigo de convite e descrição 
		std::vector<CanalTexto> canaisTexto; //<! vetor de canais de texto 
		std::vector<int> participantesIDs; //<! vetor com id dos participantes
		
	public:
		/*! Busca se o nome do canal passado como parametro existe
			@param nome o nome a ser buscado
			@return true se for achado, false se não
		*/
		bool canalExistente(std::string nome);

		/*! listar os nomes dos canais naquele servidor
		 * 
		*/
		void listarCanais();

		/*! Busca se o usuário participa deste servidor
			@param id id do usuário a ser buscado
			@return true se for participante, false se não
		*/
		bool usuarioParticipante(int id);

		/*! Remove o ID do usuário da lista de participantes do server
			@param id com o ID a ser removido
		*/
		void removeParticipante(int id);

		/*! adiciona usuario com o ID a lista de participantes do servidor
			@param id com o id a ser adicionado
		*/
		void adicionaID(int id);

		/*! Adiciona um objeto canal ao vetor de canais de texto
			@param canal com o canal a ser adicionado
		*/
		void adicionaCanal(CanalTexto canal);

		/*! Retorna o ID do usuario
					@return retorna um int com id
			*/
		int getUserID() const;

		/*! Seta o ID do usuario como o id passado pelo parametro
			@param id_ a ser armazenado
		*/
		void setUserID(int id_);

		/*! Retorna o nome do servidor
				@return retorna uma string com nome do servidor
		*/
		std::string getNomeServer() const;

		/*! Seta o nome do servidor como o nome do servidor passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setNomeServer(std::string nome_);

		/*! Retorna a descrição do servidor
				@return retorna uma string com a descrição do servidor
		*/
		std::string getServerDescricao() const;

		/*! Seta a descrição servidor como a descrição servidor passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setServerDescricao(std::string desc);

		/*! Retorna o codigo de convite do servidor
				@return retorna uma string com o codigo de convite para o servidor
		*/
		std::string getInviteCode() const;

		/*! Seta o codigo de convite do servidor como o codigo de convite passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setInviteCode(std::string code);

};


#endif
