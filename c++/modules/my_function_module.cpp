// https://cppreference.com/w/cpp/language/modules.html
export module my_function_module;

import <iostream>;

export extern const double EXPORTED_CONST = 3.14159265359;

export void hello()
{
    std::cout << "Hello, world!" << std::endl;
}
