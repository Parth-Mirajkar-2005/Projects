#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// Define ANSI escape codes for colors
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"
#define ANSI_COLOR_RED "\033[1;31m"
#define ANSI_COLOR_PINK "\033[1;35m"
// #define ANSI_COLOR_RESET "\033[0m"

int MAX_NUM = 100;
const int MAX_SIZE = 10;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

class Angle
{
private:
    double degree;
    double radian;
    int choice_1;
    int choice_2;

    void conversion_to_radian()
    {
        radian = degree * (3.1415927 / 180);
    }

    void conversion_to_degee()
    {
        degree = radian * (180 / 3.1415927);
    }

public:
    Angle()
    {
        degree = 0;
        radian = 0;
    }

    void Angle_Type()
    {
        cout << "Enter your value of angel in any of the following format : " << endl;
        cout << "1. Degree\n2. Radian\n3. Exit\n";
        cout << "Enter choice : ";
        cin >> choice_1;
        while (choice_1 < 1 || choice_1 > 3)
        {
            cout << ANSI_COLOR_RED << "Enter proper choice ..... " << ANSI_COLOR_RESET << endl;
            cout << "1. Degree\n2. Radian\n3. Exit\n";
            cout << "Enter choice : ";
            cin >> choice_1;
        }
        cout << "\nEnter value of angle : ";
        switch (choice_1)
        {
        case 1:
            cin >> degree;
            if (degree < 90)
                cout << ANSI_COLOR_YELLOW << "Enterd angle is a 'Acute Angle'." << ANSI_COLOR_RESET;
            else if (degree > 90)
                cout << ANSI_COLOR_YELLOW << "Entered angle is a 'Obtuse Angle'." << ANSI_COLOR_RESET;
            else
                cout << ANSI_COLOR_YELLOW << "Entered angle is a 'Right Angle'." << ANSI_COLOR_RESET;
            break;

        case 2:
            if (radian < (3.1415927 / 2))
                cout << ANSI_COLOR_YELLOW << "Enterd angle is a 'Acute Angle'." << ANSI_COLOR_RESET;
            else if (radian > (3.1415927 / 2))
                cout << ANSI_COLOR_YELLOW << "Entered angle is a 'Obtuse Angle'." << ANSI_COLOR_RESET;
            else
                cout << ANSI_COLOR_YELLOW << "Entered angle is a 'Right Angle'." << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(1);

        default:
            cout << ANSI_COLOR_RED << "Unknown Error is appering................" << ANSI_COLOR_RESET;
        }
        if (choice_1 = 1)
        {
            conversion_to_radian();
        }
    }

    void choice()
    {
        cout << "Enter Which action you want to perform on the angle you entered : \n";
        cout << "Trigonometric Functions : \n";
        cout << "1. Convert to Radian\n2. Convert to degree\n";
        cout << "3. sin\n4. cos\n5. tan\n6. sin inverse\n7. cos inverse\n8. tan inverse\n9. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice_2;
        while (choice_2 > 9 || choice_2 < 1)
        {
            cout << ANSI_COLOR_RED << "Invalid choice ..................\nRe-enter the choice : " << ANSI_COLOR_RESET;
            cin >> choice_2;
        }
    }

    void Switch_case()
    {
        switch (choice_2)
        {
        case 1:
            conversion_to_radian();
            cout << "Entered Angle in radian : " << ANSI_COLOR_YELLOW << radian << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            conversion_to_degee();
            cout << "Entered Angle in degree : " << ANSI_COLOR_YELLOW << degree << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            cout << "Sin = " << ANSI_COLOR_YELLOW << sin(radian) << ANSI_COLOR_RESET << endl;
            break;

        case 4:
            cout << "Cos = " << ANSI_COLOR_YELLOW << cos(radian) << ANSI_COLOR_RESET << endl;
            break;

        case 5:
            cout << "Tan = " << ANSI_COLOR_YELLOW << tan(radian) << ANSI_COLOR_RESET << endl;
            break;

        case 6:
            cout << "Inverse of Sin(degree) = " << ANSI_COLOR_YELLOW << asin(radian) * 180.0 / 3.1415927 << ANSI_COLOR_RESET << endl;
            break;

        case 7:
            cout << "Inverse of Cos(degree) = " << ANSI_COLOR_YELLOW << acos(radian) * 180.0 / 3.1415927 << ANSI_COLOR_RESET << endl;
            break;

        case 8:
            cout << "Inverse of tan(degree) = " << ANSI_COLOR_YELLOW << atan(radian) * 180.0 / 3.1415927 << ANSI_COLOR_RESET << endl;
            break;

        case 9:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown Error......................." << ANSI_COLOR_RESET;
        }
    }
};

class Arithmatic
{
private:
    double num1;
    double num2;
    int operation;
    double Arr[100];

public:
    Arithmatic()
    {
        num1 = 0;
        num2 = 0;
        operation = 6;
        for (int i = 0; i < 100; i++)
        {
            Arr[i] = 0;
        }
    }

    void input()
    {
        cout << "Enter which operation you want to perform : " << endl;
        cout << "1. Addition(+) \n2. Subsraction(-) \n3. Multiplication(*) \n4. Division(/) \n5. Modulus(%) \n6. Exit \n";
        cout << "Enter Which Operation You want To Perform : ";
        cin >> operation;
        while (operation > 6 || operation < 1)
        {
            cout << ANSI_COLOR_RED << "ERROR : Invalid Input .............." << ANSI_COLOR_RESET << endl;
            cout << "Enter which operation you want to perform : " << endl;
            cout << "1. Addition(+) \n2. Subsraction(-) \n3. Multiplication(*) \n4. Division(/) \n5. Modulus(%) \n6. Exit \n";
            cout << "Enter Which Operation You want To Perform : ";
            cin >> operation;
        }
    }

