#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    // Nivel 3
    Tree g{TipoDato{"g"}};

    /*
    g
    */

    // Nivel 2
    Tree e{TipoDato{"e"}};
    Tree f{TipoDato{"f"}};
    f.add_subtree(g);

    /*
    e
    f-g
    */

    // Nivel 1
    Tree b{TipoDato{"b"}};
    Tree c{TipoDato{"c"}};
    Tree d{TipoDato{"d"}};
    c.add_subtree(e);
    c.add_subtree(f);

    /*
      e
     /
    c
     \
      f-g
    */

    // Nivel 0
    Tree a{TipoDato{"a"}};
    a.add_subtree(b);
    a.add_subtree(c);
    a.add_subtree(d);

    /*
      d e
     / /
    a-c
     \ \
      b f-g
    */

    // Get some properties
    std::cout << "Altura: " << a.height() << std::endl;
    std::cout << "Tamaño/peso: " << a.size() << std::endl;
}
