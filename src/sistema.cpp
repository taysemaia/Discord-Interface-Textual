#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int id_ = -1;
std::string servidorVisualizado = "";
std::string canalVisualizado = "";

std::pair<std::string, std::string> pair1(servidorVisualizado, canalVisualizado);
std::pair<std::string, std::string> pair2(servidorVisualizado, canalVisualizado);


std::vector<Usuario> Sistema::getUsuarios() const{

  return usuarios;
}

bool Sistema::UsuarioLogado(int id)
{
  std::map<int, std::pair<std::string, std::string>>::iterator it;
  it = usuariosLogados.find(id);

  if (it == usuariosLogados.end())
  {
    return false;
  }
  return true;
}


void Sistema::adicionarAosLogados(int idLogado)
{
  usuariosLogados.insert({idLogado, (pair1)});
}


bool Sistema::buscaEmail(std::string email)
{

  for (auto &elem : usuarios)
  {
    if (elem.getEmail() == email)
    {

      return false;
    }
  }

  return true;
}


bool Sistema::buscaSenhaEmail(std::string senha, std::string email)
{

  for (auto &elem : usuarios)
  {
    if (elem.getEmail() == email && elem.getSenha() == senha)
    {
      adicionarAosLogados(elem.getID());
      return true;
    }
  }

  return false;
}


bool Sistema::buscaNomeServidor(std::string nome)
{

  for (auto &elem : servidores)
  {
    if (elem.getNomeServer() == nome)
    {
      return true;
    }
  }

  return false;
}


string Sistema::quit()
{
  return "Saindo do Concordo...";
}


string Sistema::create_user(const string email, const string senha, const string nome)
{

  if (!buscaEmail(email))
  {

    return "Usuário já existe!";
  }
  else
  {

    Usuario usuario;
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setNome(nome);
    id_++;
    usuario.setID(id_);
    usuarios.push_back(usuario);

    return "Usuário criado com sucesso!";
  }
}


string Sistema::login(const string email, const string senha)
{
  if (buscaSenhaEmail(senha, email))
  {
    return email + " logado(a) com sucesso!";
  }
  else
  {
    return "Senha ou usuário inválidos!";
  }
}


string Sistema::disconnect(int id)
{

  if (!UsuarioLogado(id))
  {
    return "Usuário(a) não está logado(a)!";
  }

  usuariosLogados.erase(id);
  return "Usuário desconectado(a)!";
}

string Sistema::create_server(int id, const string nome)
{
  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  if (buscaNomeServidor(nome))
  {
    return "Servidor com esse nome já existente!";
  }

  Servidor servidor;
  servidor.setUserID(id);
  servidor.setNomeServer(nome);
  servidores.push_back(servidor);
  return "Servidor criado!";
}


string Sistema::set_server_desc(int id, const string nome, const string descricao)
{
	if(!UsuarioLogado(id)){
		return "Usuário não está logado.";
	}

  for (auto &itr : servidores)
  {
    if (itr.getNomeServer() == nome && itr.getUserID() == id)
    {
      itr.setServerDescricao(descricao);
      return "Descrição do servidor alterada!";
    }
    else if (!buscaNomeServidor(nome))
    {
      return "Servidor não existe!";
    }
  }
  return "Você não pode alterar a descrição de um servidor que não foi criado por você";
}


string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{
	if(!UsuarioLogado(id)){
		return "Usuário não está logado.";
	}

  for (auto &elem : servidores)
  {
    if (elem.getNomeServer() == nome && elem.getUserID() == id && codigo.length() != 0)
    {
      elem.setInviteCode(codigo);
      return "Código de convite do servidor modificado";
    }
  }
  //alguma coisa ficou faltando aqui
  return "Código de convite do servidor removido";
}


string Sistema::list_servers(int id){ 
  int i = 0;
  cout << "Listando Servidores:" << endl;
  cout << "--------------------" << endl; 
  for (auto &elem : servidores){
    i++;
    cout <<"Servidor" << i << " : " << elem.getNomeServer() << endl;
  }

  return "--------------------";
}


string Sistema::remove_server(int id, const string nome)
{
 
  for (auto itr = servidores.begin(); itr != servidores.end(); itr++)
  {
    if (itr->getNomeServer() == nome && itr->getUserID() == id)
    {
      cout<<"Apagando servidor "<<itr->getNomeServer()<< endl;
      servidores.erase(itr);
      return "Servidor apagado!";
    }
  }

  return "Você não pode apagar este servidor";
}