    void process()
    {
        int n;
        double ANS = 0; // Regular variable declaration
        switch (operation)
        {
        case 1:
            cout << "How many numbers you want to add in each other : ";
            cin >> n;
            if (n == 0)
            {
                cout << ANSI_COLOR_RED << "Invalid Input..........." << ANSI_COLOR_RESET << endl;
                exit(1);
            }
            cout << "Enter numbers you want to add : \n";
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Value at Number " << i + 1 << " : ";
                cin >> Arr[i];
            }
            for (int i = 0; i < n; i++)
            {
                ANS += Arr[i];
            }
            cout << "Addition of ";
            for (int i = 0; i < n - 1; i++)
            {
                cout << Arr[i] << " + ";
            }
            cout << Arr[n - 1] << " = " << ANSI_COLOR_YELLOW << ANS << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            cout << "How many numbers you want to substract from each other : ";
            cin >> n;
            if (n == 0)
            {
                cout << ANSI_COLOR_RED << "Invalid Input..........." << ANSI_COLOR_RESET << endl;
                exit(1);
            }
            cout << "Enter numbers you want to subsract : \n";
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Value at Number " << i + 1 << " : ";
                cin >> Arr[i];
            }

            ANS = Arr[0];

            for (int i = 0; i < n; i++)
            {
                ANS -= Arr[i + 1];
            }
            cout << "Subsraction of ";
            for (int i = 0; i < n - 1; i++)
            {
                cout << Arr[i] << " - ";
            }
            cout << Arr[n - 1] << " = " << ANSI_COLOR_YELLOW << ANS << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            ANS = 1;
            cout << "How many numbers you want to multiply with each other : ";
            cin >> n;
            if (n == 0)
            {
                cout << ANSI_COLOR_RED << "Invalid Input..........." << ANSI_COLOR_RESET << endl;
                exit(1);
            }
            cout << "Enter numbers you want to multiply : \n";
            for (int i = 0; i < n; i++)
            {
                cout << "Enter Value at Number " << i + 1 << " : ";
                cin >> Arr[i];
            }
            for (int i = 0; i < n; i++)
            {
                ANS *= Arr[i];
            }
            cout << "Multiplication of ";
            for (int i = 0; i < n - 1; i++)
            {
                cout << Arr[i] << " * ";
            }
            cout << Arr[n - 1] << " = " << ANSI_COLOR_YELLOW << ANS << ANSI_COLOR_RESET << endl;
            break;

        case 4:
            cout << "Enter numbers you want to divide with each other : \n";
            cout << "Numrator : ";
            cin >> num1;
            cout << "Dinominator : ";
            cin >> num2;
            if (num2 == 0)
            {
                cout << ANSI_COLOR_RED << "Division is not possible ,since dinominator is 0." << ANSI_COLOR_RESET << endl;
                exit(1);
            }
            else
            {
                ANS = num1 / num2;
            }
            cout << "The division of " << num1 << " and " << num2 << " is " << num1 << " / " << num2 << " = " << ANSI_COLOR_YELLOW << ANS << ANSI_COLOR_RESET << endl;
            break;

        case 5:
            cout << "Enter numbers you want to modulo with each other : \n";
            cout << "Numrator : ";
            cin >> num1;
            cout << "Dinominator : ";
            cin >> num2;
            if (num2 == 0)
            {
                cout << ANSI_COLOR_RED << "Modulus is not possible ,since dinominator is 0." << ANSI_COLOR_RESET << endl;
                exit(1);
            }
            else
            {
                ANS = (int)num1 % (int)num2;
            }
            cout << "The modulo of " << num1 << " and " << num2 << " is " << num1 << " % " << num2 << " = " << ANSI_COLOR_YELLOW << ANS << ANSI_COLOR_RESET << endl;
            break;

        case 6:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown ERROR is found .............." << ANSI_COLOR_RESET << endl;
        }
    }
};

class Complex
{
private:
    double real;
    double img;

    void input()
    {
        cout << "Enter the Complex number : " << endl;
        cout << "Real : ";
        cin >> real;
        cout << "Imaginary : ";
        cin >> img;
    }

    void output()
    {
        cout << "Complex Number : " << ANSI_COLOR_YELLOW << real << " + " << img << "i" << ANSI_COLOR_RESET << endl;
    }

    Complex operator+(Complex const &in)
    {
        Complex out;
        out.real = real + in.real;
        out.img = img + in.img;
        return out;
    }

    Complex operator-(Complex const &in)
    {

        Complex out;
        out.real = real - in.real;
        out.img = img - in.img;
        return out;
    }

    Complex operator*(Complex const &in) //(a+ib)*(c+id) = (ac-bd) + (ad + bc)i
    {                                    //(1 + 2i)*(3 + 4i) = (3 + 4i ) + (6i - 8)
        Complex out;                     //                  =  -5 + 10i
        out.real = (real * in.real) - (in.img * img);
        out.img = (real * in.img) + (img * in.real);
        return out;
    }

    Complex operator/(Complex const &in) //(a + bi) / (c + di) = (ac + bd) + (bc - ad)i) / (c^2 + d^2).
    {                                    //(1 + 2i) / (3 + 4i) = 2.94744 + 0.535898i
        Complex out;
        double denominator = (sqrt(in.real) + sqrt(in.img));
        out.real = ((real * in.real) + (img * in.img)) / denominator;
        out.img = ((in.real * img) - (real * in.img)) / denominator;
        //			out.real = ((real * in.img)+(img * in.img))/(sqrt(in.real) + sqrt(in.img));
        //			out.img = ((img * in.real)-(real * in.img))/(sqrt(in.real) + sqrt(in.img));
        return out;
    }

public:
    Complex()
    {
        real = 0;
        img = 0;
    }

    void choice(Complex c1, Complex c2)
    {
        int C;
        Complex c;
        cout << "Enter First complex number : " << endl;
        c1.input();
        cout << "Enter the second complex number : " << endl;
        c2.input();

        cout << "\n 1. -> Addition \n 2. -> Substraction \n 3. -> Multiplicarion \n 4. -> Divisionn \n 5 -> Exit \n"
             << endl;
        cout << "Enter your choice : ";
        cin >> C;
        while (C < 1 || C > 5)
        {
            cout << ANSI_COLOR_RED << "Enter Propper Input ..............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter Your choice : ";
            cin >> C;
        }
        switch (C)
        {
        case 1:
            c = c1 + c2;
            cout << "The Sum of the entered complex number is : ";
            c.output();
            break;

        case 2:
            c = c1 - c2;
            cout << "The Substraction of the entered complex number is : ";
            c.output();
            break;

        case 3:
            c = c1 * c2;
            cout << "The Multiplication of the entered complex number is : ";
            c.output();
            break;

        case 4:
            c = c1 / c2;
            cout << "The Division of the entered complex number is : ";
            c.output();
            break;

        case 5:
            exit;
            break;

        default:
            cout << ANSI_COLOR_RED << "Enter propper choice ..............." << ANSI_COLOR_RESET << endl;
        }
    }
};

