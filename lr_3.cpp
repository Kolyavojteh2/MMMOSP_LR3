#include "lr_3.h"
#include <QtMath>

long long factorial(long long n) {
    if ((n == 0) || (n == 1))
        return 1;
    else
        return n*factorial(n-1);
}

LR_3::LR_3() {
    addFunction("get_p", [](MathematicalVars args) -> MathematicalVars {
        float p = args["lambda"].toDouble() * args["1/u"].toDouble() / args["c"].toDouble();

        MathematicalVars result;
        result.insert("p", p);
        return result;
    });

    addFunction("get_r", [](MathematicalVars args) -> MathematicalVars {
        float r = args["lambda"].toDouble() * args["c"].toDouble();

        MathematicalVars result;
        result.insert("r", r);
        return result;
    });

    addFunction("get_p0", [](MathematicalVars args) -> MathematicalVars {
        float sum = 0.0f;
        for (int s = 0; s < args["c"].toInt() - 1; s++) {
            sum += pow(args["c"].toInt() * args["p"].toDouble(), s) / factorial(s);
        }
        sum += pow(args["c"].toInt() * args["p"].toDouble(), args["c"].toInt()) / factorial(args["c"].toInt()) * (1.0 / (1.0 - args["p"].toDouble()));
        sum = pow(sum, -1);

        MathematicalVars result;
        result.insert("p0", sum);
        return result;
    });

    addFunction("get_Lq", [](MathematicalVars args) -> MathematicalVars {
        float first_part = pow(args["r"].toDouble(), args["c"].toInt()) * args["p"].toDouble() / factorial(args["c"].toInt());
        float second_part = 1.0 / (pow(1.0 - args["p"].toDouble(), 2)) * args["p0"].toDouble();
        float Lq = first_part * second_part;

        MathematicalVars result;
        result.insert("Lq", Lq);
        return result;
    });

    addFunction("get_L", [](MathematicalVars args) -> MathematicalVars {
        float L = args["Lq"].toDouble() + args["r"].toDouble();
        MathematicalVars result;
        result.insert("L", L);
        return result;
    });

    addFunction("get_W", [](MathematicalVars args) -> MathematicalVars {
        float W = args["L"].toDouble() / args["lambda"].toDouble();
        MathematicalVars result;
        result.insert("W", W);
        return result;
    });

    addFunction("get_Wq", [](MathematicalVars args) -> MathematicalVars {
        float Wq = args["W"].toDouble() - args["1/u"].toDouble();
        MathematicalVars result;
        result.insert("Wq", Wq);
        return result;
    });

    addFunction("get_B", [](MathematicalVars args) -> MathematicalVars {
        float u = pow(args["1/u"].toDouble(), -1);
        float B = 1.0 / (u - args["lambda"].toDouble());
        MathematicalVars result;
        result.insert("B", B);
        return result;
    });

    addFunction("get_pq", [](MathematicalVars args) -> MathematicalVars {
        float pq = 1.0 - args["p0"].toDouble();
        MathematicalVars result;
        result.insert("pq", pq);
        return result;
    });

}

MathematicalVars LR_3::simulateTheModel() {

    MathematicalVars functionResult = runFunction("get_p", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_r", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_p0", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_Lq", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_L", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_W", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_Wq", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_B", _variables);
    _variables = _variables.unite(functionResult);

    functionResult = runFunction("get_pq", _variables);
    _variables = _variables.unite(functionResult);

    return _variables;
}
