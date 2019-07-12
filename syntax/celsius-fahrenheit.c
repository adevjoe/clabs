/**
 * print Fahrenheit-Celsius table
 * 
 * 公式: ℃=(5/9)(°F-32)
 */
#include <stdio.h>

void printFahrenheitToCelsius()
{
    printf("printFahrenheitToCelsius\n");
    printf("Fahrenheit\tCelsius\n");
    float fahr = 0;    // 温度表下限
    float upper = 300; // 温度表上限
    float step = 20;
    while (fahr <= upper)
    {
        printf("%-10.0f\t%-6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
        /* %3.0f 指定字符宽度为 3，保留 0 位小数的浮点数
            %-2d 右对齐*/
        fahr += step;
    }
}

void printFahrenheitToCelsiusInt()
{
    printf("printFahrenheitToCelsius with int\n");
    printf("Fahrenheit\tCelsius\n");
    int fahr = 0;    // 温度表下限
    int upper = 300; // 温度表上限
    int step = 20;
    while (fahr <= upper)
    {
        printf("%10d\t%6d\n", fahr, 5 * (fahr - 32) / 9); // 先执行 (5/9) 会舍位，得到 0
        fahr += step;
    }
}

void printCelsiusToFahrenheit()
{
    printf("printCelsiusToFahrenheit\n");
    printf("Celsius\tFahrenheit\n");
    float celsius = -20; // 温度表下限
    float upper = 100;   // 温度表上限
    float step = 10;
    while (celsius <= upper)
    {
        printf("%6.0f\t%10.0f\n", celsius, celsius * 9.0 / 5.0 + 32);
        celsius += step;
    }
}

void printFahrenheitToCelsiusReverse()
{
    printf("printFahrenheitToCelsiusReverse\n");
    printf("Fahrenheit\tCelsius\n");
    for (float fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%-10.0f\t%-6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}

int main()
{
    printFahrenheitToCelsius();
    printf("\n");
    printCelsiusToFahrenheit();
    printf("\n");
    printFahrenheitToCelsiusInt();
    printf("\n");
    printFahrenheitToCelsiusReverse();
    return 0;
}