#include "lista_simples.h"

lista_simples::lista_simples(){
	ptrPrimeiro = NULL;
}

lista_simples::~lista_simples(){
	no1* ptrAux;
	while(ptrPrimeiro != NULL){
		ptrAux = ptrPrimeiro;
		ptrPrimeiro = ptrPrimeiro->getNext();
		delete ptrAux;
	}
}

bool lista_simples::estaNaLista(elemento ele){
	no1 *ptrAux;
	if(ptrPrimeiro == NULL)
	return false;
	else{
	ptrAux = ptrPrimeiro;
	while(ptrAux != NULL)
		if(ptrAux->getInfo() == ele){
		return true;                          
		} else
			ptrAux = ptrAux->getNext();
	}
	return false;
}

bool lista_simples::vazia(){
	if (ptrPrimeiro == NULL)
		return true;
	else
		return false;
}

void lista_simples::insereElemento(elemento ele){
	if (ptrPrimeiro == NULL){
		ptrPrimeiro = new no1;
		ptrPrimeiro->setInfo(ele);
	} else {
		no1 *ptrUltimo;
		no1 *ptrAux;
		ptrUltimo = ptrPrimeiro;
		while(ptrUltimo->getNext() != NULL)
			ptrUltimo = ptrUltimo->getNext();
		ptrAux = new no1;
		ptrAux->setInfo(ele);
		ptrAux->setNext(NULL);
		ptrUltimo->setNext(ptrAux);
	}
}

bool lista_simples::removeElemento(elemento ele){
	no1 *ptrAux = NULL;
	no1 *ptrAuxAnterior = NULL;
	if(ptrPrimeiro == NULL)
		return false;
	else {
		if(ptrPrimeiro->getInfo() == ele){
			ptrAux = ptrPrimeiro->getNext();
			delete ptrPrimeiro;
			ptrPrimeiro = ptrAux;;
			return true;
		} else {
			ptrAux = ptrPrimeiro;
			ptrAuxAnterior = NULL;
			while((ptrAux->getInfo() != ele) && (ptrAux->getNext()!=NULL)){
				ptrAuxAnterior = ptrAux;
				ptrAux = ptrAux->getNext();
			}
 		}
	}
	
	if(ptrAux->getInfo() == ele){
		ptrAuxAnterior->setNext(ptrAux->getNext());
		delete ptrAux;
		return true;
	}
	
	return false;
}

void lista_simples::printAll(){
	no1* no = ptrPrimeiro;
	cout << no->getInfo() << " ";
	while(no->getNext() != NULL){
		no = no->getNext();
		cout << no->getInfo() << " ";
	}
	cout << endl;
}
	