class Quadratic_Equation
{
private:
    int x1, x2;
    int a;
    int b;
    int c;

public:
    Quadratic_Equation()
    {
        x1 = 0;
        x2 = 0;
        a = 0;
        b = 0;
        c = 0;
    }

    void input()
    {
        cout << "Enter the Quadratic Equation in the form of 'a*x^2 + b*x +c = 0' : \n";
        cout << "Enter the values : \n";
        cout << "a : ";
        cin >> a;
        while (a == 0)
        {
            cout << "ERROR : Entered equation is not a quadratic equation \n Renter the value of 'a' ....\n";
            cout << "a : ";
            cin >> a;
        }
        cout << "b : ";
        cin >> b;
        cout << "c : ";
        cin >> c;
    }

    void Operation()
    {
        if (pow(b, 2) - 4 * a * c < 0)
        {
            cout << "Roots of the Quadratic Equations are not real.....";
            exit(1);
        }
        else
        {
            x1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
            x2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
        }
    }

    void output()
    {
        if (x1 == x2)
        {
            cout << "Entered Quadratic equation contains single root only ,";
            cout << "Root : " << ANSI_COLOR_YELLOW << x1 << ANSI_COLOR_RESET;
        }
        else
        {
            cout << "Entered Quadratic equation have two roots : \n";
            cout << "Root 1 : " << ANSI_COLOR_YELLOW << x1 << ANSI_COLOR_RESET;
            cout << "\nRoot 2 : " << ANSI_COLOR_YELLOW << x2 << ANSI_COLOR_RESET;
        }
    }
};

class Linear_Equation
{
private:
    double matrix[MAX_SIZE][MAX_SIZE + 1];
    int n;

public:
    Linear_Equation() : n(0) {}

    void inputEquations()
    {
        cout << "Enter the number of variables (up to 10): ";
        cin >> n;

        cout << "Enter the coefficients and constants:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << "Equation " << i + 1 << ":\n";
            for (int j = 0; j < n + 1; ++j)
            {
                cout << "Coefficient " << j + 1 << ": ";
                cin >> matrix[i][j];
            }
        }
    }

    void gaussJordan()
    {
        for (int i = 0; i < n; ++i)
        {
            double divisor = matrix[i][i];
            for (int j = 0; j < n + 1; ++j)
            {
                matrix[i][j] /= divisor;
            }

            for (int k = 0; k < n; ++k)
            {
                if (k != i)
                {
                    double multiplier = matrix[k][i];
                    for (int j = 0; j < n + 1; ++j)
                    {
                        matrix[k][j] -= multiplier * matrix[i][j];
                    }
                }
            }
        }
    }

    void outputSolution()
    {
        cout << "Solution:\n";
        for (int i = 0; i < n; ++i)
        {
            cout << ANSI_COLOR_YELLOW << "x" << i + 1 << ANSI_COLOR_RESET << " = " << ANSI_COLOR_YELLOW << matrix[i][n] << ANSI_COLOR_RESET << endl;
        }
    }

    void solve()
    {
        inputEquations();
        gaussJordan();
        outputSolution();
    }
};

class Switch_Case : public Quadratic_Equation, public Linear_Equation
{
public:
    Switch_Case()
    {
        int choice;
        while (choice < 1 || choice > 3)
        {
            cout << "Which type of Equation do you want to solve?\n";
            cout << "1. Quadratic Equation\n2. Linear Equation\n3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            while (choice < 1 || choice > 3)
            {
                cout << ANSI_COLOR_RED << "Enter propper choice............\n"
                     << ANSI_COLOR_RESET;
                cout << "Re-enter choice : ";
                cin >> choice;
            }

            switch (choice)
            {
            case 1:
            {
                Quadratic_Equation Q;
                Q.input();
                Q.Operation();
                Q.output();
                break;
            }

            case 2:
            {
                Linear_Equation solver;
                solver.solve();
                break;
            }

            case 3:
            {
                exit(0);
                break;
            }

            default:
            {
                cout << ANSI_COLOR_RED << "Unknown ERROR ................\n"
                     << ANSI_COLOR_RESET;
                break;
            }
            }
        }
    }
};

class Logarithm
{
private:
    double log1;
    double log2;
    int choice1;
    int choice2;
    int choice3;

public:
    Logarithm()
    {
        log1 = 0;
        log2 = 0;
    }

    void input_value()
    {
        cout << "Enter two numbers : " << endl;
        cout << "First number : ";
        cin >> log1;
        cout << "Second number : ";
        cin >> log2;
    }

    void Display_choice()
    {
        cout << "1. Logarithmic value\n2. Logarithmic Operation\n3. Exit\n";
        cout << "Enter Your choice : ";
        cin >> choice1;
        while (choice1 < 1 || choice1 > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .................." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter the choice : ";
            cin >> choice1;
        }
    }

    void Switch_case_1()
    {
        cout << "1. Logarithmic value with base 'e' \n2. Logarithmic value with base 10 \n3. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice2;
        while (choice2 < 1 || choice2 > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .................." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter the choice : ";
            cin >> choice2;
        }
        switch (choice2)
        {
        case 1:
            cout << "Enter a number : ";
            cin >> log1;
            cout << "Log with base e = " << ANSI_COLOR_YELLOW << log(log1) << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            cout << "Enter a number : ";
            cin >> log1;
            cout << "Log with base 10 = " << ANSI_COLOR_YELLOW << log10(log1) << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown error................" << ANSI_COLOR_RESET << endl;
        }
    }

    void Switch_case_2()
    {
        cout << "1. Logarithmic Addition\n2. Logarithmic Substraction\n3. Logarithmic Multiplication\n4. Logarithmic Division\n5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice3;
        while (choice3 < 1 || choice3 > 5)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .................." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter the choice : ";
            cin >> choice2;
        }

