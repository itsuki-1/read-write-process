#include <iostream>
#include <cstdint>
#include <array>
#include <Windows.h>

int main()
{
    const int32_t arraySize{ 128 };

    int32_t varInt{ 123456 };
    
    std::string varString{ "DefaultString" };

    std::array<char, arraySize> arrChar{ "Long char array right here ->" };

    int32_t* ptr2int{ &varInt };

    int32_t** ptr2ptr{ &ptr2int };

    int32_t*** ptr2ptr2{ &ptr2ptr };


    // loop
    while (true)
    {
        std::cout << "Process ID: " << std::dec << GetCurrentProcessId() << '\n';

        std::cout << std::endl;

        std::cout << "varInt" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&varInt) << ") = " << std::dec << varInt << '\n';

        std::cout << "varString" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&varString) << ") = " << varString << '\n';

        std::cout << "arrChar" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(arrChar.data()) << ") = " << arrChar.data() << '\n'; // ~~void pointer means it can point to whatever the fuck it could~~ and the .data is simply get pointer to data from std::array

        std::cout << std::endl;

        std::cout << "ptr2int" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&ptr2int) << ") = 0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(ptr2int) << '\n';

        std::cout << "ptr2ptr" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&ptr2ptr) << ") = 0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(ptr2ptr) << '\n';

        std::cout << "ptr2ptr2" << '\t' << "(0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&ptr2ptr2) << ") = 0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(ptr2ptr2) << '\n';

        std::cout << std::endl;

        std::cout << "Press ENTER to print again. " << '\n';

        std::cin.get();

        std::cout << std::endl;

        std::cout << "------------------------------------" << '\n';

        std::cout << std::endl;
    }
    
    return 0;
}