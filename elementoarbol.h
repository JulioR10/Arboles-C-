#ifndef ELEMENTOARBOL_H
#define ELEMENTOARBOL_H

#include "tipodato.h"
#include <vector>
#include <memory>

class ElementoArbol
{
public:
    // Members
    TipoDato dato;
    std::vector<std::shared_ptr<ElementoArbol>> children;
public:
    // Constructor
    ElementoArbol(const TipoDato& dato_);
};

#endif // ELEMENTOARBOL_H
