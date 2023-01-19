#include "../includes/Form.hpp"

Form::Form() : _name("Unknown"), _grade_required_to_execute(150), _grade_required_to_sign(150), _is_signed(false), _target("Unnamed target")
{
	
}

Form::Form(const std::string name) : _name(name), _grade_required_to_execute(150), _grade_required_to_sign(150), _is_signed(false), _target("Unnamed target")
{
	
}

Form::Form(int grade_required_to_sign, int grade_required_to_execute) : _name("Unknown"),
_grade_required_to_execute(grade_required_to_execute), _grade_required_to_sign(grade_required_to_sign), _is_signed(false), _target("Unnamed target")
{
	if (grade_required_to_sign > 150 || grade_required_to_execute > 150)
	{
		throw GradeTooLowException("Constructor exception : grade is too low... (beyond 150)");
	}
	if (grade_required_to_sign < 1 || grade_required_to_execute < 1)
	{
		throw GradeTooHighException("Constructor exception : grade is too high... (below 1)");
	}
}

Form::Form(const std::string name, int grade_required_to_sign, int grade_required_to_execute) : _name(name),
_grade_required_to_execute(grade_required_to_execute), _grade_required_to_sign(grade_required_to_sign), _is_signed(false), _target("Unnamed target")
{
	if (grade_required_to_sign > 150 || grade_required_to_execute > 150)
	{
		throw GradeTooLowException("Constructor exception : grade is too low... (beyond 150)");
	}
	if (grade_required_to_sign < 1 || grade_required_to_execute < 1)
	{
		throw GradeTooHighException("Constructor exception : grade is too high... (below 1)");
	}
}

Form::Form(const std::string name, int grade_required_to_sign, int grade_required_to_execute, const std::string target) :
_name(name), _grade_required_to_execute(grade_required_to_execute), _grade_required_to_sign(grade_required_to_sign), _is_signed(false), _target(target)
{
	if (grade_required_to_sign > 150 || grade_required_to_execute > 150)
	{
		throw GradeTooLowException("Constructor exception : grade is too low... (beyond 150)");
	}
	if (grade_required_to_sign < 1 || grade_required_to_execute < 1)
	{
		throw GradeTooHighException("Constructor exception : grade is too high... (below 1)");
	}
}

Form::Form(const Form &other) : _name(other.getName()), _grade_required_to_execute(other.get_grade_required_to_execute()),
_grade_required_to_sign(other.get_grade_required_to_sign()), _is_signed(false), _target(get_target())
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	_is_signed = other.get_is_signed();
	return (*this);
}

const std::string& Form::getName() const
{
    return (_name);
}

bool Form::get_is_signed() const
{
	return (_is_signed);
}

int Form::get_grade_required_to_sign() const
{
	return (_grade_required_to_sign);
}

int Form::get_grade_required_to_execute() const
{
	return (_grade_required_to_execute);
}

const std::string& Form::get_target() const
{
	return (_target);
}

void Form::BeSigned(Bureaucrat &b)
{
	if (_is_signed)
    {
        return ;
    }
    if (b.getGrade() > _grade_required_to_sign) // > car + le grade est élévé, plus il est bas dans la hiérarchie
    {
        throw GradeTooLowException("Bureaucrat cannot sign as his grade is no sufficient (BeSigned exception)");
    }
    _is_signed = true;
}


std::ostream& operator<<(std::ostream& os, const Form &a)
{
    os << "name = " << a.getName() << "\nSigned state = " << a.get_is_signed() << "\nGrade required to sign = "<< a.get_grade_required_to_sign() << "\nGrade required to execute = "<< a.get_grade_required_to_execute() << "\nTarget = " << a.get_target() << std::endl;
    return (os);
}

Form::GradeTooHighException::GradeTooHighException(const char *error) : _error(error)
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return (_error);
}

Form::GradeTooLowException::GradeTooLowException(const char *error) : _error(error)
{

}

const char* Form::GradeTooLowException::what() const throw()
{
    return (_error);
}

void Form::execute(const Bureaucrat& executor) const
{
    if (_is_signed == false)
    {
        throw std::runtime_error("Form is not signed... cannot execute.");
    }
    if (_grade_required_to_execute < executor.getGrade())
    {
        throw std::runtime_error("Grade is too low... cannot execute.");
    }
    action();
}

Form::~Form()
{
	
}

