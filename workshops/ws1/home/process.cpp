#include <iostream>
#include "String.h"

namespace sdds
{
	void process(const char* str)
	{
		String a = String(str);
		std::cout << a << std::endl;
	}
}