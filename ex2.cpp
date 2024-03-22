#include <iostream>
#include <cstdint>
#include <Windows.h>
#include <string>
#include <array>
#include <vector>

template <typename T>

T dataRead(HANDLE hProcess, LPCVOID address, LPVOID pointer, SIZE_T dataSize, SIZE_T bytesRead)
{
    if (hProcess == NULL)
    {
	    std::cout << "OpenProcess failed. GetLastError = " << std::dec << GetLastError() << std::endl;

	    system("pause");

	    return EXIT_FAILURE;
    }
    else
    {
        std::cout << "OpenProcess success." << '\n';

        std::cout << std::endl;
    }

    T dataRead{};

    BOOL readProcess = ReadProcessMemory(hProcess, (LPCVOID)0xCDAA5FF8E8, &dataRead, sizeof(T), 0);

    if (readProcess == FALSE)
    {
        std::cout << "ReadProcessMemory failed. GetLastError = " << std::dec << GetLastError() << std::endl;

	    system("pause");

	    return EXIT_FAILURE;
    }
    else
    {
        std::cout << "ReadProcessMemory success." << '\n';

        std::cout << std::endl;
    }
    
    return dataRead;
}

template <typename U>

U dataWrite(HANDLE hProcess, LPVOID address, LPCVOID pointer, SIZE_T dataSize, SIZE_T bytesWrite, U dataOverride)
{
    if (hProcess == NULL)
    {
        std::cout << "OpenProcess failed. GetLastError = " << std::dec << GetLastError() << std::endl;

        system("pause");

        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "OpenProcess success." << '\n';

        std::cout << std::endl;
    }

    U dataWrite{ dataOverride };

    BOOL writeProcess = WriteProcessMemory(hProcess, (LPVOID)0xCDAA5FF8E8, &dataWrite, sizeof(U), 0);

    if (writeProcess == FALSE)
    {
        std::cout << "WriteProcessMemory failed. GetLastError = " << std::dec << GetLastError() << std::endl;

        system("pause");

        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "Data overrided." << '\n';

        std::cout << std::endl;
    }

    return dataWrite;
}

int main()
{
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 12748);

    int32_t intRead{ dataRead<int32_t>(hProcess, (LPCVOID)0xCDAA5FF8E8, &intRead, sizeof(int32_t), 0) };

    std::cout << "Adress of intRead = " << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&intRead) << '\n';

    std::cout << "Value of intRead = " << std::dec << intRead << std::endl;

    int32_t intWrite{ dataWrite<int32_t>(hProcess, (LPVOID)0xCDAA5FF8E8, &intWrite, sizeof(int32_t), 0, -249) };

    int32_t ptrRead{ dataRead<int32_t>(hProcess, (LPCVOID)0xCDAA5FF838, &ptrRead, sizeof(int32_t), 0) };

    std::cout << "Adress of ptrRead = " << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&ptrRead) << '\n';

    std::cout << "Value of ptrRead = " << std::dec << ptrRead << std::endl;

    std::cout << "Press ENTER to quit." << '\n';

    std::cin.get();

    return 0;
}