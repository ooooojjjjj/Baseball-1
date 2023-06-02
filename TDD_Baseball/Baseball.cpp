#include <string>
#include <stdexcept>

using namespace std;
class Baseball
{
public:
    bool IsNumbers(string& sInput)
    {
        for (char cEach : sInput)
        {
            if (cEach >= '0' && cEach <= '9') continue;
            return true;
        }

        return false;
    }

    bool IsDuplicated(std::string& sInput)
    {
        return sInput[0] == sInput[1]
            || sInput[0] == sInput[2]
            || sInput[1] == sInput[2];
    }

    void CheckInputValidity(std::string& sInput)
    {
        if ("" == sInput)
        {
            throw invalid_argument("값을 넣어야 합니다.");
        }

        if (3 != sInput.length())
        {
            throw invalid_argument("자리 수 오류.");
        }

        if (IsNumbers(sInput))
        {
            throw invalid_argument("숫자로만 구성해야 합니다.");
        }

        if (IsDuplicated(sInput))
        {
            throw invalid_argument("숫자가 중복되면 안됩니다.");
        }
    }

    void Guess(string sInput)
    {
        CheckInputValidity(sInput);
    }
};