#include <QCoreApplication>
#include <mathematicalmodel.h>
#include <iostream>
#include <iomanip>

#include "lr_3.h"
int main(int argc, char *argv[])
{
    LR_3 model;

    model.addVariable("lambda", 20);
    model.addVariable("1/u", 0.1);
    model.addVariable("c", 20);

    auto result = model.simulateTheModel();

    std::cout << "====Input data====\n";
    std::cout << "Інтенсивність потоку(кількість покупців за хвилину):\n";
    std::cout << std::right << std::setw(8) << "lambda" << " = " << std::left << std::setw(7) << result["lambda"].toDouble() << std::endl;

    std::cout << "Середня тривалість обслуговування:\n";
    std::cout << std::right << std::setw(8) << "1/u" << " = " << std::left << std::setw(7) << result["1/u"].toDouble() << std::endl;

    std::cout << "Кількість каналів:\n";
    std::cout << std::right << std::setw(8) << "c" << " = " << std::left << std::setw(7) << result["c"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "====Variables====\n";
    std::cout << "Навантаження системи:\n";
    std::cout << std::right << std::setw(8) << "p" << " = " << std::left << std::setw(7) << result["p"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "Середня кількість викликів за середній час обслуговування:\n";
    std::cout << std::right << std::setw(8) << "r" << " = " << std::left << std::setw(7) << result["r"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "Cередня кількість викликів у системі:\n";
    std::cout << std::right << std::setw(8) << "L" << " = " << std::left << std::setw(7) << result["L"].toDouble() << std::endl;

    std::cout << "Cередня кількість викликів у черзі:\n";
    std::cout << std::right << std::setw(8) << "Lq" << " = " << std::left << std::setw(7) << result["Lq"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "Cередній час перебування у системі:\n";
    std::cout << std::right << std::setw(8) << "W" << " = " << std::left << std::setw(7) << result["W"].toDouble() << std::endl;

    std::cout << "Cередній час очікування (у черзі):\n";
    std::cout << std::right << std::setw(8) << "Wq" << " = " << std::left << std::setw(7) << result["Wq"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "Cередня тривалість періоду зайнятості системи:\n";
    std::cout << std::right << std::setw(8) << "B" << " = " << std::left << std::setw(7) << result["B"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << "Iмовірність того, що виклик затримається у черзі:\n";
    std::cout << std::right << std::setw(8) << "pq" << " = " << std::left << std::setw(7) << result["pq"].toDouble() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;

    return 0;
}
