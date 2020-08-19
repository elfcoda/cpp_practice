#include "in.h"
using namespace std;

template <typename T>
constexpr bool is_vector = std::is_same_v<typename std::decay<T>::type, std::vector<typename std::decay<T>::type::value_type, typename std::decay<T>::type::allocator_type>>;

template <typename T>
struct is_container_vector_helper
{
    constexpr static bool is_vector = false;
};
template <typename... U>
struct is_container_vector_helper<std::vector<U...>>
{
    constexpr static bool is_vector = true;
};

template <typename T>
struct is_container_vector
{
    constexpr static bool is_vector = is_container_vector_helper<typename std::decay<T>::type>::is_vector;
};

enum AA{
    AA_a = 1,
};

constexpr AA mm = AA_a;

void f1(int& x)
{
    cout << "lllll" << endl;
}

void f1(int&& x)
{
    cout << "rrrrr" << endl;
}

template <class T, class U>
std::enable_if_t<is_container_vector<T>::is_vector &&
                 is_container_vector<U>::is_vector &&
                 std::is_same_v<typename std::decay_t<T>::value_type,
                                typename std::decay<U>::type::value_type>,
                 void>
h1(T&& v1, U&& v2)
{
}

int main()
{
    std::vector<int> v1 = {1};
    std::vector<int> v2 = {1};
    h1(v1, std::vector<int>{1});
    return 0;
}
