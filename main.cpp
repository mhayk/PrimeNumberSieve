#include <QCoreApplication>
#include <QList>
#include <math.h>
#include <iostream>
#include <QDebug>

#include "primethread.h"

#define MAX 499900000

using namespace std;

int array[MAX];

void printPrimes(int size)
{
    int i;

    for(i=0; i < size; i++)
    {
        if(array[i] !=0)
        {
            cout << array[i] << " ";
        }
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    qDebug() << QThread::currentThreadId();

    int nThreads;
    int i,n = atoi(argv[1]);

    for (i=2; i<=n; i++) {
        array[i]=i;
    }

    nThreads = floor(sqrt(n));
    cout << nThreads;

    QList<PrimeThread*> m_listThread;

    i=2;

    cout << "while: " << array[i] << "<" << nThreads << endl;
    while(array[i] <= nThreads)
    {
        PrimeThread *t = new PrimeThread();
        t->setMaxValue(n);
        t->setPrimeNumber(i);
        t->setArrayList(array);
        t->start();
        m_listThread.append(t);
        i++;
    }


    for(i=0; i< m_listThread.count(); i++)
    {
        while (!m_listThread.at(i)->isFinished());
    }

    printPrimes(n);

    m_listThread.clear();

    return a.exec();
//    return 0;

}
