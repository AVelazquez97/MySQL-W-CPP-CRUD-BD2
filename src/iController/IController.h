#ifndef ICONTROLLER_H_
#define ICONTROLLER_H_

#include <ctime>
#include <iostream>

using namespace std;

#include "../datatypes/DTBook.h"

// Esta sería la interfaz que realiza las operaciones del BookController
class IController {
    private: 

    public:
        virtual ~IController();

		// En esta sección se definen todas las operaciones que están definidas en el controlador. 
		// Deben ser virtuales e igualadas a 0
        virtual void insertABook() = 0;
        virtual void deleteABook() = 0;
        virtual void updateABook() = 0;
        virtual DTBook viewABook() = 0;
	    virtual DTBook** viewAllBooks() = 0;
};

#endif // ICONTROLLER_H_