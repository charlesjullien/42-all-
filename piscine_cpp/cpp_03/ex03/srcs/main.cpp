#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main(int ac, char **av)
{
	ClapTrap Macron("Macron");
	std::cout << std::endl;
	ScavTrap Veran("Veran");
	FragTrap Castex("Castex");

	DiamondTrap Blanquer;
	Blanquer.highFivesGuys();
	Blanquer.guardGate();
	Blanquer.takeDamage(10);
	Blanquer.beRepaired(256);
	Blanquer.attack("Veran");
	Veran.takeDamage(7);
	Blanquer.whoAmI();
	Veran.attack("Blanquer");
	Blanquer.takeDamage(7);

	DiamondTrap Schiappa(Blanquer);
	
	std::cout << "Schiappa : " << std::endl;
	std::cout << "name: " << Schiappa.get_name() << std::endl;
    std::cout << "pairent name: " << Schiappa.get_parent_name() << std::endl;
    std::cout << "hitpoints: " << Schiappa.get_hp() << std::endl;
    std::cout << "energyPoints: " << Schiappa.get_mana() << std::endl;
    std::cout << "attackDamage: " << Schiappa.get_ad() << std::endl;

	std::cout << "\nBlanquer : " << std::endl;
	std::cout << "name: " << Blanquer.get_name() << std::endl;
    std::cout << "pairent name: " << Blanquer.get_parent_name() << std::endl;
    std::cout << "hitpoints: " << Blanquer.get_hp() << std::endl;
    std::cout << "energyPoints: " << Blanquer.get_mana() << std::endl;
    std::cout << "attackDamage: " << Blanquer.get_ad() << std::endl;

	DiamondTrap DM("Dupond-Moretti");
	DM.attack("Schiappa");
	Schiappa.takeDamage(100000);
	DM.attack("Schiappa");
	DM.attack("Schiappa");
	DM.attack("Schiappa");
	DM.attack("Schiappa");
	DM.attack("Schiappa");
	DM.whoAmI();
	std::cout << "\nDupont_Moretti : " << std::endl;
	std::cout << "name: " << DM.get_name() << std::endl;
    std::cout << "pairent name: " << DM.get_parent_name() << std::endl;
    std::cout << "hitpoints: " << DM.get_hp() << std::endl;
    std::cout << "energyPoints: " << DM.get_mana() << std::endl;
    std::cout << "attackDamage: " << DM.get_ad() << std::endl;


	Macron.attack("Castex");
	Castex.takeDamage(4);
	Macron.attack("Castex");
	Castex.takeDamage(2);
	Castex.beRepaired(3);
	Castex.beRepaired(3);

	Castex.highFivesGuys();

	Castex.attack("Véran");
	Veran.takeDamage(0);

	Veran.attack("Castex");
	Castex.takeDamage(10);
	Castex.beRepaired(1);

	Veran.guardGate();

	Macron.attack("Castex");
	Castex.takeDamage(10);
	Castex.beRepaired(10);


	std::cout << "\n\n\n" <<std::endl;


	FragTrap elon;

    std::cout << "Hit points = " << elon.get_hp() << std::endl;
    std::cout << "Energy points = " << elon.get_mana() << std::endl;
    std::cout << "Attack damages = " << elon.get_ad() << std::endl;
    elon.takeDamage(30);

    ClapTrap vlad(elon);
    vlad.takeDamage(30);

    ClapTrap emmanuel;
    emmanuel = vlad;
    emmanuel.takeDamage(30);

    ScavTrap jeff("jeff");
    jeff.attack("elon");
    jeff.takeDamage(40);
    elon.beRepaired(90);
    elon.highFivesGuys();


	return (0);	
}
