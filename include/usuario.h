#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario{

	private:

		int id; //<! id do usuario 
		std::string nome, email, senha; //<! nome, email e senha do usuario

	public:

		/*! Retorna o ID do usuario
				@return retorna um int com id
		*/
		int getID() const;

		/*! Seta o ID do usuario como o id passado pelo parametro
			@param id_ a ser armazenado
		*/
		void setID(int id_);

		/*! Retorna o nome do usuario
				@return retorna uma string com nome do usuario
		*/
		std::string getNome() const;

		/*! Seta o nome do usuario como o nome passado pelo parametro
			@param nome_ a ser armazenado
		*/
		void setNome(std::string nome_);

		/*! Retorna o email do usuario
				@return retorna uma string com email do usuario
		*/
		std::string getEmail() const;

		/*! Seta o email do usuario como o email passado pelo parametro
			@param email_ a ser armazenado
		*/
		void setEmail(std::string email_);

		/*! Retorna a senha do usuario
				@return retorna uma string com a senha do usuario
		*/
		std::string getSenha() const;

		/*! Seta a senha do usuario como a senha passado pelo parametro
			@param senha_ a ser armazenado
		*/
		void setSenha(std::string senha_);



};

#endif
