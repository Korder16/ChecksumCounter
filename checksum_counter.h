#ifndef CHECKSUMCOUNTER_H
#define CHECKSUMCOUNTER_H

#include <QCryptographicHash>
#include <QFile>

class ChecksumCounter
{
public:
    ChecksumCounter();

    QByteArray operator ()(const QString& filename);

    QByteArray checksum(const QString& filename,
                        QCryptographicHash::Algorithm hash_algorithm = QCryptographicHash::Md5);
};

#endif // CHECKSUMCOUNTER_H
