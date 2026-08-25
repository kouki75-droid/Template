// Template.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <queue>


/// ////////////////////////////////////////////////////////////////////
// 1. 関数テンプレートの例

int main_int (int a, int b)
{
    return a > b ? a : b;
}

long main_long (long a, long b)
{
    return a > b ? a : b;
}

float main_float (float a, float b)
{
    return a > b ? a : b;
}

////////////////////////////////////////////////////
// 2. 関数テンプレートの例
template<class T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int a = max(3, 5);
double b = max(3.0, 5.0);


///////////////////////////////////////////////////   
// 3. クラステンプレートの例
template<typename T,std::size_t N>
class StaticArray {
	T data[N];
public:
	constexpr T& operator[](std::size_t i){ return data[i]; }
	constexpr const T& operator[](std::size_t i) const { return data[i]; }
	constexpr std::size_t size() const { return N; }
};


////////////////////////////////////////////////////
// 4. クラステンプレートの特殊化の例
// デフォルトのテンプレート
template<typename T>struct IsPointer 
{
	static constexpr bool value = false;
};

// 特殊化
template<typename U> struct IsPointer <U*> 
{
    static constexpr bool value = true;
};

struct NotPointer :IsPointer<int> {


};

////////////////////////////////////////////////////
//5. 演習問題1
template<typename T> struct IsArray
{
    static constexpr bool value = false;
};

template<typename T, std::size_t N>
struct IsArray<T[N]>
{
    static constexpr bool value = true;
};

////////////////////////////////////////////////////
//6. 演習問題2
template<typename T> struct IsConst
{
    static constexpr bool value = false;
};

template<typename T> struct IsConst<const T>
{
    static constexpr bool value = true;
};

int main()
{

   /* int a = 10;
    int b = 20;

    float c = 10.1;
    float d = 10.2;

    std::cout << "max:" << max(a, b) << std::endl;

    std::cout << "max:" << max(c, d) << std::endl;*/

  /*  StaticArray<int, 3 > data;

    for (auto i = 0; i < data.size(); ++i) {

        data[i] =  i;
	}

	std::cout << data[11] << std::endl;*/

	/*std::cout << IsPointer<int>::value << std::endl;
    std::cout << IsPointer<int*>::value << std::endl;
    std::cout << IsPointer<float>::value << std::endl;
    std::cout << IsPointer<float*>::value << std::endl;
    std::cout << NotPointer::value << std::endl;*/

    std::cout << IsArray<int>::value << std::endl;
    std::cout << IsArray<int[10]>::value << std::endl;
    std::cout << IsArray<float[5]>::value << std::endl;

	std::cout << "--------------------" << std::endl;

    std::cout << IsConst<int>::value << std::endl;
    std::cout << IsConst<const int>::value << std::endl;
    std::cout << IsConst<float>::value << std::endl;
    std::cout << IsConst<const float>::value << std::endl;

}