        switch (choice3)
        {
        case 1:
            input_value();
            cout << "Logarithmic Addition : " << ANSI_COLOR_YELLOW << log(exp(log1) + exp(log2)) << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            input_value();
            cout << "Logarithmic Substraction : " << ANSI_COLOR_YELLOW << log(exp(log1) - exp(log2)) << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            input_value();
            cout << "Logarithmic Multiplication : " << ANSI_COLOR_YELLOW << log(exp(log1) * exp(log2)) << ANSI_COLOR_RESET << endl;
            break;

        case 4:
            input_value();
            cout << "Logarithmic dicision : " << ANSI_COLOR_YELLOW << log(exp(log1) / exp(log2)) << ANSI_COLOR_RESET << endl;

        case 5:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown Error....................." << ANSI_COLOR_RESET << endl;
        }
    }

    void Main_Switch()
    {
        switch (choice1)
        {
        case 1:
            Switch_case_1();
            break;

        case 2:
            Switch_case_2();
            break;

        case 3:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknoun error.............................." << ANSI_COLOR_RESET << endl;
        }
    }
};

class Matrix
{
private:
    int rows;
    int cols;
    int mat[MAX_ROWS][MAX_COLS];

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
        {
            cout << ANSI_COLOR_RED << "Invalid dimensions for matrix. Please provide positive values within the range." << ANSI_COLOR_RESET << endl;
            exit(1);
        }
    }

    void input()
    {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter element of matrix at (" << i + 1 << "," << j + 1 << ") : ";
                cin >> mat[i][j];
            }
        }
    }

    void output()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << ANSI_COLOR_YELLOW << mat[i][j] << " " << ANSI_COLOR_RESET;
            }
            cout << endl;
        }
    }

    Matrix add(Matrix &M)
    {
        if (rows != M.rows || cols != M.cols)
        {
            cout << ANSI_COLOR_RED << "Matrix dimensions do not match for addition." << ANSI_COLOR_RESET << endl;
            exit(1);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] + M.mat[i][j];
            }
        }
        return result;
    }

    Matrix subtract(Matrix &M)
    {
        if (rows != M.rows || cols != M.cols)
        {
            cout << ANSI_COLOR_RED << "Matrix dimensions do not match for subtraction." << ANSI_COLOR_RESET << endl;
            exit(1);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] - M.mat[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix &M)
    {
        if (cols != M.rows)
        {
            cout << ANSI_COLOR_RED << "Matrix dimensions do not match for multiplication." << ANSI_COLOR_RESET << endl;
            exit(1);
        }

        Matrix result(rows, M.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < M.cols; j++)
            {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.mat[i][j] += mat[i][k] * M.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix performOperation(Matrix &M)
    {
        int choice;
        cout << "Choose operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;

        while (!(cin >> choice) || choice < 1 || choice > 4)
        {
            cout << ANSI_COLOR_RED << "Invalid choice. Please enter a valid operation." << ANSI_COLOR_RESET << endl;
            cout << "Choose operation:" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Exit" << endl;
        }

        Matrix result(rows, cols);

        switch (choice)
        {
        case 1:
            result = add(M);
            break;

        case 2:
            result = subtract(M);
            break;

        case 3:
            result = multiply(M);
            break;

        case 4:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Invalid choice. Please select a valid operation." << ANSI_COLOR_RESET << endl;
            exit(1);
        }
        return result;
    }
};

class UnitConverter
{
private:
    double conversionFactors[13];

public:
    UnitConverter()
    {
        // Length conversions
        conversionFactors[0] = 39.3701; // meters_to_inches
        conversionFactors[1] = 0.0254;  // inches_to_meters
        conversionFactors[2] = 3.28084; // meters_to_feet
        conversionFactors[3] = 0.3048;  // feet_to_meters

        // Mass conversions
        conversionFactors[4] = 2.20462;  // kilograms_to_pounds
        conversionFactors[5] = 0.453592; // pounds_to_kilograms
        conversionFactors[6] = 1000;     // kilograms_to_grams
        conversionFactors[7] = 0.001;    // grams_to_kilograms

        // Power conversions
        conversionFactors[8] = 0.00134102; // watts_to_horsepower
        conversionFactors[9] = 745.7;      // horsepower_to_watts

        // Time conversions
        conversionFactors[10] = 60;        // minutes_to_seconds
        conversionFactors[11] = 0.0166667; // seconds_to_minutes
        // Add more conversions as needed
    }

    // Function to perform unit conversion
    double performConversion(double value, int conversionIndex)
    {
        if (conversionIndex >= 0 && conversionIndex < 13)
        {
            return value * conversionFactors[conversionIndex];
        }
        else
        {
            cout << ANSI_COLOR_RED << "Conversion not supported or invalid.\n"
                 << ANSI_COLOR_RESET;
            return 0.0;
        }
    }

    void startConversion()
    {
        int conversionIndex;
        double value;

        // cout << "Welcome to the Universal Unit Converter!\n\n";
        cout << "Select the conversion type:\n";
        cout << "1. Meters to Inches\n";
        cout << "2. Inches to Meters\n";
        cout << "3. Meters to Feet\n";
        cout << "4. Feet to Meters\n";
        cout << "5. Kilograms to Pounds\n";
        cout << "6. Pounds to Kilograms\n";
        cout << "7. Kilograms to Grams\n";
        cout << "8. Grams to Kilograms\n";
        cout << "9. Watts to Horsepower\n";
        cout << "10. Horsepower to Watts\n";
        cout << "11. Minutes to Seconds\n";
        cout << "12. Seconds to Minutes\n";

        cout << "\nEnter the index of conversion : ";
        cin >> conversionIndex;
        while (conversionIndex < 1 || conversionIndex > 13)
        {
            cout << ANSI_COLOR_RED << "Enter proper input.........." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter index of conversion : ";
            cin >> conversionIndex;
        }

        cout << "Enter the value to convert: ";
        cin >> value;

        double convertedValue = performConversion(value, conversionIndex - 1);
        cout << "\nResult:\n";
        cout << value << " ";
        switch (conversionIndex)
        {
        case 1:
            cout << "Meters to Inches";
            break;
        case 2:
            cout << "Inches to Meters";
            break;
        case 3:
            cout << "Meters to Feet";
            break;
        case 4:
            cout << "Feet to Meters";
            break;
        case 5:
            cout << "Kilograms to Pounds";
            break;
        case 6:
            cout << "Pounds to Kilograms";
            break;
        case 7:
            cout << "Kilograms to Grams";
            break;
        case 8:
            cout << "Grams to Kilograms";
            break;
        case 9:
            cout << "Watts to Horsepower";
            break;
        case 10:
            cout << "Horsepower to Watts";
            break;
        case 11:
            cout << "Minutes to Seconds";
            break;
        case 12:
            cout << "Seconds to Minutes";
            break;
        default:
            cout << "Invalid conversion ..................";
            break;
        }
        cout << " = " << ANSI_COLOR_YELLOW << convertedValue << ANSI_COLOR_RESET << endl;
    }
};

class Universal_Values
{
private:
    int choice;

public:
    void Display_choices()
    {
        cout << "The Universal Quantities are : " << endl;
        cout << "1. Speed of Light (c)\n";
        cout << "2. Planck's Constant\n";
        cout << "3. Gravitational Constant (G)\n";
        cout << "4. Avogadro's Number (Nₐ)\n";
        cout << "5. Boltzmann Constant (k)\n";
        cout << "6. π (Pi)\n";
        cout << "7. Euler's Number (e)\n";
        cout << "8. Golden Ratio (ϕ)\n";
        cout << "9. Exit";
    }

    void Enter_Choice()
    {
        cout << "Enter which Value you want : ";
        cout << "\nEnter your choice : ";
        cin >> choice;
        while (choice < 1 || choice > 9)
        {
            cout << ANSI_COLOR_RED << "Invalid choice.........\n"
                 << ANSI_COLOR_RESET;
            cout << "Renter the choice :";
            cin >> choice;
        }
    }

    void Display_values()
    {
        switch (choice)
        {
        case 1:
            cout << ANSI_COLOR_YELLOW << "Speed of Light (c) = 3.00 * 10^8 meters per second (in vacuum)" << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            cout << ANSI_COLOR_YELLOW << "Planck's Constant = 6.626 * 10^(-34) joule seconds" << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            cout << ANSI_COLOR_YELLOW << "Gravitational Constant (G) = 6.674 * 10^(-11) cubic meters per kilogram per second square" << ANSI_COLOR_RESET << endl;
            break;

        case 4:
            cout << ANSI_COLOR_YELLOW << "Avogadro's Number (Nₐ) = 6.022 * 10^(23) particles per mole" << ANSI_COLOR_RESET << endl;
            break;

        case 5:
            cout << ANSI_COLOR_YELLOW << "Boltzmann Constant (k) = 1.381 * 10^(-23) joules per kelvin" << ANSI_COLOR_RESET << endl;
            break;

        case 6:
            cout << ANSI_COLOR_YELLOW << "π (Pi) = 3.14159265358979323846264338327950288419716939937510" << ANSI_COLOR_RESET << endl;
            break;

        case 7:
            cout << ANSI_COLOR_YELLOW << "Euler's Number (e) =  2.71828" << ANSI_COLOR_RESET << endl;
            break;

        case 8:
            cout << ANSI_COLOR_YELLOW << "Golden Ratio (ϕ) = 1.61803" << ANSI_COLOR_RESET << endl;
            break;

        case 9:
            exit(1);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown Error.............." << ANSI_COLOR_RESET << endl;
        }
    }
};

class Shape
{
private:
    int choice;
    double radius;
    double side;
    double length;
    double breadth;
    double height;
    double side_1;
    double side_2;
    double side_3;

public:
    void circle()
    {
        cout << "Enter Radius of the circle : ";
        cin >> radius;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Area\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (2 * M_PI * radius) << ANSI_COLOR_RESET << endl;
            break;

        case 2:
            cout << "Area : " << ANSI_COLOR_YELLOW << (M_PI * radius * radius) << ANSI_COLOR_RESET << endl;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET << endl;
        }
    }

    void square()
    {
        cout << "Enter side of the square : ";
        cin >> side;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Area\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (4 * side) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Area : " << ANSI_COLOR_YELLOW << (side * side) << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void rectangle()
    {
        cout << "Enter sides of the rectangle : \n";
        cout << "Length : ";
        cin >> length;
        cout << "Breadth :";
        cin >> breadth;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Area\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (2 * (length + breadth)) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Area : " << ANSI_COLOR_YELLOW << (length * breadth) << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET << endl;
        }
    }

    void triangle()
    {
        cout << "Enter the sides of the triangle : ";
        cout << "Side 1 : ";
        cin >> side_1;
        cout << "Side 2 : ";
        cin >> side_2;
        cout << "Side 3 : ";
        cin >> side_3;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Area\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (side_1 + side_2 + side_3) << ANSI_COLOR_RESET;
            break;

        case 2:
        {
            double s = (side_1 + side_2 + side_3) / 2;
            cout << "Area : " << ANSI_COLOR_YELLOW << sqrt(s * (s - side_1) * (s - side_2) * (s - side_3)) << ANSI_COLOR_RESET;
            break;
        }

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void cube()
    {
        cout << "Enter side of the cube : ";
        cin >> side;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Surface Area\n3. Volume\n4. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (12 * side) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Surface Area : " << ANSI_COLOR_YELLOW << (6 * side * side) << ANSI_COLOR_RESET;
            break;

        case 3:
            cout << "Volume : " << ANSI_COLOR_YELLOW << (side * side * side) << ANSI_COLOR_RESET;
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void cuboid()
    {
        cout << "Enter sides of the cuboid : \n";
        cout << "Length : ";
        cin >> length;
        cout << "Breadth :";
        cin >> breadth;
        cout << "Height : ";
        cin >> height;
        cout << "What do you want to find ? " << endl;
        cout << "1. Perimeter \n2. Surface Area\n3. Volume\n4. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Perimeter : " << ANSI_COLOR_YELLOW << (2 * (length + breadth + height)) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Surface Area : " << ANSI_COLOR_YELLOW << (2 * (length * breadth + length * height + breadth * height)) << ANSI_COLOR_RESET;
            break;

        case 3:
            cout << "Volume : " << ANSI_COLOR_YELLOW << (length * breadth * height) << ANSI_COLOR_RESET;
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void sphere()
    {
        cout << "Enter Radius of the sphere : ";
        cin >> radius;
        cout << "What do you want to find ? " << endl;
        cout << "1. Surface Area\n2. Volume\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Surface Area : " << ANSI_COLOR_YELLOW << (4 * M_PI * pow(radius, 2)) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Volume : " << ANSI_COLOR_YELLOW << ((4.0 / 3.0) * M_PI * pow(radius, 3)) << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void cylinder()
    {
        cout << "Enter dimensions of the cylinder : " << endl;
        cout << "Radius : ";
        cin >> radius;
        cout << "Height : ";
        cin >> height;
        cout << "What do you want to find ? " << endl;
        cout << "1. Surface Area\n2. Volume\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
            cout << "Surface Area : " << ANSI_COLOR_YELLOW << (2 * M_PI * radius * (radius + height)) << ANSI_COLOR_RESET;
            break;

        case 2:
            cout << "Volume : " << ANSI_COLOR_YELLOW << (M_PI * pow(radius, 2) * height) << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void cone()
    {
        cout << "Enter dimensions of the cone : " << endl;
        cout << "Radius : ";
        cin >> radius;
        cout << "Height : ";
        cin >> height;
        cout << "What do you want to find ? " << endl;
        cout << "1. Surface Area\n2. Volume\n3. Exit\n";
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
        switch (choice)
        {
        case 1:
        {
            double slant_height = sqrt(pow(radius, 2) + pow(height, 2));
            cout << "Surface Area : " << ANSI_COLOR_YELLOW << (M_PI * radius * slant_height + M_PI * pow(radius, 2)) << ANSI_COLOR_RESET;
            break;
        }

        case 2:
            cout << "Volume : " << ANSI_COLOR_YELLOW << ((1.0 / 3.0) * M_PI * pow(radius, 2) * height) << ANSI_COLOR_RESET;
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << ANSI_COLOR_RED << "Unknown choice." << ANSI_COLOR_RESET;
        }
    }

    void show_choice()
    {
        cout << "\nWhich shape do you want?\n";
        cout << "1. Circle\n2. Square\n3. Rectangle\n4. Triangle\n5. Cube\n6. Cuboid\n7. Sphere\n8. Cylinder\n9. Cone\n10. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        while (choice < 1 || choice > 10)
        {
            cout << ANSI_COLOR_RED << "Enter propper choice .............." << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
    }

    void Shape_Switch_case()
    {
        switch (choice)
        {
        case 1:
            circle();
            break;

        case 2:
            square();
            break;

        case 3:
            rectangle();
            break;

        case 4:
            triangle();
            break;

        case 5:
            cube();
            break;

        case 6:
            cuboid();
            break;

        case 7:
            sphere();
            break;

        case 8:
            cylinder();
            break;

        case 9:
            cone();
            break;

        case 10:
            exit(0);
            break;

        default:
            cout << "Unknown choice.";
        }
    }
};

class CurrencyConverter
{
private:
    double conversionRates[5][5];

public:
    CurrencyConverter()
    {
        // Initialize conversion rates
        conversionRates[1][2] = 0.85; // USD to EUR
        conversionRates[1][1] = 1.0;  // USD to USD
        conversionRates[1][3] = 0.72; // USD to GBP
        conversionRates[1][4] = 75.0; // USD to INR
        conversionRates[1][5] = 3.67; // USD to AED

        conversionRates[2][1] = 1.18; // EUR to USD
        conversionRates[2][2] = 1.0;  // EUR to EUR
        conversionRates[2][3] = 0.84; // EUR to GBP
        conversionRates[2][4] = 88.0; // EUR to INR
        conversionRates[2][5] = 4.43; // EUR to AED

        conversionRates[3][1] = 1.38;  // GBP to USD
        conversionRates[3][2] = 1.19;  // GBP to EUR
        conversionRates[3][3] = 1.0;   // GBP to GBP
        conversionRates[3][4] = 103.0; // GBP to INR
        conversionRates[3][5] = 5.02;  // GBP to AED

        conversionRates[4][1] = 0.013;  // INR to USD
        conversionRates[4][2] = 0.011;  // INR to EUR
        conversionRates[4][3] = 0.0097; // INR to GBP
        conversionRates[4][4] = 1.0;    // INR to INR
        conversionRates[4][5] = 0.049;  // INR to AED

        conversionRates[5][1] = 0.27;  // AED to USD
        conversionRates[5][2] = 0.23;  // AED to EUR
        conversionRates[5][3] = 0.20;  // AED to GBP
        conversionRates[5][4] = 20.40; // AED to INR
        conversionRates[5][5] = 1.0;   // AED to AED
    }

    double convert(double amount, int fromIndex, int toIndex)
    {
        if (fromIndex < 1 || fromIndex > 5 || toIndex < 1 || toIndex > 5)
        {
            cout << ANSI_COLOR_RED << "Invalid currency index!" << ANSI_COLOR_RESET << endl;
            return -1;
        }

        return amount * conversionRates[fromIndex][toIndex];
    }

    void startConversion()
    {
        double amount;
        int fromIndex, toIndex;

        cout << "Currency Converter" << endl;

        cout << "Available Currencies:" << endl;
        cout << "1: USD (US Dollar)" << endl;
        cout << "2: EUR (Euro)" << endl;
        cout << "3: GBP (British Pound)" << endl;
        cout << "4: INR (Indian Rupee)" << endl;
        cout << "5: AED (United Arab Emirates Dirham)" << endl;

        cout << "Enter amount to convert: ";
        cin >> amount;

        cout << "Enter currency index to convert from: ";
        cin >> fromIndex;

        cout << "Enter currency index to convert to: ";
        cin >> toIndex;

        double result = convert(amount, fromIndex, toIndex);
        if (result != -1)
        {
            cout << ANSI_COLOR_YELLOW << amount << ANSI_COLOR_RESET << " in currency " << fromIndex << " is equivalent to " << ANSI_COLOR_YELLOW << result << ANSI_COLOR_RESET << " in currency " << toIndex << endl;
        }
    }
};

class TicTacToe
{
private:
    char board[3][3];   // 3x3 Tic Tac Toe board
    char currentPlayer; // Current player (X or O)
public:
    TicTacToe()
    {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X'; // Player X starts
    }

    // Function to display the Tic Tac Toe board
    void displayBoard()
    {
        cout << " " << ANSI_COLOR_YELLOW << board[0][0] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[0][1] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[0][2] << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_PINK << "-----------" << ANSI_COLOR_RESET << endl;
        cout << " " << ANSI_COLOR_YELLOW << board[1][0] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[1][1] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[1][2] << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_PINK << "-----------" << ANSI_COLOR_RESET << endl;
        cout << " " << ANSI_COLOR_YELLOW << board[2][0] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[2][1] << ANSI_COLOR_RESET << ANSI_COLOR_PINK << " | " << ANSI_COLOR_RESET << ANSI_COLOR_YELLOW << board[2][2] << ANSI_COLOR_RESET << endl;
    }

    // Function to check if the game has been won
    bool checkWin()
    {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true; // Row win
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true; // Column win
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true; // Diagonal win
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true; // Diagonal win
        return false;    // No win
    }

    // Function to check if the game is a draw
    bool checkDraw()
    {
        // If there is any empty space on the board, the game is not a draw
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        // If all spaces are filled and nobody won, it's a draw
        return true;
    }

    // Function to switch players
    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to make a move
    bool makeMove(int row, int col)
    {
        // Check if the move is valid and the cell is empty
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
            return false;
        // Set the move on the board
        board[row][col] = currentPlayer;
        return true;
    }

    // Function to start the game
    void startGame()
    {
        int row, col;
        while (true)
        {
            // Display the current board
            cout << "Current board:" << endl;
            displayBoard();

            // Get the move from the current player
            cout << "Player " << currentPlayer << ", enter your move : \n";
            cout << "Row (1-3) : ";
            cin >> row;
            cout << "Column (1-3) : ";
            cin >> col;

            // Convert move to zero-based index
            row--;
            col--;

            // Make the move
            if (!makeMove(row, col))
            {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            // Check if the current player has won
            if (checkWin())
            {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the game is a draw
            if (checkDraw())
            {
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch to the other player
            switchPlayer();
        }

        // Display the final board
        cout << "Final board:" << endl;
        displayBoard();
    }
};

/*
class Scientific_Calculator : public Angle, public Arithmatic, public Complex, public Switch_Case, public Logarithm, public Matrix, public UnitConverter, public Universal_Values
{
private:
    int choice;

public:
    Scientific_Calculator();

    void display_choice()
    {
        cout << "Welcome to the scientific calculator made by F.Y. students : " << endl;
        cout << "Following Functions can be perforemed by using this calculator : " << endl;
        cout << "1. Arithmatic Operations. " << endl;
        cout << "2. Matrix Operations. " << endl;
        cout << "3. Complex Numbers and it's Arithmatics." << endl;
        cout << "4. Equation Solving. " << endl;
        cout << "5. Logaritham and it's Arithmatics." << endl;
        cout << "6. Angles and Angle Conversions." << endl;
        cout << "7. Unit Conversion. " << endl;
        cout << "8. Universal Values. " << endl;
        cout << "9. Exit." << endl;
    }

    void input_choice()
    {
        cout << "Enter the task you want to perform (in the form of choice) : ";
        cin >> choice;
        while (choice < 1 || choice > 9)
        {
            cout << "Enter proper choice............" << endl;
            cout << "1. Arithmatic Operations. " << endl;
            cout << "2. Matrix Operations. " << endl;
            cout << "3. Complex Numbers and it's Arithmatics." << endl;
            cout << "4. Equation Solving. " << endl;
            cout << "5. Logaritham and it's Arithmatics." << endl;
            cout << "6. Angles and Angle Conversions." << endl;
            cout << "7. Unit Conversion. " << endl;
            cout << "8. Universal Values. " << endl;
            cout << "9. Exit." << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }
    }

    void Calculator()
    {
        // switch (choice)
        // {
            // case 1 :                                // Arithmatic Operations
            // Arithmatic A;
            // A.input();
            // A.process();
            // break;

            // case 2 :                                // Matrix Operations
            // int rows, cols;
            // cout << "Enter the number of rows and columns for matrices: ";
            // cout << "Rows : ";
            // cin >> rows;
            // cout << "Columns : ";
            // cin >> cols;
            // while (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
            // {
            //     cout << "Invalid input. Please enter positive values within the range." << endl;
            //     cout << "Enter the number of rows and columns for matrices: ";
            //     cout << "Rows : ";
            //     cin >> rows;
            //     cout << "Columns : ";
            //     cin >> cols;
            // }

            // Matrix M1(rows, cols);
            // cout << "Enter the first matrix :" << endl;
            // M1.input();

            // Matrix M2(rows, cols);
            // cout << "Enter the second matrix :" << endl;
            // M2.input();

            // Matrix result = M1.performOperation(M2);
            // result.output();
            // break;

            // case 3 :                                // Complex Numbers and it's Arithmatics
            // Complex c1, c2;
            // Complex c;
            // c.choice(c1, c2);
            // break;

            // case 4 :                                // Equation Solving
            // Switch_Case S;
            // break;

            // case 5 :                                // Logaritham and it's Arithmatics
            // Logarithm L;
            // L.Display_choice();
            // L.Main_Switch();
            // break;

            // case 6 :                                // Angles and Angle Conversions
            // Angle An;
            // An.Angle_Type();
            // An.choice();
            // An.Switch_case();
            // break;

            // case 7 :                                // Unit Conversion
            // UnitConverter converter;
            // converter.startConversion();
            // break;

            // case 8 :                                // Universal Values
            // Universal_Values U;
            // U.Display_choices();
            // U.Enter_Choice();
            // U.Display_values();
            // break;

            // case 9 :                                // Exit
            // exit(1);
            // break;

            // default :
            // cout<<"Unknown error.................."<<endl;
        // 
        }

        if (choice == 1)
            {
                Arithmatic A;
                A.input();
                A.process();
            }

            else if (choice == 2)
            {
                int rows, cols;
                cout << "Enter the number of rows and columns for matrices: ";
                cout << "Rows : ";
                cin >> rows;
                cout << "Columns : ";
                cin >> cols;
                while (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
                {
                    cout << "Invalid input. Please enter positive values within the range." << endl;
                    cout << "Enter the number of rows and columns for matrices: ";
                    cout << "Rows : ";
                    cin >> rows;
                    cout << "Columns : ";
                    cin >> cols;
                }

                Matrix M1(rows, cols);
                cout << "Enter the first matrix :" << endl;
                M1.input();

                Matrix M2(rows, cols);
                cout << "Enter the second matrix :" << endl;
                M2.input();

                Matrix result = M1.performOperation(M2);
                result.output();
            }

            else if (choice == 3)
            {
                Complex c1, c2;
                Complex c;
                c.choice(c1, c2);
            }

            else if (choice == 4)
            {
                Switch_Case S;
            }

            else if (choice == 5)
            {
                Logarithm L;
                L.Display_choice();
                L.Main_Switch();
            }

            else if (choice == 6)
            {
                Angle An;
                An.Angle_Type();
                An.choice();
                An.Switch_case();
            }

            else if (choice == 7)
            {
                UnitConverter converter;
                converter.startConversion();
            }

            else if (choice == 8)
            {
                Universal_Values U;
                U.Display_choices();
                U.Enter_Choice();
                U.Display_values();
            }

            else if (choice == 9)
            {
                exit(1);
            }

            else
            {
                cout<<"Unknown error............";
            }
    }

};
*/

int main()
{
    int choice;

    do
    {
        cout << "\n";
        cout << ANSI_COLOR_BLUE << "-=======================================-" << endl;
        cout << "|               CALCULATOR              |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|   1. Arithmetic Operations            |" << endl;
        cout << "|   2. Matrix Operations                |" << endl;
        cout << "|   3. Complex Numbers and Arithmetic   |" << endl;
        cout << "|   4. Equation Solving                 |" << endl;
        cout << "|   5. Logarithm and Arithmetic         |" << endl;
        cout << "|   6. Angles and Angle Conversions     |" << endl;
        cout << "|   7. Shapes and Geometry              |" << endl;
        cout << "|   8. Currency Conversion              |" << endl;
        cout << "|   9. Unit Conversion                  |" << endl;
        cout << "|   10. Universal Values                |" << endl;
        cout << "|   11. Fun Game: Tic Tac Toe           |" << endl;
        cout << "|   12. Exit                            |" << endl;
        cout << "|---------------------------------------|" << endl;
        // Display calculator body with numbers and operations
        cout << "|    7    |    8    |    9    |    +    |" << endl;
        cout << "|    4    |    5    |    6    |    -    |" << endl;
        cout << "|    1    |    2    |    3    |    *    |" << endl;
        cout << "|    0    |    .    |    =    |    /    |" << endl;
        cout << "-=======================================-" << ANSI_COLOR_RESET << endl;

        cout << "Enter the task you want to perform (in the form of choice) : ";
        cin >> choice;
        while (choice < 1 || choice > 12)
        {
            cout << "\n";
            cout << ANSI_COLOR_RED << "Invalid Choice........" << ANSI_COLOR_RESET << endl;
            cout << ANSI_COLOR_BLUE << "-=======================================-" << endl;
            cout << "|               CALCULATOR              |" << endl;
            cout << "|---------------------------------------|" << endl;
            cout << "|   1. Arithmetic Operations            |" << endl;
            cout << "|   2. Matrix Operations                |" << endl;
            cout << "|   3. Complex Numbers and Arithmetic   |" << endl;
            cout << "|   4. Equation Solving                 |" << endl;
            cout << "|   5. Logarithm and Arithmetic         |" << endl;
            cout << "|   6. Angles and Angle Conversions     |" << endl;
            cout << "|   7. Shapes and Geometry              |" << endl;
            cout << "|   8. Currency Conversion              |" << endl;
            cout << "|   9. Unit Conversion                  |" << endl;
            cout << "|   10. Universal Values                |" << endl;
            cout << "|   11. Fun Game: Tic Tac Toe           |" << endl;
            cout << "|   12. Exit                            |" << endl;
            cout << "|---------------------------------------|" << endl;
            // Display calculator body with numbers and operations
            cout << "|    7    |    8    |    9    |    +    |" << endl;
            cout << "|    4    |    5    |    6    |    -    |" << endl;
            cout << "|    1    |    2    |    3    |    *    |" << endl;
            cout << "|    0    |    .    |    =    |    /    |" << endl;
            cout << "-=======================================-" << ANSI_COLOR_RESET << endl;
            cout << "Re-enter your choice : ";
            cin >> choice;
        }

        if (choice == 1) // Arithmatic Operations.
        {
            Arithmatic A;
            while (true)
            {
                A.input();
                A.process();
                cout << endl;
            }
        }

        else if (choice == 2) // Matrix Operations
        {
            int rows, cols;
            cout << "Enter the number of rows and columns for matrices: ";
            cout << "Rows : ";
            cin >> rows;
            cout << "Columns : ";
            cin >> cols;
            while (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
            {
                cout << ANSI_COLOR_RED << "Invalid input. Please enter positive values within the range." << ANSI_COLOR_RESET << endl;
                cout << "Enter the number of rows and columns for matrices: ";
                cout << "Rows : ";
                cin >> rows;
                cout << "Columns : ";
                cin >> cols;
            }

            Matrix M1(rows, cols);
            cout << "Enter the first matrix :" << endl;
            M1.input();

            Matrix M2(rows, cols);
            cout << "Enter the second matrix :" << endl;
            M2.input();

            Matrix result = M1.performOperation(M2);
            result.output();
            exit(1);
        }

        else if (choice == 3) // Complex Numbers and it's Arithmatics.
        {
            Complex c1, c2;
            Complex c;
            c.choice(c1, c2);
        }

        else if (choice == 4) // Equation Solving.
        {
            Switch_Case S;
        }

        else if (choice == 5) // Logaritham and it's Arithmatics
        {
            Logarithm L;
            while (true)
            {
                L.Display_choice();
                L.Main_Switch();
            }
        }

        else if (choice == 6) // Angles and Angle Conversions.
        {
            Angle An;
            An.Angle_Type();
            An.choice();
            An.Switch_case();
        }

        else if (choice == 7) // Shapes snd Geometry.
        {
            Shape S;
            while (true)
            {
                S.show_choice();
                S.Shape_Switch_case();
            }
        }

        else if (choice == 8) // Curracy Convertation.
        {
            CurrencyConverter converter;
            converter.startConversion();
        }

        else if (choice == 9) // Unit Conversion.
        {
            UnitConverter converter;
            while (true)
            {
                converter.startConversion();
            }
        }

        else if (choice == 10) // Universal Values.
        {
            Universal_Values U;
            while (true)
            {
                U.Display_choices();
                U.Enter_Choice();
                U.Display_values();
            }
        }

        else if (choice == 11) // Fun Game :- Tic Tac To.
        {
            while (true)
            {
                TicTacToe game;
                game.startGame();
            }
        }

        else if (choice == 12) // Exit
        {
            exit(1);
        }

        else
        {
            cout << "Unknown error............";
        }
    } while (choice != 12);

    return 0;
}