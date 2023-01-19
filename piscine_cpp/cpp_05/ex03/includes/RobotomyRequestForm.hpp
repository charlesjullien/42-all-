#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Form.hpp"


class RobotomyRequestForm : public Form
{
	public:

	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	explicit RobotomyRequestForm(const std::string target);


	private:

	virtual void action() const;

};

#endif
