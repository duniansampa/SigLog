#ifndef IMAGEPROVIDERWRAPPER_H
#define IMAGEPROVIDERWRAPPER_H

#include <QObject>

#include "ImageProvider.h"
#include "FileSystemModel.h"

class ImageProviderWrapper: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant icon  READ icon WRITE setIcon NOTIFY iconChanged)

public:
    explicit ImageProviderWrapper(QObject *parent = 0):QObject(parent){
        m_imageProvider =  NULL;
    }
    explicit ImageProviderWrapper(ImageProvider * imProvider, QObject *parent = 0): QObject(parent){

       m_imageProvider = imProvider;
    }

    virtual ~ImageProviderWrapper(){
        delete m_imageProvider;
    }

    QVariant icon(){
        return QIcon();
    }

    void setIcon(QVariant value)
    {  if ( m_imageProvider){
            m_imageProvider->setIcon(value);
            emit iconChanged();
       }
    }

    ImageProvider * getImageProvider() const{
       return  m_imageProvider;
    }
    void setImageProvider(ImageProvider *  imageProvider){
        m_imageProvider = imageProvider;
    }

signals:
    void iconChanged();
public slots:

private:
     ImageProvider * m_imageProvider;
     QVariant m_value;
};

Q_DECLARE_METATYPE(ImageProviderWrapper * )

#endif // IMAGEPROVIDERWRAPPER_H
