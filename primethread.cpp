#include "primethread.h"

using namespace std;

PrimeThread::PrimeThread()
{
    this->m_run = true;
}

void PrimeThread::run()
{
    int i,j;
    //qDebug() << QThread::currentThreadId();
    while(m_run)
    {
        for(i=this->m_number; i <= this->m_number; i++)
        {
            if (m_array[i]==i)
            {
                for (j=i+i; j <= m_maxNumber; j+=i) {
                    m_array[j]=0;
                }
            }
            this->m_run = false;
        }
    }
}

void PrimeThread::setPrimeNumber(int number)
{
    this->m_number = number;
    cout << "thread received the value to check: " << this->m_number << endl;
}

void PrimeThread::setArrayList(int *array)
{
    this->m_array = array;
}

void PrimeThread::setMaxValue(int value)
{
    this->m_maxNumber = value;
}
