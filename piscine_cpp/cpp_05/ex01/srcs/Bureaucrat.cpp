#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(int grade) : _name("Unknown"), _grade(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException("Constructor exception : grade is too low... (beyond 150)");
	}
	else if (grade < 1)
	{
		throw GradeTooHighException("Constructor exception : grade is too high... (below 1)");
	}
}
	
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
	{
		throw GradeTooLowException("Constructor exception : grade is too low... (beyond 150)");
	}
	else if (grade < 1)
	{
		throw GradeTooHighException("Constructor exception : grade is too high... (below 1)");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other.getGrade();
	return (*this);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

const std::string& Bureaucrat::getName() const
{
    return (_name);
}

void Bureaucrat::rise_grade()
{
	if (_grade == 1)
	{
		throw GradeTooHighException("Cannot rise Bureaucrat's grade any further... current grade == 1");
	}
	_grade = _grade - 1;
}

void Bureaucrat::lower_grade()
{
	if (_grade == 150)
	{
		throw GradeTooLowException("Cannot lower Bureaucrat's grade any further... current grade == 150");
	}
	_grade = _grade + 1;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.get_is_signed() == true)
	{
		std::cout << _name << " cannot sign because form has already been signed." << std::endl;
	}
	if (form.get_grade_required_to_sign() < _grade)
	{
		std::cout << _name << " cannot sign because his grade is too low." << std::endl;
	}
	else
	{
		std::cout << _name << " signs " << form.getName() << std::endl;
		form.BeSigned(*this);
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *error)
{
	_error = error;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (_error);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *error)
{
	_error = error;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (_error);
}

Bureaucrat::~Bureaucrat()
{
	
}