string Sistema::enter_server(int id, const string nome, const string codigo){

  if (!UsuarioLogado(id)){
    return "Usuário não está logado"; 
  }

  if(!buscaNomeServidor(nome)){
    return "Servidor não existente";
  }

  //procurar se ele já é participante

  for(auto &elem : servidores){ 

    if(elem.getNomeServer() == nome && elem.getUserID() == id){ // se o usuario for dono do servidor
      
      if (elem.usuarioParticipante(id)){ // SE O DONO JA ESTIVER NA LISTA DE IDS

        usuariosLogados.at(id).first = nome;
        return "Entrou no servidor com sucesso!";

      }
      //SE NAO ESTIVER NA LISTA DE IDS
      elem.adicionaID(id);
      usuariosLogados.at(id).first = nome;  
      return "Entrou no servidor com sucesso!";
    }
    // SE NAO FOR O DONO DO SERVIDOR E TIVER TUDO CERTO
    else if(elem.getNomeServer() == nome && elem.getInviteCode() == codigo){  // se o codigo for vazio ou tiver um codigo certo
      
      usuariosLogados.at(id).first = nome; // adiciona a tabela de usuarios logados o nome do servidor sendo visualizado
      
      if(elem.usuarioParticipante(id)){ // se ele ja participa nao precisa adicionar ID ao vetor
        return "Entrou no servidor com sucesso!";
      }

      elem.adicionaID(id);

      return "Entrou no servidor com sucesso!";
    }
  }

  return "Código não correspondente ao Servidor que deseja entrar!";

}


string Sistema::leave_server(int id, const string nome){

  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == nome){

      if (!elem.usuarioParticipante(id)){
        return "Usuário não participa deste servidor!"; 
      }
      usuariosLogados.at(id).first = ""; 
      elem.removeParticipante(id); 
      return "Saindo do servidor!";
    } 
  }

  return "Servidor Inexistente!"; 
}


string Sistema::list_participants(int id){

  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  std::string servidor_ = usuariosLogados.at(id).first;

  if(servidor_ == ""){

    return "O usuário não está visualizando nenhum servidor!";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){ // se o nome do servidor sendo visualizado é o servidor elem
      cout << "#Lista de Participantes: " << endl;

      for(auto &i : usuarios){ // percorrendo o vetor de usuarios

        if(!elem.usuarioParticipante(i.getID())){

          return "Este usuário não está no servidor!";
        } // a cada usuario do vetor, ver se ele participa do servidor
      
        cout <<  i.getNome() << endl;
      }

    } 
  }

  return "-------------------------";
}


string Sistema::list_channels(int id) {
  if (!UsuarioLogado(id)){
    return "O usuário não está logado!";
  }

  std::string servidor_ = usuariosLogados.at(id).first;

  if(servidor_ == ""){

    return "O usuário não está visualizando nenhum servidor!";
  }
  cout << "#Canais de texto do servidor "<< servidor_ << endl;
  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){
      elem.listarCanais(); //listar canais do servidor elem
      return "------------------";
    } 
  }
  return "";
}


string Sistema::create_channel(int id, const string nome){

  if(!UsuarioLogado(id)){
    return "O usuário não está logado";
  }

  std::string servidor_ = usuariosLogados.at(id).first;

  if(servidor_ == ""){
    return "O usuário não está visualizando nenhum servidor";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){
      if(elem.canalExistente(nome)){
        return "Canal já existe!";
      }
      CanalTexto canal;
      canal.setNomeCanal(nome);
      elem.adicionaCanal(canal);
      return "Canal " + nome + " adicionado";
    }
  }

  return "";
}


string Sistema::enter_channel(int id, const string nome){

  if(!UsuarioLogado(id)){
    return "O usuário não está logado";
  }

  std::string servidor_ = usuariosLogados.at(id).first;

  if(servidor_ == ""){
    return "O usuário não está visualizando nenhum servidor";
  }

  for(auto &elem : servidores){
    if(elem.getNomeServer() == servidor_){

      if(!elem.canalExistente(nome)){
        return "Este canal não existe!";
      }

      usuariosLogados.at(id).second = nome;
      return "Entrou no canal " + nome;
    }
  }
  return "";
}


string Sistema::leave_channel(int id)
{
  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  std::string nomeCanal = usuariosLogados.at(id).second;

  if(nomeCanal == ""){
    return "O usuário não está em nenhum Canal de texto!";
  }

  usuariosLogados.at(id).second = ""; 

  return "Saindo do canal...";
  
}


string Sistema::send_message(int id, const string mensagem){

  if(!UsuarioLogado(id)){
    return "Usuário não está logado!";
  }

  std::string nomeCanal = usuariosLogados.at(id).second;

  if(nomeCanal == ""){
    return "O usuário não está em nenhum Canal de texto e você não pode enviar mensagens!";
  }

  /*std::string servidor_ = usuariosLogados.at(id).first;


  for(auto &elem : servidores){
    
  }

  Mensagem msg;
  msg.setEnviadaPor(id);
  msg.setConteudo(mensagem);
  //como adicionar no vetor de mensagens que é de canal de texto?
  */

  return "";
}

/*! Lista as mensagem no canal que o usuário com id passado está visualizando.
				@param id um id válido de algum usuário cadastrado e logado no sistema.
				@return uma string vazia em caso de sucesso ou uma mensagem de erro em caso de falha.
		*/
string Sistema::list_messages(int id)
{
  
  return "";
}

