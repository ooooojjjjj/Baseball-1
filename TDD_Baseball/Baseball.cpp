#include <string>
#include <stdexcept>

using namespace std;

struct Result
{
    bool bSolved;
    int nStrikes;
    int nBalls;
};

class Baseball
{
public:
    explicit Baseball(const string& sAnswer)
        : sAnswer(sAnswer)
    {
    }

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

    bool IsAnswer(std::string& sInput)
    {
        return sAnswer == sInput;
    }

    void CheckSBcount(string sInput, int& nStrikes, int& nBalls)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (sInput[i] == sAnswer[j])
                {
                    if (i == j)
                        nStrikes++;
                    else
                        nBalls++;
                }
            }
        }
    }

    Result Guess(string sInput)
    {
        Result stResult = { false, 0, 0 };

        CheckInputValidity(sInput);

        if (IsAnswer(sInput)) 
            return { true, 3, 0 };

        int nStrikes = 0;
        int nBalls = 0;
        CheckSBcount(sInput, nStrikes, nBalls);

        return { false, nStrikes, nBalls };
    }

private:
    string sAnswer;
};