#include <iostream>
#include <limits>

#include <assert.h>
#include <math.h>

using namespace std;


/* ===================================================================== */

class Matrix
{
public:
    Matrix() { }
    Matrix(int rows, int columns);
    Matrix(const Matrix& other);
    ~Matrix();
    
    static Matrix ones(int rows, int columns);
    
    double operator()(int row, int column) const { return elem(row, column); }   
    friend istream& operator>>(istream& stream, Matrix& m);
    
    int get_n_rows() const { return n_rows; }
    int get_n_columns() const { return n_columns; }
    
    Matrix crop(int r1, int c1, int r2, int c2) const;
    Matrix horizontal_merge(const Matrix& other) const;
    
    Matrix transpose() const;
    Matrix operator*(const Matrix& rhs) const;
    Matrix operator-() const;
    Matrix& operator+=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs) const;
    Matrix& operator-=(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs) const;
    Matrix& operator=(const Matrix& rhs);
    Matrix& operator*=(double d);

    
private:
    double* data;
    int n_rows, n_columns;
    
    double& elem(int row, int column) { return data[row * n_columns + column]; }
    const double& elem(int row, int column) const { return data[row * n_columns + column]; }
    
};


Matrix::Matrix(int rows, int columns) :
    n_rows(rows), n_columns(columns)
{
    data = new double[rows*columns];
}


Matrix::~Matrix()
{
    delete [] data;
}



Matrix::Matrix(const Matrix& other) :
    Matrix(other.n_rows, other.n_columns)
{
    for(int i = 0; i < n_rows * n_columns; i++)
        data[i] = other.data[i];
}


Matrix Matrix::crop(int r1, int c1, int r2, int c2) const
{
    int result_n_rows = r2 - r1;
    int result_n_columns = c2 - c1;
    
    Matrix result(result_n_rows, result_n_columns);
    
    for(int i = 0; i < result_n_rows; i++)
        for(int j = 0; j < result_n_columns; j++)
            result.elem(i, j) = elem(r1 + i, c1 + j);
    
    return result;
}



Matrix Matrix::transpose() const
{
    Matrix result(n_columns, n_rows);
    
    for(int i = 0; i < n_rows; i++)
        for(int j = 0; j < n_columns; j++)
            result.elem(j, i) = elem(i, j);
    
    return result;
}



Matrix Matrix::ones(int rows, int columns)
{
    Matrix result(rows, columns);

    for(int i = 0; i < rows*columns; i++)
        result.data[i] = 1;

    return result;
}



Matrix Matrix::horizontal_merge(const Matrix& other) const
{
    assert(n_rows == other.n_rows);
    
    Matrix result(n_rows, n_columns + other.n_columns);
    
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
            result.elem(i, j) = elem(i, j);
        
        for(int j = 0; j < other.n_columns; j++)
            result.elem(i, n_columns + j) = other.elem(i, j);
    }
    
    return result;
}



Matrix Matrix::operator*(const Matrix& rhs) const
{
    // Matrices must have compatible dimension
    assert(n_columns == rhs.n_rows);

    Matrix result(n_rows, rhs.n_columns);

    // Matrix multiplication algorithm
    for(int lhs_row = 0; lhs_row < n_rows; lhs_row++)
        for(int rhs_col = 0; rhs_col < rhs.n_columns; rhs_col++)
        {
            double temp = 0;

            for(int i = 0; i < n_columns; i++)
                temp += elem(lhs_row, i) * rhs.elem(i, rhs_col);

            result.elem(lhs_row, rhs_col) = temp;
        }

    return result;
}


Matrix Matrix::operator-() const
{
    Matrix result(n_rows, n_columns);
    
    for(int i = 0; i < n_rows; i++)
        for(int j = 0; j < n_columns; j++)
            result.elem(i, j) = - elem(i, j);
    
    return result;
}


Matrix& Matrix::operator+=(const Matrix& rhs)
{
    assert(n_rows == rhs.n_rows && n_columns == rhs.n_columns);

    // Add each element of lhs to each element of rhs
    for(int i = 0; i < n_rows; i++)
        for(int j = 0; j < n_columns; j++)
            elem(i, j) += rhs.elem(i, j);

    // Return lhs
    return *this;
}


Matrix Matrix::operator+(const Matrix& rhs) const
{
    Matrix result(*this);
    result += rhs;
    return result;
}


Matrix& Matrix::operator-=(const Matrix& rhs)
{
    assert(n_rows == rhs.n_rows && n_columns == rhs.n_columns);

    // Add each element of lhs to each element of rhs
    for(int i = 0; i < n_rows; i++)
        for(int j = 0; j < n_columns; j++)
            elem(i, j) += - rhs.elem(i, j);

    // Return lhs
    return *this;
}


