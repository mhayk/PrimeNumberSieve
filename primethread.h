#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <QtCore>

class PrimeThread : public QThread
{
private:
    bool m_run;
    int m_number;
    int *m_array;
    int m_maxNumber;
public:
    PrimeThread();
    void run();
    void setPrimeNumber(int number);
    void setArrayList(int *array);
    void setMaxValue(int value);

};

#endif // PRIMETHREAD_H
