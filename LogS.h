#include <ostream>
#include <tuple>

class CLogS final
{
private:
    std::ostream& output;

public:
    CLogS(std::ostream& os) : output(os) {}
    ~CLogS() = default;

    CLogS(CLogS&&) = delete;
    CLogS(const CLogS&&) = delete;
    CLogS& operator=(const CLogS&) = delete;
    CLogS& operator=(CLogS&&) = delete;

private:
    // # Many arguments (ex: ["Test: ", "Hello, world!"])
    template <size_t i = 0, typename... T>
    void Print(std::tuple<T...> t)
    {
        if (output.good())
        {
            output << std::get<i>(t);

            if constexpr(i + 1 < sizeof...(T))
            {
                Print<i + 1>(t);
            }
            else
            {
                output << std::endl;
            }
        }
    }

public:
    // # One argument (ex: ["Test"])
    template <typename T>
    void Print(T&& value)
    {
        if (output.good())
        {
            output << value << std::endl;
        }
    }

    // # Many arguments (ex: ["Test: ", "Hello, world!"])
    template <typename... T>
    void Print(T... args)
    {
        Print(std::tuple<T...>(args...));
    }
};
