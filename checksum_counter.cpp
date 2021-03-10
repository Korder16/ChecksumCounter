#include "checksum_counter.h"

ChecksumCounter::ChecksumCounter() {}


QByteArray ChecksumCounter::operator ()(const QString& filename)
{
    return checksum(filename);
}

QByteArray ChecksumCounter::checksum(const QString &filename, QCryptographicHash::Algorithm hash_algorithm)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) {

        QCryptographicHash hash(hash_algorithm);
        if(hash.addData(&file)) {
            return hash.result().toHex();
        }
    }
    return QByteArray();
}
