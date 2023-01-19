#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
//les templates se mettent toujours dans le .hpp
template<typename T>//déclaration générique d'un template
void swap(T &t1, T &t2)//peu importe le type de t1 ou t2... char, int, double, char*... ca va fonctionner
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

template<typename T>
T min(T t1, T t2)
{
	if (t1 < t2)
		return t1;
	return t2;
}

template<typename T>
T max(T t1, T t2)
{
	if (t1 > t2)
		return t1;
	return t2;
}

#endif
