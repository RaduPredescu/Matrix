#include <iostream>
#include <cmath>
class matrice
{
    int lines1, cols1;
    int lines2, cols2;
    int a[101][101];
    int b[101][101];

public:
    void set_dim1(int n, int m)
    {
        lines1 = n;
        cols1 = m;
    }
    void set_dim2(int n, int m)
    {
        lines2 = n;
        cols2 = m;
    }
    void set_val1(int i, int j, int x)
    {
        a[i][j] = x;
    }
    void set_val2(int i, int j, int x)
    {
        b[i][j] = x;
    }
    void prod(int v[101][101])
    {
        for (int aux1 = 1; aux1 <= lines1; aux1++)
            for (int aux2 = 1; aux2 <= cols2; aux2++)
                for (int aux3 = 1; aux3 <= lines2; aux3++)
                    v[aux1][aux2] += a[aux1][aux3] * b[aux3][aux2];
    }
    void sum(int v[101][101])
    {
        for (int aux1 = 1; aux1 <= lines1; ++aux1)
            for (int aux2 = 1; aux2 <= cols2; ++aux2)
                v[aux1][aux2] = a[aux1][aux2] + b[aux1][aux2];
    }
    void dif(int v[101][101])
    {
        for (int aux1 = 1; aux1 <= lines1; ++aux1)
            for (int aux2 = 1; aux2 <= cols2; ++aux2)
                v[aux1][aux2] = a[aux1][aux2] - b[aux1][aux2];
    }
    int trace1()
    {
        int s = 0;
        for (int aux1 = 1; aux1 <= lines1; ++aux1)
            s += a[aux1][aux1];
        return s;
    }
    int trace2()
    {
        int s = 0;
        for (int aux1 = 1; aux1 <= lines1; ++aux1)
            s += b[aux1][aux1];
        return s;
    }
    int determinant1(int matrix[101][101], int lines1)
    {
        int det = 0;
        int suba[101][101];
        if (lines1 == 2)
            return ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2]));
        else
        {
            for (int x = 1; x <= lines1; x++)
            {
                int subi = 0;
                for (int i = 2; i <= lines1; i++)
                {
                    int subj = 0;
                    for (int j = 1; j <= lines1; j++)
                    {
                        if (j == x)
                            continue;
                        suba[subi][subj] = a[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * a[1][x] * determinant1(suba, lines1 - 1));
            }
        }
        return det;
    }
    int determinant2(int matrix[101][101], int lines2)
    {
        int det = 0;
        int subb[101][101];
        if (lines2 == 2)
            return ((b[1][1] * b[2][2]) - (b[2][1] * b[1][2]));
        else
        {
            for (int x = 1; x <= lines2; x++)
            {
                int subi = 0;
                for (int i = 2; i <= lines2; i++)
                {
                    int subj = 0;
                    for (int j = 1; j <= lines2; j++)
                    {
                        if (j == x)
                            continue;
                        subb[subi][subj] = b[i][j];
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * b[1][x] * determinant2(subb, lines2 - 1));
            }
        }
        return det;
    }
};
int main()
{
    int r1, c1,nrOp;
    matrice ob;
    std::cout << "Enter number of operations";
    std:: cout<< '\n';
    std::cin >> nrOp;
    std:: cout<< '\n';
    while (nrOp--)
    {
        std::cout << '\n';
        std::cout << "Enter number of rows for M1" << '\n';
        std::cin >> r1;
        std::cout << '\n';
        std::cout << "Enter number of columns for M1" << '\n';
        std::cin >> c1;
        ob.set_dim1(r1, c1);
        std::cout << '\n';
        std::cout << "Enter 1st matrix";
        std::cout << '\n';
        for (int i = 1; i <= r1; ++i)
            for (int j = 1; j <= c1; ++j)
            {
                int x;
                std::cin >> x;
                ob.set_val1(i, j, x);
            }
        int r2, c2;
        std::cout << "Enter number of rows for M2" << '\n';
        std::cin >> r2;
        std::cout << '\n';
        std::cout << "Enter number of columns for M2" << '\n';
        std::cin >> c2;
        ob.set_dim2(r2, c2);
        std::cout << '\n';
        std::cout << "Enter 2nd matrix";
        std::cout << '\n';
        for (int i = 1; i <= r2; ++i)
            for (int j = 1; j <= c2; ++j)
            {
                int x;
                std::cin >> x;
                ob.set_val2(i, j, x);
            }
        int v[101][101];
        std::cout << '\n';
        std::string op;
        std::cout << "Enter operation";
        std::cout << '\n';
        std::cin >> op;
        if (op == "PRODUCT")
        {
            if (c1 != r2)
            {
                std::cout << "Wrong values!";
                return 0;
            }
            ob.prod(v);
            for (int i = 1; i <= r1; ++i)
            {
                for (int j = 1; j <= c2; ++j)
                    std::cout << v[i][j] << " ";
                std::cout << '\n';
            }
        }
        if (op == "SUM")
        {
            if (r1 != r2 or c1 != c2)
            {
                std::cout << "Wrong values!";
                return 0;
            }
            ob.sum(v);
            for (int i = 1; i <= r1; ++i)
            {
                for (int j = 1; j <= c2; ++j)
                    std::cout << v[i][j] << " ";
                std::cout << '\n';
            }
        }
        if (op == "DIF")
        {
            if (r1 != r2 or c1 != c2)
            {
                std::cout << "Wrong values!";
                return 0;
            }
            ob.dif(v);
            for (int i = 1; i <= r1; ++i)
            {
                for (int j = 1; j <= c2; ++j)
                    std::cout << v[i][j] << " ";
                std::cout << '\n';
            }
        }
        if (op == "DETERMINANT1" and r1 == c1)
        {
            int ab[101][101], n;
            std::cout << ob.determinant1(ab, r1);
        }
        if (op == "DETERMINANT2" and r2 == c2)
        {
            int ab[101][101];
            std::cout << ob.determinant2(ab, r2);
        }
        if (op == "TRACE1")
        {
            std::cout << ob.trace1();
        }
        if (op == "TRACE2")
        {
            std::cout << ob.trace2();
        }
    }
    return 0;
}