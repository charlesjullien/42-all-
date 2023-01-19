#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
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

	Bureaucrat();
	explicit Bureaucrat(const std::string name);
	explicit Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	int getGrade() const;
	const std::string& getName() const;
	void rise_grade();
	void lower_grade();
	void signForm(Form &form);

	void executeForm(const Form &form);//ajouté par rapport au 01

	
	private:

	const std::string _name;
	int _grade;
	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &a);

#endif
