#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QDebug>
#include <QModelIndex>
#include <QIcon>

class ImageProvider : public QQuickImageProvider
{
    public:
        explicit ImageProvider();
        QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
        void setIcon(QVariant value);
    signals:

    public slots:

    private:
        QVariant  m_value;
};

Q_DECLARE_METATYPE(ImageProvider * )
#endif // IMAGEPROVIDER_H
