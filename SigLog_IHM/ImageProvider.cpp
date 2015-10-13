#include "ImageProvider.h"

ImageProvider::ImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    QIcon icon = m_value.value<QIcon>();

    return icon.pixmap(32,32);
}
void ImageProvider::setIcon(QVariant value)
{
    m_value = value;
}
