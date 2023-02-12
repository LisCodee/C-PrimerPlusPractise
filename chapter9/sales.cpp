#include "sales.h"
#include <limits>

namespace SALES
{
    void setSales(Sales& s, const double ar[], int n)
    {
        double sum = 0;
        double min = std::numeric_limits<double>::max();
        double max = std::numeric_limits<double>::min();
        for(int i = 0; i < n; ++i)
        {
            min = min > ar[i] ? ar[i] : min;
            max = max < ar[i] ? ar[i] : max;
            sum += ar[i];
        }
        double average = sum / n;
        s.average = average;
        s.max = max;
        s.min = min;
        for (int i = 0; i < 4; i++)
        {
            s.sales[i] = 0;
            if(i < n)
                s.sales[i] = ar[i];
        }
    }
    void setSales(Sales& s)
    {
        //..
    }
    void showSales(Sales& s)
    {
        //..
    }
}