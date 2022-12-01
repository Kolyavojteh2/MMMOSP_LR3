#ifndef LR_3_H
#define LR_3_H

#include <mathematicalmodel.h>

class LR_3 : public MathematicalModel
{
public:
    LR_3();

    MathematicalVars simulateTheModel() override;
};

#endif // LR_3_H
