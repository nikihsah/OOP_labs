#include <iostream>
using namespace std;
//EX 1.3

template <typename T>
T max(T a, T b) {
    cout << "max traf" << endl;
    return (a > b) ? a : b;
}
const char* max(const char* a, const char* b) {
    cout << "max char" << endl;
    return (a > b) ? a : b;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX 2.1
class Complex {
private:
    // vehestvennay i mnimay
    double m_re, m_im;

public:

    Complex();
    Complex(double re, double im = 0);

    double GetRe() {
        return m_re;
    }
    double GetIm() {
        return m_im;
    }

    //Operators:
    // *
    Complex operator*(const Complex& a) {
        return Complex(m_re * a.m_re - m_im * a.m_im,
            m_re * a.m_im - m_im * a.m_re);
    }
    // * on number
    Complex operator*(const double& a) {
        return Complex(m_re * a, m_im * a);
    }
    // =
    Complex& operator=(const Complex& a) 
    {
        if (this != &a)
        {
            m_re = a.m_re;
            m_im = a.m_im;
        }
        return *this;
    }
    double& operator=(const double& a)
    {
        return m_re;
    }
    // out
    friend ostream& operator<< (ostream& out, const Complex& x) 
    {
        return (out << "(" << x.m_re << "," << x.m_im << ")");
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX 2.2
template <class T>
class matrix {

private:
    T** M; // matrix
    int m; // col-vo str
    int n; // col-vo stlb

public:

    matrix()
    {
        n = m = 0;
    }

    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;

        M = (T**) new T * [m];

        
        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        //matrix full 0
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }

    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    matrix operator=(const matrix& _M)
    {
        if (n > 0)
        {
            
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }

        // coppy data M <= _M
        m = _M.m;
        n = _M.n;

        // memory clean
        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        // copy
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;

        
    }

    // destructor
    ~matrix()
    {
        if (n > 0)
        {
            // освободить выделенную память для каждой строки
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }


};


int main()
{
    /*
    //EX 1.3
    int i = max(4,8);
    double d = max(17.2, 17.3);
    const char* ch = max("Hello","World");
    cout << "i = " << i << endl;
    cout << "d = " << d << endl;
    cout << "ch = " << ch << endl;
    */

    //EX 2.3
    matrix<int> in(2, 3);
    in.SetMij(1, 1, 2.1);
    in.SetMij(1, 2, 3);
    in.SetMij(2, 1, 'h');

    Complex comp(1.0);

    in.SetMij(2, 2, comp);
}

