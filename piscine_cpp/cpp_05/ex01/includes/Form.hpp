#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

	//Exception grade too high
	class GradeTooHighException : public std::exception
    {
    private:
        const char *_error;

    public:
        explicit GradeTooHighException(const char *error);
        virtual const char* what() const throw();
    };


	//Exception grade too low
    class GradeTooLowException : public std::exception
    {
    private:
        const char *_error;

    public:
        explicit GradeTooLowException(const char *error);
        virtual const char* what() const throw();
    };

	Form();
	explicit Form(const std::string name);
	Form(int grade_required_to_sign, int grade_required_to_execute);
	Form(std::string name, int grade_required_to_sign, int grade_required_to_execute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	int get_grade_required_to_execute() const;
	int get_grade_required_to_sign() const;
	bool get_is_signed() const;
	const std::string& getName() const;
	
	void BeSigned(Bureaucrat &b);
	
	private:

	const std::string _name;
	const int _grade_required_to_sign;
	const int _grade_required_to_execute;
	bool _is_signed;
	
};

std::ostream& operator<<(std::ostream& os, const Form &a);

#endif
