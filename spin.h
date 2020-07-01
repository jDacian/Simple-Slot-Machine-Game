#ifndef FREE_SPIN_H
#define FREE_SPIN_H

#endif // FREE_SPIN_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <time.h>
#include <QThread>
#include <QMessageBox>

class Spin: public QObject {
    Q_OBJECT
public slots:
    void spin();
};
