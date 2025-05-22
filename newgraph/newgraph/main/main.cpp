// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "graph.h"
#include <iostream>
#include "algorithm.h" 




int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <txt_file> <csv_file>" << std::endl;
        return 1;
    }

    Graph txtGraph(argv[1]);
    std::cout << "Working with " << argv[1] << std::endl;
    writeGraph(txtGraph, argv[1]);

    Graph csvGraph(argv[2]);
    std::cout << "Working with " << argv[2] << std::endl;
    writeGraph(csvGraph, argv[2]);

    std::cout << "All graphs are written successfully" << std::endl;
    return 0;
}

//g++ main.cpp graph.cpp node.cpp algorithm.cpp -o main.exe
//.\main.exe testgraph.txt 1000.csv

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
