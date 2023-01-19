#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main(int ac, char **av)
{
	const Animal* sample[4];

    for (int i = 0; i < 2; ++i)
    {
        sample[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i)
    {
        sample[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i)
    {
        delete sample[i];
    }

    Cat angora;
    Cat m_coone;
    angora.define_cat_ideas(0, "Meow");
    m_coone = angora;

    std::cout << std::endl;

    std::cout << "angora brain idea at index 0: " << angora.get_cat_ideas(0) << std::endl;
    std::cout << "m_coone brain idea at index 0: " << m_coone.get_cat_ideas(0) << std::endl;
    std::cout << "angora brain idea at index 0: " << &(angora.get_cat_ideas(0)) << std::endl;
    std::cout << "m_coone brain idea at index 0: " << &(m_coone.get_cat_ideas(0)) << std::endl;

    std::cout << std::endl;

    angora.define_cat_ideas(1, "RRRrrr");


    std::cout << "angora brain idea at index 1: " << angora.get_cat_ideas(1) << std::endl;
    std::cout << "m_coone brain idea at index 1: " << m_coone.get_cat_ideas(1) << std::endl;
    std::cout << "angora brain idea at index 1: " << &(angora.get_cat_ideas(1)) << std::endl;
    std::cout << "m_coone brain idea at index 1: " << &(m_coone.get_cat_ideas(1)) << std::endl;

     std::cout << std::endl;

    angora.define_cat_ideas(1, "Fffffffffft");
    m_coone.define_cat_ideas(1, "Meeeeeeeow");


    std::cout << "angora brain idea at index 1: " << angora.get_cat_ideas(1) << std::endl;
    std::cout << "m_coone brain idea at index 1: " << m_coone.get_cat_ideas(1) << std::endl;
    std::cout << "angora brain idea at index 1: " << &(angora.get_cat_ideas(1)) << std::endl;
    std::cout << "m_coone brain idea at index 1: " << &(m_coone.get_cat_ideas(1)) << std::endl;


	return (0);	
}
