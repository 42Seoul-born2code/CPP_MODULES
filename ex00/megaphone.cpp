#include <iostream>

int main(int argc, char **argv) {
    int i;
    char *words;

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (i < argc) 
    {
        words = argv[i];
        while (*words)
        {
            std::cout << (char)std::toupper(*words);
            words++;
        }
        std::cout << " ";
        i += 1;
    }
    std::cout << std::endl;
    return (0);
}