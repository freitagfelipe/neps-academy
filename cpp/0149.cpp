#include <iostream>

int main() {
    int Ha, Ma, Hr, Mr, answer;

    std::cin >> Ha >> Ma >> Hr >> Mr;

    answer = (Hr - Ha) * 60 + Mr - Ma;
    
    if(answer < 45)
        std::cout << "Atrasado " << 45 - answer << std::endl; 
    else
        std::cout << "Sucesso" << std::endl;

    return 0;
}