Matrix Matrix::operator-(const Matrix& rhs) const
{
    Matrix result(*this);
    result -= rhs;
    return result;
}



Matrix& Matrix::operator=(const Matrix& rhs)
{
    if(this != &rhs) // exclude self-assignment case
    {
        if(data) delete [] data;

        n_rows = rhs.n_rows;
        n_columns = rhs.n_columns;
        
        data = new double[n_rows * n_columns];

        for(int i = 0; i < n_rows * n_columns; i++)
            data[i] = rhs.data[i];
    }

    // Return the lhs, for chained expressions.
    return *this;
}



Matrix& Matrix::operator*=(double d)
{
    for(int i = 0; i < n_rows; i++)
        for(int j = 0; j < n_columns; j++)
            elem(i, j) *= d;

    return *this;
}


double min(const Matrix& m)
{
    double min = numeric_limits<double>::max();
    
    for(int i = 0; i < m.get_n_rows(); i++)
        for(int j = 0; j < m.get_n_columns(); j++)
            if(m(i, j) < min) min = m(i, j);

    return min;
}



Matrix operator*(const Matrix& m, double d)
{
    Matrix result = m;
    result *= d;
    return result;
}


Matrix operator*(double d, const Matrix& m)
{
    return operator*(m, d);
}




istream& operator>>(istream& stream, Matrix& m)
{
    double a;
    
    for(int i = 0; i < m.n_rows; i++)
        for(int j = 0; j < m.n_columns; j++)
        {
            stream >> a;
            m.elem(i, j) = a;
        }
    
    return stream;
}


ostream& operator<<(ostream& stream, const Matrix& m)
{   
    for(int i = 0; i < m.get_n_rows(); i++)
    {
        for(int j = 0; j < m.get_n_columns(); j++)
        {
            if(j != 0) stream << " ";
            stream << m(i, j);
        }
        
        stream << endl;
    }
    
    return stream;
}


/* ===================================================================== */


// Evaluates h(theta) on sample x.
// "x" must be a row vector
// "theta" must be a column vector
double h(const Matrix& theta, const Matrix& x)
{
    assert(theta.get_n_rows() == x.get_n_columns());
    assert(theta.get_n_columns() == x.get_n_rows() == 1);
    
    double result = 0.0;
    
    // Simple vector multiplication
    for(int i = 0; i < theta.get_n_rows(); i++)
        result += theta(i, 0) * x(0, i);
    
    return result;
}


// Returns the cost function (squared error) of the linear regression represented by theta
double J(const Matrix& X, const Matrix& Y, const Matrix& theta)
{
    assert(X.get_n_rows() == Y.get_n_rows());
    assert(X.get_n_columns() == theta.get_n_rows());
    assert(Y.get_n_columns() == 1);
    
    double m = (double)Y.get_n_rows();
    
    double sum = 0;
    for(int i = 0; i < m; i++)
    {
        Matrix x = X.crop(i, 0, i, X.get_n_columns());
        sum += pow( h(theta, x) - Y(i, 0), 2.0);
    }
    
    sum /= (m * 2.0);
}


// Returns the learned theta vector
Matrix gradient_descent(const Matrix& X, const Matrix& Y, const Matrix& init_theta, double alpha)
{
    Matrix theta = init_theta;
    Matrix prev_theta(init_theta.get_n_rows(), init_theta.get_n_columns());
    
    double m = (double)Y.get_n_rows();
    
    while(true)
    {
        prev_theta = theta;
        theta -= (alpha / m) * X.transpose() * ( X * theta - Y );
        
        if( fabs(min(theta - prev_theta)) < 0.00001)
            break;
    }
    
    return theta;
}





int main()
{
    int F, N;
    
    cin >> F;
    cin >> N;
    
    Matrix m(N, F + 1);
    cin >> m;

    Matrix X = m.crop(0, 0, m.get_n_rows(), m.get_n_columns() - 1);
    
    // Adds the first column of ones in front of X
    X = Matrix::ones(X.get_n_rows(), 1).horizontal_merge(X);
        
    Matrix Y = m.crop(0, m.get_n_columns() - 1, m.get_n_rows(), m.get_n_columns());
    
    Matrix init_theta = Matrix::ones(F + 1, 1);
    Matrix theta = gradient_descent(X, Y, init_theta, 0.1);
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        Matrix x(1, F);
        cin >> x;
        x = Matrix::ones(1, 1).horizontal_merge(x);
        
        cout << h(theta, x) << endl;
    }
    
    return 0;
}
