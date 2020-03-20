/*
 * The public interface for an Operand.
 * Can be used to avoid any implementation details.
 *
 * Written by Sean Hodges, last edited Nov. 18 2019
 */

#include <string>
using namespace std;

#ifndef IOPERAND_H
#define IOPERAND_H

class IOperand {
private:
protected:
public:
    virtual ~IOperand() { }

    virtual void Verify() = 0;
    virtual void Initialize() = 0;

    virtual bool CanSetValue() = 0;
    virtual bool CanGetValue() = 0;

    virtual string GetName() = 0;
    virtual string GetType() = 0;

    virtual void GetValue(int& result) = 0;
    virtual void GetValue(string& result) = 0;
    virtual void SetValue(int value) = 0;
    virtual void SetValue(string value) = 0;

};

#endif // IOPERAND_H
